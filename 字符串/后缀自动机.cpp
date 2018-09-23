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

const int CHAR = 26;
const int MAXN = 250010;
/*
	完全不能理解 太高深莫测了.........
	等全部整理完毕了再回来看 
*/
struct SAM_Node
{
    SAM_Node *fa, *next[CHAR];
    int len;
    int id, pos;
    SAM_Node(){}
    SAM_Node(int _len)
    {
        fa = 0;
        len = _len;
        memset(next, 0, sizeof(next));
    }
};

SAM_Node SAM_node[MAXN * 2], *SAM_root, *SAM_last;
int SAM_size;

SAM_Node *newSAM_Node(int len)
{
    SAM_node[SAM_size] = SAM_Node(len);
    SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
SAM_Node *newSAM_Node(SAM_Node *p)
{
    SAM_node[SAM_size] = *p; SAM_node[SAM_size].id = SAM_size;
    return &SAM_node[SAM_size++];
}
void SAM_init()
{
    SAM_size = 0;
    SAM_root = SAM_last = newSAM_Node(0);
    SAM_node[0].pos = 0;
}
void SAM_add(int x, int len)
{
    SAM_Node *p = SAM_last, *np = newSAM_Node(p->len+1);
    np->pos = len;
    SAM_last = np;
    for (; p && !p->next[x]; p = p->fa)
    {
        p->next[x] = np;
    }
    if (!p)
    {
        np->fa = SAM_root;
        return;
    }
    SAM_Node *q = p->next[x];
    if (q->len == p->len + 1)
    {
        np->fa = q;
        return ;
    }
    SAM_Node *nq = newSAM_Node(q);
    nq->len = p->len + 1;
    q->fa = nq;
    np->fa = nq;
    for(;p && p->next[x] == q; p = p->fa)
        p->next[x] = nq;
}
void SAM_build(char *s)
{
    SAM_init();
    int len = (int)strlen(s);
    for (int i = 0; i < len; i++)
    {
        SAM_add(s[i] - 'a', i + 1);
    }
}

/*
 //  加入串后进行拓扑排序
 char str[MAXN];
 int topocnt[MAXN];
 SAM_Node *topsam[MAXN * 2];
 int n = (int)strlen(str);
 SAM_build(str);
 memset(topocnt, 0, sizeof(topocnt));
 for (int i = 0; i < SAM_size; i++)
 {
    topocnt[SAM_node[i].len]++;
 }
 for (int i = 1; i <= n; i++)
 {
    topocnt[i] += topocnt[i-1];
 }
 for (int i = 0; i < SAM_size; i++)
 {
    topsam[--topocnt[SAM_node[i].len]] = &SAM_node[i];
 }
 */


//  多串的建立:
//  多串的建立,注意SAM_init()的调用
//void SAM_build(char *s)
//{
//    int len = (int)strlen(s);
//    SAM_last = SAM_root;
//    for (int i = 0; i < len; i++)
//    {
//        if (!SAM_last->next[s[i] - '0'] || !(SAM_last->next[s[i] - '0']->len == i+1))
//        {
//            SAM_add(s[i] - '0',i+1);
//        }
//        else
//        {
//            SAM_last = SAM_last->next[s[i] - '0'];
//        }
//    }
//}

int main(){
	char c[] = "abacacad";
	SAM_build(c);
	int i = 1;
	while(i != SAM_size){
		cout << SAM_node[i].id << " " << SAM_node[i].len << " " << SAM_node[i].pos << endl;
		i ++;
	}













}

