#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int beautySum(std::string s) {
        int n = s.size();
        std::vector<std::vector<int>> prefixFreq(n + 1, std::vector<int>(26, 0));

        // Compute prefix frequency array
        for (int i = 0; i < n; ++i) {
            prefixFreq[i + 1] = prefixFreq[i];
            prefixFreq[i + 1][s[i] - 'a']++;
        }

        int totalBeauty = 0;

        // Iterate over all substrings
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                std::vector<int> freq(26, 0);
                for (int k = 0; k < 26; ++k) {
                    freq[k] = prefixFreq[j + 1][k] - prefixFreq[i][k];
                }
                totalBeauty += calculateBeauty(freq);
            }
        }

        return totalBeauty;
    }

private:
    int calculateBeauty(const std::vector<int>& freq) {
        int maxFreq = INT_MIN, minFreq = INT_MAX;
        for (int count : freq) {
            if (count > 0) {
                maxFreq = std::max(maxFreq, count);
                minFreq = std::min(minFreq, count);
            }
        }
        return maxFreq - minFreq;
    }
};

int main() {
    Solution sol;
    std::string s1 = "aabcb";
    std::cout << "The sum of beauty of all substrings of \"" << s1 << "\" is: " << sol.beautySum(s1) << std::endl;

    std::string s2 = "aabcbaa";
    std::cout << "The sum of beauty of all substrings of \"" << s2 << "\" is: " << sol.beautySum(s2) << std::endl;

    return 0;
}
