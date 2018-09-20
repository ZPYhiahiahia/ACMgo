#include<bits/stdc++.h>
#include<stack>
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define rep(i,n) for(int (i)=0;(i)<n;(i)++)
#define read(n) scanf("%d",&n);
#define readll(n) scanf("%lld",&n);
#define readdb(n) scanf("%lf",&n);
#define readch(n) scanf("%c",&n);
#define readstr(n) scanf("%s",n);
#define test printf("test\n");
#define init(n) memset(n,0,sizeof(n));

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int , int> p_ii;

int MOD(int a, int b)
{
    return a - a / b * b;
}

int miu(int n)
{
    int cnt, k = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (MOD(n, i))
        {
            continue;
        }
        cnt = 0;
        k++;
        while (MOD(n, i) == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt >= 2)
        {
            return 0;
        }
    }
    if (n != 1)
    {
        k++;
    }
    return MOD(k, 2) ? -1 : 1;
}

int main(){
















}

