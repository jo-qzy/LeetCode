class Solution {
public:
	int firstUniqChar(string s) {
		//自己建一个check数组，记录下标，下标已记录就置-1
		//时间32ms，远比使用stl快
		int check[255] = { 0 };
		for (string::iterator cur = s.begin(); cur != s.end(); cur++)
		{
			if (check[*cur] == 0)
				check[*cur] = cur - s.begin();
			else
				check[*cur] = -1;
		}
		if (check[s[0]] != 0)
			check[s[0]] = -1;
		for (string::iterator cur = s.begin(); cur != s.end(); cur++)
		{
			if (check[*cur] != -1)
				return check[*cur];
		}
		return -1;
	}
};

//用stl的map写，但是时间是自己建数组的两倍，思路相同，有些时候还是不用stl的快
//自从学了stl，思维都被局限了一直觉得stl好，stl是好，但是有些地方要思考为什么不用stl
//这里因为map底层是一个红黑树，而第一种方法实现直接就一个数组，什么插入的通通不需要考虑
//所以第一种快
class Solution {
public:
	int firstUniqChar(string s) {
		map<char, int> check;
		for (string::iterator cur = s.begin(); cur != s.end(); cur++)
		{
			if (check[*cur] == 0)
				check[*cur] = cur - s.begin();
			else
				check[*cur] = -1;
		}
		if (check[s[0]] != 0)
			check[s[0]] = -1;
		for (string::iterator cur = s.begin(); cur != s.end(); cur++)
		{
			if (check[*cur] != -1)
				return check[*cur];
		}
		return -1;
	}
};