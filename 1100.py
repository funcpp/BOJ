x = [];
for i in range(8):
	x.append(input());

num = 0;
cnt = 0;

for i in range(8):
	for j in range(8):
		if num==0 and x[i][j]=='F':
			cnt+=1;
		if j!=7:
			num^=1;

print(cnt);
