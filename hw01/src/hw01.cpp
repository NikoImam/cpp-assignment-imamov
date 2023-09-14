#include <hw01.h>
#include <cmath>

int getNumbersSum(int num)//сумма цифр числа
{
    int sum = 0;
    while(num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

bool isPrime(int num)//проверка числа на простоту
{
    bool isPrimeFlag = true;
    for(int i = 2; i <= (int)sqrt(num); i++)
    {
        if(num % i == 0)
        {
            isPrimeFlag = false;
            break;
        }
    }
    return isPrimeFlag;
}

int totalSum(int start, int end)//сумма простых двузначных чисел в заданном интервале
{
    int sum = 0;
    for(int i = start; i <= end; i++)
    {
        if(isPrime(i))
        {
            sum += getNumbersSum(i);
        }
    }
    return sum;
}

int hw01(int start, int end)
{
    if(start % 1000 < 100 && start % 100 > 9 && end % 1000 < 100 && end % 100 > 9)//проверка на двузначность
    {
        return totalSum(start, end);
    }
    return -1;
}