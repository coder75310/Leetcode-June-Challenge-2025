/* 2311. Longest Binary Subsequence Less Than or Equal to K :
You are given a binary string s and a positive integer k.

Return the length of the longest subsequence of s that makes up a binary number less than or equal to k.

Note:

The subsequence can contain leading zeroes.
The empty string is considered to be equal to 0.
A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the 
remaining characters. */


class Solution {
public:
    int longestSubsequence(string s, int k) {
        int count = 0;
        long long val = 0;
        long long power = 1;
        int n = s.size();

        // Traverse from right to left
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                count++;  // Always include zero
            } else {
                if (power <= k && val + power <= k) {
                    val += power;
                    count++;
                }
                // If power exceeds k, don't add this '1', but continue the loop
            }

            // Update power (next bit's value)
            if (power <= k) power *= 2;
        }

        return count;
    }
};
