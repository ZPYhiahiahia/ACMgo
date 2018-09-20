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
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int , int> p_ii;

int n, m;           //  输入n个数,其中本质不同的有m个
int rcd[MAX_N];     //  记录每个位置填的数
int used[MAX_N];    //  标记m个数可以使用的次数
int num[MAX_N];     //  存放输入中本质不同的m个数

void unrepeat_combination(int l, int p)
{
    int i;
    for (i = 0; i < l; i++)     //  每次都输出
    {
        printf("%d", rcd[i]);
        if (i < l - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (i = p; i < m; i++)     //  循环依旧从p开始,枚举剩下的本质不同的数
    {
        if (used[i] > 0)        //  若还可以用, 则可用次数减
        {
            used[i]--;
            rcd[l] = num[i];    //  在l位置放上该
            unrepeat_combination(l+1, i);   //  填下一个位置
            used[i]++;          //可用次数恢复
        }
    }
}

int read_data()
{
    int i, j, val;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    m = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        for (j = 0; j < m; j++)
        {
            if (num[j] == val)
            {
                used[j]++;
                break;
            }
        }
        if (j == m)
        {
            num[m] = val;
            used[m++] = 1;
        }
    }
    return 1;
}

int main(){
















}

