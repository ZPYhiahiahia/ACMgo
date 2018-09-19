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
有2堆石子。A B两个人轮流拿，A先拿。每次可以从一堆中取任意个或从
2堆中取相同数量的石子，但不可不取。拿到最后1颗石子的人获胜。假设
A B都非常聪明，拿石子的过程中不会出现失误。给出2堆石子的数量，问
最后谁能赢得比赛。 
*/ 

int main()
{
    int t, a, b, m, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        m = b - a;
        k = (int)(m * (1 + sqrt(5)) / 2.0);
        //m = ? * a
        //k = m / ?
        //?:黄金分割数
        //如果a == k，则为后手赢，否则先手赢（奇异局）
        printf("%s\n", a == k ? "B" : "A");
    }
    return 0;
}


