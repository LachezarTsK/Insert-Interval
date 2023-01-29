
/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function (intervals, newInterval) {
    const mergedIntervals = [];
    let index = 0;

    while (index < intervals.length && newInterval[0] > intervals[index][1]) {
        mergedIntervals.push(intervals[index]);
        ++index;
    }

    while (index < intervals.length && newInterval[1] >= intervals[index][0]) {
        newInterval[0] = Math.min(intervals[index][0], newInterval[0]);
        newInterval[1] = Math.max(intervals[index][1], newInterval[1]);
        ++index;
    }
    mergedIntervals.push(newInterval);

    while (index < intervals.length) {
        mergedIntervals.push(intervals[index]);
        ++index;
    }

    return mergedIntervals;
};
