#include "BigNumCalc.h"

#include <algorithm>
#include <list>

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
  std::list<int> sum;
  int carry = 0;

  auto it1 = num1.rbegin();
  auto it2 = num2.rbegin();

  while (it1 != num1.rend() || it2 != num2.rend() || carry != 0) {
    int digit1 = (it1 != num1.rend()) ? *it1 : 0;
    int digit2 = (it2 != num2.rend()) ? *it2 : 0;

    int currentSum = digit1 + digit2 + carry;
    carry = currentSum / 10;
    sum.push_front(currentSum % 10);

    if (it1 != num1.rend()) ++it1;
    if (it2 != num2.rend()) ++it2;
  }

  return sum;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
  std::list<int> difference;
  int borrow = 0;

  auto it1 = num1.rbegin();
  auto it2 = num2.rbegin();

  while (it1 != num1.rend() || it2 != num2.rend()) {
    int digit1 = (it1 != num1.rend()) ? *it1 : 0;
    int digit2 = (it2 != num2.rend()) ? *it2 : 0;

    int currentDiff = digit1 - digit2 - borrow;
    if (currentDiff < 0) {
      currentDiff += 10;
      borrow = 1;
    } else {
      borrow = 0;
    }

    difference.push_front(currentDiff);

    if (it1 != num1.rend()) ++it1;
    if (it2 != num2.rend()) ++it2;
  }

  // Remove leading zeros
  difference.erase(std::find_if(difference.begin(), difference.end(),
                                [](int digit) { return digit != 0; }),
                   difference.end());

  return difference;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, int num2) {
  std::list<int> product;
  int carry = 0;

  auto it = num1.rbegin();

  while (it != num1.rend() || carry != 0) {
    int digit = (it != num1.rend()) ? *it : 0;

    int currentProd = digit * num2 + carry;
    carry = currentProd / 10;
    product.push_front(currentProd % 10);

    if (it != num1.rend()) ++it;
  }

  return product;
}
