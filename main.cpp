#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal r1("2.3");
    BigReal r2("-3.5");
    BigReal res = r1 + r2;
    cout << res.leftNum << "." << res.rightNum;
    return 0;
}


