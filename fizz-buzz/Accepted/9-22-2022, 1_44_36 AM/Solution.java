// https://leetcode.com/problems/fizz-buzz

class Solution {
    public List<String> fizzBuzz(int n) {
        
        List<String> newArray= new ArrayList<> (n);
        
        for(int i=1;i<=n;i++){
            boolean by3= i%3==0;
            boolean by5= i%5==0;
            if( (by3) && (by5)){
                newArray.add("FizzBuzz");
                
            }else if(by5){
                newArray.add("Buzz");
            }else if(by3){
                newArray.add("Fizz");
            }else newArray.add(String.valueOf(i));
        }
        
        return newArray;
        
    }
}