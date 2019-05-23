#include <stdio.h>
#include <stdlib.h>

int main()
{
    int max = 0;
    int count = 0;
    int a[20];
    int sizea = sizeof(a)/sizeof(int);

    srand(time(NULL));

    for (int i = 0; i < sizea; i++)
    {
        a[i] = random_number(-5, 5);
    }

    for (int i = 0; i < sizea; i++)
    {
        printf("\t%d",a[i]);
    }

    int zerosFound = 0;
    for(int i = 0; i < sizea; i++)
    {
        if(a[i] == 0)
        {
            if (max < count)
            {
                max = count;
            }
            count = 0;
            zerosFound++;
        }
        else if (zerosFound > 0 && a[i] > 0)
        {
            count++;
        }
    }

    printf("\nMax count positive numbers between zeros: %d", max);

    return 0;
}


int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1;
    }


    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}
