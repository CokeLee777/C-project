#include <iostream>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

const int NAME_LEN = 20; //학생 이름을 배열로 저장하기위한 상수형 변수

class Student_Profile
{
private:
    char* Name;            //학생 이름
    int Num;               //학생 학번
    double Atd_Score;      //출석 점수(30%)
    double Hwk_Score;      //과제 점수(10%)
    double Middle_Score;   //중간고사 점수(30%)
    double Final_Score;    //기말고사 점수(30%)
    double Total_Score;    //환산 합산 점수(100%)

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

    int get_StudentNum() { return Num; } //학번을 얻는 함수

    void Student_Show()
    {
        cout << "이름 : " << Name << endl;
        cout << "학번 : " << Num << endl;
        cout << "출석 점수 : " << Atd_Score << endl;
        cout << "과제 점수 : " << Hwk_Score << endl;
        cout << "중간고사 점수 : " << Middle_Score << endl;
        cout << "기말고사 점수 : " << Final_Score << endl;
        cout << "환산합산 점수 : " << Total_Score << endl;
    }

    void Student_Arr()
    {
        cout << "   " << Name << "  ";
        cout << "  " << Num << "   ";
        cout << "       " << Total_Score << "  ";
    }
};

Student_Profile* prfArr[100];      //학생정보 저장을 위한 클래스 객체의 포인터 배열
int prfNum = 0;                    //저장된 학생정보 수

//메뉴 함수
void Menu(void)
{
    cout << "----------menu----------" << endl;
    cout << "1. 학생 정보 등록" << endl;
    cout << "2. 학생 정보 삭제" << endl;
    cout << "3. 학생 정보 탐색" << endl;
    cout << "4. 학생 정보 전체 출력" << endl;
    cout << "5. 최종점수 출력" << endl;
    cout << "6. 프로그램 종료" << endl;
}

double Score_percent[4] = { 0,0,0,0 }; //점수비율을 입력받을 배열

//점수 비율을 입력 받는 함수
void Percent_set()
{
    cout << "점수 비율 입력 (출석비율,과제비율,중간고사비율,기말고사비율) : ";
    cin >> Score_percent[0] >> Score_percent[1] >> Score_percent[2] >> Score_percent[3];
}

//학생 정보를 입력 받는 함수
void Student_Input()
{
    char name[NAME_LEN];
    int num;
    double atd = 0, hwk = 0, middle = 0, final = 0, total = 0;
    cout << endl;
    cout << "==학생 정보 입력==" << endl;
    cout << "이름 : "; cin >> name;
    cout << "학번 : "; cin >> num;
    cout << "출석 점수 : "; cin >> atd;
    cout << "과제 점수 : "; cin >> hwk;
    cout << "중간고사 점수 : "; cin >> middle;
    cout << "기말고사 점수 : "; cin >> final;
    total = (atd * Score_percent[0] + hwk * Score_percent[1] + middle * Score_percent[2] + final * Score_percent[3]) / 100;
    prfArr[prfNum++] = new Student_Profile(name, num, atd, hwk, middle, final, total);
}

//학생 정보를 지우는 함수
void Student_Delete()
{
    int num;
    cout << "학번을 입력해주세요 : "; cin >> num;

    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i]->get_StudentNum() != NULL && prfArr[i]->get_StudentNum() == num)
        {
            cout << endl;
            delete prfArr[i];
            prfArr[i] = NULL;

            for (int j = i; j < prfNum; j++)      //학생 정보를 지운 뒤 배열을 앞으로 정렬하기 위한 반복문
            {
                prfArr[j] = prfArr[j + 1];

            }

            prfNum -= 1;                          //학생 정보를 지운 뒤 학생 수 하나를 삭제함

            cout << "삭제 되었습니다." << endl;
            break;
        }
        else if (prfArr[i]->get_StudentNum() != num && prfArr[i + 1] == NULL)
        {
            cout << endl;
            cout << "존재하지 않는 학번입니다. " << endl;
            break;
        }
    }
}

//학생 정보를 탐색하는 함수
void Student_Search()
{
    int num;
    cout << "학번을 입력해주세요 : "; cin >> num;
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
        else if (prfArr[i]->get_StudentNum() != num && prfArr[i + 1] == NULL)
        {
            cout << endl;
            cout << "존재하지 않는 학번입니다. " << endl;
            break;

        }
    }
}

//학생 정보를 전체 출력하는 함수
void Student_AllOutput()
{
    cout << "==학생 정보 전체 출력== " << endl;
    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i] != NULL)
        {
            prfArr[i]->Student_Show();
            cout << endl;
        }
    }
}

//입력받은 학생 정보 중 이름, 학번, 최종점수를 출력하는 함수
void Student_Rank()
{
    cout << endl;
    cout << "          == 최종 성적 == " << endl;
    cout << "    이름       학번         최종 점수" << endl;
    for (int i = 0; i < prfNum; i++)
    {
        if (prfArr[i] != NULL)
        {
            prfArr[i]->Student_Arr();
            cout << endl;
        }
    }
}

int main(void)
{
    Percent_set();

    int choice;

    while (1)
    {
        Menu();
        cout << "번호를 입력하세요 : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (prfNum < 100)       //저장할 수 있는 최대 학생 수는 100명으로 임의 설정되어있음.
            {
                cout << endl;
                cout << "현재 정보가 입력된 학생의 수 (" << prfNum << " / 100명)";
                Student_Input();
                break;
            }
            else {
                cout << endl;
                cout << "입력 가능한 학생 수를 초과하였습니다." << endl;
                break;
            }
            break;
        case 2:
            if (prfNum > 0)
            {
                Student_Delete();
            }
            else
            {
                cout << endl;
                cout << "등록된 학생 정보가 없습니다." << endl << endl;
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
                cout << "등록된 학생 정보가 없습니다." << endl << endl;
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
                cout << "등록된 학생 정보가 없습니다." << endl << endl;
            }
            break;
        case 5:
            if (prfNum > 0) {
                Student_Rank();
            }
            else {
                cout << endl;
                cout << "등록된 학생 정보가 없습니다. " << endl << endl;
            }
            break;

        case 6:
            for (int i = 0; i < prfNum; i++)
            {
                delete prfArr[i]; //프로그램 종료 전에 학생 정보 삭제
            }
            cout << "프로그램을 종료합니다." << endl;
            return 0;
        default:
            cout << "숫자를 잘못 입력하셨습니다." << endl;
        }
    }
    return 0;
}