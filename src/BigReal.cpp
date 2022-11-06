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
    for(int i=0; i<realnum.length(); i++)
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
    for(int i=index; i<realnum.length(); i++)
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
string additionn(string num1,string num2)
{
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    string res = "";
    int carry = 0;
    while (it1 != num1.rend())
    {
        int twoDigitsSum;
        carry = 0;
        twoDigitsSum = ((*it1 - '0') + (*it2 - '0'));
        if (twoDigitsSum >= 10)
        {
            carry = 1;
        }
        res = char((twoDigitsSum % 10) + '0') + res;
        *(it1 + 1) = char(((*(it1 + 1) - '0') + carry) + '0');
        it1++;
        it2++;
    }
    if (carry)
    {
        res = char((carry) + '0') + res;
    }
    return res;
}


BigReal BigReal::operator+ (BigReal anotherReal)
{
    int test = 0;
    BigReal result,n1, n2;
    string right1,right2, right3, carry, carry2;
    if(this->rightNum.size() > anotherReal.rightNum.size())
        test = this->rightNum.size();
    else if(this->rightNum.size() < anotherReal.rightNum.size())
        test = anotherReal.rightNum.size();
    right1 = this->rightNum.getNumber();
    right2 = anotherReal.rightNum.getNumber();
    while (right1.length() < right2.length())
    {
        right1 = right1 + '0';
    }
    while (right2.length() < right1.length())
    {
        right2 = right2 + '0';
    }
    if(this->leftNum.sign() == 1 && anotherReal.leftNum.sign() == 1)
    {

        result.leftNum = this->leftNum + anotherReal.leftNum;
        result.rightNum = additionn(right1,right2);
    }
    else if(this->leftNum.sign() == 0 && anotherReal.leftNum.sign() == 0)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        cout << '-';
        return n1 + n2;
    }
    else if(this->leftNum.sign() == 0 && anotherReal.leftNum.sign() == 1)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        return n2 - n1;
    }
    else if(this->leftNum.sign() == 1 && anotherReal.leftNum.sign() == 0)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        return n1 - n2;

    }
    right3 = result.rightNum.getNumber();
    if(result.rightNum.size() > test)
    {
        for(int i = 0; i < (result.rightNum.size() - test); i++)
        {
            carry = carry + right3[i];
        }
        for(int i = 0; i <= (result.rightNum.size() - test); i++)
        {
            carry2 = carry2 + right3[rightNum.size() -1 - i];
        }
        result.leftNum  = result.leftNum + carry;
        result.rightNum =  carry2;
    }
    return result;
}

string subtractionn(string num1,string num2)
{
    deque<long long>d;
    string res;

    for (long long i = num1.length() - 1; i >= 0; i--)
    {
        if (num1[i] < num2[i])
        {
            num1[i] = char (((num1[i] - '0') + 10) + '0');
            num1[i - 1] = char (((num1[i - 1] - '0') - 1) + '0');
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
        else
        {
            d.push_front((num1[i] - '0') - (num2[i] - '0'));
        }
    }

    for (auto i : d)
    {
        res += to_string(i);
    }
    return res;
}

BigReal BigReal::operator- (BigReal anotherReal)
{
    BigReal n1, n2, result;
    string right1,right2, left1, left2;
    right1 = this->rightNum.getNumber();
    right2 = anotherReal.rightNum.getNumber();
    left1 = this->leftNum.getNumber();
    left2 = anotherReal.leftNum.getNumber();
    if(this->leftNum.sign() == 1 && anotherReal.leftNum.sign() == 1)
    {
        if(this->leftNum < anotherReal.leftNum)
        {
            if(this->rightNum > anotherReal.rightNum)
            {
                right2 = "1" + right2;
                left2 = subtractionn(left2, "1");
                result.leftNum = subtractionn(left2, left1);
                result.rightNum = additionn(right1, right2);
                cout << '-';
            }

            else
            {
                result.leftNum = subtractionn(left2, left1);
                result.rightNum = subtractionn(right2, right1);
                cout << '-';
            }
        }
        else
        {
            if(this->rightNum < anotherReal.rightNum)
            {
                right1 = "1" + right1;
                left1 = subtractionn(left1, "1");
                result.leftNum = subtractionn(left1, left2);
                result.rightNum = subtractionn(right1, right2);
            }
            else
            {
                result.leftNum = subtractionn(left1, left2);
                result.rightNum = subtractionn(right1, right2);
            }
        }
        return result;
    }
    else if(this->leftNum.sign() == 0 && anotherReal.leftNum.sign() == 1)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        cout << '-';
        return n1 + n2;

    }
    else if(this->leftNum.sign() == 1 && anotherReal.leftNum.sign() == 0)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        return n1 + n2;
    }
    else if (this->leftNum.sign() == 0 && anotherReal.leftNum.sign() == 0)
    {
        n1.leftNum = this->leftNum.getNumber();
        n1.rightNum = this->rightNum.getNumber();
        n2.leftNum = anotherReal.leftNum.getNumber();
        n2.rightNum = anotherReal.rightNum.getNumber();
        return n2 - n1;
    }
}
