#include<bits/stdc++.h>
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
int gcd(int x, int y)
{
    if (!x || !y)
    {
        return x > y ? x : y;
    }
    for (int t; t = x % y, t; x = y, y = t) ;
    return y;
}

/*
 *  «Ûx£¨y πµ√gcd(a, b) = a * x + b * y;
 */
int extgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    int d = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;

    return d;
}
int main(){
	















}

