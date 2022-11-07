#ifndef BIGREAL_H
#define BIGREAL_H

#include "BigDecimalInt.h"

using namespace std;

class BigReal{
public:
    BigDecimalInt leftNum;
    BigDecimalInt rightNum;
    BigReal();
    BigReal(string realnum);
    BigReal(BigDecimalInt bigIntger);
    BigReal (const BigReal& other);
    BigReal& operator= (BigReal& other);
    BigReal (BigReal&& other);
    BigReal& operator= (BigReal&& other);
    BigReal operator+ (BigReal anotherReal);
    BigReal operator- (BigReal anotherReal);
    bool operator< (BigReal anotherReal);
    bool operator> (BigReal anotherReal);
    bool operator== (BigReal anotherReal);
    int size();
    int sign();
    friend ostream& operator << (ostream& out, BigReal num);
    friend istream& operator >> (istream& in, BigReal &num);

};


#endif // BIGREAL_H
