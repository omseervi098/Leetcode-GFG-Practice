class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int freq[26]={0};
        for(int i=0;i<words2.size();i++){
            int freq1[26]={0};
            for(auto it:words2[i]){
                freq1[it-'a']+=1;
            }
            for(int i=0;i<26;i++)
                freq[i]=max(freq1[i],freq[i]);
        }
        vector<string> ans;
        for(auto it:words1){
            string temp=it;
            int cnt=0,i=0;
            int tmp[26]={0};
            for(i=0;i<temp.size();i++){
                tmp[temp[i]-'a']+=1;
            }
            for(i=0;i<26;i++){
    
               if(freq[i]>tmp[i]) break;
            }
            if(i==26){
                ans.push_back(it);
            }
        }
        return ans;
    }
};