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
 *  默认目标映射关系是 key 1 => val 1 …… key n => val n
 *  如果序列不是 1~n 可以通过 map 建立新的目标映射关系
 *  交换任意区间的本质是改变了元素的后继，故建立元素与其初始状态后继的映射关系
 */
const int MAXN = 30;

int n;
int vis[MAXN];
int A[MAXN], B[MAXN];

int getMinSwaps()
{
    memset(vis, 0, sizeof(vis));

    for (int i = 1; i <= n; i++)
    {
        B[A[i]] = A[i % n + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        B[i] = (B[i] - 2 + n) % n + 1;
    }

    int cnt = n;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        vis[i] = 1;
        cnt--;
        for (int j = B[i]; j != i; j = B[j])
        {
            vis[j] = 1;
        }
    }

    return cnt;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i];
    }

    int res = getMinSwaps();

    cout << res << '\n';

    return 0;
}

