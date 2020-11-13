T = int(input());
for i in range(T):
	H, W, N = input().split();
	H=int(H);
	W=int(W);
	N=int(N);

	x=N%H;
	y=N//H+1;
	if x==0:
		x=H;
		y-=1;
	print(x*100+y);