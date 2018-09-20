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

/*
 *  欧拉函数法
 *  a 和 m 互质
 */
//  快速幂取模
long long powM(long long a, long long b, long long m)
{
    long long tmp = 1;
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a % m;
    }

    tmp = powM(a, b >> 1, m);
    tmp = tmp * tmp % m;

    if (b & 1)
    {
        tmp = tmp * a % m;
    }

    return tmp;
}

long long inv(long long a, long long m)
{
    return powM(a, m - 2, m);
}

int main(){
















}

