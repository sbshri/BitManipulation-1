// Time complexity: O(n)
// Space complexity: O(1)

/*
xor1 = Take XOR of all numbers -> this will give xor of 2 non-repeated numbers 
Take 2's complement of this and xor it to the xor1 
Now AND every number to this and whichever doesn't give 0, xor it to a new variable xor2
xor2 will be one of the numbers 
given that, we can get the other number by XORing it with another number 
*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;
        long xor1 = 0;
        // xor all numbers
        for(int n:nums) {
            xor1 = xor1 ^ n;
        }
        long temp = xor1 & (~xor1 + 1);
        long xor2 = 0;

        // xor the numbers that doesn't give 0 when ANDed with xor1 
        for(int n:nums) {
            if((temp & n) != 0)
                xor2 = xor2 ^ n;
        }
        
        return vector<int> ({(int)xor2, (int)(xor1 ^ xor2)});
    }
};