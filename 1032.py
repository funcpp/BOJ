N = int(input());
arr = [];

for i in range(N):
	arr.append(input());

ans = "";
l = len(arr[0]);
for i in range(l):
	b=True;
	for j in range(N):
		if arr[0][i]!=arr[j][i]:
			b=False;
	if b:
		ans+=arr[0][i];
	else:
		ans+="?";

print(ans);