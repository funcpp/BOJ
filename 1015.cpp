#include <stdio.h>

int main() {

	int i, j, N;
	int arr[50];
	int t[50] = {0, };
	scanf("%d", &N);
	for (i = 0; i<N; i++) {
		scanf("%d", &arr[i]);
		for (j = 0; j<i; j++) {
			if (arr[j] > arr[i]) {
				t[j]++;
			}
			else if (arr[j] <= arr[i])
			{
				t[i]++;
			}
		}
	}

	for (i = 0; i<N; i++)
	{
		printf("%d ", t[i]);
	}
	return 0;
}
