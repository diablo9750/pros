// ConsoleApplication2.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <clocale>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "struct.h"


using namespace std;
using namespace types;

namespace types {
	// ��������� ��������� ������� �������

	void Init(container &b);
	void Clear(container &b);
	game *InGame(game &g, ifstream &ifst);
	void OutGame(game *g, ofstream &ofst);
	cartoon *InCartoon(cartoon &c, ifstream &ifst);
	void OutCartoon(cartoon *c, ofstream &ofst);
	void Out(film *f, ofstream &ofst);
	film *In(ifstream &ifst);
	int addlist(container &b, ifstream &ifst);
	void InContainer(container &b, ifstream &ifst);
	void Out(container &b, ofstream &ofst);
	bool Compare(film *first, film *second);
}


void main(int argc, char* argv[])
{
	SetConsoleCP(1251);// ��������� ������� �������� win-cp 1251 � ����� �����
	SetConsoleOutputCP(1251); // ��������� ������� �������� win-cp 1251 � ����� ������ 
	setlocale(LC_CTYPE, "rus"); // ����� ������� ��������� ������

	ifstream ifst("in.txt");
	ofstream ofst("out.txt", ios::trunc);
	/*if (argc != 3) {
	cout << "incorrect command line! "
	"Waited: command infile outfile" << endl;
	exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);*/
	cout << "�����!" << endl;
	container b;
	Init(b);
	InContainer(b, ifst);
	ofst << "��������� ��������. " << endl;
	Out(b, ofst);
	Clear(b);
	ofst << "��������� ����. " << endl;
	Out(b, ofst);
	cout << "����." << endl;


	system("pause");

}


