#include "Speakers.h"
void Speakers::Set_Name(string n) { Conference::Set_Name(n); }
void Speakers::Set_Annotation(string a) { this->Annotation = a; }
void Speakers::Set_Organization(string o) { this->Organization = o; }
void Speakers::Set_Report(string r) { this->Report = r; }

string Speakers::Get_Name() { return Conference::Get_Name(); }
string Speakers::Get_Annotation() { return Annotation; }
string Speakers::Get_Report() { return Report; }
string Speakers::Get_Organization() { return Organization; }

Speakers::Speakers() {
	Set_Name("");
	Set_Annotation("");
	Set_Report("");
	Set_Organization("");
	cout << "Вызван конструктор без параметров для класса Speakers" << endl;
}
Speakers::Speakers(string n, string o, string r, string a){
	Set_Name(n);
	Set_Annotation(a);
	Set_Report(r);
	Set_Organization(o);
	cout << "Вызван конструктор с параметрами для класса Speakers" << endl;
}
Speakers::Speakers(const Speakers& speak) {
	Set_Name(speak.Name);
	Set_Annotation(speak.Annotation);
	Set_Report(speak.Report);
	Set_Organization(speak.Organization);
	cout << "Вызван конструктор копирования для класса Speakers" << endl;
}
Speakers::~Speakers() { cout << "Вызван деструктор для класса Speakers" << endl; }
