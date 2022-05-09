//Problem no 119
//My solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> v(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            for(int j=0;j<=i;j++){
                v[i].push_back(0);
            }
        }
        for(int i=0;i<rowIndex+1;i++){
            for(int j=0;j<=i;j++){
                if(j==0||i==j)
                {
                    v[i][j]=1;
                }
            }
        }
        for(int i=2;i<rowIndex+1;i++){
            for(int j=1;j<i;j++){
                v[i][j]=v[i-1][j-1]+v[i-1][j];
            }
        }vector<int>ans;
         for(int i=0;i<rowIndex+1;i++){
            if(i==rowIndex){
                for(int j=0;j<=i;j++){
                    ans.push_back(v[i][j]);
                }
            }
        }
        return ans;
        
    }
};
//Way more better solution then mine
//will uplaud later 