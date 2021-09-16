#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string reducetitle(string);
string reduce(string);
string convertCPU(int);
string convertMB(int);
string convertRAM(int);
string convertGPU(int);
void SearchCPU();
void SearchGPU();
void SearchMB();
void SearchRAM();
void Search(string);
int main(void)
{
	cout << "start\n";
	system("python Serachtest.py");
	system("cls");
	string mode;
	int mode_num;

	while (1)
	{
		cout << "\n\nCPU : 1\n"
			 << "MB : 2\n"
			 << "RAM : 3\n"
			 << "GPU : 4\n"
			 << "Exit : 0\n";
		cout << "Input mode : ";
		cin >> mode_num;
		cin.get();

		if (mode_num < 0 || mode_num > 7)
		{
			cout << "Input Error\n";
			system("pause");
			exit(1);
		}
		else if (mode_num == 0)
		{
			break;
		}

		switch (mode_num)
		{
		case 1:
			SearchCPU();
			break;

		case 2:
			SearchMB();
			break;

		case 3:
			SearchRAM();
			break;

		case 4:
			SearchGPU();
			break;

		default:
			cout << "none";
			break;
		}
	}

	system("pause");
	return 0;
}

string reduce(string str)
{
	int Site1 = 0, Site2 = 0;
	string temp;
	Site1 = str.find(">") + 1;
	Site2 = str.find("<", Site1);
	temp.assign(str, Site1, Site2 - Site1);
	return temp;
}

string reducetitle(string str)
{
	int Site1 = 0, Site2 = 0;
	string temp;
	Site1 = str.find("'") + 1;
	Site2 = str.find("'", Site1);
	temp.assign(str, Site1, Site2 - Site1);
	return temp;
}

string convertCPU(int scr_num)
{
	switch (scr_num)
	{
	case 1:
		return ">Intel i3-";
		break;
	case 2:
		return ">Intel i5-";
		break;
	case 3:
		return ">Intel i7-";
		break;
	case 4:
		return ">Intel i9-";
		break;
	case 5:
		return "AMD R5 ";
		break;
	case 6:
		return "AMD R7 ";
		break;
	case 7:
		return "AMD R9 ";
		break;
	}
}

string convertMB(int scr_num)
{
	switch (scr_num)
	{
	case 1:
		return "Intel B460";
		break;
	case 2:
		return "Intel B560";
		break;
	case 3:
		return "Intel Z590";
		break;
	case 4:
		return "AMD B450";
		break;
	case 5:
		return "AMD B550";
		break;
	case 6:
		return "AMD X570";
		break;
	}
}

string convertRAM(int scr_num)
{
	switch (scr_num)
	{
	case 1:
		return "KLEVV";
		break;
	case 2:
		return "十銓";
		break;
	case 3:
		return "桌上型記憶體 DDR4";
		break;
	case 4:
		return "DDR4 雙通道";
		break;
	case 5:
		return "DDR4 四通道";
		break;
	case 6:
		return "筆記型記憶體 DDR4";
		break;
	}
}

string convertGPU(int scr_num)
{
	switch (scr_num)
	{
	case 1:
		return "GTX1650";
		break;
	case 2:
		return "GTX1650 SUPER";
		break;
	case 3:
		return "GTX1660";
		break;
	case 4:
		return "GTX1660Ti";
		break;
	case 5:
		return "GTX1660 SUPER";
		break;
	case 6:
		return "RTX2060";
		break;
	case 7:
		return "RTX3060";
		break;
	case 8:
		return "RTX3060TI";
		break;
	case 9:
		return "RTX3070";
		break;
	case 10:
		return "RTX3070 Ti";
		break;
	case 11:
		return "RTX3080";
		break;
	case 12:
		return "RTX3080 Ti";
		break;
	case 13:
		return "AMD RX6700XT";
		break;
	case 14:
		return "AMD RX6800";
		break;
	case 15:
		return "AMD RX6800XT";
		break;
	}
}

