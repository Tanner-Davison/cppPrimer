#include <iostream>

int (*func(int addP))[10] {
  static int arrS[10];
  try {
    if (addP > 0) {
      for (int i = 0; i < 10; ++i) {
        arrS[i] = i + addP;
      }
      return &arrS;
    } else {
      throw std::runtime_error("Cannot add to 0");
    }
  } catch (std::runtime_error &err) {
    std::cout << err.what() << std::endl;
  }
  return nullptr;
}
void myRec(int *arr, int index) {
  std::cout << arr[index] << std::endl;
  if (index > 0) {
    --index;
    myRec(arr, index);
  } else {
    std::cout << "end" << std::endl;
  }
}
std::string (&stringArr())[10] { // Exercise 6.36 p:230
  static std::string myTempString[10];

  return myTempString;
}
int main() {
  typedef int &lref;
  typedef int &&rref;
  int n;
  lref &r1 = n;

  int arrTest[10]{10, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  myRec(arrTest, 10);
  return 0;
}
