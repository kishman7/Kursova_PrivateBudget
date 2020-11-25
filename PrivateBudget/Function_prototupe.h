#pragma once
#define _CRT_SECURE_NO_DEPRECATE //����� �������, �� �� �� ����������
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>
#include <direct.h>
#include <fstream>
#include <iomanip> // ��� ������������ ������� �� 2 ����� ���� ���� ��� ������ � ����


using namespace std;

/// <summary>
/// ������� ��� ���������
/// </summary>
void Register(); // ������� ��� ���������
/// <summary>
/// ������� ��� �������� ����� �� ������
/// </summary>
void Login(); // ������� ��� �������� ����� �� ������
/// <summary>
/// ������� ��� ���� ������
/// </summary>
void GenMenu(); // ������� ��� ���� ������
/// <summary>
/// ������� ��� ��������� ����
/// </summary>
void MainMenu(string); // ������� ��� ��������� ����
/// <summary>
/// ������� ��� ���������� �����
/// </summary>
bool GetFileUser(string login, ifstream& fin); // ������� ��� ���������� ����� ��� ������


vector<string> Split(string data); // ������� ������� ����� �� ������

vector<string> Split1(string data); // ������� ������� ����� �� ������


struct User // ��������� ��� ��������� �� �����
{
	string login;
	string password;
	string name;
	string age;
};
struct Operaciya // ��������� ��� ���� �����
{
	string data;
	double suma;
	string typ; // ��� �������� (�����/�������)
	string Vid = ""; // ��� �������� (������/������/����.�������/������ ��� ����� ������)

	// ���� ������� �������� �������, ��� ���� �������� ����� �� ������
	int GetDataDay() // ��� �������� ����� ���� �� ������, ��� ��������� ����� � ����
	{
		return stoi((Split1(data))[0]);
	}
	int GetDataMonth() // ��� �������� ����� ���� �� ������, ��� ��������� ����� � ������
	{
		return stoi((Split1(data))[1]);
	}
	int GetDataYear() // ��� �������� ����� ���� �� ������, ��� ��������� ����� � �����
	{
		return stoi((Split1(data))[2]);
	}
};

struct DjerelFin // ��������� ��� ���������� ����� ������� ������������
{
	double cash = 0.0;
	double card = 0.0;
	double bank_account = 0.0;
	double credit = 0.0;
	vector<Operaciya> Ryh_koshtiv; // ��������� ��� Operaciya (����, ���� �����, ��� ��������)

};



struct StatVutrat // ��������� ��� ���������� ����� ����� ������
{
	double famaly = 0.0; // ���
	double car = 0.0; // ���������
	double comynal = 0.0; // ��������� �������
	double producty = 0.0; // ��������
	double recreation = 0.0; // ���������
	double presents = 0.0; // ���������
	double others = 0.0; // ����, �� �� ������� � ����� �������

	vector<Operaciya> Ryh_koshtiv; // ��������� ��� Operaciya (����, ���� �����, ��� ��������)
};

struct Zalushok
{
	double zalushok_cash = 0.0; // ��� ����������� ������� ������
	double zalushok_card = 0.0; // ��� ����������� ������� ������
	double zalushok_bank_account = 0.0; // ��� ����������� ������� ����������� �������
	double zalushok_credit = 0.0; // ��� ����������� ������� �������
};
/// <summary>
/// ������� ��� ������ ����� � ���� � ��������� ���� (MainMenu) ��� ������ ������������
/// </summary>
/// <param name="fout"></param>
void ZapusFileMainMenu(ofstream& fout, DjerelFin djerelfin); // ������� ��� ������ ����� � ���� � ��������� ���� (UserCabinet) ��� ������ ������������ 
/// <summary>
/// ������� ��� ������ ����� � ���� � ��������� ���� (UserCabinet) ��� ������� ������ 
/// </summary>
/// <param name="fout"></param>
/// <param name="statvutrat"></param>
void ZapusFileMainMenuVutraty(ofstream& fout, StatVutrat statvutrat); // ������� ��� ������ ����� � ���� � ��������� ���� (UserCabinet) ��� ������� ������ 
/// <summary>
/// ������� ��� ��������� ������� ����� �� �������� ������������
/// </summary>
/// <param name="Num"></param>
/// <param name="zalushok"></param>
/// <param name="djerelfin"></param>
/// <param name="statvutrat"></param>
/// <returns></returns>
double ZalushokObrahunok(int Num, Zalushok& zalushok, DjerelFin djerelfin, double Vutrata); // ������� ��� ��������� ������� ����� �� �������� ������������
/// <summary>
/// ������� ��� ������ ����� � ���� � ��������� ���� (UserCabinet) ��� ������� ����� �� �������� ������������ 
/// </summary>
/// <param name="fout"></param>
/// <param name="zalushok"></param>
void ZapusFileZalushok(ofstream& fout, Zalushok zalushok); // ������� ��� ������ ����� � ���� � ��������� ���� (UserCabinet) ��� ������� ����� �� �������� ������������ 
/// <summary>
/// ������� ��� ������ ����� �� ������ ������� ���
/// </summary>
/// <param name="choice"></param>
/// <returns></returns>
int ChoiceMonthDay(int choice); // ������� ��� ������ ����� �� ������ ������� ���
/// <summary>
/// ������� ��� ������ ����� �����
/// </summary>
/// <param name="choice"></param>
/// <returns></returns>
string ChoiceMonthNazva(int choice); // ������� ��� ������ ����� �����

