#include<bits/stdc++.h>
using namespace std;
/*
 *  ����ɸѡ���ж�С��MAXN�����ǲ�������
 *  notprime��һ�ű�false��ʾ��������true��ʾ����
 */

const int MAXN = 1000010;
bool notprime[MAXN];

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = true;
    for (int i = 2; i < MAXN; i++)
    {
        if (!notprime[i])
        {
            if (i > MAXN / i)   //  ��ֹ���i * i���������i,j��long long)
            {
                continue;
            }
            //  ֱ�Ӵ�i * i��ʼ�Ϳ��ԣ�С��i�����Ѿ�ɸѡ����
            for (int j = i * i; j < MAXN; j += i)
            {
                notprime[j] = true;
            }
        }
    }
}

int main(){
















}

