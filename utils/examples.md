# Практикум СИ, 15.01.2024 - преговор
## Примери

<details>
<summary> <b>Пример №1</b> </summary>
  
Оптимизирайте следния код:
```c++
#include <iostream>
void bubbleSort(const int* arr, size_t size)
{
    for(int i = 0; i < size - 1; i++) {
        for(int j = i; j < size - 1; j++) {
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
```
</details>

<details>
<summary> <b>Пример №2</b> </summary>
  
Посочете грешките в следния код:
```c++
#include <iostream>

void initPointer(char* toInitialize) {
    toInitialize = new char[26 + 1];

    for (size_t i = 97; i < 123; i++)
        toInitialize[i - 97] = (char)(i);

    toInitialize[26] = '\0';    
}

int main() {
    char* result = nullptr;
    initPointer(result);
    std::cout << result;
    delete[] result;
}
```
</details>

<details>
<summary> <b>Пример №3</b> </summary>
  
Какво ще изведе следният код:
```c++
#include <iostream>

int main() {
    int x = 5;
    if (x = 0) {
        std::cout << "Zero" << std::endl;
    } else if (x < 0) {
        std::cout << "Negative" << std::endl;
    } else {
        std::cout << "Positive" << std::endl;
    }
    return 0;
}
```
</details>

<details>
<summary> <b>Пример №4</b> </summary>
  
Посочете грешките в кода:
```c++
#include <iostream>

char* f()
{
    char[2] arr;
    arr[0] = 'a';
    arr[1] = 98;
    return arr;
}

int main() {
    char* ptr = f();
    cout << ptr;
    return 0;
}
```
</details>

<details>
<summary> <b>Пример №5</b> </summary>
  
Посочете грешките в кода:
```c++
#include <iostream>

int main() {
    char[5] str = "abcdw";
    for(int i = 0; i < 5; i++)
        cout << str[i];
    return 0;
}
```
</details>

<details>
<summary> <b>Пример №6</b> </summary>
  
Какво ще изведе кода:
```c++
#include <iostream>

int main() {
    char* ptr = new char[3];
    ptr[0] = 'a';
    ptr[1] = 'b';
    ptr[2] = 0;
    char* ptr2 = new char[3];
    ptr2[0] = 'c';
    ptr2[1] = 'd';
    ptr2[2] = 0;

    char*& ref = ptr;
    ref = ptr2;
    std::cout << ref << std::endl;
    std::cout << ptr;

    return 0;
}
```
</details>

<details>
<summary> <b>Пример №7</b> </summary>
  
Какво ще изведе кода:
```c++
#include <iostream>

int main() {
    int a = 2;
    int b = 5;
    int c = 11;
    int d = c << 2;
    int e = a | b;
    int f = e ^ b;
    int g = f ^ e;
    std::cout << d << " " << e << " " << f << " " << g;

    return 0;
}
```
</details>

<details>
<summary> <b>Пример №8</b> </summary>
  
Какво ще изведе кода:
```c++
#include <iostream>
bool f() {
    cout << 1;
    return true;
}
bool g() {
    cout << 2;
    return false;
}
bool h() {
    cout << 3;
    return true;
}
int main() {
    f() && g() && h();
    f() & g() & h();

    return 0;
}
```
</details>
