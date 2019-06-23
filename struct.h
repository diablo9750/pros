#ifndef _struct
#define _struct
namespace types {

	enum type { GAME = 1, CARTOON = 2 };
	//Игровой
	struct game {
		type key; //ключ
		char name[100];//Название фильма
		char director[100];//Имя режиссёра
	};

	//Мультфильм
	struct cartoon {
		type key; //ключ
		char name[100];//Название фильма
		int type;//Вид мультфильма
	};

	//Обобщённая структура
	struct film {
		type key; //ключ
	};

	// Простейший контейнер на основе одномерного массива
	struct container
	{
		enum { max_len = 100 }; // максимальная длина
		int len; // текущая длина
		film* cont[max_len];
	};
}
#endif
