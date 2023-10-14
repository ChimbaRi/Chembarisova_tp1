#pragma once
#include "Conference.h"
/* Для Conf_program определено : день, время выступлений и наименование. */
class Conf_program :
    public Conference
{
private:
    int Day;
    int Month;
    int Seconds;
    int Hours;
public:
    // Конструкторы
    Conf_program();
    Conf_program(string n, int d, int m, int s, int h);
    Conf_program(const Conf_program& con);

    // Деструктор
    ~Conf_program();

    // Геттеры
    string Get_Name() override;
    int Get_Day();
    int Get_Month();
    int Get_Seconds();
    int Get_Hours();

    // Сеттеры
    void Set_Name(string n) override;
    void Set_Day(int d);
    void Set_Month(int m);
    void Set_Seconds(int s);
    void Set_Hours(int h);
};

