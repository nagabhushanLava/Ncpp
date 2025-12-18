#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int romanToInt(const string& s) {
    unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0;
    int n = s.size();

    for (int i = 0; i < n; ++i) {
        // Get value of current symbol
        int currentVal = values[s[i]];

        // Look ahead to next symbol if it exists
        if (i + 1 < n) {
            int nextVal = values[s[i + 1]];
            if (currentVal < nextVal) {
                // Subtract current value if it's less than the next one
                result -= currentVal;
            } else {
                // Otherwise add it
                result += currentVal;
            }
        } else {
            // Last character, just add its value
            result += currentVal;
        }
    }

    return result;
}

int main() {
    string roman;

    cout << "Enter a Roman numeral: ";
    cin >> roman;

    int number = romanToInt(roman);

    cout << "Integer value: " << number << endl;

    return 0;
}
