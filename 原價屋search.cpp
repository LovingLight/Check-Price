#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
string reducetitle(string);
string reduce(string);
int main(void)
{
	system("python Serachtest.py");
	fstream FileInput, FileOutput;
	int count = 0;
	string scr_txt, temp, upper_scr_txt, lower_scr_txt;
	FileInput.open("­ì»ù«Î.txt", ios::in);
	FileOutput.open("result.txt", ios::out);
	cout << "Search : ";
	getline(cin, scr_txt);
	transform(scr_txt.begin(), scr_txt.end(), back_inserter(upper_scr_txt), ::toupper);
	transform(scr_txt.begin(), scr_txt.end(), back_inserter(lower_scr_txt), ::toupper);
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
		if (temp.find("<OPTGROUP ") != -1 && (temp.find(upper_scr_txt) != -1 || temp.find(lower_scr_txt) != -1))
		{
			cout << reducetitle(temp) << endl << endl;
			FileOutput << reducetitle(temp) << endl << endl;
			break;
		}
	} while (!FileInput.eof());

	do
	{
		if (FileInput.eof())
			break;
		getline(FileInput, temp);
		if ((temp.find(upper_scr_txt) != -1 || temp.find(lower_scr_txt) != -1) && temp.find("OPTION ") != -1)
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
	return 0;
}

string reduce(string str)
{
	int Site1 = 0, Site2 = 0;
	string temp;
	Site1 = str.find(">") + 1;
	Site2 = str.find("¡»") - 1;
	temp.assign(str, Site1, Site2 - Site1);
	return temp;
}

string reducetitle(string str)
{
	int Site1 = 0, Site2 = 0;
	string temp;
	Site1 = str.find("'") + 1;
	Site2 = str.find("'",Site1);
	temp.assign(str, Site1, Site2 - Site1);
	return temp;
}

