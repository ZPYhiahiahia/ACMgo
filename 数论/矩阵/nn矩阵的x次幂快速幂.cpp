/*
 *  ��������� n*n�����x����
 */
#define MAXN 111
#define mod(x) ((x) % MOD)
#define MOD 1000000007
#define LL long long

int n;

struct mat
{
    int m[MAXN][MAXN];
} unit; //  ��Ԫ����

//  ����˷�
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

void init_unit()
{
    for (int i = 0; i < MAXN; i++)
    {
        unit.m[i][i] = 1;
    }
    return ;
}

mat pow_mat(mat a, LL n)
{
    mat ret = unit;
    while (n)
    {
        if (n & 1)
        {
//            n--;
            ret = ret * a;
        }
        n >>= 1;
        a = a * a;
    }
    return ret;
}

int main()
{
    LL x;
    init_unit();

    while (cin >> n >> x)
    {
        mat a;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a.m[i][j];
            }
        }
        a = pow_mat(a, x);  //  a�����x����
        //  �������
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j + 1 == n)
                {
                    cout << a.m[i][j] << endl;
                }
                else
                {
                    cout << a.m[i][j] << " ";
                }
            }
        }
    }
    return 0;
}
