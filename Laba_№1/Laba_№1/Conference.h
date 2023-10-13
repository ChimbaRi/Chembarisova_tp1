#pragma once
#include <iostream>
#include <string>

using namespace std;

class Conference
{
private:
    string Name; // ФИО или наименование выступления
protected:
    // Геттеры
    virtual string Get_Name() = 0;
    // Сеттеры
    virtual void Set_Name(string n) = 0;
};

