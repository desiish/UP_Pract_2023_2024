#include <iostream>
using namespace std;

bool isDigit(char ch)
{
  return ch >= '0' && ch <= '9';
}

unsigned getDigitFromChar(char ch)
{
  if (!isDigit(ch))
    return 10;

  return ch - '0';
}
unsigned getNumber(const char* str, unsigned& get)
{
  unsigned num = 0;
  while (isDigit(str[get]))
  {
    num *= 10;
    num += getDigitFromChar(str[get]);
    get++;
  }

  return num;
}

unsigned getProductOfNumbersInStr(char* str)
{
  if (!str)
    return 0;

  unsigned get, put;
  get = put = 0;
  unsigned product = 1;
  while (str[get] != '\0')
  {
    if (isDigit(str[get]))
    {
      product *= getNumber(str, get);
    }

    str[put] = str[get];
    put++;

    if (str[get] == '\0')
      break;

    get++;
  }

  str[put] = '\0';

  return product;
}

int main()
{
  char str[] = "Abc23ffds3ff5";
  cout << getProductOfNumbersInStr(str) << " " << str;
  return 0;
}
