struct comp{
bool operator()(const pair<int, string> &a, const pair<int, string> &b) const 
    { 
        if(a.first==b.first)
        {
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};

class FoodRatings {
public:
    map<string,int> f;
    map<string, set<pair<int, string>, comp>> m;
    map<string, string> d;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            f[foods[i]]=ratings[i];
            m[cuisines[i]].insert({ratings[i], foods[i]});
            d[foods[i]]=cuisines[i];
        }
 
    }
    
    void changeRating(string food, int newRating) {
        m[d[food]].erase({f[food], food});
        m[d[food]].insert({newRating, food});
        f[food]=newRating;
    }
    
    string highestRated(string cuisine) {
         return (*--m[cuisine].end()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */