class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idxof0=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){idxof0=i;break;}
        }cout<<idxof0<<endl;
        if(idxof0==-1){
            vector<int>num(nums.begin(),nums.end());
            for(auto &it:num)it*=it;
            reverse(num.begin(),num.end());return num;
        }
        vector<int> ans(nums.begin(),nums.begin()+idxof0);
        reverse(ans.begin(),ans.end());
        vector<int>num(nums.begin()+idxof0,nums.end());
        for(auto &it:ans)
            it=it*it;
        for(auto &it:num)
            it=it*it;
        for(auto it:ans){
            cout<<it<<" "; 
        }
        vector<int> fans;
        int i=0,j=0;
        int m=ans.size(),n=num.size();
        while(i<m and j<n){
            if(ans[i]<num[j]){
                fans.push_back(ans[i]);
                i++;
            }else {
                fans.push_back(num[j]);
                j++;
            }
        }
        while(i<m){
            fans.push_back(ans[i]);
            i++;
        }
        while(j<n){
            fans.push_back(num[j]);
            j++;
        }
    
        return fans;
    }
};