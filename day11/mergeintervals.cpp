/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/

#include <iostream>
#include <vector>

void merge(std::vector<std::vector<int>>& intervals, std::vector<std::vector<int>> &merged) {
   for(size_t i = 0, j = 0; i < intervals.size(); i++, j++) {
        merged.push_back(std::vector<int>());
        merged[j].push_back(intervals[i].front());
        
        if((i + 1) < intervals.size() && intervals[i].back() >= intervals[i + 1].front()){
            merged[j].push_back(intervals[++i].back());
        }
        else {
            merged[j].push_back(intervals[i].back());
        }
    } 
}

template <size_t rowsM, size_t colsM, size_t rowsI, size_t colsI>
void mergeF(int (&merged)[rowsM][colsM], int (&intervals)[rowsI][colsI]) {
    
    for(size_t i = 0, j = 0; i < rowsI; i++, j++) {
        merged[j][0] = intervals[i][0];

        if((i + 1) < rowsI && intervals[i][1] >= intervals[i+1][0]) {
            merged[j][1] = intervals[++i][1];
        } 
        else {
            merged[j][1] = intervals[i][1];
        }
        
    }

}

int main() {

    std::vector<std::vector<int>> intervals{{1,3}, {2,6}, {8,10}, {15,18}};
    std::vector<std::vector<int>> merged{};

    merge(intervals, merged);

    for (size_t i = 0; i < merged.size(); i++)
    {
        for (size_t j = 0; j < merged[i].size(); j++)
        {
            std::cout << merged[i][j] << " ";
        }
    }
  
    std::cout << "\n";
 
    std::vector<std::vector<int>> intervals2{{1,4}, {4,5}};
    std::vector<std::vector<int>> merged2{};

    merge(intervals2, merged2);

    for (size_t i = 0; i < merged2.size(); i++)
    {
        for (size_t j = 0; j < merged2[i].size(); j++)
        {
            std::cout << merged2[i][j] << " ";
        }
    }

    std::cout << "\n";

    //no vectors. fixed array
    int intervalF[][2] =  {{1,3}, {2,6}, {8,10}, {15,18}};
    size_t rows = 4;
    size_t cols = 2;
    size_t count = 1;

    // count size of rows for merged 2d array
    for(size_t i = 0; i < rows - 1; i++) {
        if(intervalF[i][1] < intervalF[i+1][0]) {
            count++;
        }        
    }
    
    std::cout << count << "\n";
    int mergedF[3][2] = {};
    mergeF(mergedF, intervalF);
    

    for(size_t i = 0; i < count; i++) {
        for(size_t j = 0; j < cols; j++) {
            std::cout << mergedF[i][j] << " ";
        }
    } 

    std::cout <<  "\n";
    return 0;
}
