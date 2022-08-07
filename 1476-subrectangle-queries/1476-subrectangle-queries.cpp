class SubrectangleQueries {
public:
    vector<vector<int>> rec;
    vector<vector<int>> update;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec=rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        update.push_back({row1,col1,row2,col2,newValue});
    }
    
    int getValue(int row, int col) {
        for(int i=update.size()-1;i>=0;i--){
            if(row>=update[i][0] and row<=update[i][2] and col>=update[i][1] and col<=update[i][3]) return update[i][4];
        }
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */