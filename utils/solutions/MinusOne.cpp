#include <iostream>

//max counting system
const int MAX_K_VALUE = 16;

//helper functions
int getIndexFromChar(char s)
{
    if (s >= '0' && s <= '9')
        return s - '0';

    if (s >= 'A' && s <= 'F')
        return s - 'A' + 10;

    return -1;
}

char getCharFromIndex(int index)
{
    if (index >= 0 && index <= 9)
        return index + '0';

    if (index >= 10 && index <= 15)
        return index + 'A' - 10;

    return 0;
}

bool canBeDecremented(int index, int k)
{
    return index != 0;
}

bool isValidDigitInK(char digit, int k)
{
    int index = getIndexFromChar(digit);
    return (index != -1 && index < k);
}

bool isValidInput(const char arr[], size_t size, int k)
{
    if (k > MAX_K_VALUE)
        return false;

    for (int i = 0; i < k; i++)
    {
        if (!isValidDigitInK(arr[i], k))
            return false;

    }

    return true;
}

//minusOne solution
void minusOne(char arr[], size_t size, int k)
{
    if (!isValidInput(arr, size, k))
        return; // do nothing

    char maxDigitInK = getCharFromIndex(k - 1);
    for (int i = size - 1; i >= 0; i--)
    {
        int index = getIndexFromChar(arr[i]);
        if (!canBeDecremented(index, k))
        {
            arr[i] = maxDigitInK;
        }
        else
        {
            index--;
            arr[i] = getCharFromIndex(index);
            break;
        }
    }
}
