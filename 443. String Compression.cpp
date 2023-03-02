class Solution {
public:
    int compress(vector<char>& chars) {
        int N = chars.size();
        int anchor = 0, write = 0;
        for(int read = 0; read < N; read++){
            if(read == N-1 || chars[read] != chars[read+1]){
                chars[write++] = chars[anchor];
                if(read > anchor){
                    int count = read - anchor + 1;
                    for(char c : to_string(count)){
                        chars[write++] = c;
                    }
                }
                anchor = read+1;
            }
        }
        return write;
    }
};
