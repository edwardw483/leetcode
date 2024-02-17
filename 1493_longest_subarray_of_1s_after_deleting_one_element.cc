#include <vector>
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //Iterate through the array
        //If we see first zero, then note the position, ignore, and keep counting ones
        //If we see second zero, then move the position back to where the noted position was.
        //Have a "maximum" variable, which keeps track of the maximum number of 1's possible
        //If the array is filled with ones, remove any ONE element
        bool seenFirstZero = false;
        int maxOnes = 0;
        int numOnes = 0;
        int firstZeroPosition;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0 && !seenFirstZero){
                seenFirstZero = true;
                firstZeroPosition = i;
            }else if(nums[i] == 0 && seenFirstZero){
                seenFirstZero = false;
                i = firstZeroPosition;
                numOnes = 0;
            }else{
                numOnes++;
            }
            if(maxOnes < numOnes){
                maxOnes = numOnes;
            }
        }
        if(maxOnes == nums.size()){
            maxOnes--;
        }
        return maxOnes;
    }
};