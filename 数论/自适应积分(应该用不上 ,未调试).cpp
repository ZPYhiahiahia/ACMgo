const double eps = 1e-6;    //  ���־���

//  ��������
double F(double x)
{
    double ans;
    //  ��������
    //  ...
//    ans = x * exp(x);       //  ��ԲΪ��
    return ans;
}

//  ����simpson��������Ҫ��F��һ��ȫ�ֺ���
double simpson(double a, double b)
{
    double c = a + (b - a) / 2;
    return (F(a) + 4 * F(c) + F(b)) * (b - a) / 6;
}

//  ����Ӧsimpson��ʽ���ݹ���̣�����֪��������[a, b]�ϵ�����simpsonָA
double asr(double a, double b, double eps, double A)
{
    double c = a + (b - a) / 2;
    double L = simpson(a, c), R = simpson(c, b);
    if (fabs(L + R - A) <= 15 * eps)
    {
        return L + R + (L + R - A) / 15.0;
    }
    return asr(a, c, eps / 2, L) + asr(c, b, eps / 2, R);
}

//  ����Ӧsimpson��ʽ�������̣�
double asr(double a, double b, double eps)
{
    return asr(a, b, eps, simpson(a, b));
}

int main(int argc, const char * argv[])
{
//    std::cout << asr(1, 2, eps) << '\n';
    return 0;
}
