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
 *  也可以用树状数组做
 *  a[0...n-1] cnt=0; call: MergeSort(0, n)
 */
const int N = 1010;
int a[N];
int c[N];
int cnt = 0;

void MergeSort(int l, int r)
{
    int mid, i, j, tmp;
    if (r > l + 1)
    {
        mid = (l + r) / 2;
        MergeSort(l, mid);
        MergeSort(mid, r);
        tmp = l;
        for (i = l, j = mid; i < mid && j < r;)
        {
            if (a[i] > a[j])
            {
                c[tmp++] = a[j++];
                cnt += mid - i;
            }
            else
            {
                c[tmp++] = a[i++];
            }
        }
        if (j < r)
        {
            for (; j < r; ++j)
            {
                c[tmp++] = a[j];
            }
        }
        else
        {
            for (; i < mid; ++i)
            {
                c[tmp++]=a[i];
            }
        }
        for (i = l; i < r; ++i)
        {
            a[i] = c[i];
        }
    }
    return ;
} 
int main(){
















}

