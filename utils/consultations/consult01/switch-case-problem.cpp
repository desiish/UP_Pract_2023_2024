#include <iostream>
using namespace std;
int main() 
{
    /*
    Rewrite the following code using switch statement:
    int a;
    cin >> a;
    if (a != 1) cout << “isn`t one”;
    if ((a >= 2) && (a <= 4)) cout << “between two & four”;
    if (a != 4) cout << “isn`t four”;
    */
  
    int a;
    cin >> a;
    switch (a)
    {
      case 1: cout << "isn`t four " << endl; break;
      case 2:
      case 3: cout << "isn`t one " << "between two & four " << "isn`t four" << endl; break;
      case 4: cout << "isn`t one " << "between two & four " << endl; break;
      default: cout << "isn`t one " << "isn`t four " << endl; break;
    }
}
