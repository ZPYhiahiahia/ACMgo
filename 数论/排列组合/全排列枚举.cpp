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

int n;                      //  共n个数
int rcd[MAX_N];             //  记录每个位置填的数
int used[MAX_N];            //  标记数是否用过
int num[MAX_N];             //  存放输入的n个数

void full_permutation(int l)
{
    int i;
    if (l == n)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d", rcd[i]);
            if (i < n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return ;
    }
    for (i = 0; i < n; i++)         //  枚举所有的数(n个),循环从开始
        if (!used[i])
        {                           //  若num[i]没有使用过, 则标记为已使用
            used[i] = 1;
            rcd[l] = num[i];        //  在l位置放上该数
            full_permutation(l+1);  //  填下一个位置
            used[i] = 0;            //  清标记
        }
}

int read_data()
{
    int i;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    return 1;
}

int main(){
















}

