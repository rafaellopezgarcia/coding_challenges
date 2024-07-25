#include <iostream>
#include <vector>
#include <unordered_map>

template <typename T>
using vector = std::vector<T>;

class Solution {
public:
    int rob(vector<int>& nums, int ix, std::unordered_map<int, int>& partial_sol) {
        if (ix >= nums.size()) {
            return 0;
        }

        if (partial_sol.find(ix) != partial_sol.cend()) {
            return partial_sol[ix];
        }

        int a_route = nums[ix] + rob(nums, ix + 2, partial_sol);
        int b_route = ix+1 >= nums.size() ? 0 :nums[ix+1] + rob(nums, ix + 3, partial_sol);
        partial_sol[ix] = std::max(a_route, b_route);;
        return partial_sol[ix];
    }
    int rob(vector<int>& nums) {
        std::unordered_map<int, int> partial_sol;
        partial_sol.clear();
        return std::max(rob(nums, 0, partial_sol), rob(nums, 1, partial_sol));
    }
    int rob_dp(vector<int>& nums) {
        vector<int> dp_table(nums.size()+1, 0);
        int ix = dp_table.size()-2;
        dp_table[ix] = nums[nums.size()-1];
        --ix;
        for (; ix >=0; --ix) {
            dp_table[ix] = std::max(nums[ix]+dp_table[ix+2], dp_table[ix+1]);
        }
        return dp_table[0];
    }
};

int main() {
    std::vector houses = {1,2,3,1};
    std::vector houses2 = {2,7,9,3,1};
    std::vector houses3 = {2};
    std::vector houses4 = {1,1,1,1,1,1,1,1,1,1};
    std::vector houses5 = {2,7,7,7,4};
    std::vector houses6 = {6,3,10,8,2,10,3,5,10,5,3};
    Solution sol;
    //sol.rob(houses) ;
    std::cout << sol.rob(houses) << std::endl;
    std::cout << sol.rob(houses2) << std::endl;
    std::cout << sol.rob(houses3) << std::endl;
    std::cout << sol.rob(houses4) << std::endl;
    std::cout << sol.rob(houses5) << std::endl;
    std::cout << sol.rob(houses6) << std::endl;

    std::cout << std::endl;
    std::cout << sol.rob_dp(houses) << std::endl;
    std::cout << sol.rob_dp(houses2) << std::endl;
    std::cout << sol.rob_dp(houses3) << std::endl;
    std::cout << sol.rob_dp(houses4) << std::endl;
    std::cout << sol.rob_dp(houses5) << std::endl;
    std::cout << sol.rob_dp(houses6) << std::endl;


    return 0;
}

//