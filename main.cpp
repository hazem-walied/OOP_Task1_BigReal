#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal r1;
    BigReal r2("1.1");
    r1 = r2;
    cout<<r1.leftNum<<"."<<r1.rightNum<<endl;
    cout<<r2.leftNum<<"."<<r2.rightNum<<endl;
    return 0;
}


