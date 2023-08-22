// https://leetcode.com/problems/basic-calculator

//credit to Amit Kumar aka  goodchai0

class Solution {
public:
    int calculate(string s) {
        
        stack<pair<int,int>>st; //sum,sign;
        long long int sum=0;
        
        int sign=1;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            
            // since its a string.
            //-111+10
            //
            if(isdigit(ch))
            {
                long long int num=0;
                while(i<s.size() && isdigit(s[i]))
                {
                    num=(num*10)+s[i]-'0';//'0' to convert it into int;
                    i++;
                }
                i--; // because of while loop;
                sum+=(num*sign);
                sign=1;
            }
            else if(ch=='(')
            {
                st.push(make_pair(sum,sign));//pushing the current sum with sign
                sum=0;
                sign=1;
            }
            else if(ch==')')
            {
                sum=st.top().first + (st.top().second*sum);
                st.pop();
            }
            else if(ch=='-')
            {
                sign=(-1*sign);
            }
        }
        return sum;
    }
};
