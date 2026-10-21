class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) {
            return "";
        }

        // Using direct arrays instead of unordered_map for O(1) lookups and speed
        vector<int> tfc(128, 0);
        vector<int> sfc(128, 0);

        int required = 0;
        for (char c : t) {
            if (tfc[c] == 0) required++;
            tfc[c]++;
        }

        int l = 0;
        int match = 0;
        int min_len = INT_MAX;
        int start_idx = 0;

        for (int r = 0; r < s.size(); r++) {
            char right_char = s[r];
            if (tfc[right_char] > 0) {
                sfc[right_char]++;
                if (sfc[right_char] == tfc[right_char]) {
                    match++;
                }
            }

            while (match == required) {
                // Update best window indices
                if (r - l + 1 < min_len) {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                char left_char = s[l];
                if (tfc[left_char] > 0) {
                    if (sfc[left_char] == tfc[left_char]) {
                        match--;
                    }
                    sfc[left_char]--;
                }
                l++;
            }
        }

        return min_len == INT_MAX ? "" : s.substr(start_idx, min_len);
    }
};