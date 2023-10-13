#pragma once
#include "Conference.h"
/* Для Speakers определено : ФИО, организация / ВУЗ, доклад, аннотация доклада. */
class Speakers :
    public Conference
{
private:
    string Organization;
    string Report;
    string Annotation;
    int Number; // Номер выступающего на конференции
public:
    // Конструкторы
    Speakers();
    Speakers(string n, string o, string r, string a, int num);
    Speakers(const Speakers& speak);

    // Деструктор
    ~Speakers();

    // Геттеры
    string Get_Name() override;
    string Get_Organization();
    string Get_Report();
    string Get_Annotation();
    int Get_Number();

    // Сеттеры
    void Set_Name(string n) override;
    void Set_Organization(string o);
    void Set_Report(string r);
    void Set_Annotation(string a);
    void Set_Number(int num);
};

