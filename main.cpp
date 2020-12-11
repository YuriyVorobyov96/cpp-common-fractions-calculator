#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

class Rational {
  public:
      Rational() {
        num = 0;
        den = 1;
      }

      Rational(int numerator, int denominator) {
        if (denominator < 0) {
            if (numerator < 0) {
                denominator = abs(denominator);
                numerator = abs(numerator);
            }
            else {
                denominator = abs(denominator);
                numerator = numerator - 2 * numerator;
            }
        }
        if (numerator == 0) {
            denominator = 1;
        }

        int nod = gcd(abs(numerator), abs(denominator));
        num = numerator / nod;
        den = denominator / nod;
      }

      int Numerator() const {
        return num;
      }

      int Denominator() const {
        return den;
      }

  private:
    int num;
    int den;
};

bool operator==(Rational r1, Rational r2) {
  if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() == r2.Denominator())) {
    return true;
  } else {
    return false;
  };
}

Rational operator+(Rational r1, Rational r2) {
  int p = (r1.Numerator() * r2.Denominator()) + (r2.Numerator() * r1.Denominator());
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator-(Rational r1, Rational r2) {
  int p = (r1.Numerator() * r2.Denominator()) - (r2.Numerator() * r1.Denominator());
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator*(Rational r1, Rational r2) {
  int p = r1.Numerator() * r2.Numerator();
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator/(Rational r1, Rational r2) {
  int p = r1.Numerator() * r2.Denominator();
  int q = r1.Denominator() * r2.Numerator();
  return Rational(p, q);
}

istream& operator >> (istream& stream, Rational& r) {
  int p, q;
	char c;

	stream >> p >> c >> q;

	if (stream && c == '/') {
		r = Rational(p, q);
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Rational& r) {
  stream << r.Numerator() << "/" << r.Denominator();

  return stream;
}

bool operator > (Rational r1, Rational r2) {
  return (r1.Numerator() / (double)r1.Denominator()) > double(r2.Numerator() / (double)r2.Denominator());
}

bool operator < (Rational r1, Rational r2) {
  return (r1.Numerator() / (double)r1.Denominator()) < (r2.Numerator() / (double)r2.Denominator());
}

int tests() {
  {
    const Rational r(3, 10);

    if (r.Numerator() != 3 || r.Denominator() != 10) {
      cout << "Rational(3, 10) != 3/10" << endl;

      return 1;
    }
  }

  {
    const Rational r(8, 12);

    if (r.Numerator() != 2 || r.Denominator() != 3) {
      cout << "Rational(8, 12) != 2/3" << endl;

      return 2;
    }
  }

  {
    const Rational r(-4, 6);

    if (r.Numerator() != -2 || r.Denominator() != 3) {
      cout << "Rational(-4, 6) != -2/3" << endl;

      return 3;
    }
  }

  {
    const Rational r(0, 15);

    if (r.Numerator() != 0 || r.Denominator() != 1) {
      cout << "Rational(0, 15) != 0/1" << endl;

      return 4;
    }
  }

  {
    const Rational defaultConstructed;

    if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
      cout << "Rational() != 0/1" << endl;

      return 5;
    }
  }

  {
    Rational r1(4, 6);
    Rational r2(2, 3);

    bool equal = r1 == r2;

    if (!equal) {
      cout << "4/6 != 2/3" << endl;

      return 6;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;

    bool equal = c == Rational(2, 1);

    if (!equal) {
      cout << "2/3 + 4/3 != 2" << endl;

      return 7;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;

    bool equal = c == Rational(31, 63);

    if (!equal) {
      cout << "5/7 - 2/9 != 31/63" << endl;

      return 8;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a * b;

    bool equal = c == Rational(8, 9);

    if (!equal) {
      cout << "2/3 * 4/3 != 8/9" << endl;

      return 9;
    }
  }

  {
    Rational a(5, 4);
    Rational b(15, 8);
    Rational c = a / b;

    bool equal = c == Rational(2, 3);

    if (!equal) {
      cout << "5/4 / 15/8 != 2/3" << endl;

      return 10;
    }
  }

  {
    ostringstream output;
    output << Rational(-6, 8);

    if (output.str() != "-3/4") {
      cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;

      return 11;
    }
  }

  {
    istringstream input("5/7");
    Rational r;
    input >> r;

    bool equal = r == Rational(5, 7);

    if (!equal) {
      cout << "5/7 is incorrectly read as " << r << endl;

      return 12;
    }
  }

  {
    istringstream input("");
    Rational r;

    bool correct = !(input >> r);

    if (!correct) {
      cout << "Read from empty stream works incorrectly" << endl;

      return 13;
    }
  }

  {
    istringstream input("5/7 10/8");
    Rational r1, r2;
    input >> r1 >> r2;

    bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);

    if (!correct) {
      cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;

      return 14;
    }

    input >> r1;
    input >> r2;
    correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);

    if (!correct) {
      cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;

      return 15;
    }
  }

  {
    istringstream input1("1*2"), input2("1/"), input3("/4");
    Rational r1, r2, r3;
    input1 >> r1;
    input2 >> r2;
    input3 >> r3;

    bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();

    if (!correct) {
      cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
        << r1 << " " << r2 << " " << r3 << endl;

      return 16;
    }
  }

  {
    const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};

    if (rs.size() != 3) {
      cout << "Wrong amount of items in the set" << endl;

      return 17;
    }

    vector<Rational> v;

    for (auto x : rs) {
        v.push_back(x);
    }

    if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
      cout << "Rationals comparison works incorrectly" << endl;

      return 18;
    }
  }

  {
    map<Rational, int> count;

    ++count[{1, 2}];
    ++count[{1, 2}];
    ++count[{2, 3}];

    if (count.size() != 2) {
      cout << "Wrong amount of items in the map" << endl;

      return 19;
    }
  }

  cout << "OK" << endl;
  return 0;
}

int main() {
  /*
   * Run tests or change them
   * If you see "OK" then it works perfectly, otherwise work with your code for a better result
   */
  tests();

  return 0;
}