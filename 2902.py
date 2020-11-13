s = input();
l = len(s);
ans="";
for i in range(l):
	if ord('A') <= ord(s[i]) and ord(s[i]) <= ord('Z'):
		ans+=s[i];
print(ans);
