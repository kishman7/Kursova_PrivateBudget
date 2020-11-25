#include "Function_prototupe.h"

Operaciya GetDataOperations(vector<string> data) // ������� ��� ��������� �������� ������� � ���� ����������
{
	Operaciya operaciya;
	operaciya.data = data[0]; //��������� ����� ������ �����
	operaciya.suma = stod(data[1]); //��������� ����� ������ �����, stod() - ���������� string � double
	operaciya.typ = data[2]; //��������� ������ ������� �����
	operaciya.Vid = data[3]; //��������� �������� ������� �����

	//operaciya = data[3]; //��������� ������ ������� �����
	return operaciya;
}
// ���������� ������ ��� ���������� �������
//double zalushok_cash = 0.0; // ��� ����������� ������� ������
//double zalushok_card = 0.0; // ��� ����������� ������� ������
//double zalushok_bank_account = 0.0; // ��� ����������� ������� ����������� �������
//double zalushok_credit = 0.0; // ��� ����������� ������� �������

void MainMenu(string login)
{
	system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
	const string typ_dohid = "�����";
	const string typ_vutratu = "�������";

	const string Vid_gotivka = "������";


	//������� ���� � ��������� ������������

	DjerelFin djerelfin;
	//int y = djerelfin.Ryh_koshtiv[0].GetDataDay(); // ����� ����� ���� (��)!!!

	ifstream fin;
	string path = "Users\\" + login; // ���� �� ����� �����������
	string file = "djerelfin_" + login + ".txt"; // ����� ����� � ��������� ������������
	fin.open(path + "\\" + file); // �������� ����� � �������� ����������
	if (fin.is_open())
	{
		int Counter = 0; // �����
		while (!fin.eof()) // ��������� �� ��� �� ���� ���� �� ���� �������
		{
			string Get;
			getline(fin, Get);
			if (Get.size() > 0) // size() ���� ������� ������� � Get
			{
				if (Counter == 0)
					djerelfin.cash = stod(Get); // ���������� ����� Get � strig � double � �������� ���� ���� ��������� djerelfin
				else if (Counter == 1)
					djerelfin.card = stod(Get);
				else if (Counter == 2)
					djerelfin.bank_account = stod(Get);
				else if (Counter == 3)
					djerelfin.credit = stod(Get);
				else
				{
					vector<string> data = Split(Get);
					Operaciya operation = GetDataOperations(data);
					djerelfin.Ryh_koshtiv.push_back(operation); // ��������� ������� � ������ ���� operaciya
				}
			}
			Counter++;
		}
	}
	else
	{
		cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
	}
	fin.close();

	//������� ���� � �������� ������
	StatVutrat statvutrat;
	ifstream fin1;
	//string path = "Users\\" + login; // ���� �� ����� �����������
	string file1 = "statvutrat_" + login + ".txt"; // ����� ����� � �������� ������
	fin1.open(path + "\\" + file1); // �������� ����� � �������� ����������
	if (fin1.is_open())
	{
		int Counter = 0; // �����
		while (!fin1.eof()) // ��������� �� ��� �� ���� ���� �� ���� �������
		{
			string Get;
			getline(fin1, Get);
			if (Get.size() > 0) // size() ���� ������� ������� � Get
			{
				if (Counter == 0)
					statvutrat.famaly = stod(Get); // ���������� ����� Get � strig � double � �������� ���� ���� ��������� statvutrat
				else if (Counter == 1)
					statvutrat.car = stod(Get);
				else if (Counter == 2)
					statvutrat.comynal = stod(Get);
				else if (Counter == 3)
					statvutrat.producty = stod(Get);
				else if (Counter == 4)
					statvutrat.recreation = stod(Get);
				else if (Counter == 5)
					statvutrat.presents = stod(Get);
				else if (Counter == 6)
					statvutrat.others = stod(Get);
				else
				{
					vector<string> data = Split(Get);
					Operaciya operation = GetDataOperations(data);
					statvutrat.Ryh_koshtiv.push_back(operation); // ��������� ������� � ������ ���� operaciya
				}
			}
			Counter++;
		}

	}

	else
	{
		cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
	}
	fin1.close();

	//������� ���� � �������� �����

	Zalushok zalushok;
	ifstream fin2;
	//string path = "Users\\" + login; // ���� �� ����� �����������
	string file2 = "zalushok_" + login + ".txt"; // ����� ����� � �������� ������
	fin2.open(path + "\\" + file2); // �������� ����� � �������� ����������
	if (fin2.is_open())
	{
		int Counter = 0; // �����

		while (!fin2.eof()) // ��������� �� ��� �� ���� ���� �� ���� �������
		{
			string Get;
			getline(fin2, Get);
			if (Get.size() > 0) // size() ���� ������� ������� � Get
			{
				if (Counter == 0)
				{
					zalushok.zalushok_cash = stod(Get); // ���������� ����� Get � strig � double � �������� ���� ���� ��������� zalushok
				}
				else if (Counter == 1)
				{
					zalushok.zalushok_card = stod(Get);
				}
				else if (Counter == 2)
				{
					zalushok.zalushok_bank_account = stod(Get);
				}
				else if (Counter == 3)
				{
					zalushok.zalushok_credit = stod(Get);
				}
			}
			Counter++;
		}
	}
	else
	{
		cout << "������� ���� �� ����� ��� ������ ����� �����!" << endl;
	}
	fin2.close();

	// ���������� �������� ���� ������ ������������ � ���� �������, ��� ������� � ���������� ������ ������������ (������ ��� ���� 0), 
	// ������ �� �� ����������� ���� ������� � �������
	//
	//zalushok.zalushok_cash = djerelfin.cash;
	//zalushok.zalushok_card = djerelfin.card;
	//zalushok.zalushok_bank_account = djerelfin.bank_account;
	//zalushok.zalushok_credit = djerelfin.credit;

	cout << fixed; // ������������ ��� ����� �� �����
	cout << setprecision(2); // ���������� ����� �� 2 ����� ���� ����
	ofstream fout;  // ���� �� ����� ��� ����������
	ofstream fout1;
	ofstream fout2;

	int action = 1; // ������� ��� ������ ������ ����. ���� action=0, �� false � �����, ���� action>0, �� ���������� ������
	while (action)
	{
		cout << "----- � � � �  PRIVAT BUDGET ----- " << endl << endl;
		cout << "1. ������� ������." << endl;
		cout << "2. ������� ������." << endl;
		cout << "3. ����������." << endl;
		cout << "0. ����� � ��������." << endl;
		cout << endl;
		cout << "������� ��������� ����� ���� -> ";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1: // ������
		{
			int action1 = 1; // ������� ��� ������ ������ ����. ���� action=0, �� false � �����, ���� action>0, �� ���������� ������
			bool test = true;
			while (test)
			{
				cout << "���� ������� ������������." << endl;
				cout << "1. ������.\t\t\t������ ������:\t" << djerelfin.cash << " ���." << endl;
				cout << "2. ������.\t\t\t������ ������:\t" << djerelfin.card << " ���." << endl;
				cout << "3. ���������� �������.\t\t������ �������:\t" << djerelfin.bank_account << " ���." << endl;
				cout << "4. ������.\t\t\t������ �������:\t" << djerelfin.credit << " ���." << endl;
				cout << "0. �����." << endl;

				cout << "������ ������� ������� ������������ -> ";
				cin >> action1;
				cout << endl;
				Operaciya operaciya; // ��������� ���� ��������� operaciya
				operaciya.data = "01.01.2020";
				operaciya.suma = 0;
				operaciya.typ = "0";
				switch (action1)
				{
				case 1:
				{
					cout << "��� ������ ������ ���������: " << djerelfin.cash << " ���." << endl;
					int choice;
					cout << "������ ��������� ������ ������ (1 - ���, 0 - �) -> ";
					cin >> choice;

					if (choice == 1)
					{
						double cash_popovn = 0.00;
						cout << "������ ����, ��� ������ ��������� �� ������� ������ -> ";
						cin >> cash_popovn;
						djerelfin.cash += cash_popovn;
						string data_vid;
						cout << "������ ���� ���������� ������� ������ (������ ��.��.����) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = cash_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string ���������� int � string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // �������� ��� � ����
					
					//if (fout.is_open()) // �������� ���������� � ����
				//{
				//	fout << djerelfin.cash << endl; //������ ������
				//	fout << djerelfin.card << endl; //������ ������
				//	fout << djerelfin.bank_account << endl; //������ ����������� �������
				//	fout << djerelfin.credit << endl; //������ ���������� �������
				//	for (size_t i = 0; i < djerelfin.Ryh_koshtiv.size(); i++)
				//	{
				//		fout << djerelfin.Ryh_koshtiv[i].data << " " << djerelfin.Ryh_koshtiv[i].suma << " " << djerelfin.Ryh_koshtiv[i].typ << " " << djerelfin.Ryh_koshtiv[i].Vid << endl;
				//	}
				//
				//}
				//fout.close();
				//cout << endl;

					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "��� ������ ��������� ������ ���������: " << djerelfin.card << " ���." << endl;
					int choice;
					cout << "������ ��������� ������ ������ (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double card_popovn = 0;
						cout << "������ ����, ��� ������ ��������� �� ������� ��������� ������ -> ";
						cin >> card_popovn;
						djerelfin.card += card_popovn;
						string data_vid;
						cout << "������ ���� ���������� ������� ��������� ������ (������ ��.��.����) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = card_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string ���������� int � string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // �������� ��� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 3:
				{
					cout << "��� ������ ����������� ������� ���������: " << djerelfin.bank_account << " ���." << endl;
					int choice;
					cout << "������ ��������� ������ ����������� ������� (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double bank_account_popovn = 0;
						cout << "������ ����, ��� ������ ��������� �� ������� ��������� ������� -> ";
						cin >> bank_account_popovn;
						djerelfin.bank_account += bank_account_popovn;
						string data_vid;
						cout << "������ ���� ���������� ������� ��������� ������� (������ ��.��.����) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = bank_account_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string ���������� int � string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // �������� ��� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 4:
				{
					cout << "��� ������ ���������� ������� ���������: " << djerelfin.credit << " ���." << endl;
					int choice;
					cout << "������ ��������� ������ ���������� ������� (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double credit_popovn = 0;
						cout << "������ ����, ��� ������ ��������� �� ������� ���������� ������� -> ";
						cin >> credit_popovn;
						djerelfin.credit += credit_popovn;
						string data_vid;
						cout << "������ ���� ���������� ������� ���������� ������� (������ ��.��.����) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = credit_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string ���������� int � string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // �������� ��� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 0:
				{
					test = false;
					cout << "������ ��������� ����� ����" << endl << endl;
					break;
				}
				default:
					cout << "�� ������ �� ����� ����� ����. ������ �� ��� ��� ����!" << endl;
				}
				system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
			}
			break;
		}
		case 2: // �������
		{
			int action2 = 1; // ������� ��� ������ ������ ����. ���� action=0, �� false � �����, ���� action>0, �� ���������� ������
			bool test = true;
			while (test)
			{
				cout << "���� ����� ������." << endl;
				cout << "1. ѳ��.\t\t\t\t\t\t���� ������:\t" << statvutrat.famaly << " ���." << endl;
				cout << "2. ���������.\t\t\t\t\t\t���� ������:\t" << statvutrat.car << " ���." << endl;
				cout << "3. ��������� �������.\t\t\t\t\t���� ������:\t" << statvutrat.comynal << " ���." << endl;
				cout << "4. ��������.\t\t\t\t\t\t���� ������:\t" << statvutrat.producty << " ���." << endl;
				cout << "5. ³��������.\t\t\t\t\t\t���� ������:\t" << statvutrat.recreation << " ���." << endl;
				cout << "6. ���������.\t\t\t\t\t\t���� ������:\t" << statvutrat.presents << " ���." << endl;
				cout << "7. ���� �������, �� �� ������� � ��� �������.\t���� ������:\t" << statvutrat.others << " ���." << endl;
				cout << "0. �����." << endl;

				cout << "������ ������� ������ ������ -> ";
				cin >> action2;
				cout << endl;
				Operaciya operaciya; // ��������� ���� ��������� operaciya
				operaciya.data = "01.01.2020";
				operaciya.suma = 0;
				operaciya.typ = "0";
				switch (action2)
				{
				case 1:
				{
					cout << "���� ���� ������ �� ����� \"���\" ���������: " << statvutrat.famaly << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"���\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double famaly_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> famaly_popovn;
						statvutrat.famaly += famaly_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"���\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;
						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.famaly);
							//if (Num == 1)
							//{
							//	zalushok.zalushok_cash = djerelfin.cash - statvutrat.famaly;
							//}
							//else if (Num == 2)
							//{
							//	zalushok.zalushok_card = djerelfin.card - statvutrat.famaly;
							//}
							//else if (Num == 3)
							//{
							//	zalushok.zalushok_bank_account = djerelfin.bank_account - statvutrat.famaly;
							//}
							//else if (Num == 3)
							//{
							//	zalushok.zalushok_credit = djerelfin.credit - statvutrat.famaly;
							//}
							//else
							//{
							//	cout << "������� ���� ������� ������������." << endl;
							//}
							
							fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

							ZapusFileZalushok(fout2, zalushok);

							//if (fout2.is_open()) // �������� ���������� � ����
							//{
							//	fout2 << fixed; // ������������ ��� ������ � ����
							//	fout2 << setprecision(2);  // ���������� ����� �� 2 ����� ���� ����
							//	fout2 << zalushok.zalushok_cash << endl; // ������� ������
							//	fout2 << zalushok.zalushok_card << endl; // ������� ������
							//	fout2 << zalushok.zalushok_bank_account << endl; // ������� ���������� �������
							//	fout2 << zalushok.zalushok_credit << endl; // ������� �������
							//}
							//fout2.close();
							//cout << endl;
						operaciya.data = data_vid;
						operaciya.suma = famaly_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����

						//if (fout1.is_open()) // �������� ���������� � ����
						//{
						//	fout1 << statvutrat.famaly << endl; //������ ���
						//	fout1 << statvutrat.car << endl; //������ ���������
						//	fout1 << statvutrat.comynal << endl; //������ ��������� �������
						//	fout1 << statvutrat.producty << endl; //������ ��������
						//	fout1 << statvutrat.recreation << endl; //������ ���������
						//	fout1 << statvutrat.presents << endl; //������ ���������
						//	fout1 << statvutrat.others << endl; //������ ���� �������
						//
						//	for (size_t i = 0; i < statvutrat.Ryh_koshtiv.size(); i++)
						//	{
						//		fout1 << statvutrat.Ryh_koshtiv[i].data << " " << statvutrat.Ryh_koshtiv[i].suma << " " << statvutrat.Ryh_koshtiv[i].typ << " " << statvutrat.Ryh_koshtiv[i].Vid << endl;
						//	}
						//
						//}
						//fout1.close();
						//cout << endl;
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "���� ���� ������ �� ����� \"���������\" ���������: " << statvutrat.car << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"���������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double car_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> car_popovn;
						statvutrat.car += car_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"���������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.car);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);
						
						operaciya.data = data_vid;
						operaciya.suma = car_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 3:
				{
					cout << "���� ���� ������ �� ����� \"��������� �������\" ���������: " << statvutrat.comynal << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"��������� �������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double comynal_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> comynal_popovn;
						statvutrat.comynal += comynal_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"��������� �������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.comynal);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);

						operaciya.data = data_vid;
						operaciya.suma = comynal_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 4:
				{
					cout << "���� ���� ������ �� ����� \"��������\" ���������: " << statvutrat.producty << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"��������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double producty_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> producty_popovn;
						statvutrat.producty += producty_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"��������� �������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.producty);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = producty_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 5:
				{
					cout << "���� ���� ������ �� ����� \"���������\" ���������: " << statvutrat.recreation << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"���������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double recreation_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> recreation_popovn;
						statvutrat.recreation += recreation_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"���������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.recreation);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = recreation_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 6:
				{
					cout << "���� ���� ������ �� ����� \"���������\" ���������: " << statvutrat.presents << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"���������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double presents_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> presents_popovn;
						statvutrat.presents += presents_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"���������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.presents);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = presents_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 7:
				{
					cout << "���� ���� ������ �� ����� \"���� �������\" ���������: " << statvutrat.others << " ���." << endl;
					int choice;
					cout << "������ ������ ������ ������ ����� \"���� �������\" (1 - ���, 0 - �) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double others_popovn = 0;
						cout << "������ ����, ��� ������� ������� �� ���� ����� ������ -> ";
						cin >> others_popovn;
						statvutrat.others += others_popovn;
						string data_vid;
						cout << "������ ���� ���� ������� ����� ������ \"���� �������\" (������ ��.��.����) -> ";
						cin >> data_vid;
						cout << "������� � ����� ������� ������ ���� ������� ���� �������." << endl;
						cout << "1. ������." << endl << "2. ������." << endl << "3. ���������� �������." << endl << "4. ������." << endl;
						cout << "������ ����: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.others);

						fout2.open(path + "\\" + file2); // ������� ��� ������ ����� � ����

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = others_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string ���������� int � string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // ������� ��� ������ ����� � ����
					}
					else
					{
						cout << "�������� �� ������ ������ ������ ����." << endl << endl;
					}
					break;
				}
				case 0:
				{
					test = false;
					cout << "������ ��������� ����� ����" << endl << endl;
					break;
				}
				default:
					cout << "�� ������ �� ����� ����� ����. ������ �� ��� ��� ����!" << endl;
				}
				system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
			}
			break;
		}
		case 3: // ����������
		{
			int action3 = 1; // ������� ��� ������ ������ ����. ���� action=0, �� false � �����, ���� action>0, �� ���������� ������
			bool test = true;
			while (test)
			{
				cout << "����������." << endl;
				cout << "1. ������� ����� �� �������� ������������." << endl;
				cout << "2. ������� ������ (������)." << endl;
				cout << "3. ������� ������ (������)." << endl;
				cout << "0. �����." << endl;

				cout << "������ ������� ����� ���� -> ";
				cin >> action3;
				cout << endl;
				switch (action3)
				{
				case 1:
				{
					cout << "������� ����� �� �������� ������������." << endl;
					cout << "1. ������� ����� ���� ������:\t\t "<< zalushok.zalushok_cash << " ���." << endl;
					cout << "2. ������� ����� ���� ������:\t\t\t " << zalushok.zalushok_card << " ���." << endl;
					cout << "3. ������� ����� ������ ����������� �������:\t " << zalushok.zalushok_bank_account << " ���." << endl;
					cout << "4. ������� ����� ������ �������:\t\t " << zalushok.zalushok_credit << " ���." << endl;
					cout <<  endl;
					break;
				}
				case 2:
				{
					cout << "������ ������� ����� ������." << endl << endl;
					cout << "̳����.\n1.ѳ����\n2.�����\n3.��������\n4.������\n5.�������\n6.�������\n7.������\n8.�������\n9.��������\n10.�������\n11.��������\n12.�������\n" << endl;
					cout << "������� �����, �� ���� ������ ����������� ������: ";
					int choice = 0;
					cin >> choice; // ���� �����
					cout << ChoiceMonthNazva(choice) << " = " << ChoiceMonthDay(choice) << endl; // ���� ����� �� ������� ��� � �����
					
					vector<Operaciya>SelectMonth; // ������ ��� ����, ��� ������ �� ������ ��������� �����
					cout << "���� ������." << endl;
					for (int i = 0; i < djerelfin.Ryh_koshtiv.size(); i++) // ���� ��� ����������� ������ �����
					{
						int monthdata = djerelfin.Ryh_koshtiv[i].GetDataMonth(); // � ����� ������� �������� ������ �����, ���� ��� �������
						if (monthdata == choice)	// ����� ����� ��������� � ������� �������
						{
							SelectMonth.push_back(djerelfin.Ryh_koshtiv[i]); // ���������� ������ ���� ���������� ��������� �����
							cout << djerelfin.Ryh_koshtiv[i].data << " " << djerelfin.Ryh_koshtiv[i].suma << endl; // ���� ������ � ������ �� ������
						}
					}
					cout << endl;
					cout << "������ ������� ����� ������." << endl;
					int* massiv = new int[SelectMonth.size()]{-1}; // ���������� ������. ������ ��� ���������� ������ �������
					for (int i = 0; i < SelectMonth.size(); i++) // ���� ��� ���������� �����. ������
					{
						int test1 = SelectMonth[i].suma / 10000 * 10;	// ������� � ����� �������� �� �������� �������, ��� ����� ��������� 10 ������� �� 10000
						massiv[i] = test1;	// ���������� �� �������� � �����
					}
					
					int** massuma = new int* [SelectMonth.size()]; // ���������� ����������� ������ ��� ��������� ����������� �������
					
					for (int i = 0; i < SelectMonth.size(); i++) // ���� ��� ��������� �������
					//for (int i = SelectMonth.size(); i > 0; i--)
					{
						massuma[i] = new int[10]{ 0 }; // ���������� �������� ������� (�� ������������ �� ������� ��������� ����)
						if (massiv[i] == 0)		// ���� ������ ����� ������� ����, �� ������ ������� ������� ������������
							massuma[i][9] = 1;
						else
							for (int u = 0; u < massiv[i]; u++)		// ���� �������� ����� ����� 0, �� ������� ������� ���� ���������
							{
								massuma[i][9 - u] = 1;
							}
					}


					for (int i = 0; i < 10; i++) // ���� ��� ��������� ���������� �������
					{
						if (i == 0)
							cout << "10000";
						else if (i == 1)
							cout << "9000 ";
						else if (i == 2)
							cout << "8000 ";
						else if (i == 3)
							cout << "7000 ";
						else if (i == 4)
							cout << "6000 ";
						else if (i == 5)
							cout << "5000 ";
						else if (i == 6)
							cout << "4000 ";
						else if (i == 7)
							cout << "3000 ";
						else if (i == 8)
							cout << "2000 ";
						else if (i == 9)
							cout << "1000 ";
						else
							cout << "     ";

						//for (int y = SelectMonth.size()-1; y >= 0; y--)
							//for (int i = SelectMonth.size(); i > 0; i--)
						for (int y = 0; y < SelectMonth.size(); y++)
						{
							if (massuma[y][i] == 0)
								cout << "  ";
							else
								cout << "||";
						}
						cout << endl;
					}
					delete[]massuma;
					cout << endl;

					break;
				}
				case 3:
				{
					cout << "������ ������� ����� ������." << endl << endl;
					cout << "̳����.\n1.ѳ����\n2.�����\n3.��������\n4.������\n5.�������\n6.�������\n7.������\n8.�������\n9.��������\n10.�������\n11.��������\n12.�������\n" << endl;
					cout << "������� �����, �� ���� ������ ����������� ������: ";
					int choice = 0;
					cin >> choice; // ���� �����
					cout << ChoiceMonthNazva(choice) << " = " << ChoiceMonthDay(choice) << endl; // ���� ����� �� ������� ��� � �����

					vector<Operaciya>SelectMonth;
					cout << "���� �������." << endl;
					for (int i = 0; i < statvutrat.Ryh_koshtiv.size(); i++)
					{
						int monthdata = statvutrat.Ryh_koshtiv[i].GetDataMonth();	// � ����� ������� �������� ������ �����, ���� ��� �������
						if (monthdata == choice)	// ����� ����� ��������� � ������� �������
						{
							SelectMonth.push_back(statvutrat.Ryh_koshtiv[i]);
							cout << statvutrat.Ryh_koshtiv[i].data << " " << statvutrat.Ryh_koshtiv[i].suma << endl;	// ���� ������ � ������ �� ������
						}
					}
					cout << endl;
					cout << "������ ������� ����� ������." << endl;
					int* massiv = new int[SelectMonth.size()]{ -1 };
					for (int i = 0; i < SelectMonth.size(); i++)
					{
						int test1 = SelectMonth[i].suma / 10000 * 10; 
						massiv[i] = test1;
					}

					int** massuma = new int* [SelectMonth.size()]; // ���������� ����������� ������ ��� ������ �������

					for (int i = 0; i < SelectMonth.size(); i++)
					{
						massuma[i] = new int[10]{ 0 };
						if (massiv[i] == 0)
							massuma[i][9] = 1;
						else
							for (int u = 0; u < massiv[i]; u++)
							{
								massuma[i][9 - u] = 1;
							}
					}

					for (int i = 0; i < 10; i++)
					{
						if (i == 0)
							cout << "10000";
						else if (i == 1)
							cout << "9000 ";
						else if (i == 2)
							cout << "8000 ";
						else if (i == 3)
							cout << "7000 ";
						else if (i == 4)
							cout << "6000 ";
						else if (i == 5)
							cout << "5000 ";
						else if (i == 6)
							cout << "4000 ";
						else if (i == 7)
							cout << "3000 ";
						else if (i == 8)
							cout << "2000 ";
						else if (i == 9)
							cout << "1000 ";
						else
							cout << "     ";

						for (int y = 0; y < SelectMonth.size(); y++)
						{
							if (massuma[y][i] == 0)
								cout << "  ";
							else
								cout << "||";
						}
						cout << endl;
					}
					delete[]massuma;
					cout << endl;

					break;
				}
				case 0:
				{
					test = false;
					cout << "������ ��������� ����� ����" << endl << endl;
					break;
				}
				default:
					cout << "�� ������ �� ����� ����� ����. ������ �� ��� ��� ����!" << endl;
				}
				//system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
			}
			break;
		}
	}
	system("cls"); // ����� ����� ������ (��� �� ���� ���� �������)
}
}

