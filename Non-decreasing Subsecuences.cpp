class Solution {
public:
    void solve(int prev,set<vector<int>> &ans,vector<int> temp,int i,vector<int> nums){
        if(i>=nums.size()){
            if(temp.size()>=2){
                ans.insert(temp);
            }
            return;
        }
        if(prev==-1 || nums[i]>=nums[prev]){
            temp.push_back(nums[i]);
            solve(i,ans,temp,i+1,nums);
            temp.pop_back();
        }

        solve(prev,ans,temp,i+1,nums);
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(-1,st,temp,0,nums);
        for(auto it=st.begin();it!=st.end();it++){
            ans.push_back(*it);
        }
        return ans;
    }
};