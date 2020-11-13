#include <stdio.h>
#include <iostream>
using namespace std;


char input[1003][1003];
char animal[1003][1003];
char sound[1003][1003];
int soundLen[1003];
int animalLen[1003];
char ans[900002];
int cur = 0;

void init()
{
	for (int i = 0; i < 1002; i++)
	{
		for (int j = 0; j < 1002; j++)
		{
			input[i][j] = 0;
			animal[i][j] = 0;
			sound[i][j] = 0;
		}
		soundLen[i] = 0;
		animalLen[i] = 0;
	}

	for (int i = 0; i < 900002; i++)
	{
		ans[i] = 0;
		input[0][i] = 0;
	}
	cur = 0;
}

int main()
{
	int T;
	scanf("%d ", &T);
	while(T--)
	{
		int len = 0;
		while(1)
		{
			cin.getline(input[len], 900000);
			int flag = false;
			for (int k = 0; input[len][k] != NULL; k++)  if (input[len][k] == '?') flag = true;

			if (flag)break;
			len++;
		}
		
		for (int i = 1; i < len; i++) {
			int flag = 0;
			int j = 0;
			int k = 0;
			for (k = 0; input[i][k] != NULL; k++) {
				if (flag == 2) {
					animal[i][j++] = input[i][k];
				}
				if (input[i][k] == ' ')flag += 1;
			}
			animalLen[i] = j;
		}
		
		int slen = 0, j = 0;
		for (int k = 0; input[0][k] != NULL; k++){	
			if (input[0][k] == ' ') {
				soundLen[slen] = j;
				slen++;
				j = 0;
			}
			else sound[slen][j++] = input[0][k];	
		}
		soundLen[slen] = j;
		
		for (int i = 0; i <= slen; i++)
		{
			int flag = 0;
			for(int j=1;j<len;j++)
			{
				if (soundLen[i] == animalLen[j])
				{
					for (int k = 0; sound[i][k] != NULL; k++)
					{
						if (sound[i][k] == animal[j][k])continue;
						else
						{
							flag += 1;
							break;
						}
					}
				}
				else flag += 1;
			}
			
			if (flag == (len-1))
			{
				for (int k = 0; sound[i][k] != NULL; k++)
				{
					ans[cur++] = sound[i][k];
				}
				ans[cur++] = ' ';
			}
			
		}
		if(cur>0)ans[cur - 1] = NULL;

		for (int k = 0; ans[k] != NULL; k++)cout << ans[k];
		cout << "\n";
		init();
	}
}
