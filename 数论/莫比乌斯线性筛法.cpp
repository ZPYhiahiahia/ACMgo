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
 *  Ī����˹���ݹ�ʽ
 *  ����ɸ�������Ժ�����Ī����˹������
 */
/*
	���һ��������ƽ�����ӣ���ômiu(n) = 0��
	���磺miu(4), miu(12), miu(18) = 0�� 
	���һ����������ƽ�����ӣ�������k����ͬ�������ӣ�
	��ômiu(n) = (-1)^k�����磺miu(2), miu(3), miu(30) 
	= -1,miu(1), miu(6), miu(10) = 1�� 
*/ 
const int MAXN = 1000000;
bool check[MAXN + 10];
int prime[MAXN + 10];
int mu[MAXN + 10];

void Moblus()
{
    memset(check, false, sizeof(check));
    mu[1] = 1;
    int tot = 0;
    for (int i = 2; i <= MAXN; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > MAXN)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                mu[i * prime[j]] = 0;
                break;
            }
            else
            {
                mu[i * prime[j]] = -mu[i];
            }
        }
    }
}

int main(){
	Moblus(); // mu[]�洢��Ӧλ�õ�Ī����˹����ֵ
	cout << mu[5] << endl;















}

