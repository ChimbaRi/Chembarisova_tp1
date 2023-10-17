#pragma once
#include "Speakers.h"
#include "Conf_program.h"
#include "Administration.h"
#include <sstream>   
#include <fstream>
/* Класс Keeper должен обеспечивать следующие функции :
▪ добавление и удаление производных объектов абстрактного класса 
Base(базовый класс определяется согласно варианту задания);
▪ полное сохранение себя в файле;
▪ полное восстановление себя из файла. */
class Keeper
{
private:
	Speakers* Speak;
	Administration* Admin;
	Conf_program* Prog;
	int Size_Speakers;
	int Size_Administration;
	int Size_Conf_program;
public:
	// Конструкторы
	Keeper();
	Keeper(Speakers* S, Administration* A, Conf_program* P, int s1, int s2, int s3);
	Keeper(const Keeper& keep);

	// Деструктор
	~Keeper();

	// Геттеры
	Speakers Get_Speakers(int n);
	Administration Get_Administration(int n);
	Conf_program Get_Conf_program(int n);

	int Get_Size_Speakers();
	int Get_Size_Administration();
	int Get_Size_Conf_program();

	// Добавление или удаление информации из экземпляров классов
	void Set_Speakers(string s1, string s2, string s3, string s4);
	void Set_Administration(string s1, string s2, string s3);
	void Set_Conf_program(string s1, int n1, int n2, int n3, int n4);

	void Delete_Speakers(int n);
	void Delete_Administration(int n);
	void Delete_Conf_program(int n);

	// Вывод информации на экран
	void Print_Speakers();
	void Print_Administration();
	void Print_Conf_program();

	// Сохранение и считывание информации из файла
	void Save();
	void Read();
};

