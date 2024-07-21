#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
class Solution {
public:
    void print(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                std::cout << matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    void rotate(vector<vector<int>>& matrix, int i, int j) {
        int n = matrix.size();
        int cache = matrix[i][j];
        for (int k = 0; k < 4; ++k) {
            int new_j = n - i - 1;
            std::swap(matrix[j][new_j], cache);
            i = j;
            j = new_j;
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int half = static_cast<int> (matrix.size() / 2.0);
        for(int i =0; i < half; ++i) {
            for(int j =i; j < matrix.size()-i-1; ++j) {
                rotate(matrix, i, j);
            }
        }
           
    }
};


int main() {
    std::cout << "Hello" << std::endl;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution s;
    s.print(matrix);
    s.rotate(matrix);
    std::cout << std::endl;
    s.print(matrix);

    std::cout << std::endl;
    s.print(matrix2);
    s.rotate(matrix2);
    std::cout << std::endl;
    s.print(matrix2);

    return 0;
}