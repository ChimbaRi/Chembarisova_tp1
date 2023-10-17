#include "Keeper.h"
Keeper::Keeper() {
	this->Speak = new Speakers[1];
	this->Admin = new Administration[1];
	this->Prog = new Conf_program[1];
	this->Size_Administration = this->Size_Conf_program = this->Size_Speakers = 0;
	cout << "Вызван конструктор без параметров для класса Keeper" << endl;
}
Keeper::Keeper(Speakers* S, Administration* A, Conf_program* P, int s1, int s2, int s3) {
	this->Speak = S;
	this->Admin = A;
	this->Prog = P;
	this->Size_Administration = s1;
	this->Size_Conf_program = s2;
	this->Size_Speakers = s3;
	cout << "Вызван конструктор с параметрами для класса Keeper" << endl;
}
Keeper::Keeper(const Keeper& keep) {
	this->Speak = keep.Speak;
	this->Admin = keep.Admin;
	this->Prog = keep.Prog;
	this->Size_Administration = keep.Size_Administration;
	this->Size_Conf_program = keep.Size_Conf_program;
	this->Size_Speakers = keep.Size_Speakers;
	cout << "Вызван конструктор копирования для класса Keeper" << endl;
}
Keeper::~Keeper() {
	delete[] Speak;
	delete[] Admin;
	delete[] Prog;
	cout << "Вызван деструктор для класса Keeper" << endl;
}
void Keeper::Save() {
	ofstream out;          // поток для записи
	out.open("read.txt");  // окрываем файл для записи
	bool fIt = true;   // проверка (избежание первого \n)
	if (out.is_open())
	{
		// Выступающие
		out << "Выступающие:" << endl;
		for (int i = 0; i < Size_Speakers; i++) {
			if (fIt == true) fIt = false;
			else
				out << "\n";
			out << Speak[i].Get_Name() << endl;
			out << Speak[i].Get_Organization() << endl;
			out << Speak[i].Get_Report() << endl;
			out << Speak[i].Get_Annotation() << endl;
		}
		// Администрация
		out << "\nАдминистрация:" << endl;
		for (int i = 0; i < Size_Administration; i++) {
			if (fIt == true) fIt = false;
			else
				out << "\n";
			out << Admin[i].Get_Name() << endl;
			out << Admin[i].Get_Job_title() << endl;
			out << Admin[i].Get_Area_of_responsibility() << endl;
		}
		// Программа 
		out << "\nПрограмма:" << endl;
		for (int i = 0; i < Size_Conf_program; i++) {
			if (fIt == true) fIt = false;
			else
				out << "\n";
			out << Prog[i].Get_Name() << endl;
			out << Prog[i].Get_Day() << "/" << Prog[i].Get_Month() << endl;
			out << Prog[i].Get_Hours()<<":" <<Prog[i].Get_Minutes()<< endl;
		}
	}
	out.close();
}
void Keeper::Read() {
	string fn;//новое ФИО/название
	string new_name;
	ifstream in("read.txt");
	string c;
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, c);
			if (c == "Выступающие:") {
				getline(in, fn);
				string o, n, a;
				getline(in, o);
				getline(in, n);
				getline(in, a);
				Set_Speakers(fn, o, n, a);
			}
			else
				if (c == "Администрация:") {
					getline(in, fn);
					string d, o;
					getline(in, d);
					getline(in, o);
					Set_Administration(fn, d, o);
				}
				else
					if (c == "Программа:") {
						getline(in, fn);
						string a;
						int d, m, h, min;
						getline(in, a);
						d = 10 * (int(a[0]) - 48) + int(a[1]) - 48;
						m = 10 * (int(a[3]) - 48) + int(a[4]) - 48;
						h = 10 * (int(a[0]) - 48) + int(a[1]) - 48;
						min = 10 * (int(a[3]) - 48) + int(a[4]) - 48;
						Set_Conf_program(fn, d, m, h, min);
					}
		}
	}
	in.close();
}
void Keeper::Set_Speakers(string s1, string s2, string s3, string s4) {
	Size_Speakers++;
	Speakers* S = new Speakers[Size_Speakers];
	for (int i = 0; i < Size_Speakers - 1; i++) {
		S[i] = Speak[i];
	}
	S[Size_Speakers - 1].Set_Name(s1);
	S[Size_Speakers - 1].Set_Organization(s2);
	S[Size_Speakers - 1].Set_Report(s3);
	S[Size_Speakers - 1].Set_Annotation(s4);
	Speak = S;
}
void Keeper::Set_Administration(string s1, string s2, string s3) {
	Size_Administration++;
	Administration* A = new Administration[Size_Administration];
	for (int i = 0; i < Size_Administration - 1; i++) {
		A[i] = Admin[i];
	}
	A[Size_Administration - 1].Set_Name(s1);
	A[Size_Administration - 1].Set_Job_title(s2);
	A[Size_Administration - 1].Set_Area_of_responsibility(s3);
	Admin = A;
}
void Keeper::Set_Conf_program(string s1, int n1, int n2, int n3, int n4) {
	Size_Conf_program++;
	Conf_program* P = new Conf_program[Size_Conf_program];
	for (int i = 0; i < Size_Conf_program - 1; i++) {
		P[i] = Prog[i];
	}
	P[Size_Conf_program - 1].Set_Name(s1);
	P[Size_Conf_program - 1].Set_Day(n1);
	P[Size_Conf_program - 1].Set_Month(n2);
	P[Size_Conf_program - 1].Set_Hours(n3);
	P[Size_Conf_program - 1].Set_Minutes(n4);
	Prog = P;
}
void Keeper::Print_Speakers() {
	cout << "Выступающие: " << endl;
	for (int i = 0; i < Size_Speakers; i++) {
		cout << i + 1 << ". " << Speak[i].Get_Name() << endl;
		cout << Speak[i].Get_Organization() << endl;
		cout << Speak[i].Get_Report() << endl;
		cout << Speak[i].Get_Annotation() << "\n" << endl;
	}
}
void Keeper::Print_Administration() {
	cout << "Администрация: " << endl;
	for (int i = 0; i < Size_Administration; i++) {
		cout << i + 1 << ". " << Admin[i].Get_Name() << endl;
		cout << Admin[i].Get_Job_title() << endl;
		cout << Admin[i].Get_Area_of_responsibility() << "\n" << endl;
	}
}
void Keeper::Print_Conf_program() {
	cout << "Программа: " << endl;
	for (int i = 0; i < Size_Conf_program; i++) {
		cout << i + 1 << ". " << Prog[i].Get_Name() << endl;
		cout << Prog[i].Get_Day() << "/" << Prog[i].Get_Month() << endl;
		cout << Prog[i].Get_Hours() << ":" << Prog[i].Get_Minutes() << "\n" << endl;
	}
}
void Keeper::Delete_Speakers(int n) {
	Speakers* S = new Speakers[Size_Speakers - 1];
	int b = 0;
	for (int i = 0; i < Size_Speakers; i++) {
		if (i == n - 1) continue;
		S[b] = Speak[i];
		b++;
	}
	Speak = S;
	Size_Speakers--;
}
void Keeper::Delete_Administration(int n) {
	Administration* A = new Administration[Size_Administration - 1];
	int b = 0;
	for (int i = 0; i < Size_Administration; i++) {
		if (i == n - 1) continue;
		A[b] = Admin[i];
		b++;
	}
	Admin = A;
	Size_Administration--;
}
void Keeper::Delete_Conf_program(int n) {
	Conf_program* C = new Conf_program[Size_Conf_program - 1];
	int b = 0;
	for (int i = 0; i < Size_Conf_program; i++) {
		if (i == n - 1) continue;
		C[b] = Prog[i];
		b++;
	}
	Prog = C;
	Size_Conf_program--;
}
int Keeper::Get_Size_Speakers() { return Size_Speakers; }
int Keeper::Get_Size_Administration() { return Size_Administration; }
int Keeper::Get_Size_Conf_program() { return Size_Conf_program; }
Speakers Keeper::Get_Speakers(int n) { return Speak[n]; }
Administration Keeper::Get_Administration(int n) { return Admin[n]; }
Conf_program Keeper::Get_Conf_program(int n) { return Prog[n]; }