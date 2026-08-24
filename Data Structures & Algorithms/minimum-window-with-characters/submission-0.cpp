class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> tmap;
        for (char c : t) tmap[c]++;

        unordered_map<char, int> smap;
        int required = tmap.size(); // # of distinct chars that must be fully satisfied
        int formed = 0;             // # of distinct chars currently satisfied

        int l = 0, r = 0;
        int bestLen = INT_MAX, bestL = 0;

        while (r < (int)s.size()) {
            char c = s[r];
            if (tmap.count(c)) {
                smap[c]++;
                if (smap[c] == tmap[c]) formed++;
            }

            // Window is valid -> try to shrink from the left as much as possible
            while (l <= r && formed == required) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }

                char lc = s[l];
                if (tmap.count(lc)) {
                    smap[lc]--;
                    if (smap[lc] < tmap[lc]) formed--;
                }
                l++;
            }

            r++;
        }

        return bestLen == INT_MAX ? "" : s.substr(bestL, bestLen);
    }
};