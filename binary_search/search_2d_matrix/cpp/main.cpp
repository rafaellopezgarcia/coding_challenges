#include <iostream>
#include <vector>
#include <math.h>
template <typename T>
using vector = std::vector<T>;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t ncells = matrix.size() * matrix[0].size();
        size_t half = ncells / 2; 
        size_t left = 0, right = ncells;
        auto get_value = [&m =matrix](int ix) {return m[ix / m[0].size()][ix % m[0].size()];};
    
        while (left < right) {
            half = (right - left) / 2 + left;
            if (get_value(half) == target) {
                return true;
            }
            if (target > get_value(half)) {
                left = half + 1;
            }
            else {
                right = half;
            }   
            
        }
        return false;
    }

};

int main() {   
    std::cout << "search 2d matrix" << std::endl;
    std::vector<int> values = {1};
    std::vector<int> values2 = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> matrix = {{1}};

    Solution s;

    std::cout << s.searchMatrix(matrix, 2) << std::endl;
    return 0;
}