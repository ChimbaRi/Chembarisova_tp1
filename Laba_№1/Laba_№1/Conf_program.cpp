#include "Conf_program.h"
void Conf_program::Set_Name(string n) { Conference::Set_Name(n); }
void Conf_program::Set_Day(int d) { this->Day = d; }
void Conf_program::Set_Month(int m) { this->Month = m; }
void Conf_program::Set_Seconds(int s) { this->Seconds = s; }
void Conf_program::Set_Hours(int h) { this->Hours = h; }

string Conf_program::Get_Name() { return Conference::Get_Name(); }
int Conf_program::Get_Day() { return Day; }
int Conf_program::Get_Month() { return Month; }
int Conf_program::Get_Seconds() { return Seconds; }
int Conf_program::Get_Hours() { return Hours; }

Conf_program::Conf_program() {
	Set_Name(nullptr);
	Set_Day(NULL);
	Set_Month(NULL);
	Set_Seconds(NULL);
	Set_Hours(NULL);
	cout << "Вызван конструктор без параметров для класса Conf_program" << endl;
}
Conf_program::Conf_program(string n, int d, int m, int s, int h) {
	Set_Name(n);
	Set_Day(d);
	Set_Month(m);
	Set_Seconds(s);
	Set_Hours(h);
	cout << "Вызван конструктор с параметрами для класса Conf_program" << endl;
}
Conf_program::Conf_program(const Conf_program& con) {
	Set_Name(con.Name);
	Set_Day(con.Day);
	Set_Month(con.Month);
	Set_Seconds(con.Seconds);
	Set_Hours(con.Hours);
	cout << "Вызван конструктор копирования для класса Conf_program" << endl;
}
Conf_program::~Conf_program() { cout << "Вызван деструктор для класса Conf_program" << endl; }