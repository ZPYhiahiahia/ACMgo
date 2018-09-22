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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
const int MAX_N = 100005;
bool cmp (int a , int b){
	return a>b;
}

/*
��չKMP��������⣺
����ĸ��S���Ӵ�T��S�ĳ���Ϊn��T�ĳ���Ϊm��
���ַ���T���ַ���S��ÿһ����׺�������ǰ׺��
Ҳ����˵������extend���飺
extend[i]��ʾT��S[i,n-1]�������ǰ׺��Ҫ�������extend[i](0<=i<n)��
*/ 



/*
 * ��չKMP
 * next[i]:x[i...m-1]�������ǰ׺
 * extend[i]:y[i...n-1]��x[0...m-1]�������ǰ׺
 */
void preEKMP(char x[], int m, int next[])
{
    next[0] = m;
    int j = 0;
    while (j + 1 < m && x[j] == x[j + 1])
    {
        j++;
    }
    next[1] = j;
    int k = 1;
    for (int i = 2; i < m; i++)
    {
        int p = next[k] + k - 1;
        int L = next[i - k];
        if (i + L < p + 1)
        {
            next[i] = L;
        }
        else
        {
            j = std::max(0, p - i + 1);
            while (i + j < m && x[i + j] == x[j])
            {
                j++;
            }
            next[i] = j;
            k = i;
        }
    }
    return ;
}

void EKMP(char x[], int m, char y[], int n, int next[], int extend[])
{
    preEKMP(x, m, next);
    int j = 0;
    while (j < n && j < m && x[j] == y[j])
    {
        j++;
    }
    extend[0] = j;
    int k = 0;
    for (int i = 1; i < n; i++)
    {
        int p = extend[k] + k - 1;
        int L = next[i - k];
        if (i + L < p + 1)
        {
            extend[i] = L;
        }
        else
        {
            j = std::max(0, p - i + 1);
            while (i + j < n && j < m && y[i + j] == x[j])
            {
                j++;
            }
            extend[i] = j;
            k = i;
        }
    }
    return ;
}


int main(){
	char y[] = "aaaabcaaaaa";
	char a[] = "aaaaa";
	int next[1000],extend[1000];
	int leny = strlen(y);
	int lena = strlen(a);
	EKMP(a,lena,y,leny,next,extend) ;
	for(int i = 0 ; i < 10 ; i ++){
		cout << next[i] << " ";
	}















}

