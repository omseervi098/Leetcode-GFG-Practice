class NumArray {
    vector<int> v;
    vector<int> arr;
    int n;
    int build(vector<int> &arr,vector<int> &v,int st,int end,int curr){
        if(st==end){
            v[curr]=arr[st];
            return v[curr];
        }
        int mid=st+(end-st)/2.0;
        int left=build(arr,v,st,mid,2*curr+1);
        int right=build(arr,v,mid+1,end,2*curr+2);
        return v[curr]=left+right;
    }
    int update(vector<int> &v,int st,int end,int curr,int idx,int val){
        if(st==end){
            v[curr]=val;
            return v[curr];
        }else{
            int mid=st+(end-st)/2.0;
            int left=0,right=0;
            if(idx>=st and idx<=mid)
                left=update(v,st,mid,2*curr+1,idx,val);
            else
                right=update(v,mid+1,end,2*curr+2,idx,val);
            return v[curr]=v[2*curr+1]+v[2*curr+2];
        }
    }
    int query(vector<int> &v,int st,int end,int l,int r,int curr){
        if(l<=st and r>=end) return v[curr];
        if((l<st and r<st) || (l>end and r>end)) return 0;
        int mid=st+(end-st)/2.0;
        int left=query(v,st,mid,l,r,2*curr+1);
        int right=query(v,mid+1,end,l,r,2*curr+2);
        return left+right;
    }
public:
    NumArray(vector<int>& nums) {
        int n=nums.size();
        v.resize(4*n,0);
        for(auto i:nums) arr.push_back(i);
        this->n=n;
        int ans=build(arr,v,0,n-1,0);
        cout<<ans<<endl;
    }
    
    void update(int index, int val) {
        int ans=update(v,0,n-1,0,index,val);
        cout<<ans<<endl;
    }
    
    int sumRange(int l, int r) {
        int ans= query(v,0,n-1,l,r,0);
        cout<<ans<<endl;
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */