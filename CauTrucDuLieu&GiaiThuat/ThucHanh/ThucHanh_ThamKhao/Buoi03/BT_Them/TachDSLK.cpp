#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
struct List
{
	Node *first;
	Node *last;
};

void Init(List &l);
Node *GetNode(int x);
void AddFirst(List &l, Node *new_ele);
void InsertFirst(List &l, int x);
void CreateListFirst(List &l);
void PrintList(List &l);
Node* Search(List l, int x);
void Delete_Head(List &l);
void Delete_Tail(List &l);
void XoaSauNode_q(List &l, Node *q);
void Delete_Node(List &l, int x);
void Separating_List(List &l, List &ll, int x);

int main()
{
    List l, ll;
    Init(l);
    Init(ll);
    CreateListFirst(l);
    PrintList(l);
    cout<<"==================continue================="<<endl;
    int x;
    cout<<"Nhap gia tri ban muon tim: ";
    cin>>x;
    Node *ans;
    ans = Search(l,x);
    if (ans == NULL)
        cout<<"Gia tri khong ton tai!"<<endl;
    else
        cout<<"Tim thay tai dia chi "<<int(ans)<<endl;
    cout<<"==================continue================="<<endl;
    int x1;
    cout<<"Nhap gia tri ban muon lam can cu tach danh sach: ";
    cin>>x1;
    Separating_List(l,ll,x1);
    cout<<"Danh Sach L gom: "<<endl;
    PrintList(l);
    cout<<"==================continue================="<<endl;
    cout<<"Danh Sach L1 gom: "<<endl;
    PrintList(ll);
    cout<<"====================END===================="<<endl;
    return 0;
}
void Init(List &l)
{
    l.first = l.last = NULL;
}
Node *GetNode(int x)
{
    Node *p;
    p= new Node;
    if (p == NULL)
        return NULL;
    p->data = x;
    p->link = NULL;
    return p;
}
void AddFirst(List &l, Node *new_ele)
{
    if (l.first == NULL)
    {
        l.first = new_ele;
        l.last = l.first;
    }
    else
    {
        new_ele -> link = l.first;
        l.first  = new_ele;
    }
}
void InsertFirst(List &l, int x)
{
    Node* new_ele = GetNode(x);
    Node *ans;
    ans = Search(l, x);
    if (ans == NULL)
    {
        if (new_ele == NULL)
            return;
        AddFirst(l, new_ele);
    }
}
void CreateListFirst(List &l)
{
    int x;
    cout<<"Bat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc:"<<endl;
    do{
        cin>>x;
        if (x== -1)
            break;
        InsertFirst(l, x);

    }while (x != -1);
    cout<<"da nhap du lieu xong!"<<endl;
}
void PrintList(List &l)
{
    Node *p;
    p=l.first;

    cout<<left<<setw(16)<<"Gia tri PT"<<setw(10)<<"Dia chi"<<endl;
    while (p!= NULL)
    {
        cout<<left<<setw(10)<<p->data<<"\t"<<setw(10)<<int(p)<<endl;
        p= p->link;
    }
}

Node* Search(List l, int x)
{
    Node *p;
    p=l.first;
    while (p!= NULL)
    {
        if (p->data == x)
            return p;
        p= p->link;
    }
    return NULL;
}
void Delete_Head(List &l)
{
	if (l.first == NULL)
	{
		return;
	}
	Node *p = l.first;
	l.first = l.first->link;
	delete p;
}
void Delete_Tail(List &l)
{
	if (l.first == NULL)
	{
		return;
	}
	if (l.first->link == NULL)
	{
		Delete_Head(l);
		return;
	}
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (k->link == l.last)
		{
			delete l.first;
			k->link = NULL;
			l.last = k;
			return;
		}
	}
}
void XoaSauNode_q(List &l, Node *q)
{
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (k->data == q->data)
		{
			Node *g = k->link;
			k->link = g->link;
			delete g;
		}
	}
}

void Delete_Node(List &l, int x)
{
	if (l.first == NULL)
	{
		return;
	}
	if (l.first->data == x)
	{
		Delete_Head(l);
		return;
	}
	if (l.last->data == x)
	{
		Delete_Tail(l);
		return;
	}

	Node *g = new Node;
	for (Node *k = l.first; k != NULL; k = k->link)
	{
		if (k->data == x)
		{
			g->link = k->link;
			delete k;
			return;
		}
		g = k;
	}

}
void Separating_List(List &l, List &ll, int x)
{
    Node *p;
    p=l.first;
    while (p!= NULL)
    {
        if (p->data >= x)
        {
            InsertFirst(ll, p->data);
             Delete_Node(l, p->data);
        }

        p= p->link;
    }

}
