#include "stdafx.h"
#include "struct.h" 
#include <fstream>
#include <iostream>

using namespace std;

namespace types {
	//--------------------------------------------------

	// Ввод параметров игрового фильма из файла
	game *InGame(game &g, ifstream &ifst) {
		ifst >> g.country >> g.name >> g.director;
		return &g;
	}

	// Вывод параметров игрового фильма в поток
	void OutGame(game *g, ofstream &ofst) {
		ofst << "Это игровой фильм. Страна, где произведён фильм: " << g->country << ", Название фильма: " << g->name
			<< ", Режиссёр: " << g->director << endl;
	}

	//--------------------------------------------------

	// Ввод параметров мультфильма из потока
	cartoon *InCartoon(cartoon &c, ifstream &ifst)
	{
		ifst >> c.country >> c.name >> c.type;
		return &c;
	}

	// Вывод параметров мультфильма в поток
	void OutCartoon(cartoon *c, ofstream &ofst)
	{
		ofst << "Это мультильм. Страна, где произведён фильм: " << c->country << ", Название фильма: " << c->name << ", вид мультфильма: ";

		if (c->type == 1) {
			ofst << "рисованный" << endl;
		}
		if (c->type == 2) {
			ofst << "кукольный" << endl;
		}
	}

	
	//--------------------------------------------------

	//Вывод по ключу
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
			cout << "Некорректный фильм!" << endl;
		}break;
		}
	}

	// Ввод параметров обобщенного фильма из файла
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

	// Инициализация контейнера
	void Init(container &b) {
		b.Top = nullptr;
		b.count = 0;
	}

	//Добавление узла списка
	int addlist(container &b, ifstream &ifst)
	{
		//Если контейнер пустой
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

	// Ввод содержимого контейнера из указанного потока
	void InContainer(container &b, ifstream &ifst) {
		while (!ifst.eof()) {
			if (addlist(b, ifst) != 0)
				b.count++;
		}
	}

	// Очистка контейнера от элементов
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

	// Вывод содержимого контейнера в указанный поток
	void Out(container &b, ofstream &ofst)
	{
		List* current = b.Top;
		ofst << "Контейнер содержит количество элементов равное: " << b.count << endl;
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
		ofst << "Только игровые фильмы" << endl;
		for (int i = 1; i <= b.count; i++) {
			if (current->data->key == GAME)
			{
				Out(current->data, ofst);
			}
			current = current->Next;
		}
	}
}

