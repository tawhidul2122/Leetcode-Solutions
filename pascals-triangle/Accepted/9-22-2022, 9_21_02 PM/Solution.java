// https://leetcode.com/problems/pascals-triangle

public class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            List<Integer> results = new ArrayList<>();
            for (int j = 0; j <= i; j++) {
                if (j==0){
                    results.add(1);
                }else if (j==i){
                    results.add(1);
                }else {
                    results.add(result.get(i-1).get(j-1)+result.get(i-1).get(j));
                }
            }
            result.add(results);
        }
        return result;
    }
}