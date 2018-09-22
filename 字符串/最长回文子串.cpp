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
 * ��������Ӵ�
 */

const int MAXN = 110010;
char A[MAXN * 2];
int B[MAXN * 2];

void Manacher(char s[], int len)
{
    int l = 0;
    A[l++] = '$';   //0�±�洢Ϊ�����ַ�
    A[l++] = '#';
    for (int i = 0; i < len; i++)
    {
        A[l++] = s[i];
        A[l++] = '#';
    }
    A[l] = 0;       //���ַ�
    int mx = 0;
    int id = 0;
    for (int i = 0; i < l; i++)
    {
        B[i] = mx > i ? std::min(B[2 * id - i], mx - i) : 1;
        while (A[i + B[i]] == A[i - B[i]])
        {
            B[i]++;
        }
        if (i + B[i] > mx)
        {
            mx = i + B[i];
            id = i;
        }
    }
    return ;
}

/*
 * abaaba
 * i:   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14
 * A:   $  #  a  #  b  #  a  #  a  #  b  #  a  # '\0'
 * B:   1  1  2  1  4  1  2  7  2  1  4  1  2  1    //�Ե�i��Ϊ���ĵĻ��İ뾶��������i����
 */

char s[MAXN];

int main(int argc, const char * argv[])
{
    while (std::cin >> s)
    {
        int len = (int)strlen(s);
        Manacher(s, len);
        int ans = 0;
        for (int i = 0; i < 2 * len + 2; i++)   //�������Ȳ�����λ�����ַ�������i < 2 * len + 2
        {
            ans = std::max(ans, B[i] - 1);
        }
        std::cout << ans << std::endl;
    }

    return 0;
}

