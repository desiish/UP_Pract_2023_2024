#include <iostream>
using namespace std;
long long getBinaryNum(unsigned num) 
{
    long long res = 0;
    int mult = 1;
    while (num)
    {
      res += (num % 2) * mult;
      mult *= 10;
      num /= 2;
    }
    return res;
}
unsigned getCountOfOnesInBinaryNum(long long binaryNum)
{
    unsigned count = 0;
    while (binaryNum)
    {
      if (binaryNum % 10 == 1)
        count++;
      binaryNum /= 10;
    }
    return count;
}
unsigned getCountOfOnesInNum(unsigned num)
{
    long long binaryNum = getBinaryNum(num);
    return getCountOfOnesInBinaryNum(binaryNum);
}
int main() 
{
    int num, sum = 0;
    cin >> num;
    while (num)
    {
      sum += getCountOfOnesInNum(num);
      cin >> num;
    }
    cout << sum;
}
