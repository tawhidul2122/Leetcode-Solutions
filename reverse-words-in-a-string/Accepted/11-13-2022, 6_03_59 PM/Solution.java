// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
    public String reverseWords(String s) {
        String[] word = s.trim().replaceAll(" +", " ").split(" ");
        StringBuilder newString = new StringBuilder("");
        for(int i=word.length-1; i>=0; i--){
             newString.append(word[i] + " ");
        }  
        return newString.toString().trim();
    }
}