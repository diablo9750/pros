#ifndef _struct
#define _struct
namespace types {

	enum type { GAME = 1, CARTOON = 2 };
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
		int type;//��� �����������
	};

	//���������� ���������
	struct film {
		type key; //����
	};

	// ���������� ��������� �� ������ ����������� �������
	struct container
	{
		enum { max_len = 100 }; // ������������ �����
		int len; // ������� �����
		film* cont[max_len];
	};
}
#endif
