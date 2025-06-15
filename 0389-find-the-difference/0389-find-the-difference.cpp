class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char ,int> mpp;
        for(auto ch:s){
            mpp[ch]++;
        }

        for(auto ch:t){
            mpp[ch]--;
        }
        char ans;
        for(auto ch:mpp){
            if(mpp[ch.first]){
                ans = ch.first;
            }
        }

        return ans;

    }
};