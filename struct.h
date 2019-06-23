#ifndef _struct
#define _struct

//�������� �������� �������
namespace types {

	enum type { GAME = 1, CARTOON = 2};
	//�������
	struct game {
		type key; //����
		char name[100];//�������� ������
		char director[100];//��� ��������
	};

	//����������
	struct cartoon {
		type key; //����
		char name[100];//�������� ������
		int type;
	};


	//���������� ���������
	struct film {
		type key; //����
	};

	struct List {
		List() {
			this->Next = nullptr;
			this->Priv = nullptr;
			this->data = nullptr;
		};
		List* Next;
		List* Priv;
		film* data;
	};

	// ���������� ��������� �� ������ ����������� �������
	struct container
	{
		List* Top;
		int count;
		void addlist();
	};
}
#endif
