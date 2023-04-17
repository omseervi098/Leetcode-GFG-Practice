class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       
        int n=candies.size();
         vector<bool> a(n);
        int maxno=candies[0];
        for(int i=0;i<n;i++)
        {
            if(candies[i]>maxno)
            {
                maxno=candies[i];
            }
        }
        for(int i=0;i<n;i++)
        {
            if((candies[i]+extraCandies)>=maxno)
            {
                a[i]=true;
            }
            else
            {
                a[i]=false;
            }
        }
        return a;
    }
};