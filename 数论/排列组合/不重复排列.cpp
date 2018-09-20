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
int n, m;           //  ����n����,���л�����ͬ����m��
int rcd[MAX_N];     //  ��¼ÿ��λ�������
int used[MAX_N];    //  ���m��������ʹ�õĴ���
int num[MAX_N];     //  ��������л�����ͬ��m����

void unrepeat_permutation(int l)
{
    int i;
    if (l == n)     //  ������n����,�����
    {
        for (i = 0; i < n; i++)
        {
            printf("%d", rcd[i]);
            if (i < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return ;
    }
    for (i = 0; i < m; i++)             //  ö��m�����ʲ�ͬ����
    {
        if (used[i] > 0)                //  ����num[i]��û������,���ʹ�ô�����
        {
            used[i]--;
            rcd[l] = num[i];            //  ��lλ�÷��ϸ���
            unrepeat_permutation(l+1);  //  ����һ��λ��
            used[i]++;                  //  ��ʹ�ô����ָ�
        }
    }
}

int read_data()
{
    int i, j, val;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    m = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &val);
        for (j = 0; j < m; j++)
        {
            if (num[j] == val)
            {
                used[j]++; break;
            }
        }
        if (j == m)
        {
            num[m] = val;
            used[m++] = 1;
        }
    }
    return 1;
}

int main(){
















}

