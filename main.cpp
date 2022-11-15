#include <bits/stdc++.h>
#include "BigDecimalInt.h"
#include"BigReal.h"
using namespace std;



int main()
{
    BigReal n1 ("11.90");
    BigReal n2 ("233.1134322222222292");
    BigReal n3 = n1 - n2;
    //next statement will print -221.21134322222222292
    cout << n3 << endl;
    //next statement will print 1
    cout << n3.sign() << endl;

    BigReal p1 ("11.90");
    BigReal p2 ("233.1134322222222292");
    BigReal p3 = p1 + p2;
    //next statement will print 245.01
    cout << p3 << endl;
    cout << "size of p3 is: " << p3.size() << endl;

    //input assignment overloading
    cin >> n1;
    cout << n1 << endl;
    return 0;
}


