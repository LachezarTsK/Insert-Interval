
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
public:
    vector<vector<int>> insert(const vector<vector<int>>& intervals, vector<int>& newInterval) const {
        vector < vector<int> > mergedIntervals;
        int index = 0;

        while (index < intervals.size() && newInterval[0] > intervals[index][1]) {
            mergedIntervals.push_back(intervals[index]);
            ++index;
        }

        while (index < intervals.size() && newInterval[1] >= intervals[index][0]) {
            newInterval[0] = min(intervals[index][0], newInterval[0]);
            newInterval[1] = max(intervals[index][1], newInterval[1]);
            ++index;
        }
        mergedIntervals.push_back(newInterval);

        while (index < intervals.size()) {
            mergedIntervals.push_back(intervals[index]);
            ++index;
        }

        return mergedIntervals;
    }
};
