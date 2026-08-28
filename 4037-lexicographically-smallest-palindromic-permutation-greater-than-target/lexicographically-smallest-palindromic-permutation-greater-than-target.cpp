class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length(), m = n / 2;
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > n % 2) return "";

        vector<int> avail(26, 0);
        for (int i = 0; i < 26; ++i) avail[i] = cnt[i] / 2;

        auto make_pal = [&](string prefix, vector<int> rem) {
            for (int i = 0; i < 26; ++i) prefix.append(rem[i], 'a' + i);
            string rev = prefix;
            if (n % 2) prefix += mid;
            reverse(rev.begin(), rev.end());
            return prefix + rev;
        };

        string ans = "";
        auto update = [&](const string& cand) {
            if (cand > target && (ans.empty() || cand < ans)) ans = cand;
        };

        string pref = "";
        update(make_pal(pref, avail));

        for (int i = 0; i < m; ++i) {
            for (int c = target[i] - 'a' + 1; c < 26; ++c) {
                if (avail[c]) {
                    avail[c]--;
                    update(make_pal(pref + char('a' + c), avail));
                    avail[c]++;
                }
            }

            int t_idx = target[i] - 'a';
            if (!avail[t_idx]) break;
            pref += target[i];
            avail[t_idx]--;
        }

        if (pref.size() == m) {
            update(make_pal(pref, avail));
        }

        return ans;
    }
};