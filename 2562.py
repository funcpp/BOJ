a = [];
idx=0;
Max=0;

for i in range(9):
	a.append(int(input()));
	if Max < a[i]:
		Max=a[i];
		idx=i;

print(Max, idx+1);
