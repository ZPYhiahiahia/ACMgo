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
int n, m;                       //  �൱��n��ѭ��,ÿ��ѭ������Ϊm
int rcd[MAX_N];                 //  ��¼ÿ��λ�������
void loop_permutation(int l)
{
    int i;
    if (l == n)                 //  �൱�ڽ����� n ��ѭ�������ڲ�
    {
        for (i = 0; i < n; i++)
        {
            cout << rcd[i];
            if (i < n-1)
            {
                cout << " ";
            }
        }
        cout << "\n";
        return ;
    }
    for (i = 0; i < m; i++)     //  ÿ��ѭ������Ϊm
    {
        rcd[l] = i;             //  ��lλ�÷�i
        loop_permutation(l + 1);  //  ����һ��λ��
    }
}

int main(){
















}

