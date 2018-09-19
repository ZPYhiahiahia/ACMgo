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
	有一堆石子共有N个。A B两个人轮流拿，A先拿。每次最少拿1颗，
	最多拿K颗，拿到最后1颗石子的人获胜。假设A B都非常聪明，
	拿石子的过程中不会出现失误。给出N和K，问最后谁能赢得比赛。 
*/ 

/*		bashgame		*/ 

int bash(int N, int K)
{
    if (N % (K + 1) == 0) 
    {
        return 2;
    }
    return 1;
}

int main(){
















}

