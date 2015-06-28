class pikachu =
	object (self)
		val health = ref 100
		val energy = ref 100
		val hygiene = ref 100
		val happiness = ref 100

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