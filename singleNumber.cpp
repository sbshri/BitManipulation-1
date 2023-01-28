// Approach 1 : Bitwise XOR
// Time complexity: O(n)
// Space complexity: O(1)

/*
XOR property is 0 if the bits are same and 1 if the bits are not the same 
  11
^ 01
 ---
  10

If we add all the numbers, the number remaining at the end is the non-repeated number

*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        long result = 0;
        for(int n:nums) {
            result ^= n;
        }
        return (int)result;
    }
};

// Approach 2
// add numbers to hashset and delete if present - the number remaining is the result