//
//  JSViewController.swift
//  d07
//
//  Created by Alexandre FOLLIN on 10/13/16.
//  Copyright © 2016 Alexandre FOLLIN. All rights reserved.
//

import UIKit
import JSQMessagesViewController
import RecastAI
import ForecastIO

class JSQViewController: JSQMessagesViewController, HandlerRecastRequestProtocol {
    
    var firstError = true
    var bot : RecastAIClient?
    var client : APIClient?
    
    let incomingBubble = JSQMessagesBubbleImageFactory().incomingMessagesBubbleImageWithColor(UIColor(red: 10/255, green: 180/255, blue: 230/255, alpha: 1.0))
    let outgoingBubble = JSQMessagesBubbleImageFactory().outgoingMessagesBubbleImageWithColor(UIColor.lightGrayColor())
    var messages = [JSQMessage]()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setup()
        
        client = APIClient(apiKey: "bb6e581c4a8b7d9e7926b575a1714680")
        client?.units = .UK
        client?.language = .French
        self.bot = RecastAIClient(token : "f8a8c07f0a7e497312efe8a642ff21e9", handlerRecastRequestProtocol: self)
        self.bot?.textRequest("Go fuck yourself")
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
    }
    func reloadMessagesView() {
        self.collectionView?.reloadData()
    }
    
    func setup() {
        self.senderId = UIDevice.currentDevice().identifierForVendor?.UUIDString
        self.senderDisplayName = UIDevice.currentDevice().identifierForVendor?.UUIDString
    }
    
    /**/
    
    override func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return self.messages.count
    }
    
    override func collectionView(collectionView: JSQMessagesCollectionView!, messageDataForItemAtIndexPath indexPath: NSIndexPath!) -> JSQMessageData! {
        let data = self.messages[indexPath.row]
        return data
    }
    
    override func collectionView(collectionView: JSQMessagesCollectionView!, didDeleteMessageAtIndexPath indexPath: NSIndexPath!) {
        self.messages.removeAtIndex(indexPath.row)
    }
    
    override func collectionView(collectionView: JSQMessagesCollectionView!, messageBubbleImageDataForItemAtIndexPath indexPath: NSIndexPath!) -> JSQMessageBubbleImageDataSource! {
        let data = messages[indexPath.row]
        switch(data.senderId) {
        case self.senderId:
            return self.outgoingBubble
        default:
            return self.incomingBubble
        }
    }
    
    override func collectionView(collectionView: JSQMessagesCollectionView!, avatarImageDataForItemAtIndexPath indexPath: NSIndexPath!) -> JSQMessageAvatarImageDataSource! {
        return nil
    }
    
    /**/
    
    override func didPressSendButton(button: UIButton!, withMessageText text: String!, senderId: String!, senderDisplayName: String!, date: NSDate!) {
        self.bot?.textRequest(text)
    }
    
    override func didPressAccessoryButton(sender: UIButton!) {
        bot?.startStreamRequest()
        let Alert = UIAlertController(title: "Voice dictation", message: "Press OK for send your request", preferredStyle: UIAlertControllerStyle.Alert)
        
        Alert.addAction(UIAlertAction(title: "Ok", style: .Default, handler: { (action: UIAlertAction!) in
            self.bot?.stopStreamRequest()
        }))
        presentViewController(Alert, animated: true, completion: nil)
    }
    
    func recastRequestDone(response : Response)
    {
        if response.source != nil && firstError == false
        {
            let message = JSQMessage(senderId: senderId, displayName: self.senderDisplayName, text: response.source)
            self.messages += [message]
            self.finishSendingMessage()
        }
        if let lat = response.sentences?[0].entities?.locations?[0].lat, lng = response.sentences?[0].entities?.locations?[0].lng
        {
            self.client!.getForecast(latitude: Double(lat), longitude: Double(lng)){ (data, err) in
                if ((err) != nil) { print("err") }
                else {
                    print(data?.daily?.summary)
                    dispatch_async(dispatch_get_main_queue()){
                        let message = JSQMessage(senderId: "Server", displayName: "Server", text: data?.daily?.summary!)
                        self.messages += [message]
                        self.finishSendingMessage()
                    }
                }
            }
        }
        else if firstError == false {
            let message = JSQMessage(senderId: "Server", displayName: "Server", text: "Sorry.")
            self.messages += [message]
            self.finishSendingMessage()
        }
        else {
            firstError = false
        }
        
        print(response.source)
    }
    
    func recastRequestError(error : NSError)
    {
        if firstError == true
        {
            firstError = false
            return
        }
        else
        {
            print("Delegate Error : \(error)")
        }
    }
}
