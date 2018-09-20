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
 *  baby_step giant _step
 *  a^x = b(mod n) n不要求是素数
 *  求解上式0 ≤ x < n的解
 */
#define MOD 76543
int hs[MOD];
int head[MOD];
int _next[MOD];
int id[MOD];
int top;

void insert(int x, int y)
{
    int k = x % MOD;
    hs[top] = x;
    id[top] = y;
    _next[top] = head[k];
    head[k] = top++;
    return ;
}

int find(int x)
{
    int k = x % MOD;
    for (int i = head[k]; i != -1; i = _next[i])
    {
        if (hs[i] == x)
        {
            return id[i];
        }
    }
    return -1;
}

long long BSGS(int a, int b, int n)
{
    memset(head, -1, sizeof(head));
    top = 1;
    if (b == 1)
    {
        return 0;
    }
    int m = (int)sqrt(n * 1.0), j;
    long long x = 1, p = 1;
    for (int i = 0; i < m; i++, p = p * a % n)
    {
        insert(p * b % n, i);
    }
    for (long long i = m; ; i++)
    {
        if ((j = find(x = x * p % n)) != -1)
        {
            return i - j;
        }
        if (i > n)
        {
            break;
        }
    }

    return -1;
}

int main(){
















}

