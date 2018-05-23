bool isPalindrome(int x) {
    if (x < 0)
    {
		//需要翻转的数小于0，直接返回
        return false;
    }
    int origin = x;//原始数据，一个原则，尽量不动参数
    int reverse = 0;//翻转后的数据
    while (origin != 0)
    {
        reverse *= 10;
        reverse += origin % 10;
        origin /= 10;
    }
    if (reverse == x)
    {
		//翻转后的数等于原数
        return true;
    }
    return false;
}