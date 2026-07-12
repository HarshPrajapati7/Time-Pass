class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> copy=arr;
        sort(copy.begin(),copy.end());

        unordered_map<int, int> rankMap;
        int rank = 0;

        for(int x:copy){
            if(rankMap.find(x)== rankMap.end()){
                rank++;
                rankMap[x]=rank;
            }
        }

        vector<int> ans;
        for(int x :arr){
            ans.push_back(rankMap[x]);
        }
        return ans;
        
    }
};