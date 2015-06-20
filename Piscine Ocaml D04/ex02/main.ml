let rec print_list l = match l with
	| [] -> ()
	| tete::queue -> print_endline (Card.toStringVerbose tete); print_list queue

let () =
	let w = Card.newCard Card.Value.Queen Card.Color.Heart in 	(* Queen Heart *)
	let x = Card.newCard Card.Value.As Card.Color.Club in 		(* As Club *)
	let y = Card.newCard Card.Value.T10 Card.Color.Spade in 	(* 10 Spade *)
	let z = Card.newCard Card.Value.T2 Card.Color.Diamond in 	(* 2 Diamond *)
	let zbis = Card.newCard Card.Value.T2 Card.Color.Club in 	(* 2 Club *)
	let lili = (w::x::y::z::zbis::[]) in

	print_string "                                                0     \n";
	print_endline (Card.toStringVerbose w); 										(* toStringVerbose *)
	print_endline (Card.toString x); 												(* toString *)
	print_endline (Card.toStringVerbose y); 										(* toStringVerbose *)
	print_endline (Card.toString z); 												(* toString *)
	print_string "                                                1     \n";

	print_endline (string_of_bool (Card.isClub x)); 								(* isClub *)
	print_endline (string_of_bool (Card.isHeart y)); 								(* isHeart *)
	print_string "                                                2     \n";

	print_endline (string_of_bool (Card.isOf x Card.Color.Heart)); 					(* isOf *)
	print_endline (string_of_bool (Card.isOf x Card.Color.Club)); 					(* isOf *)
	print_string "                                                3     \n";

	print_endline (Card.Value.toStringVerbose (Card.getValue x)); 					(* getValue *)
	print_string "                                                4     \n";

	print_endline (Card.Color.toStringVerbose (Card.getColor x)); 					(* getColor *)
	print_string "                                                5     \n";

	print_int (Card.compare z zbis); 												(* compare z = zbis *)
	print_char '\n';
	print_int (Card.compare z x); 													(* compare z < x *)
	print_char '\n';
	print_string "                                                6     \n";

	print_endline (Card.toStringVerbose (Card.max z zbis)); 						(* max *)
	print_endline (Card.toStringVerbose (Card.max z y)); 							(* max *)
	print_string "                                                7     \n";

	print_endline (Card.toStringVerbose (Card.min z zbis)); 						(* min *)
	print_endline (Card.toStringVerbose (Card.min z y)); 							(* min *)
	print_string "                                                8     \n";

	print_endline (Card.toStringVerbose (Card.best lili)); 							(* best *)
	print_string "                                                9     \n";

	print_list Card.allDiamonds; 													(* list allDiamond *)
	print_string "                                                10     \n";

	print_list Card.all; 															(* list all *)
	print_char '\n'

