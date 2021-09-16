#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "<OPTGROUP LABEL='2019十銓掛牌上市！堅不可摧(桌上型 DDR4 )'>";
	if (str.find("<OPTGROUP ") != -1 && str.find("十銓") != -1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false \n";
	}

	system("pause");
	return 0;
}
