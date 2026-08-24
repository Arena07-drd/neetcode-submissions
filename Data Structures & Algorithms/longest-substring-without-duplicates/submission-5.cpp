class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> mp;

        int ws = 0;
        int max_len = 0;

        for (int we = 0; we < s.size(); we++) {
            if (mp.contains(s[we])) {
                ws = max(ws, mp[s[we]] + 1);
            }

            mp[s[we]] = we;

            max_len = max(max_len, we - ws + 1);
        }

        return max_len;

    }
};
