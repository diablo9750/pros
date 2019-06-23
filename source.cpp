#include <fstream>
#include "struct.h" 
using namespace std;
namespace types {

	// Ввод параметров игрового фильма из файла
	game* InGame(game& g, ifstream& ifst) {
		ifst >> g.name >> g.director;
		return &g;
	}

	// Вывод параметров игрового фильма в поток
	void OutGame(game* g, ofstream& ofst) {
		ofst << "Это игровой фильм. Название фильма: " << g->name
			<< ", Режиссёр: " << g->director << endl;
	}

	//--------------------------------------------------

		// Ввод параметров мультфильма из потока
	cartoon* InCartoon(cartoon& c, ifstream& ifst)
	{
		ifst >> c.name >> c.type;
		return &c;
	}

	// Вывод параметров мультфильма в поток
	void OutCartoon(cartoon* c, ofstream& ofst)
	{
		ofst << "Это мультильм. Название фильма: "
			<< c->name << ", вид мультфильма: ";

		if (c->type == 1) {
			ofst << "рисованный" << endl;
		}
		if (c->type == 2) {
			ofst << "кукольный" << endl;
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
				cout << "Некорректный фильм!" << endl;
			}break;
		}
	}

	// Ввод параметров обобщенного фильма из файла
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

		// Инициализация контейнера
	void Init(container& b) { b.len = 0; }

	// Очистка контейнера от элементов
	void Clear(container& b) {
		for (int i = 0; i < b.len; i++) {
			delete b.cont[i];
		}
		b.len = 0;
	}

	// Ввод содержимого контейнера из указанного потока
	void In(container& b, ifstream& ifst) {
		while (!ifst.eof()) {
			if ((b.cont[b.len] = In(ifst)) != 0) { b.len++; }
		}
	}

	// Вывод содержимого контейнера в указанный поток
	void Out(container& b, ofstream& ofst) {
		ofst << "Контейнер содержит количество элементов равное: " << b.len << endl;
		for (int i = 0; i < b.len; i++) {
			ofst << i + 1 << ": ";
			Out((b.cont[i]), ofst);
		}
	}
}