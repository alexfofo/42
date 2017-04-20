//
//  ViewController.swift
//  d07
//
//  Created by Alexandre FOLLIN on 10/12/16.
//  Copyright © 2016 Alexandre FOLLIN. All rights reserved.
//

import UIKit
import ForecastIO
import RecastAI

class ViewController: UIViewController, HandlerRecastRequestProtocol {

    var client : APIClient?
    var bot : RecastAIClient?
    
    var lat : Float = 0.0
    var lng : Float = 0.0
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.client = APIClient(apiKey: "ca143ae3435351a70c89cd631c0908fc")
        self.bot = RecastAIClient(token: "f70cdd6bc4ca0140c103290e17287211", handlerRecastRequestProtocol: self)
        client?.units = .UK
        client?.language = .French
    }


    @IBOutlet weak var textField: UITextField!

    @IBOutlet weak var lablab: UILabel!
    
    
    @IBAction func butbut(sender: UIButton) {
        if lablab.text != nil {
            self.bot?.textRequest(textField.text!)
        }
    }
    
    func recastRequestDone(response : Response)
    {
        print("coucou")
        print(response.sentences![0].entities!.locations![0].lat)
        lat = response.sentences![0].entities!.locations![0].lat
        lng = response.sentences![0].entities!.locations![0].lng
//        lablab.text = "lat : \(lat), lng: \(lng)"
        print("coucou2")
        

        
        self.client!.getForecast(latitude: Double(lat), longitude: Double(lng)){ (data, err) in
            if ((err) != nil) { print("err") }
            else {
                print(data?.daily?.summary)
                dispatch_async(dispatch_get_main_queue()){
                    self.lablab.text = data?.daily?.summary!
                }
                
            }
        }
    }
    func recastRequestError(error : NSError)
    {
        print("Delegate Error : \(error)")
        lablab.text = "Error"
    }
    
    

}

