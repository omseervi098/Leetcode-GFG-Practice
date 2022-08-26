class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long long int arr[30]={0};
        for(int i=0;i<30;i++){
            arr[i]=pow(2,i);
            //cout<<arr[i]<<" ";
            
        }
        bool ans=false;
        for(int i=0;i<30;i++){
            int temp=arr[i];
            
            unordered_map<int,int> freqof2;
            while(temp>0){
                int rem=temp%10;
                freqof2[rem]+=1;
                temp/=10;
            }
            unordered_map<int,int> freq;
            temp=n;
            while(temp>0){
                int rem=temp%10;
                freq[rem]+=1;
                temp/=10;
            }
            int j=0;
            bool flag=false;
            for( j=0;j<=9;j++){
               
                if( freq[j]==freqof2[j]){
                   flag=true;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag==true)
                return true;
        }
        return false;
    }
};