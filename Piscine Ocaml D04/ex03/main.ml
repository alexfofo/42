let rec print_list l = match l with
	| [] -> ()
	| tete::queue -> print_string tete; print_string "  "; print_list queue

let d (carte, reste) =
	print_string "carte tirée : ";
	print_string (Deck.Card.toString carte);
	print_string "\n"

let () =
	let d1 = Deck.newDeck () in
	let d2 = Deck.newDeck () in
	let draw = Deck.drawCard d1 in
	print_list (Deck.toStringList d1);
	print_string "\n\n";
	print_list (Deck.toStringList d2);
	print_string "\n\n";
	print_list (Deck.toStringListVerbose d1);
	print_string "\n\n";
	print_list (Deck.toStringListVerbose d2);
	print_string "\n\n";
	d draw








(* Pour tester les autre chose que le Deck (copie colle du main ex02), commenter au dessus, decommenter au dessous *)

(* 

let rec print_list_2 l = match l with
	| [] -> ()
	| tete::queue -> print_endline (Deck.Card.toStringVerbose tete); print_list_2 queue

let () =
	let w = Deck.Card.newCard Deck.Card.Value.Queen Deck.Card.Color.Heart in 	(* Queen Heart *)
	let x = Deck.Card.newCard Deck.Card.Value.As Deck.Card.Color.Club in 		(* As Club *)
	let y = Deck.Card.newCard Deck.Card.Value.T10 Deck.Card.Color.Spade in 	(* 10 Spade *)
	let z = Deck.Card.newCard Deck.Card.Value.T2 Deck.Card.Color.Diamond in 	(* 2 Diamond *)
	let zbis = Deck.Card.newCard Deck.Card.Value.T2 Deck.Card.Color.Club in 	(* 2 Club *)
	let lili = (w::x::y::z::zbis::[]) in

	print_string "                                                0     \n";
	print_endline (Deck.Card.toStringVerbose w); 										(* toStringVerbose *)
	print_endline (Deck.Card.toString x); 												(* toString *)
	print_endline (Deck.Card.toStringVerbose y); 										(* toStringVerbose *)
	print_endline (Deck.Card.toString z); 												(* toString *)
	print_string "                                                1     \n";

	print_endline (string_of_bool (Deck.Card.isClub x)); 								(* isClub *)
	print_endline (string_of_bool (Deck.Card.isHeart y)); 								(* isHeart *)
	print_string "                                                2     \n";

	print_endline (string_of_bool (Deck.Card.isOf x Deck.Card.Color.Heart)); 					(* isOf *)
	print_endline (string_of_bool (Deck.Card.isOf x Deck.Card.Color.Club)); 					(* isOf *)
	print_string "                                                3     \n";

	print_endline (Deck.Card.Value.toStringVerbose (Deck.Card.getValue x)); 					(* getValue *)
	print_string "                                                4     \n";

	print_endline (Deck.Card.Color.toStringVerbose (Deck.Card.getColor x)); 					(* getColor *)
	print_string "                                                5     \n";

	print_int (Deck.Card.compare z zbis); 												(* compare z = zbis *)
	print_char '\n';
	print_int (Deck.Card.compare z x); 													(* compare z < x *)
	print_char '\n';
	print_string "                                                6     \n";

	print_endline (Deck.Card.toStringVerbose (Deck.Card.max z zbis)); 						(* max *)
	print_endline (Deck.Card.toStringVerbose (Deck.Card.max z y)); 							(* max *)
	print_string "                                                7     \n";

	print_endline (Deck.Card.toStringVerbose (Deck.Card.min z zbis)); 						(* min *)
	print_endline (Deck.Card.toStringVerbose (Deck.Card.min z y)); 							(* min *)
	print_string "                                                8     \n";

	print_endline (Deck.Card.toStringVerbose (Deck.Card.best lili)); 							(* best *)
	print_string "                                                9     \n";

	print_list_2 Deck.Card.allDiamonds; 													(* list allDiamond *)
	print_string "                                                10     \n";

	print_list_2 Deck.Card.all; 															(* list all *)
	print_char '\n' *)