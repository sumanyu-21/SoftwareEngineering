/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        // F F F F T T T T (number greater than or equal to hidden number is true)
        int left  =1, right = n;//min(n, INT_MAX-1)+1;
        while(left<right)
        {
            int mid = left + (right - left)/2;
            if(guess(mid)<=0) 
            {
                right = mid;
            }
            else 
                left = mid+1;
        }
        return left;
    }
};