A,B,C = input().split();
A=int(A);
B=int(B);
C=int(C);

if C-B <=0:
	print(-1);
else:
	print(A//(C-B)+1);