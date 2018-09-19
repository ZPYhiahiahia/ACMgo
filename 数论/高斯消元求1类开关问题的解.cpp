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

//  ��˹��Ԫ���󷽳���Ľ�
//  �����ڸ���Ϳɫһ������ 
const int MAXN = 300;
//  ��equ�����̣�var����Ԫ�������������Ϊequ������Ϊvar��1���ֱ�Ϊ0��var
int equ, var;
int a[MAXN][MAXN];  //  �������
int x[MAXN];        //  �⼯
int free_x[MAXN];   //  �����洢���ɱ�Ԫ�����ö�����ɱ�Ԫ����ʹ�ã�
int free_num;       //  ���ɱ�Ԫ�ĸ���

//  ����ֵΪ��1��ʾ�޽⣬Ϊ0��Ψһ�⣬���򷵻����ɱ�Ԫ����
int Gauss()
{
    int max_r, col, k;
    free_num = 0;
    for (k = 0, col = 0; k < equ && col < var; k++, col++)
    {
        max_r = k;
        for (int i = k + 1; i < equ; i++)
        {
            if (abs(a[i][col]) > abs(a[max_r][col]))
            {
                max_r = i;
            }
        }
        if (a[max_r][col] == 0)
        {
            k--;
            free_x[free_num++] = col;   //  �������ɱ�Ԫ
            continue;
        }

        if (max_r != k)
        {
            for (int j = col; j < var + 1; j++)
            {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; i++)
        {
            if (a[i][col] != 0)
            {
                for (int j = col; j < var + 1; j++)
                {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (int i = k; i < equ; i++)
    {
        if (a[i][col] != 0)
        {
            return -1;  //  �޽�
        }
    }

    if (k < var)
    {
        return var - k; //  ���ɱ�Ԫ����
    }

    //  Ψһ�⣬�ش�
    for (int i = var - 1; i >= 0; i--)
    {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; j++)
        {
            x[i] ^= (a[i][j] && x[j]);
        }
    }

    return 0;
}
int main(){
















}

