class Solution {
public:
    bool winnerOfGame(string c) {
        vector<int> cnta,cntb;
        for(int i=0;i<c.size();){
            int j=i;
            while(i<c.size() and c[i]==c[j]){
                i++;
            }
            if(c[j]=='A') cnta.push_back(i-j);
            else cntb.push_back(i-j);
        }
        int sm1=0,sm2=0;
        for(auto i:cnta) sm1+=max(i-2,0);
        for(auto i:cntb) sm2+=max(i-2,0);
        if(sm2>=sm1) return false;
        return true;
    }
};