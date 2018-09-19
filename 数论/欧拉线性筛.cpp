#include<bits/stdc++.h>
/*
 *  同时得到欧拉函数和素数表
 */
using namespace std;
const int MAXN = 10000000;

bool check[MAXN + 10];
int phi[MAXN + 10];
int prime[MAXN + 10]; //tot个素数 
int tot;    //  素数个数
void phi_and_prime_table(int N); // N以内的素数 
int main(){
	int n;
	scanf("%d",&n);
	phi_and_prime_table(n);
	for(int i = 0 ; i < tot ; i ++){
		cout << prime[i] << " "; 
	}
	cout << endl << tot << endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}




void phi_and_prime_table(int N)
{
    memset(check, false, sizeof(check));
    phi[1] = 1;
    tot = 0;
    for (int i = 2; i <= N; i++)
    {
        if (!check[i])
        {
            prime[tot++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < tot; j++)
        {
            if (i * prime[j] > N)
            {
                break;
            }
            check[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
    return ;
}

