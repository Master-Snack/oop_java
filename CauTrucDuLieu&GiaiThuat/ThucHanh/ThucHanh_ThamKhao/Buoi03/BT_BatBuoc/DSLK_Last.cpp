#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *link;
};
struct List
{
    Node *first, *last;
};

void Init(List &l);
Node *GetNode(int x);
void AddLast(List &l, Node *new_ele);
void InsertLast(List &l, int x);
void CreateListLast(List &l);
void PrintList(List &l);
long SumEvenNumber(List l);
Node* Search(List l, int x);

int main()
{
    List l;
    Init(l);
    CreateListLast(l);
    PrintList(l);
    cout<<"Tong cac so chan trong DS = "<<SumEvenNumber(l)<<endl;
    int x;
    cout<<"Nhap gia tri ban muon tim: ";
    cin>>x;
    Node *ans;
    ans = Search(l,x);
    if (ans == NULL)
        cout<<"Gia tri khong ton tai!"<<endl;
    else
        cout<<"Tim thay tai dia chi "<<int(ans)<<endl;
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
void AddLast(List &l, Node *new_ele)
{
    if (l.first == NULL)
    {
        l.last = new_ele;
        l.first = l.last;
    }
    else
    {
        l.last -> link = new_ele;
        l.last  = new_ele;
    }
}
void InsertLast(List &l, int x)
{
    Node* new_ele = GetNode(x);
    if (new_ele == NULL)
        return;
    AddLast(l, new_ele);
}
void CreateListLast(List &l)
{
    int x;
    cout<<"Bat dau nhap danh sach cac so nguyen, nhap -1 de ket thuc:"<<endl;
    do{
        cin>>x;
        if (x == -1)
            break;
        InsertLast(l, x);

    }while (x != -1);
    cout<<"da nhap du lieu xong!"<<endl;
}
void PrintList(List &l)
{
    Node *p;
    p=l.first;
    cout<<"DS gom: "<<endl;
    cout<<left<<setw(16)<<"Gia tri PT"<<setw(10)<<"Dia chi"<<endl;
    while (p!= NULL)
    {
        cout<<setw(10)<<p->data<<"\t"<<setw(10)<<int(p)<<endl;
        p= p->link;
    }
}
long SumEvenNumber(List l)
{
    Node *p;
    long SumEven = 0;
    p=l.first;
    while (p!= NULL)
    {
        if (p->data % 2 == 0)
            SumEven += p->data;
        p= p->link;
    }
    return SumEven;
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
