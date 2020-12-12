#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include "tests.h"
#include "rational.h"

using namespace std;

int main() {
  /*
   * Run tests or change them
   * If you see "OK" then it works perfectly, otherwise work with your code for a better result
   */
  // RATIONAL_TESTS::tests();

  try {
		Rational r1;
		Rational r2;

		char op;

		cin >> r1 >> op >> r2;

		switch (op) {
      case '+': cout << r1 + r2; break;
      case '-': cout << r1 - r2; break;
      case '*': cout << r1 * r2; break;
      case '/': cout << r1 / r2; break;
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}

  return 0;
}