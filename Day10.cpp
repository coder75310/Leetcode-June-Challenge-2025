/* 2014. Longest Subsequence Repeated k Times :
You are given a string s of length n, and an integer k. You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the 
remaining characters.

A subsequence seq is repeated k times in the string s if seq * k is a subsequence of s, where seq * k represents a string constructed by 
concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times,
is a subsequence of the string "bababcba".
Return the longest subsequence repeated k times in string s. If multiple such subsequences are found, return the lexicographically largest one.
If there is no such subsequence, return an empty string. */


class Solution {
public:
    bool isSubsequence(string& source, string& target, int k) {
        int i = 0, j = 0, repeat = 0;
        while (i < source.size() && repeat < k) {
            if (source[i] == target[j]) {
                j++;
                if (j == target.size()) {
                    j = 0;
                    repeat++;
                }
            }
            i++;
        }
        return repeat == k;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        vector<char> validChars;
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) {
                validChars.push_back(c);
            }
        }

        queue<string> q;
        q.push("");
        string result = "";

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            for (char c : validChars) {
                string next = cur + c;

                // Optimization: Early pruning
                unordered_map<char, int> count;
                for (char ch : next) count[ch]++;
                bool valid = true;
                for (auto& [ch, cnt] : count) {
                    if (cnt * k > freq[ch]) {
                        valid = false;
                        break;
                    }
                }
                if (!valid) continue;

                if (isSubsequence(s, next, k)) {
                    if (next.size() > result.size() || (next.size() == result.size() && next > result)) {
                        result = next;
                    }
                    q.push(next);  // Only continue from valid
                }
            }
        }

        return result;
    }
};
