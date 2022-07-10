class Solution {
public:
    int maxArea(vector<int>& height) {
        int gmax;
    int n=height.size();
    int st=0,end=n-1;
    gmax=0;
    while(st<end){
        gmax=max((abs(end-st))*min(height[st],height[end]),gmax);
        if(height[st]>height[end])
            end--;
        else if(height[end]>=height[st])
            st++;
    }
    return gmax;
    }
};