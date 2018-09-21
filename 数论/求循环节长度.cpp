/*
 *  ��1/i��ѭ���ڳ��ȵ����ֵ��i<=n
 */
#include<bits/stdc++.h>
using namespace std; 
const int MAXN = 1005;

int res[MAXN];  //  ѭ���ڳ���

int main()
{
    memset(res, 0, sizeof(res));

    int i, temp, j, n;

    for (temp = 1; temp <= 1000; temp++)
    {
        i = temp;
        while (i % 2 == 0)
        {
            i /= 2;
        }
        while (i % 5 == 0)
        {
            i /= 5;
        }
        n = 1;
        for (j = 1; j <= i; j++)
        {
            n *= 10;
            n %= i;
            if (n == 1)
            {
                res[temp] = j;
                break;
            }
        }
    }

    int max_re;

    while (cin >> n)
    {
        max_re = 1;
        for (i = 1; i <= n; i++)
        {
            if (res[i] > res[max_re])
            {
                max_re = i;
            }
        }
        cout << max_re << endl;
    }
    return 0;
}
