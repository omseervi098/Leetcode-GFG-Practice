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
                if(limitleft==0)
                    cnt++;
                else if(limitleft>0){
                    //Binary Search to get max element which is less than limitleft
                    int val=binarysearch(people,i+1,limitleft);
                    if(val!=-1){
                        people[val]=INT_MAX; //change val to mark person visited
                        cnt++;
                    }else
                        cnt++; //if we get no pair then take single person on boat
                }
            }
        }
        return cnt;
    }
};