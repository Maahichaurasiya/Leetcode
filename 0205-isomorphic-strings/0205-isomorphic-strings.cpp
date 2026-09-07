class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        for (int i = 0; i < s.size(); i++) {
            // check mapping s->t
            if (mp1.count(s[i])) {
                if (mp1[s[i]] != t[i]) {
                    return false;
                }
            }
            // check mapping t->s
            if (mp2.count(t[i])) {
                if (mp2[t[i]] != s[i]) {
                    return false;
                }
            }
            // create mapping
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};