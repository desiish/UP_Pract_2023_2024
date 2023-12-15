#include <iostream>
using namespace std;
constexpr size_t MAX_SIZE = 1024;

void init(bool* masks, size_t size, bool value)
{
  if (!masks)
    return;

  for (int i = 0; i < size; i++)
  {
    masks[i] = value;
  }
}

void addMasks(bool* masks, size_t size, int a)
{
  if (!masks || a >= size)
    return;

  for (int i = 0; i <= a; i++)
  {
    if ((a | i) == a)
      masks[i] = true;
  }
}

unsigned getCountOfOnes(const bool* masks, size_t size)
{
  if (!masks)
    return 0;

  unsigned count = 0;
  for (int i = 0; i < size; i++)
  {
    if (masks[i])
    {
      count++;
    }
  }
  return count;
}

unsigned getCountOfSubmasks(const int* arr, size_t size)
{
  if (!arr)
    return 0;
  
  bool masks[MAX_SIZE];
  init(masks, MAX_SIZE, 0);

  for (int i = 0; i < size; i++)
  {
    addMasks(masks, MAX_SIZE, arr[i]);
  }

  return getCountOfOnes(masks, size2);
}


int main()
{
  int arr[MAX_SIZE];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << getCountOfSubmasks(arr, n);
  return 0;
}
