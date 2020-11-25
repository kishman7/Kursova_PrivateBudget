#include "Function_prototupe.h"

Operaciya GetDataOperations(vector<string> data) // Функція для присвоєння елементів вектора в поля структкури
{
	Operaciya operaciya;
	operaciya.data = data[0]; //присвоєння першої чатини рядка
	operaciya.suma = stod(data[1]); //присвоєння другої чатини рядка, stod() - перетворює string в double
	operaciya.typ = data[2]; //присвоєння третьої частини рядка
	operaciya.Vid = data[3]; //присвоєння четвертої частини рядка

	//operaciya = data[3]; //присвоєння третьої частини рядка
	return operaciya;
}
// Оголошення змінних для визначення залишку
//double zalushok_cash = 0.0; // для відображення залишку готівки
//double zalushok_card = 0.0; // для відображення залишку картки
//double zalushok_bank_account = 0.0; // для відображення залишку банківського рахунку
//double zalushok_credit = 0.0; // для відображення залишку кредиту

void MainMenu(string login)
{
	system("cls"); // очищає екран консолі (все що вище даної команди)
	const string typ_dohid = "Дохід";
	const string typ_vutratu = "Витрати";

	const string Vid_gotivka = "Готівка";


	//считуємо файл з джерелами фінансування

	DjerelFin djerelfin;
	//int y = djerelfin.Ryh_koshtiv[0].GetDataDay(); // вертає число дати (дні)!!!

	ifstream fin;
	string path = "Users\\" + login; // шлях до папки користувача
	string file = "djerelfin_" + login + ".txt"; // назва файла з джерелами фінансування
	fin.open(path + "\\" + file); // відкриття файла і подальше считування
	if (fin.is_open())
	{
		int Counter = 0; // рядки
		while (!fin.eof()) // считується до тих пір поки файл не буде порожній
		{
			string Get;
			getline(fin, Get);
			if (Get.size() > 0) // size() рахує кількість символів в Get
			{
				if (Counter == 0)
					djerelfin.cash = stod(Get); // перетворює змінну Get зі strig в double і присвоює його полю структури djerelfin
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
					djerelfin.Ryh_koshtiv.push_back(operation); // присвоєння значень у вектор типу operaciya
				}
			}
			Counter++;
		}
	}
	else
	{
		cout << "Невірний шлях до файла або невірна назва файла!" << endl;
	}
	fin.close();

	//считуємо файл з статтями витрат
	StatVutrat statvutrat;
	ifstream fin1;
	//string path = "Users\\" + login; // шлях до папки користувача
	string file1 = "statvutrat_" + login + ".txt"; // назва файла з статтями витрат
	fin1.open(path + "\\" + file1); // відкриття файла і подальше считування
	if (fin1.is_open())
	{
		int Counter = 0; // рядки
		while (!fin1.eof()) // считується до тих пір поки файл не буде порожній
		{
			string Get;
			getline(fin1, Get);
			if (Get.size() > 0) // size() рахує кількість символів в Get
			{
				if (Counter == 0)
					statvutrat.famaly = stod(Get); // перетворює змінну Get зі strig в double і присвоює його полю структури statvutrat
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
					statvutrat.Ryh_koshtiv.push_back(operation); // присвоєння значень у вектор типу operaciya
				}
			}
			Counter++;
		}

	}

	else
	{
		cout << "Невірний шлях до файла або невірна назва файла!" << endl;
	}
	fin1.close();

	//считуємо файл з залишком коштів

	Zalushok zalushok;
	ifstream fin2;
	//string path = "Users\\" + login; // шлях до папки користувача
	string file2 = "zalushok_" + login + ".txt"; // назва файла з статтями витрат
	fin2.open(path + "\\" + file2); // відкриття файла і подальше считування
	if (fin2.is_open())
	{
		int Counter = 0; // рядки

		while (!fin2.eof()) // считується до тих пір поки файл не буде порожній
		{
			string Get;
			getline(fin2, Get);
			if (Get.size() > 0) // size() рахує кількість символів в Get
			{
				if (Counter == 0)
				{
					zalushok.zalushok_cash = stod(Get); // перетворює змінну Get зі strig в double і присвоює його полю структури zalushok
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
		cout << "Невірний шлях до файла або невірна назва файла!" << endl;
	}
	fin2.close();

	// Присвоюємо значення полів джерел фінансування в поля залишки, щоб залишки в статистиці відразу відображались (інакше там буде 0), 
	// допоки ми не використаємо поле залишків у програмі
	//
	//zalushok.zalushok_cash = djerelfin.cash;
	//zalushok.zalushok_card = djerelfin.card;
	//zalushok.zalushok_bank_account = djerelfin.bank_account;
	//zalushok.zalushok_credit = djerelfin.credit;

	cout << fixed; // заокруглення при виводі на екран
	cout << setprecision(2); // заокруглює число до 2 знаків після коми
	ofstream fout;  // шлях до файла вже оголошений
	ofstream fout1;
	ofstream fout2;

	int action = 1; // функція для вибору пункту меню. Якщо action=0, то false і вихід, якщо action>0, то продовжуємо роботу
	while (action)
	{
		cout << "----- М Е Н Ю  PRIVAT BUDGET ----- " << endl << endl;
		cout << "1. Джерела доходу." << endl;
		cout << "2. Категорії витрат." << endl;
		cout << "3. Статистика." << endl;
		cout << "0. Вихід з аккаунту." << endl;
		cout << endl;
		cout << "Виберіть відповідний пункт меню -> ";
		cin >> action;
		cout << endl;
		switch (action)
		{
		case 1: // Доходи
		{
			int action1 = 1; // функція для вибору пункту меню. Якщо action=0, то false і вихід, якщо action>0, то продовжуємо роботу
			bool test = true;
			while (test)
			{
				cout << "Ваші джерела фінансування." << endl;
				cout << "1. Готівка.\t\t\tБаланс готівки:\t" << djerelfin.cash << " грн." << endl;
				cout << "2. Картка.\t\t\tБаланс картки:\t" << djerelfin.card << " грн." << endl;
				cout << "3. Банківський рахунок.\t\tБаланс рахунку:\t" << djerelfin.bank_account << " грн." << endl;
				cout << "4. Кредит.\t\t\tБаланс кредиту:\t" << djerelfin.credit << " грн." << endl;
				cout << "0. Вихід." << endl;

				cout << "Оберіть потрібне джерело фінансування -> ";
				cin >> action1;
				cout << endl;
				Operaciya operaciya; // Оголошуємо поля структури operaciya
				operaciya.data = "01.01.2020";
				operaciya.suma = 0;
				operaciya.typ = "0";
				switch (action1)
				{
				case 1:
				{
					cout << "Ваш баланс готівки становить: " << djerelfin.cash << " грн." << endl;
					int choice;
					cout << "Бажаєте поповнити баланс готівки (1 - так, 0 - ні) -> ";
					cin >> choice;

					if (choice == 1)
					{
						double cash_popovn = 0.00;
						cout << "Вкажіть суму, яку бажаєте поповнити до балансу готівки -> ";
						cin >> cash_popovn;
						djerelfin.cash += cash_popovn;
						string data_vid;
						cout << "Введіть дату поповнення балансу готівки (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = cash_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string переводить int в string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // записуємо дані у файл
					
					//if (fout.is_open()) // записуємо результати у файл
				//{
				//	fout << djerelfin.cash << endl; //Баланс готівки
				//	fout << djerelfin.card << endl; //Баланс картки
				//	fout << djerelfin.bank_account << endl; //Баланс банківського рахунку
				//	fout << djerelfin.credit << endl; //Баланс отриманого кредиту
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
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Ваш баланс банківської картки становить: " << djerelfin.card << " грн." << endl;
					int choice;
					cout << "Бажаєте поповнити баланс готівки (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double card_popovn = 0;
						cout << "Вкажіть суму, яку бажаєте поповнити до балансу банківської картки -> ";
						cin >> card_popovn;
						djerelfin.card += card_popovn;
						string data_vid;
						cout << "Введіть дату поповнення балансу банківської картки (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = card_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string переводить int в string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // записуємо дані у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Ваш баланс банківського рахунку становить: " << djerelfin.bank_account << " грн." << endl;
					int choice;
					cout << "Бажаєте поповнити баланс банківського рахунку (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double bank_account_popovn = 0;
						cout << "Вкажіть суму, яку бажаєте поповнити до балансу банківської рахунку -> ";
						cin >> bank_account_popovn;
						djerelfin.bank_account += bank_account_popovn;
						string data_vid;
						cout << "Введіть дату поповнення балансу банківської рахунку (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = bank_account_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string переводить int в string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // записуємо дані у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 4:
				{
					cout << "Ваш баланс отриманого кредиту становить: " << djerelfin.credit << " грн." << endl;
					int choice;
					cout << "Бажаєте поповнити баланс отриманого кредиту (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double credit_popovn = 0;
						cout << "Вкажіть суму, яку бажаєте поповнити до балансу отриманого кредиту -> ";
						cin >> credit_popovn;
						djerelfin.credit += credit_popovn;
						string data_vid;
						cout << "Введіть дату поповнення балансу отриманого кредиту (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						operaciya.data = data_vid;
						operaciya.suma = credit_popovn;
						operaciya.typ = typ_dohid;
						operaciya.Vid = to_string(action1); // to_string переводить int в string

						djerelfin.Ryh_koshtiv.push_back(operaciya);

						fout.open(path + "\\" + file);
						ZapusFileMainMenu(fout, djerelfin); // записуємо дані у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 0:
				{
					test = false;
					cout << "Оберіть відповідний пункт меню" << endl << endl;
					break;
				}
				default:
					cout << "Ви обрали не вірний пункт меню. Зробіть ще раз свій вибір!" << endl;
				}
				system("cls"); // очищає екран консолі (все що вище даної команди)
			}
			break;
		}
		case 2: // Витрати
		{
			int action2 = 1; // функція для вибору пункту меню. Якщо action=0, то false і вихід, якщо action>0, то продовжуємо роботу
			bool test = true;
			while (test)
			{
				cout << "Ваші статті витрат." << endl;
				cout << "1. Сім’я.\t\t\t\t\t\tСума витрат:\t" << statvutrat.famaly << " грн." << endl;
				cout << "2. Автомобіль.\t\t\t\t\t\tСума витрат:\t" << statvutrat.car << " грн." << endl;
				cout << "3. Комунальні послуги.\t\t\t\t\tСума витрат:\t" << statvutrat.comynal << " грн." << endl;
				cout << "4. Продукти.\t\t\t\t\t\tСума витрат:\t" << statvutrat.producty << " грн." << endl;
				cout << "5. Відпочинок.\t\t\t\t\t\tСума витрат:\t" << statvutrat.recreation << " грн." << endl;
				cout << "6. Подарунки.\t\t\t\t\t\tСума витрат:\t" << statvutrat.presents << " грн." << endl;
				cout << "7. Інші витрати, які не входять в дані категорії.\tСума витрат:\t" << statvutrat.others << " грн." << endl;
				cout << "0. Вихід." << endl;

				cout << "Оберіть потрібну статтю витрат -> ";
				cin >> action2;
				cout << endl;
				Operaciya operaciya; // Оголошуємо поля структури operaciya
				operaciya.data = "01.01.2020";
				operaciya.suma = 0;
				operaciya.typ = "0";
				switch (action2)
				{
				case 1:
				{
					cout << "Ваша сума витрат по статті \"сім’я\" становить: " << statvutrat.famaly << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"сім’я\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double famaly_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> famaly_popovn;
						statvutrat.famaly += famaly_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"сім’я\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
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
							//	cout << "Невірний вибір джерела фінансування." << endl;
							//}
							
							fout2.open(path + "\\" + file2); // функція для запису даних у файл

							ZapusFileZalushok(fout2, zalushok);

							//if (fout2.is_open()) // записуємо результати у файл
							//{
							//	fout2 << fixed; // заокруглення при запису у файл
							//	fout2 << setprecision(2);  // заокруглює число до 2 знаків після коми
							//	fout2 << zalushok.zalushok_cash << endl; // Залишок готівки
							//	fout2 << zalushok.zalushok_card << endl; // Залишок картка
							//	fout2 << zalushok.zalushok_bank_account << endl; // Залишок банківський рахунок
							//	fout2 << zalushok.zalushok_credit << endl; // Залишок кредиту
							//}
							//fout2.close();
							//cout << endl;
						operaciya.data = data_vid;
						operaciya.suma = famaly_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл

						//if (fout1.is_open()) // записуємо результати у файл
						//{
						//	fout1 << statvutrat.famaly << endl; //Баланс сім’я
						//	fout1 << statvutrat.car << endl; //Баланс автомобіль
						//	fout1 << statvutrat.comynal << endl; //Баланс комунальні послуги
						//	fout1 << statvutrat.producty << endl; //Баланс продукти
						//	fout1 << statvutrat.recreation << endl; //Баланс відпочинок
						//	fout1 << statvutrat.presents << endl; //Баланс подарунки
						//	fout1 << statvutrat.others << endl; //Баланс інші витрати
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
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 2:
				{
					cout << "Ваша сума витрат по статті \"автомобіль\" становить: " << statvutrat.car << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"автомобіль\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double car_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> car_popovn;
						statvutrat.car += car_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"автомобіль\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.car);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);
						
						operaciya.data = data_vid;
						operaciya.suma = car_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 3:
				{
					cout << "Ваша сума витрат по статті \"комунальні послуги\" становить: " << statvutrat.comynal << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"комунальні послуги\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double comynal_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> comynal_popovn;
						statvutrat.comynal += comynal_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"комунальні послуги\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.comynal);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);

						operaciya.data = data_vid;
						operaciya.suma = comynal_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 4:
				{
					cout << "Ваша сума витрат по статті \"продукти\" становить: " << statvutrat.producty << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"продукти\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double producty_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> producty_popovn;
						statvutrat.producty += producty_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"комунальні послуги\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.producty);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = producty_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 5:
				{
					cout << "Ваша сума витрат по статті \"відпочинок\" становить: " << statvutrat.recreation << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"відпочинок\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double recreation_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> recreation_popovn;
						statvutrat.recreation += recreation_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"відпочинок\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.recreation);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = recreation_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 6:
				{
					cout << "Ваша сума витрат по статті \"подарунки\" становить: " << statvutrat.presents << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"подарунки\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double presents_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> presents_popovn;
						statvutrat.presents += presents_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"подарунки\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.presents);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = presents_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 7:
				{
					cout << "Ваша сума витрат по статті \"інші витрати\" становить: " << statvutrat.others << " грн." << endl;
					int choice;
					cout << "Бажаєте змінити баланс витрат статті \"інші витрати\" (1 - так, 0 - ні) -> ";
					cin >> choice;
					if (choice == 1)
					{
						double others_popovn = 0;
						cout << "Вкажіть суму, яку потрібно віднести до даної статті витрат -> ";
						cin >> others_popovn;
						statvutrat.others += others_popovn;
						string data_vid;
						cout << "Введіть дату зміни балансу статті витрат \"інші витрати\" (формат дд.мм.рррр) -> ";
						cin >> data_vid;
						cout << "Виберіть з якого джерела доходу буде покрита дана витрата." << endl;
						cout << "1. Готівка." << endl << "2. Картка." << endl << "3. Банківський рахунок." << endl << "4. Кредит." << endl;
						cout << "Зробіть вибір: ";
						int Num = 0;
						cin >> Num;

						ZalushokObrahunok(Num, zalushok, djerelfin, statvutrat.others);

						fout2.open(path + "\\" + file2); // функція для запису даних у файл

						ZapusFileZalushok(fout2, zalushok);
						operaciya.data = data_vid;
						operaciya.suma = others_popovn;
						operaciya.typ = typ_vutratu;
						operaciya.Vid = to_string(action2); // to_string переводить int в string

						statvutrat.Ryh_koshtiv.push_back(operaciya);

						fout1.open(path + "\\" + file1);

						ZapusFileMainMenuVutraty(fout1, statvutrat); // функція для запису даних у файл
					}
					else
					{
						cout << "Перейдіть до вибору іншого пункту меню." << endl << endl;
					}
					break;
				}
				case 0:
				{
					test = false;
					cout << "Оберіть відповідний пункт меню" << endl << endl;
					break;
				}
				default:
					cout << "Ви обрали не вірний пункт меню. Зробіть ще раз свій вибір!" << endl;
				}
				system("cls"); // очищає екран консолі (все що вище даної команди)
			}
			break;
		}
		case 3: // Статистика
		{
			int action3 = 1; // функція для вибору пункту меню. Якщо action=0, то false і вихід, якщо action>0, то продовжуємо роботу
			bool test = true;
			while (test)
			{
				cout << "Статистика." << endl;
				cout << "1. Залишок коштів по джерелам фінансування." << endl;
				cout << "2. Динаміка доходів (Графік)." << endl;
				cout << "3. Динаміка витрат (Графік)." << endl;
				cout << "0. Вихід." << endl;

				cout << "Оберіть потрібий пункт меню -> ";
				cin >> action3;
				cout << endl;
				switch (action3)
				{
				case 1:
				{
					cout << "Залишок коштів по джерелам фінансування." << endl;
					cout << "1. Залишок коштів Вашої готівки:\t\t "<< zalushok.zalushok_cash << " грн." << endl;
					cout << "2. Залишок коштів Вашої картки:\t\t\t " << zalushok.zalushok_card << " грн." << endl;
					cout << "3. Залишок коштів Вашого банківського рахунку:\t " << zalushok.zalushok_bank_account << " грн." << endl;
					cout << "4. Залишок коштів Вашого кредиту:\t\t " << zalushok.zalushok_credit << " грн." << endl;
					cout <<  endl;
					break;
				}
				case 2:
				{
					cout << "Графік динаміки Ваших доходів." << endl << endl;
					cout << "Місяць.\n1.Січень\n2.Лютий\n3.Березень\n4.Квітень\n5.Травень\n6.Червень\n7.Липень\n8.Серпень\n9.Вересень\n10.Жовтень\n11.Листопад\n12.Грудень\n" << endl;
					cout << "Виберіть місяць, за який хочете переглянути графік: ";
					int choice = 0;
					cin >> choice; // Вибір місяця
					cout << ChoiceMonthNazva(choice) << " = " << ChoiceMonthDay(choice) << endl; // Вивід місяця та кількості днів в місяці
					
					vector<Operaciya>SelectMonth; // вектор для того, щоб помісти всі записи вибраного місяця
					cout << "Ваші доходи." << endl;
					for (int i = 0; i < djerelfin.Ryh_koshtiv.size(); i++) // цикл для знаходження номера місяця
					{
						int monthdata = djerelfin.Ryh_koshtiv[i].GetDataMonth(); // в змінну поміщаємо значення номера місяця, який нам потрібен
						if (monthdata == choice)	// номер місяця порівнюємо з номером вибором
						{
							SelectMonth.push_back(djerelfin.Ryh_koshtiv[i]); // заповняємо вектор всіма значеннями вибраного місяця
							cout << djerelfin.Ryh_koshtiv[i].data << " " << djerelfin.Ryh_koshtiv[i].suma << endl; // Вивід доходів з датами та сумами
						}
					}
					cout << endl;
					cout << "Графік динаміки Ваших доходів." << endl;
					int* massiv = new int[SelectMonth.size()]{-1}; // оголошення динаміч. масиву для визначення висоти графіка
					for (int i = 0; i < SelectMonth.size(); i++) // цикл для заповнення динам. масиву
					{
						int test1 = SelectMonth[i].suma / 10000 * 10;	// кладемо в змінну значення із елемента вектора, при цьому визначаємо 10 частину із 10000
						massiv[i] = test1;	// присвоюємо це значення в масив
					}
					
					int** massuma = new int* [SelectMonth.size()]; // оголошення двувимірного масиву для створення віртуального графіка
					
					for (int i = 0; i < SelectMonth.size(); i++) // цикл для створення графіка
					//for (int i = SelectMonth.size(); i > 0; i--)
					{
						massuma[i] = new int[10]{ 0 }; // заповняємо стовбець графіка (по замовчуванню всі стовпці дорівнюють нулю)
						if (massiv[i] == 0)		// якщо перший рядок дорівнює нулю, то перший елемент стовпця заповнюється
							massuma[i][9] = 1;
						else
							for (int u = 0; u < massiv[i]; u++)		// якщо значення рядка більше 0, то елемент стовпця буде заповнено
							{
								massuma[i][9 - u] = 1;
							}
					}


					for (int i = 0; i < 10; i++) // цикл для виведення зображення графіка
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
					cout << "Графік динаміки Ваших витрат." << endl << endl;
					cout << "Місяць.\n1.Січень\n2.Лютий\n3.Березень\n4.Квітень\n5.Травень\n6.Червень\n7.Липень\n8.Серпень\n9.Вересень\n10.Жовтень\n11.Листопад\n12.Грудень\n" << endl;
					cout << "Виберіть місяць, за який хочете переглянути графік: ";
					int choice = 0;
					cin >> choice; // Вибір місяця
					cout << ChoiceMonthNazva(choice) << " = " << ChoiceMonthDay(choice) << endl; // Вивід місяця та кількості днів в місяці

					vector<Operaciya>SelectMonth;
					cout << "Ваші витрати." << endl;
					for (int i = 0; i < statvutrat.Ryh_koshtiv.size(); i++)
					{
						int monthdata = statvutrat.Ryh_koshtiv[i].GetDataMonth();	// в змінну поміщаємо значення номера місяця, який нам потрібен
						if (monthdata == choice)	// номер місяця порівнюємо з номером вибором
						{
							SelectMonth.push_back(statvutrat.Ryh_koshtiv[i]);
							cout << statvutrat.Ryh_koshtiv[i].data << " " << statvutrat.Ryh_koshtiv[i].suma << endl;	// Вивід витрат з датами та сумами
						}
					}
					cout << endl;
					cout << "Графік динаміки Ваших витрат." << endl;
					int* massiv = new int[SelectMonth.size()]{ -1 };
					for (int i = 0; i < SelectMonth.size(); i++)
					{
						int test1 = SelectMonth[i].suma / 10000 * 10; 
						massiv[i] = test1;
					}

					int** massuma = new int* [SelectMonth.size()]; // оголошення двувимірного масиву для виводу графіка

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
					cout << "Оберіть відповідний пункт меню" << endl << endl;
					break;
				}
				default:
					cout << "Ви обрали не вірний пункт меню. Зробіть ще раз свій вибір!" << endl;
				}
				//system("cls"); // очищає екран консолі (все що вище даної команди)
			}
			break;
		}
	}
	system("cls"); // очищає екран консолі (все що вище даної команди)
}
}

