class NumArray {
    private:
    int getSumutil(int* st,int s,int e,int l,int r,int curr){
        if(l<=s and r>=e)
            return st[curr];
        if(l>e||r<s)
            return 0;
        int mid=(s+(e-s)/2);
        return getSumutil(st,s,mid,l,r,2*curr+1)+getSumutil(st,mid+1,e,l,r,2*curr+2);
        
    }
    int getSum(int *st,int l,int r,int n){
        if(l<0||r>n-1||l>r)
            return -1;
        return getSumutil(st,0,n-1,l,r,0);
    }
    void updatevalutil(int *st,int s,int e,int i,int diff,int curr){
        if(i<s||i>e)return;
        st[curr]=st[curr]+diff;
        if(s!=e){
            int mid=(s+(e-s)/2);
            updatevalutil(st,s,mid,i,diff,2*curr+1);
            updatevalutil(st,mid+1,e,i,diff,2*curr+2);
        }
    }
    void updateval(vector<int> &arr,int *st,int n,int i,int new_val){
        if(i<0 ||i>n-1)return;
        int diff=new_val-arr[i];
        arr[i]=new_val;
        updatevalutil(st,0,n-1,i,diff,0);
    }
    int constructsegment(vector<int> &arr,int s,int end,int * st,int si){
        if(s==end)
        {
            st[si]=arr[s];
            return arr[s];
        }
        int mid=(s+(end-s)/2);
        st[si]=constructsegment(arr,s,mid,st,si*2+1)+constructsegment(arr,mid+1,end,st,si*2+2);
        return st[si];
    }
    int* constructst(vector<int> &arr,int n){
        int x=(int)(ceil(log2(n)));
        int max_size=2*(int)pow(2,x)-1;
        int *st=new int[max_size];
        constructsegment(arr,0,n-1,st,0);
        return st;
    }
   public:
    int *v;
    vector<int> num;
    int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        v=constructst(nums,n);
        for(auto it:nums)
            num.push_back(it);
    }
    
    void update(int index, int val) {
        updateval(num,v,n,index,val);
    }
    
    int sumRange(int left, int right) {
        return getSum(v,left,right,n);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */