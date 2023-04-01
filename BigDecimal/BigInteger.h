#ifndef BIGDECIMAL_BIGINTEGER_H
#define BIGDECIMAL_BIGINTEGER_H

#include <bits/stdc++.h>
using namespace std;


class BigInteger {
private:
    string number_digital;
public:
    BigInteger() = default;
    BigInteger(string number);
    BigInteger(int number);
    BigInteger(const BigInteger& number);

    BigInteger operator+(const BigInteger& number) const;
    BigInteger operator-(const BigInteger& number) const;
    BigInteger operator*(const BigInteger& number) const;
    BigInteger operator/(const BigInteger& number) const;

    friend ostream& operator<<(ostream& out, const BigInteger& num);
    friend istream& operator>>(istream& in, BigInteger& num);
};

BigInteger::BigInteger(string number) {
    
}


#endif //BIGDECIMAL_BIGINTEGER_H
