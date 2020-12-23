// Calculator that uses recursion and prioritizes n mod 2
// Author: Brett Wells
// input: an integer n
// output: The minimum number of operations "+1", "x2",
// and "x3" needed to get n from 1.

//This was written out as a test for the sample outputs
//it fails at n=10 where the k-1 n should = 9 but instead
// this code suggests n = 5 at this point

//the recursive approch doesn't seem to provide the minimum operations

#include <iostream>

using namespace std;

int mod2Calculator(int n) {
  int numOps = 0;
  //int currentNum = 1;
  if (n == 1) { //base case of recursion
    cout << "numOps:" << numOps << " ";
    cout << "n:" << n << " ";
    return numOps;
  } else if (n % 2 == 0) {
    numOps = mod2Calculator(n / 2) + 1;
  } else if (n % 3 == 0) {
    numOps = mod2Calculator(n / 3) + 1;
  } else {
    numOps = mod2Calculator(n - 1) + 1;
  }
  cout << "numOps:" << numOps << " ";
  cout << "n:" << n << " ";
  return numOps;
}

int main() {
  int num;
  cout << "Enter and integer: ";
  cin >> num;
  cout << "mod2Calculator number of calculations: " << mod2Calculator(num);
  cout << endl;
}
