#include "Function_prototupe.h"

void GenMenu() {

	int action = 1;
	while (action)
	{
		cout << "----- � � � � -----" << endl << endl;
		cout << "1. ��������� ������ ��������." << endl;
		cout << "2. ������ � ��� ������� (������ ���� �� ������)." << endl;
		cout << "0. �����." << endl;
		cout << endl;
		cout << "������� �������� ����� ����." << endl;
		cin >> action;

		switch (action)
		{
		case 1:
		{
			Register();
			break;
		}
		case 2:
		{
			Login();
			break;
		}
		case 0:
		{
			cout << "������.�� ���������!" << endl;
			break;
		}
		default:
			cout << "�� ������ �� ����� ����� ����. ������ �� ��� ��� ����!" << endl;
		}
		//system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)

	}

}