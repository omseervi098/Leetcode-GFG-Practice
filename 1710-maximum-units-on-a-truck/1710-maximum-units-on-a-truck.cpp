class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& box1, auto& box2) {return box1[1] > box2[1];});
        int totalunit=0;
        int k=0;
        while(truckSize>0 and k<boxTypes.size()){
            int temp=truckSize-boxTypes[k][0];
            if(temp<0){
                totalunit+=truckSize*boxTypes[k][1];
                truckSize=0;
            }else{
                truckSize=temp;
                totalunit+=boxTypes[k][1]*boxTypes[k][0];
            }
            k++;
        }return totalunit;
    }
};