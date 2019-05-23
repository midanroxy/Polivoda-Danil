#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int N;
    double x, leftX = 0, rightX = 6.28;

    printf("Enter x, N: ");
    if (scanf("%lf %d", &x, &N) != 2) {
        printf("Invalid input\n");
        return -1;
    }

    if (x < leftX || x > rightX) {
        char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
        printf(fmt, x, leftX, rightX);
        return -1;
    }

    double a = 1, S = a;

    for (int n = 0; n <= N; ++n) {
        double q = - x/(2*(n+1)*(2*n+1));
        a *= q;
        S += a;
    }

    double y = cos(sqrt(x));
    printf("S=%.7f\n", S);
    printf("y=%.7f\n", y);
    double eps = fabs(y-S)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);

    return 0;
}
