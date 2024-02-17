#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        //Perform two passes
        //One for the max number of candies O(n)
        int max = 0;
        for(int i : candies){
            if(i > max){
                max = i;
            }
        }
        //Create the array, setting false if extraCandies + candies[i] < max
        vector<bool> result;
        for(int i: candies){
            result.push_back((i + extraCandies) >= max);
        } 
        return result;
    }
};