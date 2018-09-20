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

int n;                      //  ��n����
int rcd[MAX_N];             //  ��¼ÿ��λ�������
int used[MAX_N];            //  ������Ƿ��ù�
int num[MAX_N];             //  ��������n����

void full_permutation(int l)
{
    int i;
    if (l == n)
    {
        for (i = 0; i < n; i++)
        {
            printf("%d", rcd[i]);
            if (i < n-1)
            {
                printf(" ");
            }
        }
        printf("\n");
        return ;
    }
    for (i = 0; i < n; i++)         //  ö�����е���(n��),ѭ���ӿ�ʼ
        if (!used[i])
        {                           //  ��num[i]û��ʹ�ù�, ����Ϊ��ʹ��
            used[i] = 1;
            rcd[l] = num[i];        //  ��lλ�÷��ϸ���
            full_permutation(l+1);  //  ����һ��λ��
            used[i] = 0;            //  ����
        }
}

int read_data()
{
    int i;
    if (scanf("%d", &n) == EOF)
    {
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    return 1;
}

int main(){
















}

