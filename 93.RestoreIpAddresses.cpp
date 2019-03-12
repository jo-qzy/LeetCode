class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string ss = s;
		vector<string> ret;
		getIp(ss, ret);
		return ret;
	}
private:
	void getIp(string& s, vector<string>& ret, int index = 0, string ip = string(), int count = 0) {
		if (count == 4)
			return;
		int ip_part = 0;
		for (int i = index; i < index + 3; i++) {
			ip_part += s[i] - '0';
			if (ip_part >= 256)
				return;
			ip_part *= 10;
			ip += s[i];
			getIp(s, ret, i + 1, ip + '.', count + 1);
			if (count == 3) {
				if (i == s.size() - 1) {
					ret.push_back(ip);
					return;
				}
			}
			if (s[i] == '0' && i == index)
				return;
		}
	}
};