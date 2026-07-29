#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        char mid_char = '\0';
        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
            half_count[i] = freq[i] / 2;
        }

        int half_len = n / 2;

        auto countPermutations = [&](vector<int> counts, int total_len, long long k_cap) -> long long {
            long long res = 1;
            int current_n = total_len;

            int max_idx = 0;
            for (int i = 0; i < 26; ++i) {
                if (counts[i] > counts[max_idx]) {
                    max_idx = i;
                }
            }

            for (int i = 0; i < 26; ++i) {
                if (i == max_idx || counts[i] == 0) continue;
                for (int j = 1; j <= counts[i]; ++j) {
                    res = (res * current_n) / j;
                    current_n--;
                    if (res > k_cap) return k_cap + 1; 
                }
            }
            return res;
        };

        long long total_possible = countPermutations(half_count, half_len, k);
        if (total_possible < k) {
            return "";
        }

        string left_half = "";
        int remaining_len = half_len;

        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_count[c] == 0) continue;

                half_count[c]--;
                long long ways = countPermutations(half_count, remaining_len - 1, k);

                if (ways >= k) {
                    left_half += (char)('a' + c);
                    remaining_len--;
                    break;
                } else {
                    k -= ways;
                    half_count[c]++; 
                }
            }
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        if (n % 2 != 0) {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};