// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long int st=1,end=n;
        long int ans=0;
        while(st<=end){
            long int mid=(st+end)/2;
            if(isBadVersion(mid)==false)
            {
                st=mid+1;
            }else{
                ans=mid;
                end=mid-1;
            }
        }
        return ans;
    }
};