class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        getSequence(ret, n);
        return ret;
    }
private:
    void getSequence(vector<string>& ret, int n, string str = string(), int left = 0, int right = 0)
    {
        if (left > n || left < right)
            return;
        if (left == n && right == n) {
            ret.push_back(str);
            return;
        }
        getSequence(ret, n, str + '(', left + 1, right);
        getSequence(ret, n, str + ')', left, right + 1);
    }
};