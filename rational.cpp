#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <numeric>
#include <cmath>
#include "rational.h"

using namespace std;

Rational::Rational() {
  num = 0;
  den = 1;
};

Rational::Rational(int numerator, int denominator) {
  if (denominator == 0) throw invalid_argument("The divisor cannot be 0");

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
};

int Rational::Numerator() const {
  return num;
}

int Rational::Denominator() const {
  return den;
}

bool operator == (Rational r1, Rational r2) {
  if ((r1.Numerator() == r2.Numerator()) && (r1.Denominator() == r2.Denominator())) {
    return true;
  } else {
    return false;
  };
}

Rational operator + (Rational r1, Rational r2) {
  int p = (r1.Numerator() * r2.Denominator()) + (r2.Numerator() * r1.Denominator());
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator - (Rational r1, Rational r2) {
  int p = (r1.Numerator() * r2.Denominator()) - (r2.Numerator() * r1.Denominator());
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator * (Rational r1, Rational r2) {
  int p = r1.Numerator() * r2.Numerator();
  int q = r1.Denominator() * r2.Denominator();
  return Rational(p, q);
}

Rational operator / (Rational r1, Rational r2) {
  if (r2.Numerator() == 0) throw domain_error("Cannot be divided by 0");

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

ostream& operator << (ostream& stream, const Rational& r) {
  stream << r.Numerator() << "/" << r.Denominator();

  return stream;
}

bool operator > (Rational r1, Rational r2) {
  return (r1.Numerator() / (double)r1.Denominator()) > double(r2.Numerator() / (double)r2.Denominator());
}

bool operator < (Rational r1, Rational r2) {
  return (r1.Numerator() / (double)r1.Denominator()) < (r2.Numerator() / (double)r2.Denominator());
}