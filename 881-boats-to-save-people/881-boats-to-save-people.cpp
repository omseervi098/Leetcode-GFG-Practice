class Solution {
public:
    
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int end=people.size()-1,cnt=0,st=0;
        while(st<=end){
            if(people[st]+people[end]<=limit){
                st++;end--;
            }else
                end--;
            cnt++;
        }
        return cnt;
    }
};