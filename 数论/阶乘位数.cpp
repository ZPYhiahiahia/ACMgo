#define PI 3.1415926

int main()
{
    int n, a;
    while (~scanf("%d", &n))
    {
        a = (int)((0.5 * log(2 * PI * n) + n * log(n) - n) / log(10));
        printf("%d\n", a + 1);
    }
    return 0;
}
