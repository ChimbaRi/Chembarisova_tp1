/*  

Класс Conference содержит данные о выступающих (Speakers), администрации (Administration) и программе (Conf_program).
    Для Speakers определено : ФИО, организация / ВУЗ, доклад, аннотация доклада.
    Для Administration определено : ФИО, должность, область ответственности на конференции.
    Для Conf_program определено : день, время выступлений и наименование.

Разработать класс Keeper, который реализует контейнер для хранения и обработки объектов.

Класс Keeper должен обеспечивать следующие функции :
    ▪ добавление и удаление производных объектов абстрактного класса Base(базовый класс определяется согласно варианту задания);
    ▪ полное сохранение себя в файле;
    ▪ полное восстановление себя из файла. 

 */
#include "Keeper.h"
#include <Windows.h>
int main()
{
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    Keeper keep;
    char c; 
    string s1, s2, s3, s4;
    while(true)
    {
        system("cls");
        cout << "1. Добавление и удаление информации пользователем" << endl;
        cout << "2. Считывание информации из файла" << endl;
        cout << "3. Сохранение информации в файл" << endl;
        cout << "4. Выход" << endl;
        cout << "\nВыберите действие: ";
        int n;
        cin >> n;
        system("cls");
        switch (n) {
        case 1:
            cout << "Какое действие вы хотите выполнить?\n" << endl;
            cout << "1. Добавление информации" << endl;
            cout << "2. Удаление информации" << endl;
            cout << "\nВыберите действие: ";
            int m;
            cin >> m;
            system("cls");
            switch (m) {
            case 1:
                cout << "Какую информацию вы хотите добавить?\n" << endl;
                cout << "1. О выступающем" << endl;
                cout << "2. О работнике администрации" << endl;
                cout << "3. О программе" << endl;
                cout << "\nВыберите действие: ";
                int j;
                cin >> j;
                system("cls");
                switch (j) {
                case 1:
                    cout << "Введите информацию в формате:\nФИО\nОрганизация или ВУЗ\nДоклад\nАннотация доклада\n" << endl;
                    getchar();
                    getline(cin, s1);
                    getline(cin, s2);
                    getline(cin, s3);
                    getline(cin, s4);
                    keep.Set_Speakers(s1, s2, s3, s4);
                    break;
                case 2:
                    cout << "Введите информацию в формате:\nФИО\nДолжность\nОбласть ответственности на конференции\n" << endl;
                    getchar();
                    getline(cin, s1);
                    getline(cin, s2);
                    getline(cin, s3);
                    keep.Set_Administration(s1, s2, s3);
                    break;
                case 3:
                    cout << "Введите информацию в формате:\nНаименование доклада\nДень/Месяд проведения\nВремя проведения (часы:минуты)\n" << endl;
                    getchar();
                    getline(cin, s1);
                    int d, m, h, min;
                    char c1, c2, c3, c4, c5;
                    cin >> c1 >> c2 >> c3 >> c4 >> c5;
                    d = 10 * (int(c1) - 48) + int(c2) - 48;
                    m = 10 * (int(c4) - 48) + int(c5) - 48;
                    cin >> c1 >> c2 >> c3 >> c4 >> c5;
                    h = 10 * (int(c1) - 48) + int(c2) - 48;
                    min = 10 * (int(c4) - 48) + int(c5) - 48;
                    keep.Set_Conf_program(s1, d, m, h, min);
                    break;
                default:
                    cout << "Данное действие не предусмотрено\n" << endl;
                }
                break;
            case 2:
                cout << "Какую информацию вы хотите удалить?\n" << endl;
                cout << "1. О выступающем" << endl;
                cout << "2. О работнике администрации" << endl;
                cout << "3. О программе" << endl;
                cout << "\nВыберите действие: ";
                int f, d;
                cin >> f;
                system("cls");
                switch (f) {
                case 1:
                    cout << "Введите номер выступающего, которого нужно исключить" << endl;
                    cin >> d;
                    keep.Delete_Speakers(d);
                    break;
                case 2:
                    cout << "Введите номер административного работника, которого нужно исключить" << endl;
                    cin >> d;
                    keep.Delete_Administration(d);
                    break;
                case 3:
                    cout << "Введите номер программы, которую нужно удалить" << endl;
                    cin >> d;
                    keep.Delete_Conf_program(d);
                    break;
                default:
                    cout << "Данное действие не предусмотрено\n" << endl;
                }
                break;
            default:
                cout << "Данное действие не предусмотрено\n" << endl;
            }
            system("cls");
            cout << "Вся информация на данный момент:\n" << endl;
            keep.Print_Speakers();
            keep.Print_Administration();
            keep.Print_Conf_program();
            cout << "Введите любой символ для продолжения" << endl;
            cin >> c;
            break;
        case 2:
            keep.Read();
            cout << "Информация получена:\n" << endl;
            cout << "Вся информация на данный момент:\n" << endl;
            keep.Print_Speakers();
            keep.Print_Administration();
            keep.Print_Conf_program();
            cout << "Введите любой символ для продолжения" << endl;
            cin >> c;
            break;
        case 3:
            keep.Save();
            cout << "Информация сохранена\n" << endl;
            cout << "Введите любой символ для продолжения" << endl;
            cin >> c;
            break;
        case 4:
            cout << "Завершение работы" << endl;
            return 0;
        default:
            cout << "Данное действие не предусмотрено\n" << endl;
            cout << "Введите любой символ для продолжения" << endl;
            cin >> c;
            break;
        }
    }
}