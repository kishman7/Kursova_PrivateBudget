#pragma once
#define _CRT_SECURE_NO_DEPRECATE //ігнор помилок, які ще не створились
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>
#include <direct.h>
#include <fstream>
#include <iomanip> // для заокруглення значень до 2 знака після коми при запису у файл


using namespace std;

/// <summary>
/// Функція для реєстрації
/// </summary>
void Register(); // Функція для реєстрації
/// <summary>
/// Функція для введення логіна та пароля
/// </summary>
void Login(); // Функція для введення логіна та пароля
/// <summary>
/// Функція для меню визова
/// </summary>
void GenMenu(); // Функція для меню визова
/// <summary>
/// Функція для головного меню
/// </summary>
void MainMenu(string); // Функція для головного меню
/// <summary>
/// Функція для считування файла
/// </summary>
bool GetFileUser(string login, ifstream& fin); // Функція для считування файла при логінені


vector<string> Split(string data); // Функція розбиває рядок по пробілу

vector<string> Split1(string data); // Функція розбиває рядок по крапці


struct User // Структура для реєстрації та логіна
{
	string login;
	string password;
	string name;
	string age;
};
struct Operaciya // Структура для руху коштів
{
	string data;
	double suma;
	string typ; // Тип операції (дохід/витрата)
	string Vid = ""; // Вид операції (готівка/картка/банк.рахунок/кредит або статті витрат)

	// Сюди вписати написану функції, яка буде розділяти рядок по крапці
	int GetDataDay() // для розбиття рядка дати по крапці, для виведення числа з днем
	{
		return stoi((Split1(data))[0]);
	}
	int GetDataMonth() // для розбиття рядка дати по крапці, для виведення числа з місяцем
	{
		return stoi((Split1(data))[1]);
	}
	int GetDataYear() // для розбиття рядка дати по крапці, для виведення числа з роком
	{
		return stoi((Split1(data))[2]);
	}
};

struct DjerelFin // структура для заповнення файла джерела фінансування
{
	double cash = 0.0;
	double card = 0.0;
	double bank_account = 0.0;
	double credit = 0.0;
	vector<Operaciya> Ryh_koshtiv; // структура для Operaciya (дата, сума коштів, вид операції)

};



struct StatVutrat // структура для заповнення файла статті витрат
{
	double famaly = 0.0; // сім’я
	double car = 0.0; // автомобіль
	double comynal = 0.0; // комунальні послуги
	double producty = 0.0; // продукти
	double recreation = 0.0; // відпочинок
	double presents = 0.0; // подарунки
	double others = 0.0; // інші, які не входять в задані категорії

	vector<Operaciya> Ryh_koshtiv; // структура для Operaciya (дата, сума коштів, вид операції)
};

struct Zalushok
{
	double zalushok_cash = 0.0; // для відображення залишку готівки
	double zalushok_card = 0.0; // для відображення залишку картки
	double zalushok_bank_account = 0.0; // для відображення залишку банківського рахунку
	double zalushok_credit = 0.0; // для відображення залишку кредиту
};
/// <summary>
/// Функція для запису даних в файл в головному меню (MainMenu) для джерел фінансування
/// </summary>
/// <param name="fout"></param>
void ZapusFileMainMenu(ofstream& fout, DjerelFin djerelfin); // Функція для запису даних в файл в головному меню (UserCabinet) для джерел фінансування 
/// <summary>
/// Функція для запису даних в файл в головному меню (UserCabinet) для статтей витрат 
/// </summary>
/// <param name="fout"></param>
/// <param name="statvutrat"></param>
void ZapusFileMainMenuVutraty(ofstream& fout, StatVutrat statvutrat); // Функція для запису даних в файл в головному меню (UserCabinet) для статтей витрат 
/// <summary>
/// Функція для обрахунку залишку коштів по джерелам фінансування
/// </summary>
/// <param name="Num"></param>
/// <param name="zalushok"></param>
/// <param name="djerelfin"></param>
/// <param name="statvutrat"></param>
/// <returns></returns>
double ZalushokObrahunok(int Num, Zalushok& zalushok, DjerelFin djerelfin, double Vutrata); // Функція для обрахунку залишку коштів по джерелам фінансування
/// <summary>
/// Функція для запису даних в файл в головному меню (UserCabinet) для залишку коштів по джерелам фінансування 
/// </summary>
/// <param name="fout"></param>
/// <param name="zalushok"></param>
void ZapusFileZalushok(ofstream& fout, Zalushok zalushok); // Функція для запису даних в файл в головному меню (UserCabinet) для залишку коштів по джерелам фінансування 
/// <summary>
/// Функція для вибору місяця та виводу кількості днів
/// </summary>
/// <param name="choice"></param>
/// <returns></returns>
int ChoiceMonthDay(int choice); // Функція для вибору місяця та виводу кількості днів
/// <summary>
/// Функція для вибору назви місяця
/// </summary>
/// <param name="choice"></param>
/// <returns></returns>
string ChoiceMonthNazva(int choice); // Функція для вибору назви місяця

