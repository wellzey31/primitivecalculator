// Calculator that uses dynamic programming memotization
// Author: Brett Wells
// input: an integer n
// output: The minimum number of operations "+1", "x2",
// and "x3" needed to get n from 1 and the intermediate values.

#include <bits/stdc++.h>

using namespace std;

class primitiveCalculator {
 public:
   //necessary because you can't use .size on a dynamic array
  int getOperations() {
    return operations;
  }

  //necessary because you can't use .size on a dynamic array
  void setOperations(int n) {
    operations = n;
  }

  //takes in an integer n and returns the intermediate values in an array
 int* calculate(int n) {
  int size = n+1;
  int* cache;
  cache = new int[size];
  for (int i = 0; i < size; i++) {
    cache[i] = 0;
  }
  for (int i = 1; i < size; i++) {
    cache[i] = cache[i-1] + 1;
    if (i % 2 == 0) {
      cache[i] = min(cache[i], cache[i / 2] + 1);
    }
    if (i % 3 == 0) {
      cache[i] = min(cache[i], cache[i / 3] + 1);
    }
  }
  /*cout << "cache: ";
  for (int i = 1; i < size; i++) {
    cout << cache[i] << " ";
  }
  cout << endl;*/
  // new array to store result with size = to last element in cache
  int* result;
  result = new int[cache[size-1]];
  size = cache[size-1]; //modify size for use in loops
  setOperations(size - 1);
  for (int i = 0; i < size; i++) { //iniates result array elements to 1
    result[i] = 1;
  }
  for (int i = size-1; i >= 0; i--) {
    result[i] = n;
    if (cache[n-1] == cache[n] - 1) n--;
    else if (n % 2 == 0 && (cache[n / 2] == cache[n] - 1)) {
      n = n / 2;
    } else {
      n = n / 3;
    }
  }
  return result;
}

private:
  int operations = 0;
};

int main() {
  clock_t tStart = clock();
  int testnum, nmax = pow(10, 6);
  srand(time(NULL));
  primitiveCalculator p;
  int* answer = p.calculate(10);
  cout << "Number of operations to go from 1 to 96234 = " << p.getOperations() << endl;
  for (int i = 0; i < p.getOperations()+1; i++) {
    cout << answer[i] << " ";
  }
  cout << endl << endl;

  answer = p.calculate(1);
  cout << "Number of operations to go from 1 to 1 = " << p.getOperations() << endl;
  for (int i = 0; i < p.getOperations()+1; i++) {
    cout << answer[i] << " ";
  }
  cout << endl << endl;

  answer = p.calculate(10);
  cout << "Number of operations to go from 1 to 10 = " << p.getOperations() << endl;
  for (int i = 0; i < p.getOperations()+1; i++) {
    cout << answer[i] << " ";
  }
  cout << endl << endl;

  for (int i = 0; i < 5; i++) {
    testnum = rand() % nmax + 1;
    answer = p.calculate(testnum);
    cout << "Number of operations to go from 1 to " << testnum << " = " << p.getOperations() << endl;
    for (int i = 0; i < p.getOperations()+1; i++) {
      cout << answer[i] << " ";
    }
    cout << endl << endl;
  }

  delete answer;
  printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  return 0;
}
