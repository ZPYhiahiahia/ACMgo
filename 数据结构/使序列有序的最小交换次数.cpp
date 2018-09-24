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

int IT_MAX = 1 << 19;
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
const int MAX_N = 100005;
bool cmp (int a , int b){
	return a>b;
}/*
 *  交换任意两数的本质是改变了元素位置，
 *  故建立元素与其目标状态应放置位置的映射关系
 */
int getMinSwaps(vector<int> &A)
{
    //  排序
    vector<int> B(A);
    sort(B.begin(), B.end());
    map<int, int> m;
    int len = (int)A.size();
    for (int i = 0; i < len; i++)
    {
        m[B[i]] = i;    //  建立每个元素与其应放位置的映射关系
    }

    int loops = 0;      //  循环节个数
    vector<bool> flag(len, false);
    //  找出循环节的个数
    for (int i = 0; i < len; i++)
    {
        if (!flag[i])
        {
            int j = i;
            while (!flag[j])
            {
                flag[j] = true;
                j = m[A[j]];    //  原序列中j位置的元素在有序序列中的位置
            }
            loops++;
        }
    }
    return len - loops;
}

vector<int> nums;

int main()
{
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(5);

    int res = getMinSwaps(nums);

    cout << res << '\n';

    return 0;
}

