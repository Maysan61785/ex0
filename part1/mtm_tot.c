#include <stdio.h>
#include <stdlib.h>P
int main()
{
    int x, i, a, b = 0, c = 0, n;
    printf("Enter size of input: \n");
    if (!scanf("%d", &x))
    {
        printf("Invalid size\n");
        return 0;
    }
        if (x <= 0)
        {
            printf("Invalid size\n");
            return 0;
        }
        int *numbers = malloc(x * sizeof(int));
        if (numbers == NULL)
        {
            return 0;
        }
        int *powers = malloc(x * sizeof(int));
        if (powers == NULL)
        {
            free(numbers);
            return 0;
        }
        else
        {
            printf("Enter numbers:\n");
            for (i = 0; i < x; i++)
            {
                if (!scanf("%d", &a))
                {
                    printf("Invalid number\n");
                    free(numbers);
                    free(powers);
                    return 0;
                }
                else
                {
                    if (a == 1)
                    {

                        numbers[i] = a;
                        powers[i] = 0;
                        continue;
                    }
                    n = a;
                    while (a != 1) // a!=0
                    {
                        if (a % 2 == 0)
                        {
                            c++;
                            a = a / 2;
                        }
                        else
                        {
                            c = 0;
                            break;
                        }
                    }
                    if (a == 1 && c != 0)
                    {
                        numbers[i] = n;
                        powers[i] = c;
                    }
                    else
                    {
                        numbers[i] = 0;
                        powers[i] = 0;
                    }
                    c = 0;
                }
            }
            for (int j = 0; j < x; j++)
            {
                if (numbers[j] != 0)
                {
                    printf("The number %d is a power of 2: a = 2^%d\n", numbers[j], powers[j]);
                    b = b + powers[j];
                }
            }
            printf("Total exponent sum is %d\n", b);
        }
        free(numbers);
        free(powers);
    return 0;
}