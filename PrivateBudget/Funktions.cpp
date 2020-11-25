#include "Function_prototupe.h";

bool GetFileUser(string login, ifstream& fin) // ������� ��� ���������� ����� ��� �������
{
	string path = "Users\\" + login; // ���� �� ����� �����������
	string file = "log_file_" + login + ".txt"; // ����� ����� � ���������� ������
	fin.open(path + "\\" + file);
	if (fin.is_open())
		return true;
	else
		return false;
}

void ZapusFileMainMenu(ofstream& fout, DjerelFin djerelfin)
{
	if (fout.is_open()) // �������� ���������� � ����
	{
		fout << fixed; // ������������ ��� ������ � ����
		fout << setprecision(2);  // ���������� ����� �� 2 ����� ���� ����
		fout << djerelfin.cash << endl; //������ ������
		fout << djerelfin.card << endl; //������ ������
		fout << djerelfin.bank_account << endl; //������ ����������� �������
		fout << djerelfin.credit << endl; //������ ���������� �������
		for (size_t i = 0; i < djerelfin.Ryh_koshtiv.size(); i++)
		{
			fout << djerelfin.Ryh_koshtiv[i].data << " " << djerelfin.Ryh_koshtiv[i].suma << " " << djerelfin.Ryh_koshtiv[i].typ << " " << djerelfin.Ryh_koshtiv[i].Vid << endl;
		}

	}
	fout.close();
	cout << endl;
}

void ZapusFileMainMenuVutraty(ofstream& fout1, StatVutrat statvutrat)
{
	if (fout1.is_open()) // �������� ���������� � ����
	{
		fout1 << fixed; // ������������ ��� ������ � ����
		fout1 << setprecision(2);  // ���������� ����� �� 2 ����� ���� ����
		fout1 << statvutrat.famaly << endl; //������ ���
		fout1 << statvutrat.car << endl; //������ ���������
		fout1 << statvutrat.comynal << endl; //������ ��������� �������
		fout1 << statvutrat.producty << endl; //������ ��������
		fout1 << statvutrat.recreation << endl; //������ ���������
		fout1 << statvutrat.presents << endl; //������ ���������
		fout1 << statvutrat.others << endl; //������ ���� �������

		for (size_t i = 0; i < statvutrat.Ryh_koshtiv.size(); i++)
		{
			fout1 << statvutrat.Ryh_koshtiv[i].data << " " << statvutrat.Ryh_koshtiv[i].suma << " " << statvutrat.Ryh_koshtiv[i].typ << " " << statvutrat.Ryh_koshtiv[i].Vid << endl;
		}

	}
	fout1.close();
	cout << endl;
}

void ZapusFileZalushok(ofstream& fout2, Zalushok zalushok)
{
	if (fout2.is_open()) // �������� ���������� � ����
	{
		fout2 << fixed; // ������������ ��� ������ � ����
		fout2 << setprecision(2);  // ���������� ����� �� 2 ����� ���� ����
		fout2 << fixed; // ������������ ��� ������ � ����
		fout2 << setprecision(2);  // ���������� ����� �� 2 ����� ���� ����
		fout2 << zalushok.zalushok_cash << endl; // ������� ������
		fout2 << zalushok.zalushok_card << endl; // ������� ������
		fout2 << zalushok.zalushok_bank_account << endl; // ������� ���������� �������
		fout2 << zalushok.zalushok_credit << endl; // ������� �������
	}
	fout2.close();
	cout << endl;
}

vector<string> Split(string data)  // ������� ����� �� ������.
{
	vector<string> result;
	char* s = new char[data.size() + 1]; // ��������� ����� ��� ���������  �������
	strcpy(s, data.c_str());  // ������� ����� � ����� char
	char* p = strtok(s, " "); // strtok ����� s ������� �� ������
	while (p != NULL) // ��������, �� ����� p �� ������
	{
		result.push_back(p); // ������� ������� ����� �� ������ � ������� �������
		p = strtok(NULL, " "); // ���������� �����, �� ���������� ������� �����
	}

	return result;
}

vector<string> Split1(string data)  // ������� ����� �� ������.
{
	vector<string> result;
	char* s = new char[data.size() + 1]; // ��������� ����� ��� ���������  �������
	strcpy(s, data.c_str());  // ������� ����� � ����� char
	char* p = strtok(s, "."); // strtok ����� s ������� �� ������
	while (p != NULL) // ��������, �� ����� p �� ������
	{
		result.push_back(p); // ������� ������� ����� �� ������ � ������� �������
		p = strtok(NULL, " "); // ���������� �����, �� ���������� ������� �����
	}

	return result;
}

double ZalushokObrahunok(int Num, Zalushok& zalushok, DjerelFin djerelfin, double Vutrata)
{
	if (Num == 1)
	{
		zalushok.zalushok_cash = djerelfin.cash - Vutrata;
		return zalushok.zalushok_cash;
	}
	else if (Num == 2)
	{
		zalushok.zalushok_card = djerelfin.card - Vutrata;
		return zalushok.zalushok_card;
	}
	else if (Num == 3)
	{
		zalushok.zalushok_bank_account = djerelfin.bank_account - Vutrata;
		return zalushok.zalushok_bank_account;
	}
	else if (Num == 4)
	{
		zalushok.zalushok_credit = djerelfin.credit - Vutrata;
		return zalushok.zalushok_credit;
	}
	else
	{
		cout << "������� ���� ������� ������������." << endl;
	}
	
}

int ChoiceMonthDay(int choice)
{
	enum months // ��������� �� ������������ ����� ������
	{
		Jan = 31, Feb = 28, Mar = 31, Apr = 30, May = 31, Jun = 30,
		Jul = 31, Aug = 31, Sep = 30, Oct = 31, Nov = 30, Dec = 31,
	};

	if (choice == 1)
		return Jan;
	else if (choice == 2)
		return Feb;
	else if (choice == 3)
		return Mar;
	else if (choice == 4)
		return Apr;
	else if (choice == 5)
		return May;
	else if (choice == 6)
		return Jun;
	else if (choice == 7)
		return Jul;
	else if (choice == 8)
		return Aug;
	else if (choice == 9)
		return Sep;
	else if (choice == 10)
		return Oct;
	else if (choice == 11)
		return Nov;
	else if (choice == 12)
		return Dec;
	else
		cout << "������ ������� �����!"  << endl;
}

string ChoiceMonthNazva(int choice)
{
	string Jan = "ѳ����";
	string Feb = "�����";
	string Mar = "��������";
	string Apr = "������";
	string May = "�������";
	string Jun = "�������";
	string Jul = "������";
	string Aug = "�������";
	string Sep = "��������";
	string Oct = "�������";
	string Nov = "��������";
	string Dec = "�������";

	if (choice == 1)
		return Jan;
	else if (choice == 2)
		return Feb;
	else if (choice == 3)
		return Mar;
	else if (choice == 4)
		return Apr;
	else if (choice == 5)
		return May;
	else if (choice == 6)
		return Jun;
	else if (choice == 7)
		return Jul;
	else if (choice == 8)
		return Aug;
	else if (choice == 9)
		return Sep;
	else if (choice == 10)
		return Oct;
	else if (choice == 11)
		return Nov;
	else if (choice == 12)
		return Dec;
	else
		cout << "������ ������� �����!" << endl;

}
