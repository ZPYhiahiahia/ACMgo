#include<bits/stdc++.h>
using namespace std; 

typedef long long ll;

const int MAXP = 16;
const int prime[MAXP] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};

ll n, res, ans;

void dfs(ll cur, ll num, int key, ll pre)  //  ��ǰֵ/��ǰԼ������/��ǰ���/��һ����
{
    if (key >= MAXP)
    {
        return ;
    }
    else
    {
        if (num > ans)
        {
            res = cur;
            ans = num;
        }
        else if (num == ans)    //  ���Լ��������ͬ����ȡ��С����
        {
            res = min(cur, res);
        }

        ll i;
        for ( i = 1; i <= pre; i++)
        {
            if (cur <= n / prime[key])  //  cur*prime[key]<=n
            {
                cur *= prime[key];
                dfs(cur, num * (i + 1), key + 1, i);
            }
            else
            {
                break;
            }
        }
    }
}

void solve()
{
    res = 1;
    ans = 1;

    dfs(1, 1, 0, 15);
    cout << res << ' ' << ans << endl;
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n;
        solve();
    }
    return 0;
}


