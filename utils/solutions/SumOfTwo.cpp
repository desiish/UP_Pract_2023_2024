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
        return index + 'A' + 10;

    return 0;
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

//sumOfTwo with in-place solution
void sumOfTwo(char arr1[], const char arr2[], size_t size, int k)
{
    if (!isValidInput(arr1, size, k) || !isValidInput(arr2, size, k))
        return; // do nothing

    int toAdd = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        int index1 = getIndexFromChar(arr1[i]);
        int index2 = getIndexFromChar(arr2[i]);

        int index = (index1 + index2 + toAdd);
        arr1[i] = getCharFromIndex(index % k);
        toAdd = index / k;
    }
}

//sumOfTwo with filling a result array
void sumOfTwo(const char arr1[], const char arr2[], char res[], size_t size, int k)
{
    if (!isValidInput(arr1, size, k) || !isValidInput(arr2, size, k))
        return; // do nothing

    int toAdd = 0;

    for (int i = size - 1; i >= 0; i--)
    {
        int index1 = getIndexFromChar(arr1[i]);
        int index2 = getIndexFromChar(arr2[i]);

        int index = (index1 + index2 + toAdd);
        res[i] = getCharFromIndex(index % k);
        toAdd = index / k;
    }
}
