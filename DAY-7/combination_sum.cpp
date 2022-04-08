class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    void func(vector<int>& candidates, int target, int idx){
        if(target == 0)ans.push_back(temp);
        if(target<0)return;
        for(int i = idx; i<candidates.size();i++){
            if(target-candidates[i]>=0){
                temp.push_back(candidates[i]);
                func(candidates, target-candidates[i], i);
                temp.pop_back();
                
            }
                
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        func(candidates, target, 0);
        return ans;
    }
};