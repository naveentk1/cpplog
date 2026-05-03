#include <iostream>

void corruption() {

  char a[8] = "AAAAAAA";
  char n[8];

  std::cout << "a: " << (void *)a << '\n';
  std::cout << "n: " << (void *)n << '\n';

  char *ptr = n;
  for (int i = 0; i < 16; i++) {
    ptr[i] = 'X';
  }

  std::cout << "a after: " << a << '\n';
}

int main() {

  corruption();
  return 0;
}
