// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> ans = new ArrayList<>();
        
        if (digits == null || digits.length() == 0) {
            return ans;
        }
        
        int len = digits.length();
        
        char[][] alphabet = new char[][] {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };
        
        StringBuilder sb = new StringBuilder();
        
        dfs(digits, len, alphabet, 0, sb, ans);
        
        return ans;
    }
    
    private void dfs(String digits, int len, char[][] alphabet, int idx, StringBuilder sb, List<String> ans) {
        if (idx == len) {
            ans.add(sb.toString());
            
            return;
        }
        
        int digit = digits.charAt(idx) - '0' - 2;
        
        for (int i = 0; i < alphabet[digit].length; i++) {
            sb.append(alphabet[digit][i]);
            dfs(digits, len, alphabet, idx + 1, sb, ans);
            sb.deleteCharAt(sb.length() - 1);
        } 
    }
}