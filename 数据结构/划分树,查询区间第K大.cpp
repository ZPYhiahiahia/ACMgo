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
 *  ������(��ѯ�����k��) 
 */
const int MAXN = 100010;

int tree[20][MAXN];     //  ��ʾÿ��ÿ��λ�õ�ֵ
int sorted[MAXN];       //  �Ѿ�����õ���
int toleft[20][MAXN];   //  toleft[p][i]��ʾ��i���1��i�����������

void build(int l, int r, int dep)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    int same = mid - l + 1;         //  ��ʾ�����м�ֵ���ұ�������ߵĸ���
    for (int i = l; i <= r; i++)    //  ע����l,����one
    {
        if (tree[dep][i] < sorted[mid])
        {
            same--;
        }
    }
    int lpos = l;
    int rpos = mid + 1;
    for (int i = l; i <= r; i++)
    {
        if (tree[dep][i] < sorted[mid])
        {
            tree[dep + 1][lpos++] = tree[dep][i];
        }
        else if (tree[dep][i] == sorted[mid] && same > 0)
        {
            tree[dep + 1][lpos++] = tree[dep][i];
            same--;
        }
        else
        {
            tree[dep + 1][rpos++] = tree[dep][i];
        }
        toleft[dep][i] = toleft[dep][l - 1] + lpos - l;
    }
    build(l, mid, dep + 1);
    build(mid + 1, r, dep + 1);
    return ;
}

//  ��ѯ�����k�����,[L,R]�Ǵ�����,[l,r]��Ҫ��ѯ��С����
int query(int L, int R, int l, int r, int dep, int k)
{
    if(l == r)
    {
        return tree[dep][l];
    }
    int mid = (L + R) >> 1;
    int cnt = toleft[dep][r] - toleft[dep][l - 1];
    if (cnt >= k)
    {
        int newl = L + toleft[dep][l - 1] - toleft[dep][L - 1];
        int newr = newl + cnt - 1;
        return query(L, mid, newl, newr, dep + 1, k);
    }
    else
    {
        int newr = r + toleft[dep][R] - toleft[dep][r];
        int newl = newr - (r - l - cnt);
        return query(mid + 1, R, newl, newr, dep + 1, k - cnt);
    }
}

/*
int tree[20][MAXN];     //  ��ʾÿ��ÿ��λ�õ�ֵ
int sorted[MAXN];       //  �Ѿ�����õ���
int toleft[20][MAXN];   //  toleft[p][i]��ʾ��i���1��i�����������
*/ 


int main()
{
    int n, m; //n���� , m�β�ѯ 
    while (scanf("%d%d", &n, &m) == 2)
    {
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tree[0][i]);
            sorted[i] = tree[0][i];
        }
        sort(sorted + 1, sorted + n + 1);
        build(1, n, 0);
        int s, t, k;
        while(m--)
        {
            scanf("%d%d%d", &s, &t, &k);
            printf("%d\n", query(1, n, s, t, 0, k));
        }
    }
    return 0;
}

