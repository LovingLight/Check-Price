#include <iostream>
#include <string>
using namespace std;
int main(void)
{
	string str = "<OPTGROUP LABEL='2019�̻ͱ��P�W���I���i�R(��W�� DDR4 )'>";
	if (str.find("<OPTGROUP ") != -1 && str.find("�̻�") != -1)
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
