#include <bits/stdc++.h>
#include "BigReal.h"
#include "BigDecimalInt.h"

using namespace std;


BigReal::BigReal()
{
    BigDecimalInt temp("0");
    leftNum = temp;
    rightNum = temp;
}
BigReal::BigReal(string realnum)
{
    int index = 0;
    string leftPt ="", rightPt="";
    for(int i=0;i<realnum.length();i++)
    {
        if(realnum[i]=='.')
        {
            index = i+1;
            break;
        }
        else
        {
            leftPt+=realnum[i];
        }
    }
    if(realnum[index]=='+' || realnum[index]=='-')
    {
        cout<<"Invalid"<<endl;
        exit(1);
    }
    for(int i=index;i<realnum.length();i++)
    {
        rightPt+=realnum[i];
    }
    if(leftPt=="" && rightPt=="")
    {
        cout<<"Invalid"<<endl;
        exit(1);
    }
    if(rightPt=="")
    {
        rightPt+="0";
    }
    else if(leftPt=="")
    {
        leftPt+="0";
    }
    BigDecimalInt left(leftPt);
    BigDecimalInt right(rightPt);
    leftNum = left;
    rightNum = right;
}
BigReal::BigReal(BigDecimalInt bigIntger)
{
    leftNum = bigIntger;
    BigDecimalInt temp("0");
    rightNum = temp;
}
BigReal::BigReal (const BigReal& other)
{
    leftNum = other.leftNum;
    rightNum = other.rightNum;
}
BigReal& BigReal::operator= (BigReal& other)
{
    this->leftNum = other.leftNum;
    this->rightNum = other.rightNum;
}
BigReal::BigReal (BigReal&& other)
{
    leftNum = other.leftNum;
    rightNum = other.rightNum;
    BigDecimalInt temp("0");
    other.leftNum = temp;
    other.rightNum = temp;
}
BigReal& BigReal::operator= (BigReal&& other)
{
    this->leftNum = other.leftNum;
    this->rightNum = other.rightNum;
    BigDecimalInt temp("0");
    other.leftNum = temp;
    other.rightNum = temp;
}

