class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(auto it:s){
            temp+=to_string((it-'a'+1));
        }int sum=0;
        cout<<temp<<endl;
        for(int i=0;i<k;i++){
            
            sum=0;
            for(auto it:temp){
                sum+=(int)(it-'0');
            }
            temp=to_string(sum);
            
        }
        return stoi(temp);
    }
};