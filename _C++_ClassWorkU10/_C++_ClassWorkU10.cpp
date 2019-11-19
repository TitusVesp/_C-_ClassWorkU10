// _C++_ClassWorkU10.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ScanInfo
{
	string model;
	int price, optr, grey;
	double x_size, y_size;
};

void WriteFile(ScanInfo *x, int size)
{
	ofstream t("file");
	t << size << endl;
	for (int i = 0; i < size; i++)
	{
		t << x[i].model << " " << x[i].price << " " <<
			x[i].optr << " " << x[i].grey << " " <<
			x[i].x_size << "x" << x[i].y_size << endl;
	}
}

void ChangeFile()
{
	char oldName[] = "fileTemp", newName[] = "file", temp[20], tempFile[200];
	temp[0] = '\0';

	cout << "Input size of you data: " << endl;
	int quality = 0;
	cin >> quality;
	if (cin.fail())
	{
		cout << "Error! Input again!" << endl;
		cin.clear();
		cin.ignore(32767, '\n');
		cin >> quality;
	}
	ScanInfo buf[20];

	for (int i = 0; i < quality; i++)
	{
		cout << "Input model: " << endl;
		temp[0] = '\0';
		while (temp[0] == '\0') cin.getline(temp, 20);
		int j = 0;  while (temp[j] != '\0') { buf[i].model[j] = temp[j++]; }
		cout << "Input price: " << endl;
		cin >> buf[i].price;
		if (cin.fail())
		{
			cout << "Error! Input again!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> buf[i].price;
		}
		cout << "Input optr: " << endl;
		cin >> buf[i].optr;
		if (cin.fail())
		{
			cout << "Error! Input again!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> buf[i].optr;
		}
		cout << "Input gray: " << endl;
		cin >> buf[i].grey;
		if (cin.fail())
		{
			cout << "Error! Input again!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> buf[i].grey;
		}
		cout << "Input x_size: " << endl;
		cin >> buf[i].x_size;
		if (cin.fail())
		{
			cout << "Error! Input again!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> buf[i].optr;
		}
		cout << "Input y_size: " << endl;
		cin >> buf[i].y_size;
		if (cin.fail())
		{
			cout << "Error! Input again!" << endl;
			cin.clear();
			cin.ignore(32767, '\n');
			cin >> buf[i].grey;
		}
		system("cls");
	}

	ofstream t("fileTemp");
	ifstream tr("file");
	temp[0] = '\0';
	int count = 0;
	while (temp[0] == '\0')
	{
		tr.getline(temp, 20);
		if (count++ > 1000)
		{
			temp[0] = '0';
			break;
		}
	}
	int size = atoi(temp);
	t << (quality + size) << endl;
	for (int i = 0; i < quality; i++)
	{
		t << buf[i].model << " " << buf[i].price << " " <<
			buf[i].optr << " " << buf[i].grey << " " <<
			buf[i].x_size << "x" << buf[i].y_size << endl;
	}

	for (int i = 0; i < size; i++)
	{
		tr.getline(tempFile, 200);
		t << tempFile << endl;
	}

	t.close();
	tr.close();

	if (remove(newName) != 0)
		cout << "Error\n";
	else
		cout << "Ok...\n";

	if (rename(oldName, newName) != 0)
		cout << "Error\n\n";
	else
		cout << "Ok...\n\n";

	return;
}

int main()
{
	ChangeFile();
	return 0;
}

