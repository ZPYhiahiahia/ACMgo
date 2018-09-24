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
typedef struct  //  点结构
{
    ll x, y;
} Point;

Point A, B, C, O;   //  三角形三点与圆心
ll r;               //  半径

//  判断线段是否和圆相交
int segOnCircle(Point *p_1, Point *p_2)
{
    ll a, b, c, dist_1, dist_2, angle_1, angle_2;   //  ax + by + c = 0;
    if (p_1->x == p_2->x)                           //  当x相等
    {
        a = 1, b = 0, c = -p_1->x;
    }
    else if (p_1->y == p_2->y)                      //  当y相等
    {
        a = 0, b = 1, c = -p_1->y;
    }
    else
    {
        a = p_1->y - p_2->y;
        b = p_2->x - p_1->x;
        c = p_1->x * p_2->y - p_1->y * p_2->x;
    }
    dist_1 = a * O.x + b * O.y + c;
    dist_1 *= dist_1;
    dist_2 = (a * a + b * b) * r * r;
    if (dist_1 > dist_2)
    {
        return 0;
    }
    angle_1 = (O.x - p_1->x) * (p_2->x - p_1->x) + (O.y - p_1->y) * (p_2->y - p_1->y);
    angle_2 = (O.x - p_2->x) * (p_1->x - p_2->x) + (O.y - p_2->y) * (p_1->y - p_2->y);
    if (angle_1 > 0 && angle_2 > 0)
    {
        return 1;
    }
    return 0;
}

int main(){
















}

