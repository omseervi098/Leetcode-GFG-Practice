class Solution {
public:
    bool winnerOfGame(string c) {
        int sm1=0,sm2=0;
        for(int i=0;i<c.size();){
            int j=i;
            while(i<c.size() and c[i]==c[j]) i++;
            if(c[j]=='A') sm1+=max(i-j-2,0);
            else sm2+=max(i-j-2,0);
        }
        return sm2>=sm1?false:true;
    }
};