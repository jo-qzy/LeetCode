/**
* Definition for an interval.
* struct Interval {
*     int start;
*     int end;
*     Interval() : start(0), end(0) {}
*     Interval(int s, int e) : start(s), end(e) {}
* };
*/
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		int index = 0;
		int i = 0, j = 0;
		for (i = 1; i < intervals.size(); i++)
		{
			//插入排序排序给定区间的start
			Interval tmp = intervals[i];
			for (j = i - 1; j >= 0; j--)
			{
				if (intervals[j].start < tmp.start)
					break;
				else
					intervals[j + 1] = intervals[j];
			}
			intervals[j + 1] = tmp;
		}
		while (index + 1 < intervals.size())
		{
			//四种情况：
			//1.前一个区间的end大于等于后一个区间的start且小于后一个区间的end
			//	新区间[前start，后end]
			//2.前一个区间的end大于等于后一个区间的end
			//	新区间[前start，前end]
			//3.前后区间start相同，但是end是后面一个区间大
			//	（排序只考虑start的大小，不考虑end大小，所以会出现此种情况）
			//	新区间为[后start，后end]
			//4.前后区间无相交
			if (intervals[index].end >= intervals[index + 1].start && intervals[index].end <= intervals[index + 1].end)
			{
				Interval tmp(intervals[index].start, intervals[index + 1].end);
				intervals.erase(intervals.begin() + index);
				intervals.erase(intervals.begin() + index);
				intervals.insert(intervals.begin() + index, tmp);
			}
			else if (intervals[index].end >= intervals[index + 1].end)
			{
				Interval tmp(intervals[index].start, intervals[index].end);
				intervals.erase(intervals.begin() + index);
				intervals.erase(intervals.begin() + index);
				intervals.insert(intervals.begin() + index, tmp);
			}
			else if (intervals[index].start == intervals[index + 1].start && intervals[index].end <= intervals[index + 1].end)
			{
				Interval tmp(intervals[index].start, intervals[index + 1].end);
				intervals.erase(intervals.begin() + index);
				intervals.erase(intervals.begin() + index);
				intervals.insert(intervals.begin() + index, tmp);
			}
			else
			{
				index++;
			}
		}
		return intervals;
	}
};