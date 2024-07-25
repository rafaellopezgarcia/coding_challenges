#include <iostream>
#include <vector>
#include <queue>

template <typename T>
using vector = std::vector<T>;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

        for (auto n : nums) {
            pq.push(n);
            if (pq.size() > k) {
                pq.pop();
            }
        }
  
        return pq.top();

    }
};


int main() {
    std::cout << "Kth largest element in array" << std::endl;
    Solution s;
    vector<int> nums {3,2,1,5,6,4};
    std::cout << s.findKthLargest(nums, 2) << std::endl;
    return 0;
}