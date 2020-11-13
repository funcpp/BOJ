a = [];
for i in range(10):
	x = int(input());
	if x%42 not in a:
		a.append(x%42);

print(len(a));