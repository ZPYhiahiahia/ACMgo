#include<bits/stdc++.h> 
#define f(x) (((x) * (3 * (x) - 1)) >> 1)
#define g(x) (((x) * (3 * (x) + 1)) >> 1)
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, ans[MAXN];

int main()
{
    scanf("%d", &n);//读入n为求把n划分成至多n个数 // 任意划分 
    ans[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; f(j) <= i; ++j)
        {
            if (j & 1)
            {
                ans[i] = (ans[i] + ans[i - f(j)]) % MOD;
            }
            else
            {
                ans[i] = (ans[i] - ans[i - f(j)] + MOD) % MOD;
            }
        }
        for (int j = 1; g(j) <= i; ++j)
        {
            if (j & 1)
            {
                ans[i] = (ans[i] + ans[i - g(j)]) % MOD;
            }
            else
            {
                ans[i] = (ans[i] - ans[i - g(j)] + MOD) % MOD;
            }
        }
    }

    printf("%d\n", ans[n]);

    return 0;
}
