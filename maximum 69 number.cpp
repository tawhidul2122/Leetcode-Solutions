class Solution {
public:
    int maximum69Number (int num) {
        vector<int> arr;
        while(num){
            arr.insert(arr.begin(), num%10);
            num /= 10;
        }
        
        bool converted = false;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] != 9 && !converted){
                arr[i] = 9;
                converted = true;
            }
            ans = ans * 10 + arr[i];
        }
        
        return ans;
    }
};