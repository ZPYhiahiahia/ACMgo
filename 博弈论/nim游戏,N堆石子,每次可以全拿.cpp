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
��N��ʯ�ӡ�A B�����������ã�A���á�ÿ��ֻ�ܴ�һ����ȡ���ɸ���
�ɽ�һ��ȫȡ�ߣ������ɲ�ȡ���õ����1��ʯ�ӵ��˻�ʤ������A 
B���ǳ���������ʯ�ӵĹ����в������ʧ�󡣸���N��ÿ��ʯ�ӵ�������
�����˭��Ӯ�ñ�����  
*/ 
/*Nim ��Ϸ*/ 
int main(int argc, const char * argv[])
{
    int N, stone, tag = 0;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d", &stone);
        tag ^= stone;
    }
    //tagΪ0��Ϊ����Ӯ������Ϊ����Ӯ
    printf("%c\n", tag == 0 ? 'B' : 'A');
    return 0;
}
















