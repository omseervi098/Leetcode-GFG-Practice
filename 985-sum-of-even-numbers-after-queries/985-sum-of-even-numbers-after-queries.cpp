class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& n, vector<vector<int>>& q) {
        //lets track all even no at start with their indexs
        //2-1 and 4-3
        //then loop q and check if idx is already present in map if yes then change that val
        unordered_map<int,int> m;
        int inism=0;
        for(int i=0;i<n.size();i++){
            if(!(n[i]&1)){
                inism+=n[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<q.size();i++){
            int num=n[q[i][1]];
            int temp=(num+q[i][0]);
            n[q[i][1]]=temp;
            if(temp&1){    
                if(!(num&1))
                    inism-=num;
            }else {
                if(num&1){
                    inism+=temp;
                }else{
                    inism+=q[i][0];
                }
            }
            cout<<temp<<" "<<inism<<endl;
            // if(inism<=0) inism=0;
            ans.push_back(inism);
        }
        return ans;
    }
};