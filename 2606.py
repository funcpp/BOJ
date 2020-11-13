N = int(input());
M = int(input());

line = [[0 for _ in range(N+1)] for _ in range(N+1)];
chk = [];

for i in range(M):
	A, B = input().split();
	A=int(A);
	B=int(B);
	line[A-1][B-1]=1;
	line[B-1][A-1]=1;

def dfs(idx):
	for i in range(N):
		if line[idx][i]==1 and i not in chk:
			chk.append(i);
			dfs(i);

chk.append(0);
dfs(0);

print(len(chk)-1);