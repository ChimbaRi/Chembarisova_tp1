#pragma once
#include <iostream>
#include <string>

using namespace std;

class Conference
{
private:
    string Name; // ��� ��� ������������ �����������
protected:
    // �������
    virtual string Get_Name() = 0;
    // �������
    virtual void Set_Name(string n) = 0;
};

