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
//tree[]用来表示每个区间的最小值，sum[]区间和，col[]打标记，表明该区间每个元素增加了多少 

//懒标记用在update上，意思是可以不用都更新，用到的时候再更新 
void build(int node,int begin,int end)
{
    if(begin==end)
    {
        tree[node]=array[begin];
        sum[node]=array[begin];
        return;
    }
    int mid=begin+(end-begin)
    build(2*node,begin,mid);
    build(2*node+1,mid+1,end);
    //用tree记录每个区间的最值 
    if(tree[node*2]<=tree[node*2+1])
        tree[node]=tree[2*node];
    else 
        tree[node]=tree[2*node+1];
}
//区间查询 
int query1(int node,int begin,int end,int left,int right)//查询3-5之间的最小值 
{
    int p1,p2;

    if(left>end || right<begin)
        return -1;
    if(begin>=right && end<=right)
        return tree[node];

    int mid=begin+(end-begin)/2;
    p1=query(2*node,begin,mid);
    p2=query(2*node+1,mid+1,end);

    if(p1==-1)return p2;
    if(p2==-1)return p1;
    if(p1<=p2)return p1;
    else return p2; 
}
//单点更新
void updata(int node ,int begin,int end,int ind,int add)//将哪个点ind更新了 add
{
    if(begin==end)
        tree[node]+=add;
    int mid=begin+(end-begin)/2;
    if(ind<=m)
        updata(node*2,left,mid,ind,add);
    else
        updata(node*2+1,mid+1,right,ind,add);
    tree[node]=min(tree[node*2,node*2+1]);
} 

//下放标记 
void pushdown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]=col[rt];
        col[rt<<1|1]=col[rt];
        sum[rt<<1]=col[rt]*(m-m/2);//这个区间要稍微大一点 
        sum[rt<<1|1]=col[rt]*(m/2);
        col[rt]=0; 
    }
} 
//区间修改 
//以修改区间的值并求整个数组的和为例 
void change(int node,int begin,int end,int left,int right,int c)
{
    if(left<=begin && end >=right)
    {
        col[node]=c;//在该节点上打一个标记 标记打给谁了，就一个么？ 
        sum[node]=c*(end-begin+1); //做和的时候用了，但是查询的时候不是这个区间了，这时就用到标记下放 
        return;
    }
    pushdown(node,end-begin+1);
    int mid=begin+(end-begin)/2;
    if(left<=mid) change(node*2,begin,end,left,mid,c) ;
    if(right>mid) change(node*2+1,begin,end,mid+1,right,c);
    sum[node]=sum[node*2]+sum[node*2+1];
}

//查询区间之和 
int query2(int node,int begin,int end,int left,int right)
{
    if(left<=begin && end>=right)//不需要就不下放了 
    {
        return sum[node];
    }
    Pushdown(node,end-begin+1);//需要的时候再下放 
    int ret=0;
    int mid=begin+(end-begin)/2;
    if(left<mid) ret+=query2(node*2,begin,end,left,mid,c) ;
    if(right>mid) ret+=query2(node*2+1,begin,end,mid+1,right,c);
    return ret; 
}

int main(){
















}

