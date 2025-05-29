class Solution {

public:
vector<string> ans;
    void rec(int n,int open , int close,string current){
        if(current.length()==2*n){
            ans.push_back(current);
            return;
        }
        //cache check

        // compute
        if(open<n){
            rec(n,open+1,close,current +'(');
        }
        if(close<open){
            rec(n,open,close+1,current + ')');
        }


        //return and sum
    }
    vector<string> generateParenthesis(int n) {
        rec(n,0,0,"");
        return ans;
    }
};