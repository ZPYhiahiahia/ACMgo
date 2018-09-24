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
const double eps = 1e-10;

struct point
{
    double x, y;
};

double min(double a, double b)
{
    return a < b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

bool inter(point a, point b, point c, point d)
{
    if (min(a.x, b.x) > max(c.x, d.x) || min(a.y, b.y) > max(c.y, d.y) || min(c.x, d.x) > max(a.x, b.x) || min(c.y, d.y) > max(a.y, b.y))
    {
        return 0;
    }
    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return h * i <= eps && j * k <= eps;
}

int main(){
















}

