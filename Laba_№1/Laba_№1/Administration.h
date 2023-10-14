#pragma once
#include "Conference.h"
/* ��� Administration ���������� : ���, ���������,
������� ��������������� �� �����������. */
class Administration :
    public Conference
{
private:
    string Job_title;
    string Area_of_responsibility;
public:
    // ������������
    Administration();
    Administration(string n, string jt, string aor);
    Administration(const Administration& adm);

    // ����������
    ~Administration();

    // �������
    string Get_Name() override;
    string Get_Job_title();
    string Get_Area_of_responsibility();

    // �������
    void Set_Name(string n) override;
    void Set_Job_title(string jt);
    void Set_Area_of_responsibility(string aor);
};

