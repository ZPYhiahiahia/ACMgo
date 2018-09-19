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
const int N = 1000;

bool a[N][N];

int Run(const int &m, const int &n)     // a[1...m][1...n]
{                                       // O(m*n)
    int i, j, k, l, r, max=0;
    int col[N];
    for (j = 1; j <= n; j++)
    {
        if (a[1][j] == 0 )
        {
            col[j] = 0;
        }
        else
        {
            for (k = 2; k <= m && a[k][j] == 1; k++);
            col[j] = k - 1;
        }
    }
    for (i = 1; i <= m; i++)
    {
        if (i > 1)
        {
            for (j = 1; j <= n; j++)
            {
                if (a[i][j] == 0)
                {
                    col[j] = 0;
                }
                else
                {
                    if (a[i - 1][j] == 0)
                    {
                        for (k = i + 1; k <= m && a[k][j] == 1; k++);
                        col[j] = k-1;
                    }
                }
            }
        }
        for (j = 1; j <= n; j++)
        {
            if (col[j] >= i)
            {
                for (l = j - 1; l > 0 && col[l] >= col[j]; --l);
                l++;
                for (r = j + 1; r <= n && col[r] >= col[j]; ++r);
                r--;
                int res = (r - l + 1) * (col[j] - i + 1);
                if( res > max )
                {
                    max = res;
                }
            }
        }
    }
    return max;
}

int main(){
















}