void SearchGPU()
{
	system("cls");

	int scr_num;

	cout << "\n\n"
		 << " 1 : GTX 1650\n"
		 << " 2 : GTX 1650 super\n"
		 << " 3 : GTX 1660\n"
		 << " 4 : GTX 1660ti\n"
		 << " 5 : GTX 1660 super\n"
		 << " 6 : RTX 2060\n"
		 << " 7 : RTX 3060\n"
		 << " 8 : RTX 3060ti\n"
		 << " 9 : RTX 3070\n"
		 << "10 : RTX 3070ti\n"
		 << "11 : RTX 3080\n"
		 << "12 : RTX 3080ti\n"
		 << "13 : AMD RX6700XT\n"
		 << "14 : AMD RX6800\n"
		 << "15 : AMD RX6800XT\n\n"
		 << "型號 : ";

	cin >> scr_num;

	if (scr_num < 1 || scr_num > 15)
	{
		cout << "Input error";
		return;
	}

	Search(convertGPU(scr_num));
	system("cls");

	return;
}

void SearchCPU()
{
	system("cls");

	int scr_num;

	cout << "\n關鍵字:\n"
		 << "1 : Intel i3系列\n"
		 << "2 : Intel i5系列\n"
		 << "3 : Intel i7系列\n"
		 << "4 : Intel i9系列\n"
		 << "5 : Amd R5系列\n"
		 << "6 : Amd R7系列\n"
		 << "7 : Amd R9系列\n"
		 << endl;

	cout << "型號 : ";
	cin >> scr_num;

	if (scr_num < 1 || scr_num > 7)
	{
		cout << "Input error\n";
		system("pause");
		system("cls");
		return;
	}

	Search(convertCPU(scr_num));
	system("cls");

	return;
}

void SearchRAM()
{
	system("cls");

	int scr_num;

	cout << "\n關鍵字\n"
		 << "1 : KLEVV科賦\n"
		 << "2 : 十銓\n"
		 << "3 : 桌上型記憶體 DDR4\n"
		 << "4 : 桌上型記憶體 DDR4 雙通道\n"
		 << "5 : 桌上型記憶體 DDR4 四通道\n"
		 << "6 : 筆記型記憶體 DDR4\n"
		 << endl;

	cout << "型號 : ";
	cin >> scr_num;

	if (scr_num < 1 || scr_num > 6)
	{
		cout << "Input error\n";
		system("pause");
		system("cls");
		return;
	}

	Search(convertRAM(scr_num));
	system("cls");

	return;
}

void SearchMB()
{
	system("cls");

	int scr_num;

	cout << "\n\n"
		 << " 1 : Intel B460/1200 腳位(不支援11代CPU)\n"
		 << " 2 : Intel B560 / 1200 腳位\n"
		 << " 3 : Intel Z590 / 1200 腳位\n"
		 << " 4 : AMD B450 / AM4\n"
		 << " 5 : AMD B550 / AM4\n"
		 << " 6 : AMD X570\n\n"
		 << "型號 : ";

	cin >> scr_num;

	if (scr_num < 1 || scr_num > 6)
	{
		cout << "Input error";
		system("pause");
		system("cls");
		return;
	}

	Search(convertMB(scr_num));
	system("cls");

	return;
}

void Search(string scr_txt)
{
	fstream FileInput, FileOutput;
	int count = 0;
	string temp;
	FileInput.open("原價屋.txt", ios::in);
	FileOutput.open("result.txt", ios::out);

	if (!FileInput.is_open())
	{
		cout << "Open failed.\n";
		exit(1);
	}

	if (!FileOutput.is_open())
	{
		cout << "Open failed.\n";
		exit(1);
	}

	do
	{
		getline(FileInput, temp);
		if (temp.find("<OPTGROUP ") != -1 && temp.find(scr_txt) != -1)
		{
			cout << reducetitle(temp) << endl
				 << endl;
			FileOutput << reducetitle(temp) << endl
					   << endl;
			break;
		}
	} while (!FileInput.eof());

	do
	{
		if (FileInput.eof())
			break;
		getline(FileInput, temp);
		if (temp.find("OPTION ") != -1)
		{
			if (temp.find("disabled") == -1)
			{
				count++;
				cout << reduce(temp) << endl;
				FileOutput << reduce(temp) << endl;
			}
		}
	} while (temp.find("OPTGROUP") == -1);

	if (count == 0)
	{
		cout << "None\n";
		FileOutput << "None\n";
	}

	FileInput.close();
	FileOutput.close();
	system("pause");
	system("cls");
	return;
}