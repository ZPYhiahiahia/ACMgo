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
��2��ʯ�ӡ�A B�����������ã�A���á�ÿ�ο��Դ�һ����ȡ��������
2����ȡ��ͬ������ʯ�ӣ������ɲ�ȡ���õ����1��ʯ�ӵ��˻�ʤ������
A B���ǳ���������ʯ�ӵĹ����в������ʧ�󡣸���2��ʯ�ӵ���������
���˭��Ӯ�ñ����� 
*/ 

int main()
{
    int t, a, b, m, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (a > b)
        {
            a ^= b;
            b ^= a;
            a ^= b;
        }
        m = b - a;
        k = (int)(m * (1 + sqrt(5)) / 2.0);
        //m = ? * a
        //k = m / ?
        //?:�ƽ�ָ���
        //���a == k����Ϊ����Ӯ����������Ӯ������֣�
        printf("%s\n", a == k ? "B" : "A");
    }
    return 0;
}


