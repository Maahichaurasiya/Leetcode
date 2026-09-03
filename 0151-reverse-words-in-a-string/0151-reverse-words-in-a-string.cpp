/*

Algorithm - Brute Force:

1. Create an empty vector<string> to store all words.
2. Create an empty string "word".
3. Traverse the string character by character.
4. If current character is not a space, add it to "word".
5. If current character is a space:
   - If "word" is not empty, store it in the vector.
   - Make "word" empty for the next word.
6. After the loop, store the last word if "word" is not empty.
7. Traverse the vector from last index to first index.
8. Add each word to the answer with a single space.
9. Return the answer.

Example:
"  hello   world  "
        ↓
["hello", "world"]
        ↓
"world hello"

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (word != "") {
                    words.push_back(word);
                    word = "";
                }
            }
        }
        if (word != "") {
            words.push_back(word);
        }

        string ans = "";

        for (int i = words.size() - 1; i >= 0; i--) {
            ans += words[i];
            if (i != 0) {
                ans += ' ';
            }
        }
        return ans;
    }
};