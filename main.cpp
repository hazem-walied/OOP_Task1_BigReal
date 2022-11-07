#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal n1 ("11.9");
    BigReal n2 ("33.1");
    BigReal n4 = n2 + n1;
    //should print result 221.21343222
    cout << n4 << endl;

    return 0;
}


