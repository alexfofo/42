module Card =
struct

module Color =
struct

	type t = Spade | Heart | Diamond | Club

	let all = [
			Spade;
			Heart;
			Diamond;
			Club
		]

	let toString color = match color with
		| Spade -> "S"
		| Heart -> "H"
		| Diamond -> "D"
		| Club -> "C"

	let toStringVerbose color = match color with
		| Spade -> "Spade"
		| Heart -> "Heart"
		| Diamond -> "Diamond"
		| Club -> "Club"

end

module Value =
struct
	type t = T2 | T3 | T4 | T5 | T6 | T7 | T8 | T9 | T10 | Jack | Queen | King | As

	let all = [
			T2; 
			T3; 
			T4; 
			T5; 
			T6; 
			T7; 
			T8; 
			T9; 
			T10; 
			Jack; 
			Queen; 
			King; 
			As
		]

	let toInt valu = match valu with
		| T2 -> 1
		| T3 -> 2
		| T4 -> 3
		| T5 -> 4
		| T6 -> 5
		| T7 -> 6
		| T8 -> 7
		| T9 -> 8
		| T10 -> 9
		| Jack -> 10
		| Queen -> 11
		| King -> 12
		| As -> 13

	let toString valu = match valu with
		| T2 -> "2"
		| T3 -> "3"
		| T4 -> "4"
		| T5 -> "5"
		| T6 -> "6"
		| T7 -> "7"
		| T8 -> "8"
		| T9 -> "9"
		| T10 -> "10"
		| Jack -> "J"
		| Queen -> "Q"
		| King -> "K"
		| As -> "A"

	let toStringVerbose valu = match valu with
		| T2 -> "2"
		| T3 -> "3"
		| T4 -> "4"
		| T5 -> "5"
		| T6 -> "6"
		| T7 -> "7"
		| T8 -> "8"
		| T9 -> "9"
		| T10 -> "10"
		| Jack -> "Jack"
		| Queen -> "Queen"
		| King -> "King"
		| As -> "As"

	let next valu = match valu with
		| As -> invalid_arg "card is As, no next card"
		| T2 -> T3
		| T3 -> T4
		| T4 -> T5
		| T5 -> T6
		| T6 -> T7
		| T7 -> T8
		| T8 -> T9
		| T9 -> T10
		| T10 -> Jack
		| Jack -> Queen
		| Queen -> King
		| King -> As

	let previous valu = match valu with
		| T2 -> invalid_arg "card is T2, no next card"
		| T3 -> T2
		| T4 -> T3
		| T5 -> T4
		| T6 -> T5
		| T7 -> T6
		| T8 -> T7
		| T9 -> T8
		| T10 -> T9
		| Jack -> T10
		| Queen -> Jack
		| King -> Queen
		| As -> King

end


	type t = (Value.t * Color.t)

	let newCard (v : Value.t) (c : Color.t) : t =
		(v, c)

	let allSpades : t list =
		let rec loop l acc = match l with
			| [] -> acc
			| tete::queue -> loop queue acc@[(tete, Color.Spade)]
		in
		loop (Value.all) []

	let allHearts : t list =
		let rec loop l acc = match l with
			| [] -> acc
			| tete::queue -> loop queue acc@[(tete, Color.Heart)]
		in
		loop (Value.all) []

	let allDiamonds : t list =
		let rec loop l acc = match l with
			| [] -> acc
			| tete::queue -> loop queue acc@[(tete, Color.Diamond)]
		in
		loop (Value.all) []

	let allClubs : t list =
		let rec loop l acc = match l with
			| [] -> acc
			| tete::queue -> loop queue acc@[(tete, Color.Club)]
		in
		loop (Value.all) []

	let all : t list =
		[]@allSpades@allClubs@allDiamonds@allHearts

	let getValue (titi : t) = match titi with
		| (v, c) -> v

	let getColor (toto : t) = match toto with
		| (v, c) -> c

	let toString (tutu : t) = match tutu with
		| (v, c) -> (Value.toString v) ^ (Color.toString c)

	let toStringVerbose (tutu : t) = match tutu with
		| (v, c) -> "Card(" ^ (Value.toStringVerbose v) ^ ", " ^ (Color.toStringVerbose c) ^ ")"

	let compare c1 c2 =
		((Value.toInt (getValue c1)) - (Value.toInt (getValue c2)))

	let max c1 c2 =
		if (compare c1 c2) >= 0 then c1 else c2

	let min c1 c2 =
		if (compare c1 c2) <= 0 then c1 else c2

	let best l = match l with
		| [] -> invalid_arg "cannot exec function best on empty list"
		| _ -> List.fold_left max (Value.T2, Color.Club) l

	let isOf t color =
		Color.toString (getColor t) = Color.toString (color)

	let isSpade t =
		Color.toString (getColor t) = "S"

	let isHeart t =
		Color.toString (getColor t) = "H"

	let isDiamond t =
		Color.toString (getColor t) = "D"

	let isClub t =
		Color.toString (getColor t) = "C"
end



type t = Card.t list

let switch_two_val_list liste index =
	let rec loop to_fill liste index count =
		if count = 52 then to_fill
		else if count = 0 then loop (to_fill@[(List.nth liste index)]) liste index (count + 1)
		else if count = index then loop (to_fill@[(List.nth liste 0)]) liste index (count + 1)
		else loop (to_fill@[(List.nth liste count)]) liste index (count + 1)
	in
	loop [] liste index 0

let newDeck () : t =
	Random.self_init ();
	let rec loop li acc =
		if (acc = 100) then li
		else loop (switch_two_val_list li (Random.int 52)) (acc + 1)
	in
	loop Card.all 0


let toStringList (te:t) =
	let rec loop te acc = match te with
		| [] -> acc
		| tete::queue -> loop queue (acc@[(Card.toString tete)])
	in
	loop te []

let toStringListVerbose (te:t) =
	let rec loop te acc = match te with
		| [] -> acc
		| tete::queue -> loop queue (acc@[(Card.toStringVerbose tete)])
	in
	loop te []

let drawCard (teuch:t) : Card.t * Card.t list =
	(List.hd teuch, List.tl teuch)






