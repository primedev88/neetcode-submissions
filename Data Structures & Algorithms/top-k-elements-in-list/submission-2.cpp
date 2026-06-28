class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums) mp[i]++;

        vector<vector<int>> freq(nums.size()+1);
        for(auto& [e,c] : mp){
            freq[c].push_back(e);
        }

        vector<int> ans;
        for(int i = freq.size()-1;i>=0;i--){
            for(int j : freq[i]){
                ans.push_back(j);
                if(ans.size() == k) return ans;
            }
        }
        return ans;
    }
};
