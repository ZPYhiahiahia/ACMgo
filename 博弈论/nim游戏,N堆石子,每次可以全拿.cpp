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
有N堆石子。A B两个人轮流拿，A先拿。每次只能从一堆中取若干个，
可将一堆全取走，但不可不取，拿到最后1颗石子的人获胜。假设A 
B都非常聪明，拿石子的过程中不会出现失误。给出N及每堆石子的数量，
问最后谁能赢得比赛。  
*/ 
/*Nim 游戏*/ 
int main(int argc, const char * argv[])
{
    int N, stone, tag = 0;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &stone);
        tag ^= stone;
    }
    //tag为0则为后手赢，否则为先手赢
    printf("%c\n", tag == 0 ? 'B' : 'A');
    return 0;
}
















