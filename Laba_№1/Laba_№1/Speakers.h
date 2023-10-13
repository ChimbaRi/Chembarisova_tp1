#pragma once
#include "Conference.h"
/* ��� Speakers ���������� : ���, ����������� / ���, ������, ��������� �������. */
class Speakers :
    public Conference
{
private:
    string Organization;
    string Report;
    string Annotation;
    int Number; // ����� ������������ �� �����������
public:
    // ������������
    Speakers();
    Speakers(string n, string o, string r, string a, int num);
    Speakers(const Speakers& speak);

    // ����������
    ~Speakers();

    // �������
    string Get_Name() override;
    string Get_Organization();
    string Get_Report();
    string Get_Annotation();
    int Get_Number();

    // �������
    void Set_Name(string n) override;
    void Set_Organization(string o);
    void Set_Report(string r);
    void Set_Annotation(string a);
    void Set_Number(int num);
};

