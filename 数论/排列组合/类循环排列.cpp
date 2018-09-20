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
int n, m;                       //  相当于n重循环,每重循环长度为m
int rcd[MAX_N];                 //  记录每个位置填的数
void loop_permutation(int l)
{
    int i;
    if (l == n)                 //  相当于进入了 n 重循环的最内层
    {
        for (i = 0; i < n; i++)
        {
            cout << rcd[i];
            if (i < n-1)
            {
                cout << " ";
            }
        }
        cout << "\n";
        return ;
    }
    for (i = 0; i < m; i++)     //  每重循环长度为m
    {
        rcd[l] = i;             //  在l位置放i
        loop_permutation(l + 1);  //  填下一个位置
    }
}

int main(){
















}

