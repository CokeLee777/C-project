#include <iostream>
# include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

const int NAME_LEN = 20;

class Student_Profile 
{
private:
	char *Name;				//학생 이름
	int Num;						//학생 학번
	double Atd_Score;      //출석 점수(30%)
	double Hwk_Score;		//과제 점수(10%)
	double Middle_Score;	//중간고사 점수(30%)
	double Final_Score;		//기말고사 점수(30%)
	double Total_Score;    //환산 합산 점수(100%)
public:
	Student_Profile(char *name, int num, double atd,  double hwk, double middle, double final , double total)
		:Num(num),Atd_Score(atd), Hwk_Score(hwk), Middle_Score(middle), Final_Score(final), Total_Score(total)
	{
		Name = new char[strlen(name) + 1];
		strcpy(Name, name);
	}
	~Student_Profile() 
	{
		delete[] Name;
	}

	int get_StudentNum() { return Num; } //학번을 얻는 함수

	void Student_Delete()
	{
		delete[] Name;

	}
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
	friend void Student_Search(Student_Profile &Search);
};

Student_Profile *prfArr[100];		//학생정보 저장을 위한 클래스 객체의 포인터 배열
int prfNum = 0;							//저장된 학생정보 수

//메뉴 함수
void Menu(void)
{
	cout << "----------menu----------" << endl;
	cout << "1. 학생 정보 등록" << endl;
	cout << "2. 학생 정보 삭제"<< endl;
	cout << "3. 학생 정보 탐색" << endl;
	cout << "4. 학생 정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
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
	total = (atd * 30 + hwk * 10 + middle * 30 + final * 30) / 100;
	prfArr[prfNum++] = new Student_Profile(name, num, atd, hwk, middle, final, total);
}

//학생 정보를 지우는 함수
void Student_Delete()
{
	
}

//학생 정보를 탐색하는 함수
void Student_Search(Student_Profile &Search)
{
	char name[NAME_LEN];
	cout << "학생 이름을 입력해주세요 : "; cin >> name;
	for (int i = 0; i < prfNum; i++)
	{
		if (prfArr[i]-> Name)
		{
			prfArr[i]->Student_Show();
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
		prfArr[i]->Student_Show(); 
		cout << endl;
	}
}

int main(void) 
{
	int choice;

	while (1)
	{
		Menu();
		cout << "번호를 입력하세요 : ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			Student_Input();
			break;
		case 2:
			Student_Delete();
			break;
		case 3:
			Student_Search();
			break;
		case 4:
			Student_AllOutput();
			break;
		case 5:
			for (int i = 0; i < prfNum; i++) 
			{
				delete prfArr[i]; //프로그램 종료 전에 학생 정보 삭제
			}
			return 0;
		default:
			cout << "숫자를 잘못 입력하셨습니다." << endl;
		}
	}
	return 0;
}
