class Solution {
public:
    bool isValid(string s) {
        vector<int> check;//栈的典型应用
        string::iterator is = s.begin();
        for (; is != s.end(); is++)
        {
            switch(is[0])
            {
            case '(':
            case '[':
            case '{':
                check.push_back(is[0]);
                break;
            case ')':
                if (check.empty() || check.back() != '(')
                    return false;
                check.pop_back();
                break;
            case ']':
                if (check.empty() || check.back() != '[')
                    return false;
                check.pop_back();
                break;
            case '}':
                if (check.empty() || check.back() != '{')
                    return false;
                check.pop_back();
                break;
            default:
                break;
            }
        }
        if (check.empty())
            return true;
        return false;
    }
};