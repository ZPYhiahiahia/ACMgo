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

int n, m;       //  ��n������ѡ��m���������
int rcd[MAX_N]; //  ��¼ÿ��λ�������
int num[MAX_N]; //  ��������n����

void select_combination(int l, int p)
{
    int i;
    if (l == m) //  ��ѡ����m����, ���ӡ
    {
        for (i = 0; i < m; i++)
        {
            printf("%d", rcd[i]);
            if (i < m - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return ;
    }
    for (i = p; i < n; i++) //  �ϸ�λ�������num[p-1],���δ�num[p]��ʼ��̽
    {
        rcd[l] = num[i];    //  ��lλ�÷��ϸ���
        select_combination(l + 1, i + 1);   //  ����һ��λ��
    }
}

int read_data()
{
    int i;
    if (scanf("%d%d", &n, &m) == EOF)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    return 1;
}

int main(){
















}

