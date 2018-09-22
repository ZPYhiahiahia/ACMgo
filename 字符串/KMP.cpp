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
	�ַ���ƥ�䡣���������ַ�����Ѱ������һ���ַ����Ƿ������һ���ַ�����
	������������ذ�������ʼλ�á�  
*/ 


/*
 * next[]�ĺ��壬x[i - next[i]...i - 1] = x[0...next[i] - 1]
 * next[i]Ϊ����x[i - z...i - 1] = x[0...z - 1]�����zֵ������x������ƥ�䣩
 */

void KMP_Pre(char x[], int m, int next[])
{
    int i, j;
    j = next[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
        {
            j = next[j];
        }
        next[++i] = ++j;
    }
    return ;
}

/*
 * kmpNext[]����˼��next'[i] = next[next[...[next[i]]]]
 * ��ֱ��next'[i] < 0����x[next'[i]] != x[i]��
 * ������Ԥ������Կ�һЩ 
 */

void preKMP(char x[], int m, int kmpNext[])
{
    int i, j;
    j = kmpNext[0] = -1;
    i = 0;
    while (i < m)
    {
        while (-1 != j && x[i] != x[j])
        {
            j = kmpNext[j];
        }
        if (x[++i] == x[++j])
        {
            kmpNext[i] = kmpNext[j];
        }
        else
        {
            kmpNext[i] = j;
        }
    }
    return ;
}

/*
 * �˺������������������е�����һ������ʹ�ã��������������������е�����һ����
 * ����x��y�г��ֵĴ����������ص�
 */

int next[10010];

int KMP_Count(char x[], int m, char y[], int n)
{
    //  x��ģʽ����y������
    int i, j;
    int ans = 0;
    //  preKMP(x, m, next);
    KMP_Pre(x, m, next);
    i = j = 0;
    while (i < n)
    {
        while (-1 != j && y[i] != x[j])
        {
            j = next[j];
        }
        i++, j++;
        if (j >= m)
        {
            ans++;
            j = next[j];
        }
    }
    return ans;
}



int main(){
	int ans = 0;
	char y[] = "ccabcabcaa";
	char a[] = "abc";
	int leny = strlen(y);
	int lena = strlen(a);
	ans = KMP_Count(a,lena,y,leny);//ͳ��a��y�г��ֵĴ��� 
	cout << ans << endl;














}

