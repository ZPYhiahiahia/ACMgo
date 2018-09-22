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
//#define init(n) memset(n,0,sizeof(n));

using namespace std;
const int MAXN = 1111;

int n;
double ans;
double p[MAXN];

void dfs(int x, int tot, double sum)    //  dfs(1, 0, ?)
{
    if (x == n + 1)
    {
        if (sum == 0.0)
        {
            return ;
        }

        if (tot & 1)
        {
            ans += 1 / sum; //  公式随意变
        }
        else
        {
            ans -= 1 / sum;
        }
        return ;
    }

    dfs(x + 1, tot, sum);
    dfs(x + 1, tot + 1, sum + p[x]);
}


void init()
{
    for (int i=1; i<=n; i++)
        cin>>p[i];
} 

int main(){
	while(cin >> n){
		ans = 0; 
		init();
		dfs(1,0,0.0);
		printf("%.4f\n",ans);
	} 
	return 0;
	
	
	
}

