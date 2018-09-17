class Solution {
public:
	string toGoatLatin(string S) {
		int slow = 0, fast = 0;//slow指向单词词首，fast指向尾
		bool flag = false;//判断第一位是否为元音的标记
		char tmp = 0;
		int count = 1;
		string ret;
		//把元音位置为1
		char check[255] = { 0 };
		check['a'] = 1;
		check['e'] = 1;
		check['i'] = 1;
		check['o'] = 1;
		check['u'] = 1;
		check['A'] = 1;
		check['E'] = 1;
		check['I'] = 1;
		check['O'] = 1;
		check['U'] = 1;
		while (fast < S.size())
		{
			slow = fast;
			//fast指向单词尾后一个位置
			while (S[fast] != ' ' && fast < S.size())
				fast++;
			//判断是否元音，是直接插入，否先标记
			if (check[S[slow]] == 1)
			{
				ret += S[slow];
				slow++;
			}
			else
			{
				tmp = S[slow];
				slow++;
				flag = true;
			}
			//逐个字母插入
			while (slow < fast)
			{
				ret += S[slow];
				slow++;
			}
			//插入元音
			if (flag == true)
			{
				ret += tmp;;
				flag = false;
			}
			//插入咩~~~~
			ret += "ma";
			for (int i = 0; i < count; i++)
				ret += 'a';
			count++;
			//插入空格
			if (S[fast] == ' ')
				ret += ' ';
			fast++;
		}
		return ret;
	}
};