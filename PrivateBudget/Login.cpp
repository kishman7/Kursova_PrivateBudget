#include "Function_prototupe.h"

void Login() // ������� ��� �������� ����� �� ������
{
	cout << "������� �����������!" << endl << endl;
	string login, password;
	int N = 3; // ������� �������� �����
	cout << "� ��� � " << N << " ������!!! ������ �����!!!" << endl;
	bool flag = false; // �������� ����� ��� ������������ ��������� ������

	for (int i = 0; i < N; i++)
	{
		cout << "������ ��� ���� -> " << endl;
		cin >> login;
		cout << "������ ��� ������ -> " << endl;
		cin >> password;
		ifstream fin;
		//string path = "Users\\" + login; // ���� �� ����� �����������
		//string file = "log_file_" + login + ".txt"; // ����� ����� � ���������� ������

		//fin.open(path + "\\" + file);
		if (GetFileUser(login, fin))
		{
			User user;
			fin >> user.login >> user.password >> user.name >> user.age;

			if (login == user.login && password == user.password)
			{
				flag = true;
				cout << "�� ������ ��������������!" << endl << endl;
				break;
			}
			else
			{
				cout << "������ ������� �� ����!" << endl << endl;

			}

		}
		else
		{
			cout << "������ ����������� �� ����!!!" << endl;
		}
	}
	if (flag == false)
	{
		cout << "�������, ��� �� ����������� ��� " << N << " ������!!!" << endl << endl;
	}
	MainMenu(string(login));

}