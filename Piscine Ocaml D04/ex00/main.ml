let rec print_list_verbose liste = match liste with 
	| e::l -> print_string (Color.toStringVerbose e) ; print_string " " ; print_list_verbose l
	| [] -> ()

let rec print_list_not_verbose liste = match liste with 
	| e::l -> print_string (Color.toString e) ; print_string " " ; print_list_not_verbose l
	| [] -> ()


let () =
	print_list_verbose Color.all;
	print_string "\n";
	print_list_not_verbose Color.all;
	print_string "\n"


