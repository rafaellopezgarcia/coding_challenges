#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>
#include <map>


template<typename T>
using vector = std::vector<T>;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int h_index = 0;
        std::map<int, int> papers_citations; // number of citations | number of papers

        for (auto citation : citations) {
            auto it = papers_citations.find(citation);
            if (it != papers_citations.end()) {
                papers_citations[citation] += 1;
            }
            else{
                papers_citations.insert(std::make_pair(citation, 1));
            }
        }
        int npapers = 0;
        for (auto it = papers_citations.rbegin(); it!= papers_citations.rend(); ++it) {
            npapers += it->second;
            h_index = std::max(h_index, std::min(npapers, it->first));
            if (h_index > it->first) {
                break;
            }
        }
        return h_index;
    }

    int hIndex2(vector<int>& citations) {
        int h_index = 0;
        std::vector<int> papers_with_n_citations(citations.size()+1, 0);
        for (int citation : citations){
            citation = std::min(citation, static_cast<int>(papers_with_n_citations.size() -1));
            papers_with_n_citations[citation]++;
        }
        int n_papers = 0;
        for (int ix = papers_with_n_citations.size() -1; ix >h_index; --ix) {
            n_papers += papers_with_n_citations[ix];
            h_index = std::max(h_index, std::min(n_papers, ix));
        }
        return h_index;
    }
};


int main() {
    std::cout << "h index coding challenge" << std::endl;
    std::vector citations = {1,3,1};
    std::vector citations2 = {1};
    std::vector citations3 = {4,4,0,0};
    std::vector citations4 = {500};
    Solution sol;
    //sol.hIndex(citations);
    //sol.hIndex(citations2);
    std::cout << sol.hIndex2(citations3) << std::endl;
    std::cout << std::endl;
    std::cout << sol.hIndex2(citations4) << std::endl;
    return 0;
}

// 0, 1, 3, 5, 6
// 6 papers with at least 0 citations
// 5 papers with at least 1 citation - index = 1
// 3 papers with at least 3 citations - index = 3
// 2 papers with at least 5 citations - index = 2
// 1 paper with at least 6 citations - index = 1 

// 0, 1, 3, 5, 6, 7
// 6 papers with at least 0 citations
// 5 papers with at least 1 citation - index = 1
// 4 papers with at least 3 citations - index = 3
// 3 papers with at least 5 citations - index = 3
// 2 papers with at least 6 citations - index = 2
// 1 paper with at least 7 citations - index = 1

// 0 citations = 10
// 1 citations = 20 1
// 4 citations = 10
// 6 citations = 4
// 7 citations = 1

// Start from the last

// 7  citations =
//
//Number of papers with 7 citations is 1
//Number of papers with at least 6 citation is 1+4
//Number of papers with at least 5 citation is 5