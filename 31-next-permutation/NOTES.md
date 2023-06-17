class Solution {
vector<vector<int>> all;
void generatePermuatation(int st,int n,vector<int> &v,vector<bool> &visited){
if(st==n){
all.push_back(v);
return;
}
for(int i=st;i<=n;i++){
// if (visited[i])
// continue;
// if (i > 0 and v[i] == v[i - 1] and !visited[i - 1])
// continue;
swap(v[st],v[i]);
generatePermuatation(st+1,n,v,visited);
swap(v[st],v[i]);
}
}
public:
void nextPermutation(vector<int>& nums) {
vector<int> v=nums;
sort(nums.begin(),nums.end());
vector<bool> visited(nums.size(), false);
generatePermuatation(0,nums.size()-1,nums,visited);
sort(all.begin(),all.end());
int n=all.size(),idx=-1;
for(int i=0;i<n;i++){
if(all[i]==v){
idx=i;
break;
}
}
for(auto &i:all){
for(auto j:i){
cout<<j<<" ";
}cout<<endl;
}cout<<endl;
cout<<idx<<" ";
nums=all[(idx+1)%(n)];
}
};