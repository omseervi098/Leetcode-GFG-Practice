class Solution {
public:
    unordered_map<string,string> s;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string alpha="qwertyuioplkjhgfdsazxcvbnm1234567890";
        string base="https::/tinyurl.com/",ans="";
        srand(time(0));
        for(int i=0;i<6;i++){
            ans+=alpha[rand()%36];
        }
        s[ans+base]=longUrl;
        return ans+base;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
       return s[shortUrl]; 
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));