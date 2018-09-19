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
 *  ģ���Է��� a * x = b (% n)
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
 *  ģ���Է�����
 *  a = B[1](% W[1]); a = B[2](% W[2]); ... a = B[k](% W[k]);
 *  ����W��B��֪��W[i] > 0��W[i]��W[j]���ʣ���a���й�ʣ�ඨ��
 */

int china(int b[], int w[], int k)
{
    int i, d, x, y, m, a = 0, n = 1;
    for (i = 0; i < k; i++)
    {
        n *= w[i];  //  ע�ⲻ��overflow
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
        return (a + n);//��С���� 
    }
}


/*
	w[i]��w[j]������ 
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
                flag = 1;   //  ��������
                break;
            }

            ll tmp = a[i] / d;
            x = x * (b[i] - bx) / d;    //  Լ��
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

