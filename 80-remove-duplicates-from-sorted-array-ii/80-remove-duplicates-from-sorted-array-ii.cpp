class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int cnt=1;
        int j=0;
        for(int i=1;i<arr.size();){
            if(arr[i]==arr[i-1]){
                cnt++;
                if(cnt==2){
                    j++;
                    arr[j]=arr[i];
                }
                i++;
            }else{
                arr[j+1]=arr[i];
                cnt=1;j++;
                i++;
            }
        }
        return j+1;
    }
};