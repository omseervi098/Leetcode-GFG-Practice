class Solution {
public:
    string addStrings(string num1, string num2) {
        vector<int> ans(max(num1.size(),num2.size())+1,0);
        int carry=0;
        int k=max(num1.size(),num2.size());
        int i,j;
        for(i=num1.size()-1,j=num2.size()-1;i>=0 and j>=0;i--,j--){
            int sum=(num1[i]-'0')+(num2[j]-'0')+carry;
            ans[k--]=sum%10;
            carry=sum/10;
        }
        for(;i>=0;i--){
            int sum=(num1[i]-'0')+carry;
            ans[k--]=sum%10;
            carry=sum/10;
        }
        for(;j>=0;j--){
            int sum=(num2[j]-'0')+carry;
            ans[k--]=sum%10;
            carry=sum/10;
        }ans[0]=carry;
        bool check=true;
        if(carry==0)
            ans[0]=-1;
        string fans="";
        for(int i=0;i<ans.size();i++){
            if(ans[i]!=-1)
            fans+=ans[i]+'0';
        }
        return fans;
        
        
    }
};