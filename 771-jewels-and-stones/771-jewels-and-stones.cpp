class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> map;
        for(auto it:jewels){
            map[it]+=1;
        }int cnt=0;
        for(int i=0;i<stones.size();i++){
            if(map.count(stones[i])>0){
                cnt++;
            }
        }return cnt;
    }
};