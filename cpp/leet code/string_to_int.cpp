/*Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer.

The algorithm for myAtoi(string s) is as follows:

Whitespace: Ignore any leading whitespace (" ").
Signedness: Determine the sign by checking if the next character is '-' or '+', assuming positivity if neither present.
Conversion: Read the integer by skipping leading zeros until a non-digit character is encountered or the end of the string is reached. If no digits were read, then the result is 0.
Rounding: If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then round the integer to remain in the range. Specifically, integers less than -231 should be rounded to -231, and integers greater than 231 - 1 should be rounded to 231 - 1.
Return the integer as the final result.*/

#include<iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n=s.size();
        int sign=1;
        long long result=0;
        while(i<n&&(s[i]==' '))
        {
            i++;
        }
        if(i<n&&((s[i]=='-')||(s[i]=='+')))
        {
            sign=(s[i]=='-')? -1 : 1;
            i++;
        }
        while(i<n&&(isdigit(s[i])))
        {
            result=result*10+(s[i]-'0');
            if(result*sign>INT_MAX)
            {
                return INT_MAX;
            }
            if(result*sign<INT_MIN)
            {
                return INT_MIN;
            }
            i++;
        }
    return static_cast<int>(result*sign);

    }
};