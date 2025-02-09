#include <iostream>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return (a - b); }
int multiply(int a, int b) { return (a * b); }

int calculate(int a, int b, int (*operation)(int, int)) {
  return operation(a, b);
};

int (*getOperation(char op))(int, int) {
  switch (op) {
  case '+':
    return &add;
  case '-':
    return &subtract;
  case '*':
    return &multiply;
  default:
    return nullptr;
  };
};

bool (*pf)(int &num, int &num2) = [](int &num, int &num2) {
  return num == num2;
};

int main() {
  int (*func_ptr)(int, int) = getOperation('+');
  int sum = func_ptr(5, 3);

  std::cout << "\nSum: of 5 + 3 = " << sum << std::endl;
  int num1 = 100;
  int num2 = 100;
  bool result = pf(num1, num2);
  if (result) {
    std::cout << "They are equal" << std::endl;
  }
  return 0;
}
