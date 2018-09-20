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

int n;          //  共n个数
int rcd[MAX_N]; //  记录每个位置填的数
int num[MAX_N]; //  存放输入的n个数

void full_combination(int l, int p)
{
    int i;
    for (i = 0; i < l; i++)             //  每次进入递归函数都输出
    {
        printf("%d", rcd[i]);
        if (i < l-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    for (i = p; i < n; i++)             //  循环同样从p开始,但结束条件变为i>=n
    {
        rcd[l] = num[i];                //  在l位置放上该数
        full_combination(l + 1, i + 1); //  填下一个位置
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
    return 1;
}

int main(){
















}

