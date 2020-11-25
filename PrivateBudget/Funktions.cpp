#include "Function_prototupe.h";

bool GetFileUser(string login, ifstream& fin) // функція для считування файла при логіненні
{
	string path = "Users\\" + login; // шлях до папки користувача
	string file = "log_file_" + login + ".txt"; // назва файла з особистими даними
	fin.open(path + "\\" + file);
	if (fin.is_open())
		return true;
	else
		return false;
}

void ZapusFileMainMenu(ofstream& fout, DjerelFin djerelfin)
{
	if (fout.is_open()) // записуємо результати у файл
	{
		fout << fixed; // заокруглення при запису у файл
		fout << setprecision(2);  // заокруглює число до 2 знаків після коми
		fout << djerelfin.cash << endl; //Баланс готівки
		fout << djerelfin.card << endl; //Баланс картки
		fout << djerelfin.bank_account << endl; //Баланс банківського рахунку
		fout << djerelfin.credit << endl; //Баланс отриманого кредиту
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
	if (fout1.is_open()) // записуємо результати у файл
	{
		fout1 << fixed; // заокруглення при запису у файл
		fout1 << setprecision(2);  // заокруглює число до 2 знаків після коми
		fout1 << statvutrat.famaly << endl; //Баланс сім’я
		fout1 << statvutrat.car << endl; //Баланс автомобіль
		fout1 << statvutrat.comynal << endl; //Баланс комунальні послуги
		fout1 << statvutrat.producty << endl; //Баланс продукти
		fout1 << statvutrat.recreation << endl; //Баланс відпочинок
		fout1 << statvutrat.presents << endl; //Баланс подарунки
		fout1 << statvutrat.others << endl; //Баланс інші витрати

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
	if (fout2.is_open()) // записуємо результати у файл
	{
		fout2 << fixed; // заокруглення при запису у файл
		fout2 << setprecision(2);  // заокруглює число до 2 знаків після коми
		fout2 << fixed; // заокруглення при запису у файл
		fout2 << setprecision(2);  // заокруглює число до 2 знаків після коми
		fout2 << zalushok.zalushok_cash << endl; // Залишок готівки
		fout2 << zalushok.zalushok_card << endl; // Залишок картка
		fout2 << zalushok.zalushok_bank_account << endl; // Залишок банківський рахунок
		fout2 << zalushok.zalushok_credit << endl; // Залишок кредиту
	}
	fout2.close();
	cout << endl;
}

vector<string> Split(string data)  // Розбиває рядок по пробілу.
{
	vector<string> result;
	char* s = new char[data.size() + 1]; // оголошуємо масив для зберігання  символів
	strcpy(s, data.c_str());  // копіюємо рядок з типом char
	char* p = strtok(s, " "); // strtok рядок s розбиває по пробілу
	while (p != NULL) // перевірка, що рядок p не пустий
	{
		result.push_back(p); // поміщаємо частину рядка до пробіла в елемент вектора
		p = strtok(NULL, " "); // завершення циклу, бо зявляється порожній рядок
	}

	return result;
}

vector<string> Split1(string data)  // Розбиває рядок по крапці.
{
	vector<string> result;
	char* s = new char[data.size() + 1]; // оголошуємо масив для зберігання  символів
	strcpy(s, data.c_str());  // копіюємо рядок з типом char
	char* p = strtok(s, "."); // strtok рядок s розбиває по крапці
	while (p != NULL) // перевірка, що рядок p не пустий
	{
		result.push_back(p); // поміщаємо частину рядка до крапки в елемент вектора
		p = strtok(NULL, " "); // завершення циклу, бо зявляється порожній рядок
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
		cout << "Невірний вибір джерела фінансування." << endl;
	}
	
}

int ChoiceMonthDay(int choice)
{
	enum months // оголошуємо та перераховуємо змінну місяців
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
		cout << "Невірно обраний місяць!"  << endl;
}

string ChoiceMonthNazva(int choice)
{
	string Jan = "Січень";
	string Feb = "Лютий";
	string Mar = "Березень";
	string Apr = "Квітень";
	string May = "Травень";
	string Jun = "Червень";
	string Jul = "Липень";
	string Aug = "Серпень";
	string Sep = "Вересень";
	string Oct = "Жовтень";
	string Nov = "Листопад";
	string Dec = "Грудень";

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
		cout << "Невірно обраний місяць!" << endl;

}
