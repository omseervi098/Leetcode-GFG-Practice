class Solution {
public:

    int minimumSum(int num) {
        string str=to_string(num);
        sort(str.begin(),str.end());
        int ans=INT_MAX;
        int sum=stoi(str.substr(0,2))+stoi(str.substr(2,2));
        string temp1="";
        temp1+=str[0];
        temp1+=str[2];
        string temp2="";
        temp2+=str[1];
        temp2+=str[3];
        int s=stoi(temp1)+stoi(temp2);
        cout<<s<<" "<<sum<<" "<<str<<endl;
        return min(sum,s);
    }
};