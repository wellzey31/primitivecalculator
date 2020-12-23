// Greedy Calculator from psuedocode in problem
// Author: Brett Wells
// input: an integer n
// output: The minimum number of operations "+1", "x2",
// and "x3" needed to get n from 1.

//This was written out to think about why this is not a good method

#include <iostream>

using namespace std;

int greedyCalculator(int n) {
  int numOps = 0;
  int currentNum = 1;
  while (currentNum < n) {
    if (currentNum <= n/3) {
      currentNum = 3 * currentNum;
    } else if (currentNum <= n/2) {
      currentNum = 2 * currentNum;
    } else {
      currentNum++;
    }
    numOps++;
  }
  return numOps;
}

int main() {
  int num;
  cout << "Enter and integer: ";
  cin >> num;
  cout << "greedyCalculator number of calculations: " << greedyCalculator(num);
  cout << endl;
}
