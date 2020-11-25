#include "Function_prototupe.h"

void GenMenu() {

	int action = 1;
	while (action)
	{
		cout << "----- М Е Н Ю -----" << endl << endl;
		cout << "1. Реєстрація нового аккаунта." << endl;
		cout << "2. Увійдіть в свій аккаунт (введіть логін та пароль)." << endl;
		cout << "0. Вихід." << endl;
		cout << endl;
		cout << "Виберіть потрібний пункт меню." << endl;
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
			cout << "Дякуємо.До побачення!" << endl;
			break;
		}
		default:
			cout << "Ви обрали не вірний пункт меню. Зробіть ще раз свій вибір!" << endl;
		}
		//system("cls"); // очищає екран консолі (все що вище даної команди)

	}

}