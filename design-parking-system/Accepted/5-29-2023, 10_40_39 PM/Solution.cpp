// https://leetcode.com/problems/design-parking-system

class ParkingSystem {
public:
    vector<int> counts;
    
    ParkingSystem(int big, int medium, int small) {
        counts = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(counts[carType-1] > 0){
            --counts[carType-1];
            return true;
        }
        
        return false;
    }
};
/**
arTyp
/**
 *carTyy
/**
y
/**
 * You
/**

/**
 * YourYourYoYourYourY YourYourYoYourYouYourYourYoYourYou
oYourYourYoYourY
YoYourYourYoYourrYoYour
/**
YoYourYouYoYourYourYoYouoYourYouYoYourYourYoYou
YYYYoYourYouYoYourY
YYYYYYoYourYouYoYouYYYYYYoYourYouYoYou Ie
I've've
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */