/*Một trung tâm tin học có nhu cầu xây dựng hệ thống quản lý học viên(học viên có thể thêm vào không
hạn chế và có thể thêm bất kỳ thời điểm nào trong năm.
Một học viên có thông tin : mã học viên, tên học viên, năm sinh.
Hãy tổ chức CTDL cho yêu cầu trên */
#include <iostream>
using namespace std;

struct HocVien
{
	int maHv;
	string tenHv;
	int namSinh;
};

struct Node
{
	HocVien hv;
	Node* next;		// tro toi node tiep theo trong bo nho
	Node* prev;		// tro toi node truoc do trong dslk
};

// khoi tao danh sach
void init(Node*& head)		// head tro den ptu dau tien trong dslk
{
	head = NULL;
}

// tao node cua ds
Node* createNode(HocVien x)
{
	Node* p = new Node;
	p->hv = x;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

// them vao dau dslk
void ThemDau(Node*& head, HocVien x)
{
	Node* p = createNode(x);
	if (head==NULL)		// danh sach rong
	{
		head = p;
	}
	else	// danh sach khong rong
	{
		p->next = head;
		head->prev = p;
		head = p;
	}
}


void xuatHv(HocVien h)
{
	cout << "Ma hv: " << h.maHv << endl;
	cout << "Ten hv: " << h.tenHv << endl;
	cout << "Nam sinh: " << h.namSinh << endl;
}

// in dslk
void output(Node *head)
{
	Node* p = head;		// tro den nut dau tien
	while (p != NULL)
	{
		xuatHv(p->hv);	// in gia tri
		p = p->next;	// tro den ptu ke tiep
	}
}



int main()
{
	Node* head;
	init(head);

	HocVien hv1;
	hv1.maHv = 1;
	hv1.tenHv = "Nguyen Van A";
	hv1.namSinh = 2000;
	ThemDau(head, hv1);

	HocVien hv2;
	hv2.maHv = 2;
	hv2.tenHv = "Tran Thi B";
	hv2.namSinh = 1998;
	ThemDau(head, hv2);

	// In danh sách học viên
	cout << "Danh sach hoc vien: \n";
	output(head);


	system("pause");
	return 0;
}