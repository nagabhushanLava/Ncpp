class Solution {
public:
    int myAtoi(string s) {
       int i = 0;
    int sign = 1;
    int result = 0;

    // 1. Skip leading spaces
    while (i < s.size() && s[i] == ' ')
        i++;

    // 2. Handle sign
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        if (s[i] == '-') sign = -1;
        i++;
    }

    // 3. Convert digits
    while (i < s.size() && isdigit(s[i])) {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return sign * result;
    }
};