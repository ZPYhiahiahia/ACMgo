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


const int MAX_DIG = 64;
//f[]������ȡ�ߵ�ʯ�Ӹ���
//sg[]:0~n��SG����ֵ
//hash[]:mex{}
int f[MAX_DIG]={1,3},sg[MAX_DIG],hash[MAX_DIG];
int k;//k��f[]����Ч����
void getSG(int n)
{
        memset(sg,0,sizeof(sg));
        for(int i=1; i<=n; i++) {
                memset(hash,0,sizeof(hash));
                for(int j=0; f[j]<=i && j < k; j++) //k��f[]����Ч����
                        hash[sg[i-f[j]]]=1;
                for(int j=0; ; j++) {   //��mes{}��δ���ֵ���С�ķǸ�����
                    if(hash[j]==0) {
                        sg[i]=j;
                        break;
                    }
                }
        }
}



int main(){
	int n;
	read(n);
	k = 2;
	getSG(n);
	for(int i = 0 ; i <= n ; i ++){
		cout << sg[i] << " "; 
	}















}

