#include <stdio.h>
 
#define MOD 1000000000
 
int dp[101][10];
int n, ans = 0;
 
int main(void) {
    scanf("%d", &n);
 
    for (int i = 1; i < 10; i++)
        dp[1][i] = 1;
 
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0)
                dp[i][0] = dp[i - 1][1] % MOD;
            else if (j == 9)
                dp[i][9] = dp[i - 1][8] % MOD;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }
 
    for (int i = 0; i < 10; i++)
        ans = (ans + dp[n][i]) % MOD;
 
    printf("%d\n", ans);
    return 0;
}
