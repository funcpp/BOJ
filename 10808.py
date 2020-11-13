s = input();
l = len(s);
cnt = [0 for _ in range(26)];
for i in range(l):
	cnt[ord(s[i])-ord('a')]+=1;

for i in range(26):
	print(cnt[i],end=' ');

