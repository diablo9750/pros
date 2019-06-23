#include "stdafx.h"
#include "struct.h" 
#include <fstream>
#include <iostream>

using namespace std;

namespace types {
	//--------------------------------------------------

	// ���� ���������� �������� ������ �� �����
	game *InGame(game &g, ifstream &ifst) {
		ifst >> g.country >> g.name >> g.director;
		return &g;
	}

	// ����� ���������� �������� ������ � �����
	void OutGame(game *g, ofstream &ofst) {
		ofst << "��� ������� �����. ������, ��� ��������� �����: " << g->country << ", �������� ������: " << g->name
			<< ", �������: " << g->director << endl;
	}

	//--------------------------------------------------

	// ���� ���������� ����������� �� ������
	cartoon *InCartoon(cartoon &c, ifstream &ifst)
	{
		ifst >> c.country >> c.name >> c.type;
		return &c;
	}

	// ����� ���������� ����������� � �����
	void OutCartoon(cartoon *c, ofstream &ofst)
	{
		ofst << "��� ���������. ������, ��� ��������� �����: " << c->country << ", �������� ������: " << c->name << ", ��� �����������: ";

		if (c->type == 1) {
			ofst << "����������" << endl;
		}
		if (c->type == 2) {
			ofst << "���������" << endl;
		}
	}

	
	//--------------------------------------------------

	//����� �� �����
	void Out(film *f, ofstream &ofst) {
		switch (f->key)
		{
		case 1:
		{
			OutGame((game*)f, ofst);
		}break;
		case 2:
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
	film *In(ifstream &ifst)
	{
		film *fm = new film;
		int k;
		ifst >> k;
		if (k == 1) {
			game *g = new game;
			fm = (film*)InGame(*g, ifst);
			fm->key = GAME;
			return fm;
		}
		if (k == 2)
		{
			cartoon *c = new cartoon;
			fm = (film*)InCartoon(*c, ifst);
			fm->key = CARTOON;
			return fm;
		}
		if (k < 1 || k>2)
		{
			return 0;
		}
	}

	//--------------------------------------------------

	// ������������� ����������
	void Init(container &b) {
		b.Top = nullptr;
		b.count = 0;
	}

	//���������� ���� ������
	int addlist(container &b, ifstream &ifst)
	{
		//���� ��������� ������
		if (b.count == 0)
		{
			b.Top = new List;
			if ((b.Top->data = In(ifst)) != 0)
				return 1;
			else
				return 0;

		}
		else
		{
			List *current = b.Top;
			for (int j = 0; j < b.count - 1; j++)
			{
				current = current->Next;
			}
			current->Next = new List;
			if ((current->Next->data = In(ifst)) != 0)
			{
				b.Top->Priv = current->Next;
				current->Next->Priv = current;
				current->Next->Next = b.Top;
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	// ���� ����������� ���������� �� ���������� ������
	void InContainer(container &b, ifstream &ifst) {
		while (!ifst.eof()) {
			if (addlist(b, ifst) != 0)
				b.count++;
		}
	}

	// ������� ���������� �� ���������
	void Clear(container &b) {
		List* current = b.Top;
		int i = 1;
		while (i < b.count)
		{
			current = current->Next;
			delete current->Priv;
			i++;
		}
		delete current;
		b.count = 0;
	}

	// ����� ����������� ���������� � ��������� �����
	void Out(container &b, ofstream &ofst)
	{
		List* current = b.Top;
		ofst << "��������� �������� ���������� ��������� ������: " << b.count << endl;
		for (int j = 1; j <= b.count; j++)
		{
			ofst << j << ": ";
			Out(current->data, ofst);
			current = current->Next;
		}
	}

	void OutFilter(container &b, ofstream &ofst)
	{
		List* current = b.Top;
		ofst << "������ ������� ������" << endl;
		for (int i = 1; i <= b.count; i++) {
			if (current->data->key == GAME)
			{
				Out(current->data, ofst);
			}
			current = current->Next;
		}
	}
}

