class ParkingSystem {
public:
    int big,medium,small;//1 2 3
    
    ParkingSystem(int big, int medium, int small) {
        this->big=big;
        this->medium=medium;
        this->small=small;
    }
    
    bool addCar(int carType) {
        if(carType==1){
            big-=1;
            if(big<0)
                return false;
        }else if(carType==2){
            medium-=1;
            if(medium<0)
                return false;
        }else if(carType==3){
            small-=1;
            if(small<0)
                return false;
        }return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */