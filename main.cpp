#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal n1 ("10.5");
    BigReal n2 ("0.5");
    BigReal n4 = n1 + n2;
    //should print result 221.21343222
    cout << n4 << endl;
    return 0;
}


