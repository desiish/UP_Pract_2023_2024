#include <iostream>
using namespace std;
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
      if (isPalindrome(currentSuffix))
          cout << currentSuffix << endl;
    } while (currentSuffix != n);
}
int main() 
{
    int num;
    cin >> num;
    printAllPalindromeSuffixes(num);
}
