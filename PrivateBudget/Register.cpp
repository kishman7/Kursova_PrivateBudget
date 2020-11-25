#include "Function_prototupe.h"

void Register() // ������� ��� ���������
{
	string login, password, password2, name, age;
	cout << "������������� � ������!" << endl << endl;
	cout << "������ ����-> ";
	cin >> login;

	ifstream fin;
	if (GetFileUser(login, fin))
	{
		system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
		cout << "���������� ��� ����!" << endl << endl;
	}
	else
	{

		do  // ���� ��� ������������ ������
		{
			cout << "������ ������ -> ";
			cin >> password;
			cout << "ϳ�������� ������ (���� ���� �� ��������� � ��������� �����) -> ";
			cin >> password2;
			if (password == password2)
			{
				cout << "³����! ������ ������������ ����!" << endl;
			}
			else if (password != password2)
			{
				cout << "�������! ������ ������������ �������� ������!" << endl;
				cout << "�������� ������ �������� ������." << endl;
			}
		} while (password != password2);

		cout << "������ ��� ��� -> ";
		cin >> name;
		cout << "������ ��� �� -> ";
		cin >> age;
		cout << endl;

		User user;
		user.login = login;
		user.password = password;
		user.name = name;
		user.age = age;

		/*��������� ����� ��� ����������� ��� ��������� � ������ �����*/
		string path = "Users\\" + login; // ��������� ����� � ������ �����
		const char* folder = path.c_str(); // c_str() - ����� ����� �������
		_mkdir(folder);

		string file = "log_file_" + login + ".txt"; // ��������� ����� ����� � ���������� ������
		ofstream fout;

		fout.open(path + "\\" + file);
		if (fout.is_open())
		{
			fout << user.login << endl;
			fout << user.password << endl;
			fout << user.name << endl;
			fout << user.age << endl;
		}
		else
		{
			cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
		}
		fout.close();

		//��������� ���� �� ���������� ���� ���� ��������� ��� ������ �� � ��������� ���� djerelfin

		double cash = 0;
		double card = 0;
		double bank_account = 0;
		double credit = 0;

		DjerelFin djerelfin;
		djerelfin.cash = cash;
		djerelfin.card = card;
		djerelfin.bank_account = bank_account;
		djerelfin.credit = credit;

		//string path = "Users\\" + login;
		string file1 = "djerelfin_" + login + ".txt"; // ��������� ����� ����� � ��������� ������������ � �����
		ofstream fout1;

		fout1.open(path + "\\" + file1);
		if (fout1.is_open())
		{
			fout1 << djerelfin.cash << endl; //������ ������
			fout1 << djerelfin.card << endl; //������ ������
			fout1 << djerelfin.bank_account << endl; //������ ����������� �������
			fout1 << djerelfin.credit << endl; //������ ���������� �������
		}
		else
		{
			cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
		}

		fout1.close();

		//��������� ���� �� ��������� ��� ������ �� � ��������� ���� statvutrat

		double famaly = 0.0; // ���
		double car = 0.0; // ���������
		double comynal = 0.0; //��������� �������
		double producty = 0.0; // ��������
		double recreation = 0.0; // ���������
		double presents = 0.0; // ���������
		double others = 0.0; // ����, �� �� ������� � ����� �������

		StatVutrat statvutrat; // ��������� ��� ���������� ����� ����� ������
		statvutrat.famaly = famaly;
		statvutrat.car = car;
		statvutrat.comynal = comynal;
		statvutrat.producty = producty;
		statvutrat.recreation = recreation;
		statvutrat.presents = presents;
		statvutrat.others = others;

		string file2 = "statvutrat_" + login + ".txt"; // ��������� ����� ����� � �������� ������ � �����
		ofstream fout2;

		fout2.open(path + "\\" + file2);
		if (fout2.is_open())
		{
			fout2 << statvutrat.famaly << endl; //������ ����� ������ ���
			fout2 << statvutrat.car << endl; //������ ����� ������ ���������
			fout2 << statvutrat.comynal << endl; //������ ����� ������ ��������� �������
			fout2 << statvutrat.producty << endl; //������ ����� ������ ��������
			fout2 << statvutrat.recreation << endl; //������ ����� ������ ���������
			fout2 << statvutrat.presents << endl; //������ ����� ������ ���������
			fout2 << statvutrat.others << endl; //������ ����� ������ ���� �������
		}
		else
		{
			cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
		}

		fout2.close();

		//��������� ���� �� ���������� ���� ���� ��������� ��� ������ �� � ��������� ���� zalushok

		double zalushok_cash = 0.0; // ��� ����������� ������� ������
		double zalushok_card = 0.0; // ��� ����������� ������� ������
		double zalushok_bank_account = 0.0; // ��� ����������� ������� ����������� �������
		double zalushok_credit = 0.0; // ��� ����������� ������� �������

		Zalushok zalushok; // ��������� ��� ���������� ����� zalushok
		zalushok.zalushok_cash = zalushok_cash;
		zalushok.zalushok_card = zalushok_card;
		zalushok.zalushok_bank_account = zalushok_bank_account;
		zalushok.zalushok_credit = zalushok_credit;

		string file3 = "zalushok_" + login + ".txt"; // ��������� ����� ����� � �������� ������ � �����
		ofstream fout3;

		fout3.open(path + "\\" + file3);
		if (fout3.is_open())
		{
			fout3 << zalushok.zalushok_cash << endl; //������ ����� ������ ���
			fout3 << zalushok.zalushok_card << endl; //������ ����� ������ ���������
			fout3 << zalushok.zalushok_bank_account << endl; //������ ����� ������ ��������� �������
			fout3 << zalushok.zalushok_credit << endl; //������ ����� ������ ��������
		}
		else
		{
			cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
		}

		fout3.close();
	}
}