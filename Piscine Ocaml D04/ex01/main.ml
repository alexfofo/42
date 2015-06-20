let rec fc l = match l with
    | h::t ->
    	print_int (Value.toInt h);
    	print_char '	';
    	print_string (Value.toString h);
    	print_char '	';
    	print_string (Value.toStringVerbose h);
    	print_char '	';
    	if Value.toString h = "2" then print_string "ERR" else
    	print_string (Value.toStringVerbose (Value.previous h));
    	print_char '	';
    	if Value.toString h = "A" then print_string "ERR" else
    	print_string (Value.toStringVerbose (Value.next h));
    	print_char '\n';
    	fc t
   | [] -> ()


let () = fc Value.all