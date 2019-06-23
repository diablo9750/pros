#include <fstream>
#include "struct.h" 
using namespace std;
namespace types {

	// ���� ���������� �������� ������ �� �����
	game* InGame(game& g, ifstream& ifst) {
		ifst >> g.name >> g.director;
		return &g;
	}

	// ����� ���������� �������� ������ � �����
	void OutGame(game* g, ofstream& ofst) {
		ofst << "��� ������� �����. �������� ������: " << g->name
			<< ", �������: " << g->director << endl;
	}

	//--------------------------------------------------

		// ���� ���������� ����������� �� ������
	cartoon* InCartoon(cartoon& c, ifstream& ifst)
	{
		ifst >> c.name >> c.type;
		return &c;
	}

	// ����� ���������� ����������� � �����
	void OutCartoon(cartoon* c, ofstream& ofst)
	{
		ofst << "��� ���������. �������� ������: "
			<< c->name << ", ��� �����������: ";

		if (c->type == 1) {
			ofst << "����������" << endl;
		}
		if (c->type == 2) {
			ofst << "���������" << endl;
		}
	}

	//--------------------------------------------------

	void Out(film* f, ofstream& ofst) {
		switch (f->key)
		{
			case GAME:
			{
				OutGame((game*)f, ofst);
			}break;
			case CARTOON:
			{
				OutCartoon((cartoon*)f, ofst);
			}break;
			default:
			{
				cout << "������������ �����!" << endl;
			}break;
		}
	}

	// ���� ���������� ����������� ������ �� �����
	film* In(ifstream& ifst)
	{
		film* fm = new film;
		int k;
		ifst >> k;
		if (k == 1) {
			game* g = new game;
			fm = (film*)InGame(*g, ifst);
			fm->key = GAME;
			return fm;
		}
		if (k == 2)
		{
			cartoon* c = new cartoon;
			fm = (film*)InCartoon(*c, ifst);
			fm->key = CARTOON;
			return fm;
		}
		else { return 0; }
	}

	//--------------------------------------------------

		// ������������� ����������
	void Init(container& b) { b.len = 0; }

	// ������� ���������� �� ���������
	void Clear(container& b) {
		for (int i = 0; i < b.len; i++) {
			delete b.cont[i];
		}
		b.len = 0;
	}

	// ���� ����������� ���������� �� ���������� ������
	void In(container& b, ifstream& ifst) {
		while (!ifst.eof()) {
			if ((b.cont[b.len] = In(ifst)) != 0) { b.len++; }
		}
	}

	// ����� ����������� ���������� � ��������� �����
	void Out(container& b, ofstream& ofst) {
		ofst << "��������� �������� ���������� ��������� ������: " << b.len << endl;
		for (int i = 0; i < b.len; i++) {
			ofst << i + 1 << ": ";
			Out((b.cont[i]), ofst);
		}
	}
}