#pragma once
#include "Conference.h"
/* Для Administration определено : ФИО, должность,
область ответственности на конференции. */
class Administration :
    public Conference
{
private:
    string Job_title;
    string Area_of_responsibility;
public:
    // Конструкторы
    Administration();
    Administration(string n, string jt, string aor);
    Administration(const Administration& adm);

    // Деструктор
    ~Administration();

    // Геттеры
    string Get_Name() override;
    string Get_Job_title();
    string Get_Area_of_responsibility();

    // Сеттеры
    void Set_Name(string n) override;
    void Set_Job_title(string jt);
    void Set_Area_of_responsibility(string aor);
};

