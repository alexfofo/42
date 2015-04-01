# -*- encoding:Latin-1 -*

full = raw_input("Balance tout: ")
# full = "3 * X^0 - 1 * X^1  = 0 "

if full.count("=") != 1:
	print "I am sorry, but I need '=' once in your equation "
	raise SystemExit

eq = full.split("=")
left_side = eq[0]
right_side = eq[1]

def get_any_of(str, match):
	i = -1
	for c in str:
		i += 1
		if c in match:
			return i
	return -1

my_list_l = []
i = 0
while len(left_side) != 0 and i < len(left_side):
	next_op = -1
	if left_side[i] is "X":
		next_op = get_any_of(left_side[i:], "+-")
		if next_op == -1:
			my_list_l.append(left_side.replace(" ", ""))
			left_side = ""
		else:
			my_list_l.append((left_side[:i + next_op]).replace(" ", ""))
			left_side = left_side[i + next_op:]
		i = -1
	i += 1

my_list_r = []
i = 0
while len(right_side) != 0 and i < len(right_side):
	next_op = -1
	if right_side[i] is "X":
		next_op = get_any_of(right_side[i:], "+-")
		if next_op == -1:
			my_list_r.append(right_side.replace(" ", ""))
			right_side = ""
		else:
			my_list_r.append((right_side[:i + next_op]).replace(" ", ""))
			right_side = right_side[i + next_op:]
		i = -1
	i += 1

def compute_x_n(llist, rlist, n):
	ret = .0
	ref = "*X^" + str(n)
	for s in llist:
		if ref in s:
			ret += eval(s[:s.find(ref)])
	for s in rlist:
		if ref in s:
			ret -= eval(s[:s.find(ref)])
	return ret

coef_x0 = compute_x_n(my_list_l, my_list_r, 0)
coef_x1 = compute_x_n(my_list_l, my_list_r, 1)
coef_x2 = compute_x_n(my_list_l, my_list_r, 2)

def get_expo(lst):
	list_of_expo = []
	for elt in lst:
		j = elt.find("X")
		k = eval(elt[j + 2:])
		if k not in list_of_expo:
			list_of_expo.append(k)
	return list_of_expo

list_of_expo = get_expo(my_list_r + my_list_l)
for x in list_of_expo:
	if x > 2 or x < 0:
		coef_NA = compute_x_n(my_list_l, my_list_r, x)
		if coef_NA != 0:
			print("vatfoudel kalay: I don't handle equation with X^{}, I prefere second degree equations :)".format(x))
			raise SystemExit

def get_reduced_form(coef_x0, coef_x1, coef_x2):
	first = 1
	ret = ""
	if coef_x0 != 0:
		ret += "{} * X^0 ".format(coef_x0)
		first = 0
	if coef_x1 > 0:
		if first == 0:
			ret += "+ "
		else:
			first = 0
		ret += "{} * X^1 ".format(coef_x1)
	elif coef_x1 < 0:
		if first == 0:
			ret += "- "
			ret += "{} * X^1 ".format(coef_x1 * -1)
		else:
			first = 0
			ret += "{} * X^1 ".format(coef_x1)
	if coef_x2 > 0:
		if first == 0:
			ret += "+ "
		else:
			first = 0
		ret += "{} * X^2 ".format(coef_x2)
	elif coef_x2 < 0:
		if first == 0:
			ret += "- "
			ret += "{} * X^2 ".format(coef_x2 * -1)
		else:
			first = 0
			ret += "{} * X^2 ".format(coef_x2)
	return ret

# print "Reduced form:", get_reduced_form(coef_x0, coef_x1, coef_x2), "= 0"

def hi_complexity():
	delta_bis = delta * -1
	complex_tmp = 2 * coef_x2
	complex_data_a = coef_x1 * -1 / complex_tmp
	complex_data_b = delta_bis**(.5) / complex_tmp
	if complex_tmp < 0:
		complex_tmp = complex_tmp * -1
	print("{} - i * {}".format(complex_data_a, complex_data_b))
	print("{} + i * {}".format(complex_data_a, complex_data_b))

if coef_x2 != 0:
	print "Reduced form:", get_reduced_form(coef_x0, coef_x1, coef_x2), "= 0"
	print("Polynomial degree: 2")
	deg_max = 2
elif coef_x1 != 0:
	print "Reduced form:", get_reduced_form(coef_x0, coef_x1, coef_x2), "= 0"
	print("Polynomial degree: 1")
	deg_max = 1
else:
	print("Polynomial degree: 0")
	deg_max = 0

if deg_max == 2:
	delta = coef_x1**2 - 4*coef_x2*coef_x0
	if delta > 0:
		print "Discriminant is strictly positive, the two solutions are:"
		sol = (-1 * coef_x1 - delta**(0.5)) / (2 * coef_x2)
		print sol
		print eval( "((-1 * coef_x1) + (delta**(0.5))) / (2*coef_x2)" )
	elif delta < 0:
		print "Discriminant is strictly negative, the two complexes solutions are:"
		hi_complexity()
	elif delta == 0:
		print "Discriminant is 0, the solution is:"
		print eval("-1 * coef_x1 / (2 * coef_x2)")

if deg_max == 1:
	print "No need to compute discriminant because highest degree is 1, the solution is:"
	print eval("-1 * coef_x0 / coef_x1")

if deg_max == 0:
	print "Hum... The reduced form I find has an infity of value for X...\nI assume you want to laugh...\nSo I'll draw you toto"
	print """#########
| 0 + 0 |
\___=___/"""
	print "Funny... isn't it?"