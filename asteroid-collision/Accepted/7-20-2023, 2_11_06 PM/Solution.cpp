// https://leetcode.com/problems/asteroid-collision

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        
        for(int& cur : asteroids){
            bool exploded = false;
            while(!stk.empty() && stk.top() > 0 && cur < 0){
                int prev = stk.top();
                if(abs(prev) > abs(cur)){
                    //do nothing
                    exploded = true;
                    break;
                }else if(abs(prev) == abs(cur)){
                    stk.pop();
                    exploded = true;
                    break;
                }else{
                    //abs(prev) < abs(cur)
                    stk.pop();
                    //cur keeps going left
                }
            }

            if(!exploded){
                stk.push(cur);
            }
        }

        asteroids.clear();

        while(!stk.empty()){
            asteroids.insert(asteroids.begin(), stk.top());
            stk.pop();
        }
        
        return asteroids;
    }
};
