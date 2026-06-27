class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.size()!= t.size()) return false;
        unordered_map<int,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<t.size();i++){
            if(mp[t[i]-'a']==0) return false;
            mp[t[i]-'a']--;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> vis(strs.size(),0);
        vector<vector<string>> ans;

        for(int i=0;i<strs.size();i++){
            vector<string> sub;
            if(vis[i]==0){
                sub.push_back(strs[i]);
                vis[i]=1;
                for(int j=i+1;j<strs.size();j++){
                    if(vis[j]==0 && isAnagram(strs[i],strs[j])){
                        vis[j]=1;
                        sub.push_back(strs[j]);
                    }
                }
                ans.push_back(sub);
            }
        }
        return ans;
    }
};
