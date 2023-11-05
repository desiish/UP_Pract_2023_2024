#include <iostream>
using namespace std;
bool isPrime(unsigned n)
{
    if (n < 2)
        return false;
    double sqrtOfN = sqrt(n);
    for (int i = 2; i <= sqrtOfN; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
unsigned reversed(unsigned n)
{
    unsigned res = 0;
    while (n)
    {
        (res *= 10) += n % 10;
        n /= 10;
    }
    return res;
}
bool isPalindrome(unsigned n)
{
    return n == reversed(n);
}
void printAllPalindromeSuffixes(unsigned n)
{
    unsigned dev = 10;
    unsigned currentSuffix;
    do
    {
      currentSuffix = n % dev;
      dev *= 10;
      if (isPalindrome(currentSuffix) || isPrime(currentSuffix))
          cout << currentSuffix << endl;
    } while (currentSuffix != n);
}
int main() 
{
    int num;
    cin >> num;
    printAllPalindromeSuffixes(num);
}
