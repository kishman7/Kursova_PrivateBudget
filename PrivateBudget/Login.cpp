#include "Function_prototupe.h"

void Login() // функція для введення логіна та пароля
{
	cout << "Пройдіть авторизацію!" << endl << endl;
	string login, password;
	int N = 3; // кількість введення спроб
	cout << "У Вас є " << N << " спроби!!! Будьте уважні!!!" << endl;
	bool flag = false; // булівська змінна для підтвердження введеного пароля

	for (int i = 0; i < N; i++)
	{
		cout << "Введіть свій логін -> " << endl;
		cin >> login;
		cout << "Введіть свій пароль -> " << endl;
		cin >> password;
		ifstream fin;
		//string path = "Users\\" + login; // шлях до папки користувача
		//string file = "log_file_" + login + ".txt"; // назва файла з особистими даними

		//fin.open(path + "\\" + file);
		if (GetFileUser(login, fin))
		{
			User user;
			fin >> user.login >> user.password >> user.name >> user.age;

			if (login == user.login && password == user.password)
			{
				flag = true;
				cout << "Ви успішно авторизувались!" << endl << endl;
				break;
			}
			else
			{
				cout << "Пароль введено не вірно!" << endl << endl;

			}

		}
		else
		{
			cout << "Такого користувача не існує!!!" << endl;
		}
	}
	if (flag == false)
	{
		cout << "Вибачте, але Ви використали свої " << N << " спроби!!!" << endl << endl;
	}
	MainMenu(string(login));

}