class Solution {
public:
    vector<vector<string>> ans;

    bool checkP(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i <= j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    void rec(int level, vector<string>& curr, string& s) {
        if (level == s.length()) {
            ans.push_back(curr);
            return;
        }

        for (int i = level; i < s.length(); i++) {
            string temp = s.substr(level, i - level + 1);
            if (checkP(temp)) {
                curr.push_back(temp);
                rec(i + 1, curr, s);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        rec(0, curr, s);
        return ans;
    }
};
