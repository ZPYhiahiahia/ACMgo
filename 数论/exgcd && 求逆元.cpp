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
 *  扩展欧几里得法（求ax + by = gcd）
 */
//  返回d = gcd(a, b);和对应于等式ax + by = d中的x、y
long long extendGcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
    {
        return -1;  //  无最大公约数
    }
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extendGcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

//  求逆元 ax = 1(mod n)
long long modReverse(long long a, long long n)
{
    long long x, y;
    long long d = extendGcd(a, n, x, y);
    if (d == 1)
    {
        return (x % n + n) % n;
    }
    else
    {
        return -1;  //  无逆元
    }
}
/*
 *  简洁写法I
 *  只能求a < m的情况，且a与m互质
 *  求ax = 1(mod m)的x值，即逆元(0 < a < m)
 */
long long inv(long long a, long long m)
{
    if (a == 1)
    {
        return 1;
    }
    return inv(m % a, m) * (m - m / a) % m;
}

int main(){
















}

