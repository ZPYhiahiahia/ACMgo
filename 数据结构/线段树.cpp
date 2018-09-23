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
//tree[]������ʾÿ���������Сֵ��sum[]����ͣ�col[]���ǣ�����������ÿ��Ԫ�������˶��� 

//���������update�ϣ���˼�ǿ��Բ��ö����£��õ���ʱ���ٸ��� 
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
    //��tree��¼ÿ���������ֵ 
    if(tree[node*2]<=tree[node*2+1])
        tree[node]=tree[2*node];
    else 
        tree[node]=tree[2*node+1];
}
//�����ѯ 
int query1(int node,int begin,int end,int left,int right)//��ѯ3-5֮�����Сֵ 
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
//�������
void updata(int node ,int begin,int end,int ind,int add)//���ĸ���ind������ add
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

//�·ű�� 
void pushdown(int rt,int m)
{
    if(col[rt])
    {
        col[rt<<1]=col[rt];
        col[rt<<1|1]=col[rt];
        sum[rt<<1]=col[rt]*(m-m/2);//�������Ҫ��΢��һ�� 
        sum[rt<<1|1]=col[rt]*(m/2);
        col[rt]=0; 
    }
} 
//�����޸� 
//���޸������ֵ������������ĺ�Ϊ�� 
void change(int node,int begin,int end,int left,int right,int c)
{
    if(left<=begin && end >=right)
    {
        col[node]=c;//�ڸýڵ��ϴ�һ����� ��Ǵ��˭�ˣ���һ��ô�� 
        sum[node]=c*(end-begin+1); //���͵�ʱ�����ˣ����ǲ�ѯ��ʱ������������ˣ���ʱ���õ�����·� 
        return;
    }
    pushdown(node,end-begin+1);
    int mid=begin+(end-begin)/2;
    if(left<=mid) change(node*2,begin,end,left,mid,c) ;
    if(right>mid) change(node*2+1,begin,end,mid+1,right,c);
    sum[node]=sum[node*2]+sum[node*2+1];
}

//��ѯ����֮�� 
int query2(int node,int begin,int end,int left,int right)
{
    if(left<=begin && end>=right)//����Ҫ�Ͳ��·��� 
    {
        return sum[node];
    }
    Pushdown(node,end-begin+1);//��Ҫ��ʱ�����·� 
    int ret=0;
    int mid=begin+(end-begin)/2;
    if(left<mid) ret+=query2(node*2,begin,end,left,mid,c) ;
    if(right>mid) ret+=query2(node*2+1,begin,end,mid+1,right,c);
    return ret; 
}

int main(){
















}

