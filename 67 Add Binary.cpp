class Solution {
public:
    string addBinary(string s1, string s2) {
        int n = s1.length();   
        int m = s2.length();
        
        int i= n-1;
        int j = m-1;
        int carry = 0;
        string  s = "";
        while(i>=0 || j>=0 || carry)
        {
            int a,b;
            if(i>=0)
            {
                a = s1[i]-'0';
                i--;
            }
            else{
                a = 0;
            }
            
            if(j>=0)
            {
                b = s2[j]-'0';
                j--;
            }
            else{
                b = 0;
            }
            
            int sum = a+b+carry;
            s += (sum%2)+'0';
            carry = (sum/2);
        }
        reverse(s.begin(), s.end());
        return s;
        
    }
};