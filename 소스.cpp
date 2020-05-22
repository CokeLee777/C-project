#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int NAME_LEN = 20; //�л� �̸��� �迭�� �����ϱ����� ����� ����

class Student_Profile
{
private:
    char* Name;            //�л� �̸�
    int Num;                  //�л� �й�
    double Atd_Score;      //�⼮ ����(30%)
    double Hwk_Score;      //���� ����(10%)
    double Middle_Score;   //�߰���� ����(30%)
    double Final_Score;      //�⸻��� ����(30%)
    double Total_Score;    //ȯ�� �ջ� ����(100%)
public:
    Student_Profile(char* name, int num, double atd, double hwk, double middle, double final, double total)
        :Num(num), Atd_Score(atd), Hwk_Score(hwk), Middle_Score(middle), Final_Score(final), Total_Score(total)
    {
        Name = new char[strlen(name) + 1];
        strcpy(Name, name);
    }
    ~Student_Profile()
    {
        delete[] Name;
    }

    int get_StudentNum() { return Num; } //�й��� ��� �Լ�

    void Student_Show()
    {
        cout << "�̸� : " << Name << endl;
        cout << "�й� : " << Num << endl;
        cout << "�⼮ ���� : " << Atd_Score << endl;
        cout << "���� ���� : " << Hwk_Score << endl;
        cout << "�߰���� ���� : " << Middle_Score << endl;
        cout << "�⸻��� ���� : " << Final_Score << endl;
        cout << "ȯ���ջ� ���� : " << Total_Score << endl;
    }

};

Student_Profile* prfArr[100];      //�л����� ������ ���� Ŭ���� ��ü�� ������ �迭
int prfNum = 0;                     //����� �л����� ��

//�޴� �Լ�
void Menu(void)
{
    cout << "----------menu----------" << endl;
    cout << "1. �л� ���� ���" << endl;
    cout << "2. �л� ���� ����" << endl;
    cout << "3. �л� ���� Ž��" << endl;
    cout << "4. �л� ���� ��ü ���" << endl;
    cout << "5. ���α׷� ����" << endl;
}

//�л� ������ �Է� �޴� �Լ�
void Student_Input()
{
    char name[NAME_LEN];
    int num;
    double atd = 0, hwk = 0, middle = 0, final = 0, total = 0;
    cout << endl;
    cout << "==�л� ���� �Է�==" << endl;
    cout << "�̸� : "; cin >> name;
    cout << "�й� : "; cin >> num;
    cout << "�⼮ ���� : "; cin >> atd;
    cout << "���� ���� : "; cin >> hwk;
    cout << "�߰���� ���� : "; cin >> middle;
    cout << "�⸻��� ���� : "; cin >> final;
    total = (atd * 30 + hwk * 10 + middle * 30 + final * 30) / 100;
    prfArr[prfNum++] = new Student_Profile(name, num, atd, hwk, middle, final, total);
}

//�л� ������ ����� �Լ�
void Student_Delete()
{
    int num;
    cout << "�й��� �Է����ּ��� : "; cin >> num;

    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i]->get_StudentNum() == num)
        {
            cout << endl;
            delete prfArr[i];
            prfArr[i] = NULL;

            for (int j = i; j < prfNum; j++)      //�л� ������ ���� �� �迭�� ������ �����ϱ� ���� �ݺ���
            {
                prfArr[j] = prfArr[j + 1];

            }

            prfNum -= 1;                        //�л� ������ ���� �� �л� �� �ϳ��� ������

            cout << "���� �Ǿ����ϴ�." << endl;
            break;
        }
    }

}

//�л� ������ Ž���ϴ� �Լ�
void Student_Search()
{
    int num;
    cout << "�й��� �Է����ּ��� : "; cin >> num;
    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i]->get_StudentNum() == num)
        {
            if (prfArr[i] != NULL)
            {
                cout << endl;
                prfArr[i]->Student_Show();
                break;
            }
        }
    }
}

//�л� ������ ��ü ����ϴ� �Լ�
void Student_AllOutput()
{
    cout << "==�л� ���� ��ü ���== " << endl;
    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i] != NULL)
        {
            prfArr[i]->Student_Show();
            cout << endl;
        }
    }
}

int main(void)
{
    int choice;

    while (1)
    {
        Menu();
        cout << "��ȣ�� �Է��ϼ��� : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Student_Input();
            break;
        case 2:
            if (prfNum > 0)
            {
                Student_Delete();
            }
            else
            {
                cout << endl;
                cout << "��ϵ� �л� ������ �����ϴ�." << endl << endl;
            }
            break;
        case 3:
            if (prfNum > 0)
            {
                Student_Search();
            }
            else
            {
                cout << endl;
                cout << "��ϵ� �л� ������ �����ϴ�." << endl << endl;
            }
            break;
        case 4:
            if (prfNum > 0)
            {
                Student_AllOutput();
            }
            else
            {
                cout << endl;
                cout << "��ϵ� �л� ������ �����ϴ�." << endl << endl;
            }
            break;
        case 5:
            for (int i = 0; i < prfNum; i++)
            {
                delete prfArr[i]; //���α׷� ���� ���� �л� ���� ����
            }
            cout << "���α׷��� �����մϴ�." << endl;
            return 0;
        default:
            cout << "���ڸ� �߸� �Է��ϼ̽��ϴ�." << endl;
        }
    }
    return 0;
}