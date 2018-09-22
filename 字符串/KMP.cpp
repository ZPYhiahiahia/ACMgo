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
	字符串匹配。给你两个字符串，寻找其中一个字符串是否包含另一个字符串，
	如果包含，返回包含的起始位置。  
*/ 


/*
 * next[]的含义，x[i - next[i]...i - 1] = x[0...next[i] - 1]
 * next[i]为满足x[i - z...i - 1] = x[0...z - 1]的最大z值（就是x的自身匹配）
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
 * kmpNext[]的意思：next'[i] = next[next[...[next[i]]]]
 * （直到next'[i] < 0或者x[next'[i]] != x[i]）
 * 这样的预处理可以快一些 
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
 * 此函数与上述两个函数中的任意一个搭配使用（即调用上述两个函数中的任意一个）
 * 返回x在y中出现的次数，可以重叠
 */

int next[10010];

int KMP_Count(char x[], int m, char y[], int n)
{
    //  x是模式串，y是主串
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
	ans = KMP_Count(a,lena,y,leny);//统计a在y中出现的次数 
	cout << ans << endl;














}

