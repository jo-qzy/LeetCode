char* intToRoman(int num) {
    int mul = 1000;
	int tmp = 0;
	char* ret = (char*)malloc(sizeof(char) * 16);
	//没有c++中的string那么方便，不能直接拼接，所以干脆开一个最大的
	//最大为3888，也就是十五个字符，反正最大也不会超过16个空间的
	*ret = '\0';
	while (mul != 0)
	{
		//tmp取出每一位，mul对应的是当前取出的是哪一位，1000就是千位，100就是百位
		tmp = num / mul % 10;
		if (tmp != 0)
		{
			switch (mul)
			{
			case 1:
				switch (tmp)
				{
				case 1: strcat(ret, "I"); break;
				case 2: strcat(ret, "II"); break;
				case 3: strcat(ret, "III"); break;
				case 4: strcat(ret, "IV"); break;
				case 5: strcat(ret, "V"); break;
				case 6: strcat(ret, "VI"); break;
				case 7: strcat(ret, "VII"); break;
				case 8: strcat(ret, "VIII"); break;
				case 9: strcat(ret, "IX"); break;
				}
				break;
			case 10:
				switch (tmp)
				{
				case 1: strcat(ret, "X"); break;
				case 2: strcat(ret, "XX"); break;
				case 3: strcat(ret, "XXX"); break;
				case 4: strcat(ret, "XL"); break;
				case 5: strcat(ret, "L"); break;
				case 6: strcat(ret, "LX"); break;
				case 7: strcat(ret, "LXX"); break;
				case 8: strcat(ret, "LXXX"); break;
				case 9: strcat(ret, "XC"); break;
				}
				break;
			case 100:
				switch (tmp)
				{
				case 1: strcat(ret, "C"); break;
				case 2: strcat(ret, "CC"); break;
				case 3: strcat(ret, "CCC"); break;
				case 4: strcat(ret, "CD"); break;
				case 5: strcat(ret, "D"); break;
				case 6: strcat(ret, "DC"); break;
				case 7: strcat(ret, "DCC"); break;
				case 8: strcat(ret, "DCCC"); break;
				case 9: strcat(ret, "CM"); break;
				}
				break;
			case 1000:
				switch (tmp)
				{
				case 1: strcat(ret, "M"); break;
				case 2: strcat(ret, "MM"); break;
				case 3: strcat(ret, "MMM"); break;
				}
				break;
			}
		}
        mul /= 10;
	}
	return ret;
}