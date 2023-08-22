// https://leetcode.com/problems/minimum-window-substring

class Solution {

public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map <char, int> map;
        for(int i = 0; i < t.length(); i++ ){
            ++map[t[i]];
        }

        int left = 0, right = 0, head = INT_MAX, len = INT_MAX, count = map.size();

        while(right < s.length()){
            char rightChar = s[right];
            if(map.find(rightChar) != map.end()){
                if(--map[rightChar] == 0) count --;
            }
            right ++;
            while(count == 0){  
                
               if(right - left < len){
                    head = left;
                    len = right - left;
                }

                
                char leftChar = s[left];
                if (map.find(leftChar)!= map.end()){
                    if(++map[leftChar] > 0){
                        count++;
                    }
                }       
                left ++;
            }
        }

        if(len == INT_MAX) return "";
        return s.substr(head, len);
    }
};