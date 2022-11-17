class MedianFinder {
    priority_queue<int> mx;
    priority_queue<int,vector<int>,greater<int>>mn;
    public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx.empty()){
            mx.push(num);
            return;
        }
        if(num<mx.top())
            mx.push(num);
        else mn.push(num);
        int temp=mx.size()-mn.size();
        if(temp>1){
            mn.push(mx.top());
            mx.pop();
        }else if(temp<-1){
            mx.push(mn.top());
            mn.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()-mn.size()==0) return (mx.top()+mn.top())/2.0;
        if(mx.size()>mn.size()) return mx.top();
        else return mn.top();
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        MedianFinder *f=new MedianFinder();
        for(auto it:nums1){
            f->addNum(it);
        }
        for(auto it:nums2) f->addNum(it);
        return f->findMedian();
    }
};