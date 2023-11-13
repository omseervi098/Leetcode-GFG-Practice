class Solution {
public:
    string sortVowels(string s) {
        // doing it in O(N)
        vector<int> freq(52,0);
        vector<char> v={'A','E','I','O','U','a','e','i','o','u'};
        for(auto it:s){
            if(find(v.begin(),v.end(),it)!=v.end()){
                if(it>='A' and it<='Z') freq[it-'A']++;
                else freq[it-'a'+26]++;
            }
        }
        int k=0;
        for(auto &i:s){
            if(find(v.begin(),v.end(),i)!=v.end()){
                while(freq[v[k]>='A' and v[k]<='Z'?(v[k]-'A'):(v[k]-'a'+26)]<=0 and k<10) k++;
                bool check=v[k]>='A' and v[k]<='Z';
                if(freq[check==true?(v[k]-'A'):(v[k]-'a'+26)]>1){
                    i=v[k];
                    freq[check==true?(v[k]-'A'):(v[k]-'a'+26)]--;
                }else{
                    i=v[k];
                    freq[check==true?(v[k++]-'A'):(v[k++]-'a'+26)]--;
                }
            }
        }
        return s;
        
    }
};