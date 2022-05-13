//problem no 189
class Solution {
public:
    void rotate(vector<int>& a, int k) {
        if(a.size()==1||a.size()==0||k==0||k==a.size())
            return;
        if(k>a.size())
            k=k%a.size();
        reverse(a.begin(), a.end());
        reverse(a.begin(),a.end()-(a.size()-k));
        reverse(a.begin()+k,a.end());
    }
};