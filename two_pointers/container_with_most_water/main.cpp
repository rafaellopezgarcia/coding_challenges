#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int out = 0, left = 0, right = height.size() - 1;
        while (left < right) {
            int area = std::min(height[left], height[right]) * (right - left);
            out = std::max(out, area);
            if (height[left] < height[right]) {
                ++left;
            }
            else {
                --right;
            }
        }
        return out;        
    }
};

int main() {
    std::cout << "container with most water" << std::endl;
    std::vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution s;
    std::cout << s.maxArea(height) << std::endl;

    return 0;
}