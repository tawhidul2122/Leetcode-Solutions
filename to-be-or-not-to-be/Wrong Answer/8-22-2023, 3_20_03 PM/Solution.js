// https://leetcode.com/problems/to-be-or-not-to-be

/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    const obj= {
        toBe(otherVal) {
            if(Val==otherVal){
                return true;
            } else {
                throw new Error("Not Equal");
            }
        },
        notToBe(otherVal){
            if(val !==otherVal){
                return true;
            } else {
                throw new Error("Equal");
            }
        },
    };
    return obj;
    
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */