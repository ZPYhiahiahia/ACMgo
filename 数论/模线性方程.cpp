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
 *  模线性方程 a * x = b (% n)
 */
void modeq(int a, int b, int n)
{
    int e, i, d, x, y;
    d = extgcd(b, a % b, x, y);
    if (b % d > 0)
    {
        cout << "No answer!\n";
    }
    else
    {
        e = (x * (b / d)) % n;
        for (i = 0; i < d; i++)
        {
            cout << i + 1 << "-th ans:" << (e + i * (n / d)) % n << '\n';
        }
    }
    return ;
}

/*
 *  模线性方程组
 *  a = B[1](% W[1]); a = B[2](% W[2]); ... a = B[k](% W[k]);
 *  其中W，B已知，W[i] > 0且W[i]与W[j]互质，求a（中国剩余定理）
 */

int china(int b[], int w[], int k)
{
    int i, d, x, y, m, a = 0, n = 1;
    for (i = 0; i < k; i++)
    {
        n *= w[i];  //  注意不能overflow
    }
    for (i = 0; i < k; i++)
    {
        m = n / w[i];
        d = extgcd(w[i], m, x, y);
        a = (a + y * m * b[i]) % n;
    }
    if (a > 0)
    {
        return a;
    }
    else
    {
        return (a + n);//最小正解 
    }
}


/*
	w[i]和w[j]不互质 
*/

typedef long long ll;

const int MAXN = 11;

int n, m;
int a[MAXN], b[MAXN];

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }

        ll ax = a[0], bx = b[0], x, y;
        int flag = 0;
        for (int i = 1; i < m; i++)
        {
            ll d = extgcd(ax, a[i], x, y);
            if ((b[i] - bx) % d != 0)
            {
                flag = 1;   //  无整数解
                break;
            }

            ll tmp = a[i] / d;
            x = x * (b[i] - bx) / d;    //  约分
            x = (x % tmp + tmp) % tmp;
            bx = bx + ax * x;
            ax = ax * tmp;              //  ax = ax * a[i] / d
        }

        if (flag == 1 || n < bx)
        {
            puts("0");
        }
        else
        {
            ll ans = (n - bx) / ax + 1;
            if (bx == 0)
            {
                ans--;
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}

