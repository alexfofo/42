let draw_square_colored x y colori =
	Graphics.set_color colori;
	Graphics.fill_rect x y 1 1

let draw_pixel_skull x y =
	let a i = i * 1 + x in
	let b i = y - i * 1 in
	draw_square_colored (a 5) (b 0) Graphics.black;
	draw_square_colored (a 6) (b 0) Graphics.black;
	draw_square_colored (a 7) (b 0) Graphics.black;
	draw_square_colored (a 8) (b 0) Graphics.black;
	draw_square_colored (a 9) (b 0) Graphics.black;
	draw_square_colored (a 10) (b 0) Graphics.black;

	draw_square_colored (a 3) (b 1) Graphics.black;
	draw_square_colored (a 4) (b 1) Graphics.black;
	draw_square_colored (a 5) (b 1) Graphics.white;
	draw_square_colored (a 6) (b 1) Graphics.white;
	draw_square_colored (a 7) (b 1) Graphics.white;
	draw_square_colored (a 8) (b 1) Graphics.white;
	draw_square_colored (a 9) (b 1) Graphics.white;
	draw_square_colored (a 10) (b 1) Graphics.white;
	draw_square_colored (a 11) (b 1) Graphics.black;
	draw_square_colored (a 12) (b 1) Graphics.black;

	draw_square_colored (a 2) (b 2) Graphics.black;
	draw_square_colored (a 3) (b 2) Graphics.white;
	draw_square_colored (a 4) (b 2) Graphics.white;
	draw_square_colored (a 5) (b 2) Graphics.white;
	draw_square_colored (a 6) (b 2) Graphics.white;
	draw_square_colored (a 7) (b 2) Graphics.white;
	draw_square_colored (a 8) (b 2) Graphics.white;
	draw_square_colored (a 9) (b 2) Graphics.white;
	draw_square_colored (a 10) (b 2) Graphics.white;
	draw_square_colored (a 11) (b 2) Graphics.white;
	draw_square_colored (a 12) (b 2) Graphics.white;
	draw_square_colored (a 13) (b 2) Graphics.black;

	draw_square_colored (a 2) (b 3) Graphics.black;
	draw_square_colored (a 3) (b 3) Graphics.white;
	draw_square_colored (a 4) (b 3) Graphics.white;
	draw_square_colored (a 5) (b 3) Graphics.white;
	draw_square_colored (a 6) (b 3) Graphics.white;
	draw_square_colored (a 7) (b 3) Graphics.white;
	draw_square_colored (a 8) (b 3) Graphics.white;
	draw_square_colored (a 9) (b 3) Graphics.white;
	draw_square_colored (a 10) (b 3) Graphics.white;
	draw_square_colored (a 11) (b 3) Graphics.white;
	draw_square_colored (a 12) (b 3) Graphics.white;
	draw_square_colored (a 13) (b 3) Graphics.black;

	draw_square_colored (a 1) (b 4) Graphics.black;
	draw_square_colored (a 2) (b 4) Graphics.white;
	draw_square_colored (a 3) (b 4) Graphics.white;
	draw_square_colored (a 4) (b 4) Graphics.white;
	draw_square_colored (a 5) (b 4) Graphics.white;
	draw_square_colored (a 6) (b 4) Graphics.white;
	draw_square_colored (a 7) (b 4) Graphics.white;
	draw_square_colored (a 8) (b 4) Graphics.white;
	draw_square_colored (a 9) (b 4) Graphics.white;
	draw_square_colored (a 10) (b 4) Graphics.white;
	draw_square_colored (a 11) (b 4) Graphics.white;
	draw_square_colored (a 12) (b 4) Graphics.white;
	draw_square_colored (a 13) (b 4) Graphics.white;
	draw_square_colored (a 14) (b 4) Graphics.black;

	draw_square_colored (a 1) (b 5) Graphics.black;
	draw_square_colored (a 2) (b 5) Graphics.white;
	draw_square_colored (a 3) (b 5) Graphics.white;
	draw_square_colored (a 4) (b 5) Graphics.white;
	draw_square_colored (a 5) (b 5) Graphics.white;
	draw_square_colored (a 6) (b 5) Graphics.white;
	draw_square_colored (a 7) (b 5) Graphics.white;
	draw_square_colored (a 8) (b 5) Graphics.white;
	draw_square_colored (a 9) (b 5) Graphics.white;
	draw_square_colored (a 10) (b 5) Graphics.white;
	draw_square_colored (a 11) (b 5) Graphics.white;
	draw_square_colored (a 12) (b 5) Graphics.white;
	draw_square_colored (a 13) (b 5) Graphics.white;
	draw_square_colored (a 14) (b 5) Graphics.black;

	draw_square_colored (a 0) (b 6) Graphics.black;
	draw_square_colored (a 1) (b 6) Graphics.white;
	draw_square_colored (a 2) (b 6) Graphics.white;
	draw_square_colored (a 3) (b 6) Graphics.black;
	draw_square_colored (a 4) (b 6) Graphics.black;
	draw_square_colored (a 5) (b 6) Graphics.black;
	draw_square_colored (a 6) (b 6) Graphics.black;
	draw_square_colored (a 7) (b 6) Graphics.white;
	draw_square_colored (a 8) (b 6) Graphics.white;
	draw_square_colored (a 9) (b 6) Graphics.black;
	draw_square_colored (a 10) (b 6) Graphics.black;
	draw_square_colored (a 11) (b 6) Graphics.black;
	draw_square_colored (a 12) (b 6) Graphics.black;
	draw_square_colored (a 13) (b 6) Graphics.white;
	draw_square_colored (a 14) (b 6) Graphics.white;
	draw_square_colored (a 15) (b 6) Graphics.black;

	draw_square_colored (a 0) (b 7) Graphics.black;
	draw_square_colored (a 1) (b 7) Graphics.white;
	draw_square_colored (a 2) (b 7) Graphics.black;
	draw_square_colored (a 3) (b 7) Graphics.black;
	draw_square_colored (a 4) (b 7) Graphics.black;
	draw_square_colored (a 5) (b 7) Graphics.black;
	draw_square_colored (a 6) (b 7) Graphics.black;
	draw_square_colored (a 7) (b 7) Graphics.white;
	draw_square_colored (a 8) (b 7) Graphics.white;
	draw_square_colored (a 9) (b 7) Graphics.black;
	draw_square_colored (a 10) (b 7) Graphics.black;
	draw_square_colored (a 11) (b 7) Graphics.black;
	draw_square_colored (a 12) (b 7) Graphics.black;
	draw_square_colored (a 13) (b 7) Graphics.black;
	draw_square_colored (a 14) (b 7) Graphics.white;
	draw_square_colored (a 15) (b 7) Graphics.black;

	draw_square_colored (a 0) (b 8) Graphics.black;
	draw_square_colored (a 1) (b 8) Graphics.white;
	draw_square_colored (a 2) (b 8) Graphics.black;
	draw_square_colored (a 3) (b 8) Graphics.black;
	draw_square_colored (a 4) (b 8) Graphics.black;
	draw_square_colored (a 5) (b 8) Graphics.black;
	draw_square_colored (a 6) (b 8) Graphics.black;
	draw_square_colored (a 7) (b 8) Graphics.white;
	draw_square_colored (a 8) (b 8) Graphics.white;
	draw_square_colored (a 9) (b 8) Graphics.black;
	draw_square_colored (a 10) (b 8) Graphics.black;
	draw_square_colored (a 11) (b 8) Graphics.black;
	draw_square_colored (a 12) (b 8) Graphics.black;
	draw_square_colored (a 13) (b 8) Graphics.black;
	draw_square_colored (a 14) (b 8) Graphics.white;
	draw_square_colored (a 15) (b 8) Graphics.black;

	draw_square_colored (a 0) (b 9) Graphics.black;
	draw_square_colored (a 1) (b 9) Graphics.white;
	draw_square_colored (a 2) (b 9) Graphics.black;
	draw_square_colored (a 3) (b 9) Graphics.black;
	draw_square_colored (a 4) (b 9) Graphics.black;
	draw_square_colored (a 5) (b 9) Graphics.black;
	draw_square_colored (a 6) (b 9) Graphics.black;
	draw_square_colored (a 7) (b 9) Graphics.white;
	draw_square_colored (a 8) (b 9) Graphics.white;
	draw_square_colored (a 9) (b 9) Graphics.black;
	draw_square_colored (a 10) (b 9) Graphics.black;
	draw_square_colored (a 11) (b 9) Graphics.black;
	draw_square_colored (a 12) (b 9) Graphics.black;
	draw_square_colored (a 13) (b 9) Graphics.black;
	draw_square_colored (a 14) (b 9) Graphics.white;
	draw_square_colored (a 15) (b 9) Graphics.black;

	draw_square_colored (a 1) (b 10) Graphics.black;
	draw_square_colored (a 2) (b 10) Graphics.white;
	draw_square_colored (a 3) (b 10) Graphics.black;
	draw_square_colored (a 4) (b 10) Graphics.black;
	draw_square_colored (a 5) (b 10) Graphics.black;
	draw_square_colored (a 6) (b 10) Graphics.white;
	draw_square_colored (a 7) (b 10) Graphics.white;
	draw_square_colored (a 8) (b 10) Graphics.white;
	draw_square_colored (a 9) (b 10) Graphics.white;
	draw_square_colored (a 10) (b 10) Graphics.black;
	draw_square_colored (a 11) (b 10) Graphics.black;
	draw_square_colored (a 12) (b 10) Graphics.black;
	draw_square_colored (a 13) (b 10) Graphics.white;
	draw_square_colored (a 14) (b 10) Graphics.black;

	draw_square_colored (a 2) (b 11) Graphics.black;
	draw_square_colored (a 3) (b 11) Graphics.white;
	draw_square_colored (a 4) (b 11) Graphics.white;
	draw_square_colored (a 5) (b 11) Graphics.white;
	draw_square_colored (a 6) (b 11) Graphics.white;
	draw_square_colored (a 7) (b 11) Graphics.black;
	draw_square_colored (a 8) (b 11) Graphics.black;
	draw_square_colored (a 9) (b 11) Graphics.white;
	draw_square_colored (a 10) (b 11) Graphics.white;
	draw_square_colored (a 11) (b 11) Graphics.white;
	draw_square_colored (a 12) (b 11) Graphics.white;
	draw_square_colored (a 13) (b 11) Graphics.black;

	draw_square_colored (a 3) (b 12) Graphics.black;
	draw_square_colored (a 4) (b 12) Graphics.white;
	draw_square_colored (a 5) (b 12) Graphics.white;
	draw_square_colored (a 6) (b 12) Graphics.white;
	draw_square_colored (a 7) (b 12) Graphics.black;
	draw_square_colored (a 8) (b 12) Graphics.black;
	draw_square_colored (a 9) (b 12) Graphics.white;
	draw_square_colored (a 10) (b 12) Graphics.white;
	draw_square_colored (a 11) (b 12) Graphics.white;
	draw_square_colored (a 12) (b 12) Graphics.black;

	draw_square_colored (a 3) (b 13) Graphics.black;
	draw_square_colored (a 4) (b 13) Graphics.white;
	draw_square_colored (a 5) (b 13) Graphics.white;
	draw_square_colored (a 6) (b 13) Graphics.white;
	draw_square_colored (a 7) (b 13) Graphics.white;
	draw_square_colored (a 8) (b 13) Graphics.white;
	draw_square_colored (a 9) (b 13) Graphics.white;
	draw_square_colored (a 10) (b 13) Graphics.white;
	draw_square_colored (a 11) (b 13) Graphics.white;
	draw_square_colored (a 12) (b 13) Graphics.black;

	draw_square_colored (a 3) (b 14) Graphics.black;
	draw_square_colored (a 4) (b 14) Graphics.white;
	draw_square_colored (a 5) (b 14) Graphics.white;
	draw_square_colored (a 6) (b 14) Graphics.black;
	draw_square_colored (a 7) (b 14) Graphics.white;
	draw_square_colored (a 8) (b 14) Graphics.white;
	draw_square_colored (a 9) (b 14) Graphics.black;
	draw_square_colored (a 10) (b 14) Graphics.white;
	draw_square_colored (a 11) (b 14) Graphics.white;
	draw_square_colored (a 12) (b 14) Graphics.black;

	draw_square_colored (a 4) (b 15) Graphics.black;
	draw_square_colored (a 5) (b 15) Graphics.black;
	draw_square_colored (a 6) (b 15) Graphics.black;
	draw_square_colored (a 7) (b 15) Graphics.black;
	draw_square_colored (a 8) (b 15) Graphics.black;
	draw_square_colored (a 9) (b 15) Graphics.black;
	draw_square_colored (a 10) (b 15) Graphics.black;
	draw_square_colored (a 11) (b 15) Graphics.black

