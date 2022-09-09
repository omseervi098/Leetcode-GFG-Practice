class Solution {
public:
    static bool comp(pair<string,int> &p1,pair<string,int> &p2){
        return p1.second>p2.second;
    }
    string intToRoman(int num) {
        vector<pair<string,int>> v;
        v.push_back({"I",1});
        v.push_back({"V",5});
        v.push_back({"X",10});
        v.push_back({"L",50});
        v.push_back({"C",100});
        v.push_back({"D",500});
        v.push_back({"M",1000});
        v.push_back({"CM",900});
        v.push_back({"XC",90});
        v.push_back({"CD",400});
        v.push_back({"XL",40});
        v.push_back({"IX",9});
        v.push_back({"IV",4});
        sort(v.begin(),v.end(),comp);

        int temp=num;
        string ans="";
       
            for(auto it:v){
                while(temp>=it.second){
                
                    temp-=it.second;
                    ans+=it.first;
                    cout<<it.second<<" ";
                
                }
            }
        
        return ans;
    }
};