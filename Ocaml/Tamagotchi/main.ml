let draw_rectangle x y long =
	Graphics.moveto (x) (y);
	Graphics.lineto (x) (y + long/2);
	Graphics.lineto (x + long) (y + long/2);
	Graphics.lineto (x + long) (y);
	Graphics.lineto (x) (y)

let write_string x y s =
	Graphics.moveto x y;
	Graphics.draw_string s

let make_button_x_color r c =
	Graphics.set_color c;
	Graphics.fill_rect (55 + 130 * (r - 1)) 25 100 50;
	Graphics.set_color Graphics.black;
	draw_rectangle (55 + 130 * (r - 1)) 25 100;
	if c = Graphics.white then Graphics.set_color Graphics.black else Graphics.set_color Graphics.white;
	write_string (List.nth [95; 215; 350; 480] (r - 1)) 45 (List.nth ["Eat"; "Thunder"; "Bath"; "Kill"] (r - 1));
	Graphics.set_color Graphics.black

let make_save_button () =
	draw_rectangle 0 550 80;
	write_string 20 565 "Save"

let make_pause_button () =
	draw_rectangle 520 550 80;
	write_string 540 565 "Pause"

let draw_init () =
	make_button_x_color 1 Graphics.white;
	make_button_x_color 2 Graphics.white;
	make_button_x_color 3 Graphics.white;
	make_button_x_color 4 Graphics.white;
	make_save_button ();
	make_pause_button ()

let mouse_is_in_button x y pikapika =
	if y < 75 && y > 25 then
		if (x > 55 && x < 155) then
			begin
				pikapika#set_health 25;
				pikapika#set_energy (-10);
				pikapika#set_hygiene (-20);
				pikapika#set_happiness 5;
				1
			end
		else if (x > 185 && x < 285) then
			begin
				pikapika#set_health (-20);
				pikapika#set_energy (25);
				pikapika#set_happiness (-20);
				2
			end
		else if (x > 315 && x < 415) then
			begin
				pikapika#set_health (-20);
				pikapika#set_energy (-10);
				pikapika#set_hygiene (25);
				pikapika#set_happiness 5;
				3
			end
		else if (x > 445 && x < 545) then
			begin
				pikapika#set_health (-20);
				pikapika#set_energy (-10);
				pikapika#set_happiness (20);
				4
			end
		else
			0
	else
		0

let do_pause () =
	ignore (Graphics.wait_next_event [Graphics.Button_down])

let do_save pikpik =
	let oc = open_out "save.itama" in
	output_string oc (string_of_int !(pikpik#get_health));
	output_char oc '\n';
	output_string oc (string_of_int !(pikpik#get_energy));
	output_char oc '\n';
	output_string oc (string_of_int !(pikpik#get_hygiene));
	output_char oc '\n';
	output_string oc (string_of_int !(pikpik#get_happiness));
	output_char oc '\n';
	close_out oc

let handle_events statu pikapika =
	if statu.Graphics.button = true then
		begin
			(* let x = statu.Graphics.mouse_x *)
			(* and y = statu.Graphics.mouse_y in *)
			let rect = mouse_is_in_button statu.Graphics.mouse_x statu.Graphics.mouse_y pikapika in
			if (rect > 0) then
				begin
					make_button_x_color rect Graphics.black;
					ignore (Graphics.wait_next_event [Graphics.Button_up])
				end
			else if (statu.Graphics.mouse_x > 0 && statu.Graphics.mouse_x < 80 && statu.Graphics.mouse_y > 550 && statu.Graphics.mouse_y < 590) then
			begin				
				do_save pikapika
			end
			else if (statu.Graphics.mouse_x > 520 && statu.Graphics.mouse_x < 600 && statu.Graphics.mouse_y > 550 && statu.Graphics.mouse_y < 590) then
			begin
				do_pause ()
			end
			else
				();
			draw_init ();
			true
		end
	else if statu.Graphics.keypressed = true then begin ignore (exit 0); true end
	else false

let game_over () =
	Random.self_init ();
	Pika_dead.draw_pika ();
	let rec loop () =
		Unix.sleep 1;
		let x = (Random.int 500) + 25 in
		let y = (Random.int 500) + 50 in
		let a = (Random.int 256) in
		let b = (Random.int 256) in
		let c = (Random.int 256) in
		if x mod 3 = 0 then Skull_pixel_art.draw_pixel_skull ((Random.int 500) + 25) ((Random.int 500) + 25) else ();
		Graphics.set_font (List.nth ["5x7"; "5x8"; "6x9"; "6x10"; "6x12"; "6x13"; "6x13Bold"; "7x13";
										"7x13Bold"; "7x14"; "7x14Bold"; "8x13"; "8x13Bold"; "9x15"; "9x15Bold"; "10x20"] (Random.int 16));
		Graphics.set_color (Graphics.rgb a b c);
		write_string x y "Game Over !";
		let sta = Graphics.wait_next_event [Graphics.Key_pressed; Graphics.Poll] in
		if sta.Graphics.keypressed then exit 0 else ();
		loop ()
	in
	loop ()

let check_time t pikapika =
	let a = Unix.time () in
	if t <> a then
		begin
			pikapika#set_health (-1);
			Pikastats.update_pika_stats !(pikapika#get_health) !(pikapika#get_energy) !(pikapika#get_hygiene) !(pikapika#get_happiness);
			if (pikapika#is_alive = false) then begin print_endline "Pika a mouru :("; ignore (game_over ()); t end else a
			end
	else t

let _ =
	print_endline "Pour lancer le jeu a partir d'une sauvegarde dans un fichier nomme save.itama : ./out 42";
	let pikapika =
	if (Array.length (Sys.argv) > 1) then
		begin
			let pikpik = new Pika_object.pikachu 0 0 0 0 in
			begin try
				let ic = open_in "save.itama" in
				pikpik#set_health (int_of_string (input_line ic));
				pikpik#set_energy (int_of_string (input_line ic));
				pikpik#set_hygiene (int_of_string (input_line ic));
				pikpik#set_happiness (int_of_string (input_line ic));
				close_in ic
			with
			| _ -> print_endline "Probleme lors de la lecture du fichier save.itama"; exit 0
			end;
			pikpik
		end
	else
		new Pika_object.pikachu 100 100 100 100
	in
	let titi = ref (Unix.time ()) in
	Graphics.open_graph " 600x600";
	draw_init ();
	Pikastats.init_pika_stats ();
	Pika.draw_pika ();
	let rec loop_infini () =
		titi := check_time !titi pikapika;
		let sta = Graphics.wait_next_event [Graphics.Button_down; Graphics.Key_pressed; Graphics.Poll] in
		if (handle_events sta pikapika) = true then
			begin
				Pikastats.update_pika_stats !(pikapika#get_health) !(pikapika#get_energy) !(pikapika#get_hygiene) !(pikapika#get_happiness);
				if (pikapika#is_alive = false) then begin print_endline "Pika a mouru :("; game_over () end else ();
				loop_infini ()
			end
		else
			loop_infini ();
	in
	ignore (loop_infini ())





















