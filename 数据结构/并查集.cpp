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
 *  INIT: makeset(n);
 *  CALL: findset(x); unin(x, y);
 */
const int N = 1010;

struct lset
{
    int p[N], rank[N], sz;
    void link(int x, int y)
    {
        if (x == y)
        {
            return ;
        }
        if (rank[x] > rank[y])
        {
            p[y] = x;
        }
        else
        {
            p[x] = y;
        }
        if (rank[x] == rank[y])
        {
            rank[y]++;
        }
        return ;
    }
    void makeset(int n)
    {
        sz = n;
        for (int i = 0; i < sz; i++)
        {
            p[i] = i;
            rank[i] = 0;
        }
        return ;
    }
    int findset(int x)
    {
        if (x != p[x])
        {
            p[x] = findset(p[x]);
        }
        return p[x];
    }
    void unin(int x, int y)
    {
        link(findset(x), findset(y));
        return ;
    }
    void compress()
    {
        for (int i = 0; i < sz; i++)
        {
            findset(i);
        }
        return ;
    }
};
int main(){
















}

