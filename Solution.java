
import java.util.ArrayList;
import java.util.List;

public class Solution {

    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> mergedIntervals = new ArrayList<>();
        int index = 0;

        while (index < intervals.length && newInterval[0] > intervals[index][1]) {
            mergedIntervals.add(intervals[index]);
            ++index;
        }

        while (index < intervals.length && newInterval[1] >= intervals[index][0]) {
            newInterval[0] = Math.min(intervals[index][0], newInterval[0]);
            newInterval[1] = Math.max(intervals[index][1], newInterval[1]);
            ++index;
        }
        mergedIntervals.add(newInterval);

        while (index < intervals.length) {
            mergedIntervals.add(intervals[index]);
            ++index;
        }

        return mergedIntervals.toArray(new int[0][2]);
    }
}
