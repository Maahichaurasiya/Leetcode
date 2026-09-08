class Solution {
public:
    static bool compare(pair<char, int> a, pair<char, int> b) {
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        // count frequency
        for (char ch : s) {
            mp[ch]++;
        }
        // store frequency and character array
        vector<pair<char, int>> v;
        for (auto x : mp) {
            v.push_back(x);
        }
        // sort on basis of frequency
        sort(v.begin(), v.end(), compare);

        // build ans
        string ans;
        for (auto x : v) {
            for (int i = 0; i < x.second; i++) {
                ans += x.first;
            }
        }

        return ans;
    }
};