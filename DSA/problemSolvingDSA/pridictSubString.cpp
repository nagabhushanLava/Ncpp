#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s)
{
    int freq[256] = {0};   // ASCII character count
    int left = 0, right = 0;
    int maxLen = 0;

    while (s[right] != '\0')
    {
        freq[(unsigned char)s[right]]++;

        // If duplicate found, shrink window
        while (freq[(unsigned char)s[right]] > 1)
        {
            freq[(unsigned char)s[left]]--;
            left++;
        }

        int windowLen = right - left + 1;
        if (windowLen > maxLen)
            maxLen = windowLen;

        right++;
    }

    return maxLen;
}
