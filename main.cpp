#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal n1 ("211.1");
    BigReal n2 ("1.031");
    BigReal n4 = n1 - n2;
    //should print result 221.21343222
    cout << n4 << endl;
    return 0;
}


