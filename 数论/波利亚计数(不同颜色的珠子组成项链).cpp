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
 *  c����ɫ�����ӣ���ɳ�Ϊs������������û�з������ʼλ��
 */
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main(int argc, const char * argv[])
{
    int c, s;
    while (cin >> c >> s)
    {
        int k;
        long long p[64];
        p[0] = 1;                   // power of c
        for (k = 0; k < s; k++)
        {
            p[k + 1] = p[k] * c;
        }
        // reflection part
        long long count = s & 1 ? s * p[s / 2 + 1] : (s / 2) * (p[s / 2] + p[s / 2 + 1]);
        // rotation part
        for (k = 1 ; k <= s ; k++)
        {
            count += p[gcd(k, s)];
            count /= 2 * s;
        }
        cout << count << '\n';
    }
    return 0;
}

int main(){
















}

