#ifndef RATIONAL_H_
#define RATIONAL_H_

class Rational {
  public:
      Rational();

      Rational(int numerator, int denominator);

      int Numerator() const;

      int Denominator() const;

  private:
    int num;
    int den;
};

bool operator == (Rational r1, Rational r2);

Rational operator + (Rational r1, Rational r2);

Rational operator - (Rational r1, Rational r2);

Rational operator * (Rational r1, Rational r2);

Rational operator / (Rational r1, Rational r2);

std::istream& operator >> (std::istream& stream, Rational& r);
std::ostream& operator << (std::ostream& stream, const Rational& r);

bool operator > (Rational r1, Rational r2);

bool operator < (Rational r1, Rational r2);

#endif