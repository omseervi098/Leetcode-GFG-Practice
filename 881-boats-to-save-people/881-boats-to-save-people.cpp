class Solution {
public:
    int binarysearch(vector<int> &people,int st,int limit){
        int end=people.size()-1,mx=-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(people[mid]<=limit){
                mx=mid;
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return mx;
    }
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int cnt=0;
        for(int i=0;i<people.size();i++){
            if(people[i]!=INT_MAX){
                int limitleft=limit-people[i];
                if(limitleft==0){
                    cnt++;
                    continue;
                }else if(limitleft<0){
                    continue;
                }
                //bINARY Search to get max element which is less than limitleft
                int val=binarysearch(people,i+1,limitleft);
               
                if(val!=-1){
                    cout<<people[val]<<endl;
                    people[val]=INT_MAX;
                    cnt++;
                }else{
                    cnt++;
                }
            }
            
        }
        return cnt;
    }
};