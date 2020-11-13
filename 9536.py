T=int(input());
for i in range(T):
	sound = input().split(' ');
	while True:
		x=input();
		sp = x.split(' ');

		if x=="what does the fox say?":
			break;
		
		while sound.count(sp[2]):
			idx=sound.index(sp[2]);
			sound[idx]='.';

	for i in sound:
		if(i != '.'):
			print(i,end=' ');
	print();