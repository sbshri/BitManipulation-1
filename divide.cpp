// Bit manipulation
// Time complexity: O(log dividend)
// Space complexity: O(1)

/*
10/3

3 >> = 6
6 >> = 12 
12 is greater than 10, and the number of shifts we need = 1
result = result + 2^1 = 2

At the last instance, the remainder was 10-6 = 4
4 > 3
Therefore, we do the process again ie divide 4/3

Key points: 
Left shift till the number goes greater than the dividend
Once that happens, add the 2 to the power of shifts 
If at the last instance, the remainder was greater than the divisor, 
devide the remainder with the divisor


*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend != 0 && divisor == 0) return INT_MAX;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        
        long ldividend = abs((long)dividend);
        long ldivisor = abs((long)divisor);
        int result = 0;


        while(ldividend >= ldivisor) {
            int shifts = 0;
            // do this till the divisor becomes greater than the dividend
            while(ldividend >= (ldivisor<<shifts)) {
                shifts++;
            }
            // would have gone 1 extra, bring it back
            shifts--;

            // 2^ can be calculated by 1 <<
            result = result + (1<<shifts);

            // Now update the divident in any case, the outer loop will take care of the breaking condition
            ldividend = ldividend - (ldivisor<<shifts);
        }

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -result;

        return result;
    }
};