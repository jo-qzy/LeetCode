class Solution {
public:
    string longestPalindrome(string s) {
		//中心扩展法解决，看了解析的解法4写的
        string::iterator start = s.begin(), end = s.begin();
        for (int i = 0; i < s.length(); i++)
        {
            int len1 = centryExpand(s, i, i + 1);//字符串为偶数长度
            int len2 = centryExpand(s, i, i);//字符串为奇数长度
            int len = max(len1, len2);//获取最长的长度
            if (len > end - start)
            {
				//修改start和end的位置
                start = s.begin() + i - (len - 1) / 2;
                end = s.begin() + i + len / 2 + 1;
            }
        }
        return string(start, end);
    }
    
private:
    int centryExpand(string s, int left, int right)
    {
        string::iterator start = s.begin() + left, end = s.begin() + right;
        while (start >= s.begin() && end < s.end() && start[0] == end[0])
        {
			//向两边扩展
            start--, end++;
        }
        return end - start - 1;
    }
};