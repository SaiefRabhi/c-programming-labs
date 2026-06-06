#include <stdio.h>

int roundToNearest100(int number)
{
    if ((number % 100) >= 50)
    {
        return ((number + 99) / 100) * 100;
    }
    else
    {
        return (number / 100) * 100;
    }
}

int main()
{
    int inputNumber;

    printf("Geben Sie eine Zahl ein: ");
    scanf("%d", &inputNumber);

    int roundedNumber = roundToNearest100(inputNumber);

    printf("Die gerundete Zahl ist: %d\n", roundedNumber);

    return 0;
}
