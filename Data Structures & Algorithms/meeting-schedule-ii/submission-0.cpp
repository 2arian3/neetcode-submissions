/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            return a.start < b.start;
        });

        multiset<int> endTimes;

        for (const auto& interval : intervals) {
            if (!endTimes.empty() && *endTimes.begin() <= interval.start) {
                endTimes.erase(endTimes.begin());
            }
            endTimes.insert(interval.end);
        }

        return endTimes.size();
    }
};
