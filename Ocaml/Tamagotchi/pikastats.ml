let draw_rectangle x y long =
	Graphics.moveto (x) (y);
	Graphics.lineto (x) (y + long/4 - 1);
	Graphics.lineto (x + long) (y + long/4 - 1);
	Graphics.lineto (x + long) (y);
	Graphics.lineto (x) (y)

let write_string x y s =
	Graphics.moveto x y;
	Graphics.draw_string s

let draw_containers () =
	draw_rectangle 48 480 104;
	write_string 80 515 "Health";
	draw_rectangle 178 480 104;
	write_string 210 515 "Energy";
	draw_rectangle 308 480 104;
	write_string 335 515 "Hygiene";
	draw_rectangle 438 480 104;
	write_string 460 515 "Happiness"

let fill_containers health energy hygiene happiness =
	Graphics.set_color Graphics.white;
	Graphics.fill_rect 50 482 100 21;
	Graphics.fill_rect 180 482 100 21;
	Graphics.fill_rect 310 482 100 21;
	Graphics.fill_rect 440 482 100 21;
	Graphics.set_color (Graphics.rgb (255 - (health * 2 + health / 2 + 5)) 0 0);
	Graphics.fill_rect 50 482 health 21;
	Graphics.set_color (Graphics.rgb (255 - (energy * 2 + energy / 2 + 5)) 0 0);
	Graphics.fill_rect 180 482 energy 21;
	Graphics.set_color (Graphics.rgb (255 - (hygiene * 2 + hygiene / 2 + 5)) 0 0);
	Graphics.fill_rect 310 482 hygiene 21;
	Graphics.set_color (Graphics.rgb (255 - (happiness * 2 + happiness / 2 + 5)) 0 0);
	Graphics.fill_rect 440 482 happiness 21

let write_percentages health energy hygiene happiness =
	Graphics.set_color (Graphics.rgb 150 150 150);
	write_string 87 486 ((string_of_int health) ^ "%");
	write_string 217 486 ((string_of_int energy) ^ "%");
	write_string 347 486 ((string_of_int hygiene) ^ "%");
	write_string 475 486 ((string_of_int happiness) ^ "%");
	Graphics.set_color Graphics.black

let update_pika_stats health energy hygiene happiness =
	fill_containers health energy hygiene happiness;
	write_percentages health energy hygiene happiness

let init_pika_stats () =
	Graphics.set_line_width 3;
	Graphics.set_color Graphics.black;
	draw_containers ();
	Graphics.set_line_width 1;
	update_pika_stats 100 100 100 100
 
