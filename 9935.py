x = str(input());
xLen=len(x);
b = str(input());
bLen=len(b);

chk = [];
chkLen=0;
t=0;

while t < xLen:
	chk.append(x[t]);
	chkLen+=1;
	t+=1;

	if chkLen >= bLen:
		for i in range(-1,-bLen-1,-1):
			if chk[i] != b[i]:
				break;
		else:
			a=0;
			while a<bLen:
				chk.pop();
				chkLen-=1;
				a+=1;

print("FRULA" if chkLen==0 else ''.join(chk));