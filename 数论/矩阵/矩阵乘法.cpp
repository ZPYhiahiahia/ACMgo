#include<bits/stdc++.h>
#define MAXN 111
#define mod(x) ((x) % MOD)
#define MOD 1000000007
#define LL long long
using namespace std ;
int n;

struct mat
{
    int m[MAXN][MAXN];
};

//  æÿ’Û≥À∑®
mat operator * (mat a, mat &b)
{
    mat ret;
    memset(ret.m, 0, sizeof(ret.m));

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            if (a.m[i][k])
            {
                for (int j = 0; j < n; j++)
                {
                    ret.m[i][j] = mod(ret.m[i][j] + (LL)a.m[i][k] * b.m[k][j]);
                }
            }
        }
    }
    return ret;
}

int main(){
















}

