#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;
//---------------------������� � ���������---------------------------------------





//------------------------MAIN----------------------------------------------------
int main() {
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	//-------------------------------���� �����-------------------------------------

	bool uniq = true;                    // �������� �� ������������
	string str;                   // ������ �� ���� ��� � ������ ��������
	string temp;                  // ������ � ����������� �������

	string in;    

	cout << "������� ��� �����: ";

	cin >> in;

	ifstream fin;

	fin.open(in);

	if (!fin.is_open())                                            // ��������� ( ���� ���� �� ������ , ��: )
	{
		cout << "������ �������� �����! ( �������� )" << endl;
	}

	else                                                          // ���� ������ , �� ��� ��� ���� ����� :

	{

		cout << "���� ������ ���������! ( ������� )" << endl;

		//----------------------------------------------------------------------------------------------

		char ch;                                                  // �����. ��� ������������� ����������

		while (!fin.eof())
		{
			ch = '\0';                                            // �������� ������� �����������

			fin.get(ch);                                          // ����� ������ ������ ( � ������ ����� ���������)

			// cout << ch;                       // ������� : ������� ������ ������� ( ����������, ��� ����� �� ����� )



			// --------------------- !!! ������ !!! ----------------------------------------------------

			if ((91 > ch && ch > 64)  || (123 > ch && ch > 96))
			{
				if (91 > ch && ch > 64)
				{
					ch += 32;
				}

				for (int i = 0; i < str.size(); i++)
				{
					if (str[i] == ch)
					{
						uniq = false;
					}
				}
				str += ch;
				if (uniq)
				{
					temp += ch;
				}
			}
			uniq = true;

		}
	}

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] > temp[j + 1]) {
				char z = temp[j]; // ������� �������������� ����������
				temp[j] = temp[j + 1]; // ������ �������
				temp[j + 1] = z; // �������� ���������
			}
		}
	}

	cout << endl << "���������� ����� � ���������� �������:\n" << temp << endl << endl;

	fin.close();

	system("pause");
	return 0;
}
