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
 *  阶乘最后非零位 复杂度O(nlongn)
 *  返回改为，n以字符串方式传入
 */
#define MAXN 10000

const int mod[20] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2};

int lastDigit(char *buf)
{
    int len = (int)strlen(buf);
    int a[MAXN], i, c, ret = 1;
    if (len == 1)
    {
        return mod[buf[0] - '0'];
    }
    for (i = 0; i < len; i++)
    {
        a[i] = buf[len - 1 - i] - '0';
    }
    for (; len; len -= !a[len - 1])
    {
        ret = ret * mod[a[1] % 2 * 10 + a[0]] % 5;
        for (c = 0, i = len - 1; i >= 0; i--)
        {
            c = c * 10 + a[i];
            a[i] = c / 5;
            c %= 5;
        }
    }
    return ret + ret % 2 * 5;
}

int main(){
















}

