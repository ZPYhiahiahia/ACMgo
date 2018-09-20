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

int n, m;       //  从n个数中选出m个构成组合
int rcd[MAX_N]; //  记录每个位置填的数
int num[MAX_N]; //  存放输入的n个数

void select_combination(int l, int p)
{
    int i;
    if (l == m) //  若选出了m个数, 则打印
    {
        for (i = 0; i < m; i++)
        {
            printf("%d", rcd[i]);
            if (i < m - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return ;
    }
    for (i = p; i < n; i++) //  上个位置填的是num[p-1],本次从num[p]开始试探
    {
        rcd[l] = num[i];    //  在l位置放上该数
        select_combination(l + 1, i + 1);   //  填下一个位置
    }
}

int read_data()
{
    int i;
    if (scanf("%d%d", &n, &m) == EOF)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    return 1;
}

int main(){
















}

