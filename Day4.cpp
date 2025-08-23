/* 3085. Minimum Deletions to Make String K-Special:
You are given a string word and an integer k.

We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.

Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.

Return the minimum number of characters you need to delete to make word k-special. */


class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word)
            freq[c]++;
        
        vector<int> freqs;
        for (auto& [ch, cnt] : freq)
            freqs.push_back(cnt);
        
        int res = INT_MAX;
        int maxFreq = *max_element(freqs.begin(), freqs.end());

        for (int target = 1; target <= maxFreq; ++target) {
            int deletions = 0;
            for (int f : freqs) {
                if (f < target) deletions += f; // too low → delete all
                else if (f > target + k) deletions += f - (target + k); // too high → delete extra
                // if in range [target, target + k], no deletion needed
            }
            res = min(res, deletions);
        }
        return res;
    }
};
