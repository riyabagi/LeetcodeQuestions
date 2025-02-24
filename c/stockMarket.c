#include <stdio.h>

#define MAX 100000

int maxProfit(int *prices, int pricesSize)
{
    int max = 0;
    for (int index = 0; index < pricesSize; index++)
    {
        for (int itr = index + 1; itr < pricesSize; itr++)
        {
            if (max < prices[itr] - prices[index])
            {
                max = prices[itr] - prices[index];
            }
        }
    }
    return max;
}

int main()
{
    char value;
    int array[MAX], index = 0, num;

    printf("Enter the array in the format [7,6,4,3,1]:\n");

    while (scanf("%c", &value) == 1)
    {
        if (value == '[' || value == ',')
            continue;
        if (value == ']')
            break;

        ungetc(value, stdin); // Put character back for correct reading
        scanf("%d", &num);    // Read full integer value
        array[index++] = num;
    }

    int result = maxProfit(array, index);
    printf("%d\n", result);

    return 0;
}