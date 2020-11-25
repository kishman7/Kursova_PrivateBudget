#include "Function_prototupe.h"

void Register() // Функція для реєстрації
{
	string login, password, password2, name, age;
	cout << "Зареєструйтесь в системі!" << endl << endl;
	cout << "Введіть логін-> ";
	cin >> login;

	ifstream fin;
	if (GetFileUser(login, fin))
	{
		system("cls"); // очищає екран консолі (все що вище даної команди)
		cout << "Користувач вже існує!" << endl << endl;
	}
	else
	{

		do  // цикл для підтвердження пароля
		{
			cout << "Введіть пароль -> ";
			cin >> password;
			cout << "Підтвердіть пароль (дане поле має співпадати з попереднім полем) -> ";
			cin >> password2;
			if (password == password2)
			{
				cout << "Вітаємо! Пароль зареєстровано вірно!" << endl;
			}
			else if (password != password2)
			{
				cout << "Помилка! Невірно підтверджений введений пароль!" << endl;
				cout << "Повторіть спробу введення пароля." << endl;
			}
		} while (password != password2);

		cout << "Введіть своє ім’я -> ";
		cin >> name;
		cout << "Введіть свій вік -> ";
		cin >> age;
		cout << endl;

		User user;
		user.login = login;
		user.password = password;
		user.name = name;
		user.age = age;

		/*Створення папки для користувача при реєстрації з іменем логіна*/
		string path = "Users\\" + login; // створення папки з назвою логіна
		const char* folder = path.c_str(); // c_str() - вертає масив символів
		_mkdir(folder);

		string file = "log_file_" + login + ".txt"; // формується назва файла з особистими даними
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
			cout << "Невірний шлях до файла або невірна назва файла!" << endl;
		}
		fout.close();

		//Оголошуємо змінні та заповнюємо ними поля структури для запису їх в створений файл djerelfin

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
		string file1 = "djerelfin_" + login + ".txt"; // формується назва файла з джерелами фінансування у юзера
		ofstream fout1;

		fout1.open(path + "\\" + file1);
		if (fout1.is_open())
		{
			fout1 << djerelfin.cash << endl; //Баланс готівки
			fout1 << djerelfin.card << endl; //Баланс картки
			fout1 << djerelfin.bank_account << endl; //Баланс банківського рахунку
			fout1 << djerelfin.credit << endl; //Баланс отриманого кредиту
		}
		else
		{
			cout << "Невірний шлях до файла або невірна назва файла!" << endl;
		}

		fout1.close();

		//Оголошуємо змінні та структуру для запису їх в створений файл statvutrat

		double famaly = 0.0; // сім’я
		double car = 0.0; // автомобіль
		double comynal = 0.0; //комунальні послуги
		double producty = 0.0; // продукти
		double recreation = 0.0; // відпочинок
		double presents = 0.0; // подарунки
		double others = 0.0; // інші, які не входять в задані категорії

		StatVutrat statvutrat; // структура для заповнення файла статті витрат
		statvutrat.famaly = famaly;
		statvutrat.car = car;
		statvutrat.comynal = comynal;
		statvutrat.producty = producty;
		statvutrat.recreation = recreation;
		statvutrat.presents = presents;
		statvutrat.others = others;

		string file2 = "statvutrat_" + login + ".txt"; // формується назва файла з статтями витрат у юзера
		ofstream fout2;

		fout2.open(path + "\\" + file2);
		if (fout2.is_open())
		{
			fout2 << statvutrat.famaly << endl; //Баланс статті витрат сім’я
			fout2 << statvutrat.car << endl; //Баланс статті витрат автомобіль
			fout2 << statvutrat.comynal << endl; //Баланс статті витрат комунальні послуги
			fout2 << statvutrat.producty << endl; //Баланс статті витрат продукти
			fout2 << statvutrat.recreation << endl; //Баланс статті витрат відпочинок
			fout2 << statvutrat.presents << endl; //Баланс статті витрат подарунки
			fout2 << statvutrat.others << endl; //Баланс статті витрат інші витрати
		}
		else
		{
			cout << "Невірний шлях до файла або невірна назва файла!" << endl;
		}

		fout2.close();

		//Оголошуємо змінні та заповнюємо ними поля структури для запису їх в створений файл zalushok

		double zalushok_cash = 0.0; // для відображення залишку готівки
		double zalushok_card = 0.0; // для відображення залишку картки
		double zalushok_bank_account = 0.0; // для відображення залишку банківського рахунку
		double zalushok_credit = 0.0; // для відображення залишку кредиту

		Zalushok zalushok; // структура для заповнення файла zalushok
		zalushok.zalushok_cash = zalushok_cash;
		zalushok.zalushok_card = zalushok_card;
		zalushok.zalushok_bank_account = zalushok_bank_account;
		zalushok.zalushok_credit = zalushok_credit;

		string file3 = "zalushok_" + login + ".txt"; // формується назва файла з статтями витрат у юзера
		ofstream fout3;

		fout3.open(path + "\\" + file3);
		if (fout3.is_open())
		{
			fout3 << zalushok.zalushok_cash << endl; //Баланс статті витрат сім’я
			fout3 << zalushok.zalushok_card << endl; //Баланс статті витрат автомобіль
			fout3 << zalushok.zalushok_bank_account << endl; //Баланс статті витрат комунальні послуги
			fout3 << zalushok.zalushok_credit << endl; //Баланс статті витрат продукти
		}
		else
		{
			cout << "Невірний шлях до файла або невірна назва файла!" << endl;
		}

		fout3.close();
	}
}