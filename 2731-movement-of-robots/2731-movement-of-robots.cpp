#define ll long long int
class Solution {
    const ll mod=1e9+7;
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i=0;i<nums.size() and d!=0;i++){
            if(s[i]=='L') nums[i]=(nums[i]-d);
            else nums[i]=(nums[i]+d);
        }
        sort(nums.begin(),nums.end());
        vector<ll> dis;
        for(int i=0;i<nums.size()-1;i++){
            ll a=nums[i],b=nums[i+1],temp=a;
            a=b;b=temp;
            dis.push_back(abs((a-b)%mod));
        }
        ll sum=0,n=dis.size();
        for(ll i=0;i<n;i++)
            sum=(sum+(n-i)*(i+1)*dis[i])%mod;
        return sum;
    }
};