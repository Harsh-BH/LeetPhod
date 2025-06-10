class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int,int>> arr;
        for(int i=0;i<x.size();i++){
            arr.push_back({y[i],x[i]});
        }

        sort(arr.begin(),arr.end(),greater<pair<int,int>>());
        int sum = 0;
        unordered_set<int> temp;
        int count = 0;
         for(int i=0;i<arr.size();i++){
            if(count<3){
                if(!temp.count(arr[i].second)){
                    sum+=arr[i].first;
                    temp.insert(arr[i].second);
                    count++;
                }
            }
        }

        return (count==3)?sum:-1;
    }
};