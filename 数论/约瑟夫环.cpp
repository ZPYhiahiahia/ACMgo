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
 *  n����(��� 1...n),��ȥ����m����,Ȼ���m+1����ʼ��1,
 *  ����k���˳�,ʣ�µ��˼�����1��ʼ����.��ʤ���ߵı��.
 */

int main(int argc, const char * argv[])
{
    int n, k, m;
    while (cin >> n >> k >> m, n || k || m)
    {
        int i, d, s = 0;
        for (i = 2; i <= n; i++)
        {
            s = (s + k) % i;
        }
        k = k % n;
        if (k == 0)
        {
            k = n;
        }
        d = (s + 1) + (m - k);
        if (d >= 1 && d <= n)
        {
            cout << d << '\n';
        }
        else if (d < 1)
        {
            cout << n + d << '\n';
        }
        else if (d > n)
        {
            cout << d % n << '\n';
        }
    }

    return 0;
}


