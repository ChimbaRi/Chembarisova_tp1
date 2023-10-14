#include "Administration.h"
void Administration::Set_Name(string n) { Conference::Set_Name(n); }
void Administration::Set_Job_title(string jt) { this->Job_title = jt; }
void Administration::Set_Area_of_responsibility(string aor) { this->Area_of_responsibility = aor; }

string Administration::Get_Name() { return Conference::Get_Name(); }
string Administration::Get_Job_title() { return Job_title; }
string Administration::Get_Area_of_responsibility() { return Area_of_responsibility; }

Administration::Administration() {
	Set_Name(nullptr);
	Set_Job_title(nullptr);
	Set_Area_of_responsibility(nullptr);
	cout << "Вызван конструктор без параметров для класса Administration" << endl;
}
Administration::Administration(string n, string jt, string aor) {
	Set_Name(n);
	Set_Job_title(jt);
	Set_Area_of_responsibility(aor);
	cout << "Вызван конструктор с параметрами для класса Administration" << endl;
}
Administration::Administration(const Administration& adm) {
	Set_Name(adm.Name);
	Set_Job_title(adm.Job_title);
	Set_Area_of_responsibility(adm.Area_of_responsibility);
	cout << "Вызван конструктор копирования для класса Administration" << endl;
}
Administration::~Administration() { cout << "Вызван деструктор для класса Administration" << endl; }