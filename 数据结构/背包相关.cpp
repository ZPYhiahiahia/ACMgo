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
const int MAXN = 101;
const int SIZE = 50001;

int dp[SIZE];
int volume[MAXN], value[MAXN], c[MAXN];
int n, v;           //  ����Ʒ������������

//  01����
void ZeroOnepark(int val, int vol)
{
    for (int j = v ; j >= vol; j--)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  ��ȫ����
void Completepark(int val, int vol)
{
    for (int j = vol; j <= v; j++)
    {
        dp[j] = max(dp[j], dp[j - vol] + val);
    }
}

//  ���ر���
void Multiplepark(int val, int vol, int amount)
{
    if (vol * amount >= v)
    {
        Completepark(val, vol);
    }
    else
    {
        int k = 1;
        while (k < amount)
        {
            ZeroOnepark(k * val, k * vol);
            amount -= k;
            k <<= 1;
        }
        if (amount > 0)
        {
            ZeroOnepark(amount * val, amount * vol);
        }
    }
}

int main()
{
    while (cin >> n >> v)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            cin >> volume[i] >> value[i] >> c[i];      //   ���ã���ֵ������
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            Multiplepark(value[i], volume[i], c[i]);
        }
        cout << dp[v] << endl;
    }
    return 0;
}
int main(){
















}

