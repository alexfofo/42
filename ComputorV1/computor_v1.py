# -*- encoding:Latin-1 -*

# a = raw_input("Balance tout: ")
a = "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
eq = a.split("=")
# print eq
left_side = eq[0]
right_side = eq[1]

my_list_l = []
i = 0
while i < len(left_side):
	if left_side[i] is "X":
		my_list_l.append((left_side[:i + 3]).replace(" ", ""))
		left_side = left_side[i + 3:]
		i = -1
	i += 1
# print "list of left elements", my_list_l

my_list_r = []
i = 0
while i < len(right_side):
	if right_side[i] is "X":
		my_list_r.append((right_side[:i + 3]).replace(" ", ""))
		right_side = right_side[i + 3:]
		i = -1
	i += 1
# print "list of right elements", my_list_r



def compute_x_n(llist, rlist, n=0):
	ret = 0
	ref = "*X^" + str(n)
	for s in llist:
		if ref in s:
			ret += eval(s[:s.find(ref)])
	for s in rlist:
		if ref in s:
			ret -= eval(s[:s.find(ref)])
	# print("ret = {}".format(ret))
	return ret

coef_x0 = compute_x_n(my_list_l, my_list_r, 0)
coef_x1 = compute_x_n(my_list_l, my_list_r, 1)
coef_x2 = compute_x_n(my_list_l, my_list_r, 2)

# print("Reduced form: {} * X^0")
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
		else:
			first = 0
		ret += "{} * X^1 ".format(coef_x1 * -1)
	if coef_x2 > 0:
		if first == 0:
			ret += "+ "
		else:
			first = 0
		ret += "{} * X^2 ".format(coef_x2)
	elif coef_x2 < 0:
		if first == 0:
			ret += "- "
		else:
			first = 0
		ret += "{} * X^2 ".format(coef_x2 * -1)
	return ret

print "Reduced form:", get_reduced_form(coef_x0, coef_x1, coef_x2), "= 0"

if coef_x2 != 0:
	print("Polynomial degree: 2")
	deg_max = 2
elif coef_x1 != 0:
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
		print "fdp les nombres complexes c'est loiiin, aucun souvenir de comment qu'on fait"
	elif delta == 0:
		print "Discriminant is 0, the solution is:"
		print eval("-1 * coef_x1 / (2 * coef_x2)")






