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
public:
    // ������������
    Speakers();
    Speakers(string n, string o, string r, string a);
    Speakers(const Speakers& speak);

    // ����������
    ~Speakers();

    // �������
    string Get_Name() override;
    string Get_Organization();
    string Get_Report();
    string Get_Annotation();

    // �������
    void Set_Name(string n) override;
    void Set_Organization(string o);
    void Set_Report(string r);
    void Set_Annotation(string a);
};

