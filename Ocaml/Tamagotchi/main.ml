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

let draw_init () =
	make_button_x_color 1 Graphics.white;
	make_button_x_color 2 Graphics.white;
	make_button_x_color 3 Graphics.white;
	make_button_x_color 4 Graphics.white

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


let handle_events statu pikapika =
	if statu.Graphics.button = true then
		begin
			let rect = mouse_is_in_button statu.Graphics.mouse_x statu.Graphics.mouse_y pikapika in
			if (rect > 0) then
				begin
					make_button_x_color rect Graphics.black;
					ignore (Graphics.wait_next_event [Graphics.Button_up])
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
	let rec loop () =
		Unix.sleep 1;
		let x = (Random.int 500) + 25 in
		let y = (Random.int 500) + 50 in
		let a = (Random.int 256) in
		let b = (Random.int 256) in
		let c = (Random.int 256) in
		(* Graphics.set_font (List.nth ["Luminari"; "Times"] (Random.int 2)); *)
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
	let pikapika = new Pika_object.pikachu in
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





















