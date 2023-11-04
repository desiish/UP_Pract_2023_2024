# Консултация СИ 5.11.2023
## I. Примитивни типове данни и преобразуване между тях. Оператори 

<details>
<summary> <b>Пример №1</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 'A';
    std::cout << a << std::endl;
}
```
</details>
<details>
<summary> <b>Пример №2</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    char a = "A";
    std::cout << a << std::endl;
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 65;
    bool b = !a;
    b += 2;
    char c = ++a;
    double d = (--a) / 2;
    int f = (a > 3);
    std::cout << b << " " << c << " " << d << " " << f << std::endl;
}
```
</details>

<details>
<summary> <b>Пример №4</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 1;
    int b = !!(a--);
    unsigned c = b == 1 ? b : !b;
    std::cout << c << std::endl;
}
```
</details>

<details>
<summary> <b>Пример №5</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    double a = 19.03;
    double b = 4.91;
    int c = a + b;
    double d = c / (2 * 1.0);
    std::cout << c << " " << d << std::endl;
}
```
</details>


<details>
<summary> <b>Пример №6</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int n = 10;
    std::cout << ((n < 3) && (n / !n));
}
```
</details>

<details>
<summary> <b>Пример №7</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    double n = 10.0;
    std::cout << n / !n;
}
```
</details>

<details>
<summary> <b>Пример №8</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int a = 100;
int main()
{
    {
        int a = 10;
        {
            a += 5;
            ::a += 5;
            int a = 3;
            a += 2;
        }
        std::cout << a << std::endl;
    }
    std::cout << a << std::endl;
}
```
</details>

## II. Условни конструкции
<details>
<summary> <b>Пример №1</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 7;
    if(a = 0, 1, 2)
        std::cout << a << std::endl;
    else
        std::cout << 12 << std::endl;
}
```
</details>

<details>
<summary> <b>Пример №2</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 23;
    if(a += а -= 3)
        a++;
    std::cout << a;
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 23;
    if(a == 3)
        --a++;
    std::cout << a;
}
```
</details>

<details>
<summary> <b>Пример №4</b> </summary>
  
Пренапишете кода със switch case конструкция.
```c++
#include <iostream>
int main()
{
      int a;
      cin >> a;
      if (a != 1) cout << “not one”;
      if ((a >= 2) && (a<=4)) cout << “between two and four”;
      if (a != 4) cout << “not four”;
}
```
</details>

## III. Цикли
<details>
<summary> <b>Пример №1</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    int a = 10;
    while (a != 0);
        std::cout << a-- << std::endl;
}
```
</details>
<details>
<summary> <b>Пример №2</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
    for (int i = 10; i > 0; i--, std::cout << i % 2 << " " << std::endl);
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
int main()
{
  	int i = 6;
  	while (std::cout << i, ----i);
}
```
</details>

## IV. Функции
<details>
<summary> <b>Пример №1</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
using namespace std;
int num = 10;
int fun(int num)
{
    cout << num;
    return num * 3;
}
int main() {
    int num = 10;
    fun(num);
    cout << num;
}
```
</details>
<details>
<summary> <b>Пример №2</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <iostream>
using namespace std;
int Sum(int a, int b, int c, int d = -5) {
    return a + b + c + d;
}

int main() {
    int num = 10;
    std::cout << Sum(num++, num + 10, ++num);
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Кои функции няма да предизвикат двусмислица?
```c++
#include <iostream>
using namespace std;
void cout(char a) { std::cout << a; } //1

void cout(int a) { std::cout << a; } //2

void cout(char a, int b) { std::cout << a << '-' << b; } //3

void cout(double a, char b) { std::cout << b << '-' << a; } //4

void cout(bool a) { std::cout << a; } //5

void cout(char a, bool b, int c) { std::cout << a <<b << c; } //6

void cout(const int a) { std::cout << a; } //7

void cout(char a, unsigned b) { std::cout << a << '-' <<b; } //8

char cout(char a) { return a; } //9
```
</details>

<details>
<summary> <b>Пример №4</b> </summary>
  
Какво ще отпечата следният код?
```c++
#include <cstdio>
#include <iostream>
using namespace std;

int f(int a = 15, int b = 12)
{
    return a + b;
}

int main() {
    cout << f() << endl;
    cout << f(1) << endl;
    cout << f(1, 2) << endl;
}

```
</details>
