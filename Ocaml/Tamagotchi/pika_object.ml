class pikachu (p1:int) (p2:int) (p3:int) (p4:int) =
	object (self)
		val health = ref p1
		val energy = ref p2
		val hygiene = ref p3
		val happiness = ref p4

		method get_health = health
		method get_energy = energy
		method get_hygiene = hygiene
		method get_happiness = happiness

		method set_health x = health := let z = !health + x in if z > 100 then 100 else if z < 0 then 0 else z
		method set_energy x = energy := let z = !energy + x in if z > 100 then 100 else if z < 0 then 0 else z
		method set_hygiene x = hygiene := let z = !hygiene + x in if z > 100 then 100 else if z < 0 then 0 else z
		method set_happiness x = happiness := let z = !happiness + x in if z > 100 then 100 else if z < 0 then 0 else z

		method is_alive = !health > 0 && !energy > 0 && !hygiene > 0 && !happiness > 0
	end