class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> count1;
        for (char c : s1) {
            count1[c]++;
        }

        unordered_map<char, int> count2;

        int l = 0;

        for (int r = 0; r < s2.size(); r++) {

            // Add the right character first
            count2[s2[r]]++;

            // If window becomes too large, remove from left
            if (r - l + 1 > s1.size()) {
                count2[s2[l]]--;
                if (count2[s2[l]] == 0) {
                    count2.erase(s2[l]);
                }
                l++;
            }

            // Window is now exactly s1.size()
            if (count1 == count2) {
                return true;
            }
        }

        return false;
    }
};