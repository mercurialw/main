#include "DList.h"
#include "Windows.h"

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    Dlist lst;
    lst.add_back(Data("������", "�������", "��������", "��������", 56, 78, 9204076147, 1999.9));
    lst.add_back(Data("��������", "���������", "����������", "������. ���������", 17, 1, 0052342434, -150));
    lst.add_back(Data("��������", "���������", "��������", "�������", 57, 27, 9092109905, 270.15));
    lst.add_back(Data("�������", "���������", "�", "����� ��������", 51, 123, 9005938448, -23000));
    lst.print();
    lst.sort();
    lst.print();
    lst.delete_neg();
    lst.print();
    return 0;
}