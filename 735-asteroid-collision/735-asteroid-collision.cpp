class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(!s.empty() and asteroids[i]<0 and  s.top()>0){
                while(s.size()>0 and abs(asteroids[i])>s.top() and s.top()>0) s.pop();
                cout<<"size id"<<s.size()<<endl;
                if(s.size() and abs(asteroids[i])==s.top()){
                    s.pop();
                }else if(s.size()==0 || abs(asteroids[i])>s.top() and s.top()<0){
                     s.push(asteroids[i]);
                }
            }else{
                s.push(asteroids[i]);
            }
        }
        n=s.size();
        vector<int> v(n,0);
        n=n-1;
        while(s.size()){
            v[n--]=s.top();
            s.pop();
        }  return v;     
    }
};