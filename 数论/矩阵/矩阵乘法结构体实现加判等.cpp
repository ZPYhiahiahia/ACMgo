/*
 *  AB == C ???
 */
struct Matrix
{
    Type mat[MAXN][MAXN];
    int n, m;
    Matrix()
    {
        n = m = MAXN;
        memset(mat, 0, sizeof(mat));
    }
    Matrix(const Matrix &a)
    {
        set_size(a.n, a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
    }
    Matrix & operator = (const Matrix &a)
    {
        set_size(a.n, a.m);
        memcpy(mat, a.mat, sizeof(a.mat));
        return *this;
    }
    void set_size(int row, int column)
    {
        n = row;
        m = column;
    }
    friend Matrix operator * (const Matrix &a, const Matrix &b)
    {
        Matrix ret;
        ret.set_size(a.n, b.m);
        for (int i = 0; i < a.n; ++i)
        {
            for (int k = 0; k < a.m; ++k)
            {
                if (a.mat[i][k])
                {
                    for (int j = 0; j < b.m; ++j)
                    {
                        if (b.mat[k][j])
                        {
                            ret.mat[i][j] = ret.mat[i][j] + a.mat[i][k] * b.mat[k][j];
                        }
                    }
                }
            }
        }
        return ret;
    }
    friend bool operator == (const Matrix &a, const Matrix &b)
    {
        if (a.n != b.n || a.m != b.m)
        {
            return false;
        }
        for (int i = 0; i < a.n; ++i)
        {
            for (int j = 0; j < a.m; ++j)
            {
                if (a.mat[i][j] != b.mat[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};
