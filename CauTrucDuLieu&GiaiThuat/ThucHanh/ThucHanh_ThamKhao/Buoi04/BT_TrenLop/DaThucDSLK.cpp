#include<bits/stdc++.h>
using namespace std;
struct Node
{
    float heSo;
    int soMu;
    Node *link;
};
struct List
{
    Node *first, *last;
};
void Init(List &l);
Node *GetNode(float heSo, int soMu);
void AddLast(List &l, Node *new_ele);
void InsertLast(List &l,float heSo, int soMu);
void NhapDaThuc(List &l);
void PrintList(List &l);
void CongDT(List d1, List d2, List &d3);
void InterchangeSort(List &l);

int main()
{
    List d1, d2, d3;
    Init(d1);
    Init(d2);
    Init(d3);
    NhapDaThuc(d1);
    InterchangeSort(d1);
    cout<<"\nDanh sach bieu dien da thuc d1: ";
    PrintList(d1);
    NhapDaThuc(d2);
    InterchangeSort(d2);
    cout<<"\nDanh sach bieu dien da thuc d2: ";
    PrintList(d2);
    CongDT(d1, d2, d3);
    cout<<"\nDanh sach bieu dien da thuc tong: ";
    PrintList(d3);
    return 0;
}
void Init(List &l)
{
    l.first = l.last = NULL;
}
Node *GetNode(float heSo, int soMu)
{
    Node *p;
    p= new Node;
    if (p == NULL)
        return NULL;
    p->heSo = heSo;
    p->soMu = soMu;
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
void InsertLast(List &l,float heSo, int soMu)
{
    Node* new_ele = GetNode(heSo, soMu);
    if (new_ele == NULL)
        return;
    AddLast(l, new_ele);
}
void NhapDaThuc(List &l)
{
    float heSo;
    int soMu;
    cout<<"Bat dau nhap da thuc (nhap he so 0 de ket thuc): "<<endl;
    do{
        cout<<"Nhap he so: ";
        cin>>heSo;
        if (heSo == 0)
            break;
        cout<<"Nhap so mu: ";
        cin>>soMu;
        InsertLast(l, heSo, soMu);
    }while (heSo!=0);
    cout<<"Da nhap da thuc xong!"<<endl;
}
void PrintList(List &l)
{
    Node *p;
    p=l.first;
    while (p!= NULL)
    {
        if (p==l.first)
        {
            if (p->heSo!=1 || p->heSo!=-1)
            {
                if (p->soMu==0)
                    printf("%.0f ", p->heSo);
                else if (p->soMu==1)
                    printf("%.0fx ", p->heSo);
                else
                    printf("%.0fx^%d  ", p->heSo, p->soMu);
            }
            else
            {
                if (p->soMu==0)
                    printf("%.0f ", p->heSo);
                else if (p->soMu==1)
                {
                    if (p->heSo==1)
                        printf("x ");
                    else
                        printf("-x ");
                }

                else
                {
                    if (p->heSo==1)
                        printf("x^%d ", p->soMu);
                    else
                        printf("-x^%d ", p->soMu);
                }

            }
        }
        else
        {
            if (p->heSo<0)
            {
                if (p->heSo!=1 || p->heSo!=-1)
                {
                    if (p->soMu==0)
                        printf("%.0f ", p->heSo);
                    else if (p->soMu==1)
                        printf("%.0fx ", p->heSo);
                    else
                        printf("%.0fx^%d  ", p->heSo, p->soMu);
                }
                else
                {
                    if (p->soMu==0)
                        printf("%.0f ", p->heSo);
                    else if (p->soMu==1)
                    {
                        if (p->heSo==1)
                            printf("x ");
                        else
                            printf("-x ");
                    }

                    else
                    {
                        if (p->heSo==1)
                            printf("x^%d ", p->soMu);
                        else
                            printf("-x^%d ", p->soMu);
                    }

                }
            }
            else
            {
                if (p->heSo!=1 || p->heSo!=-1)
                {
                    if (p->soMu==0)
                        printf("+%.0f ", p->heSo);
                    else if (p->soMu==1)
                        printf("+%.0fx ", p->heSo);
                    else
                        printf("+%.0fx^%d  ", p->heSo, p->soMu);
                }
                else
                {
                    if (p->soMu==0)
                        printf("%.0f ", p->heSo);
                    else if (p->soMu==1)
                    {
                        if (p->heSo==1)
                            printf("x ");
                        else
                            printf("-x ");
                    }

                    else
                    {
                        if (p->heSo==1)
                            printf("x^%d ", p->soMu);
                        else
                            printf("-x^%d ", p->soMu);
                    }

                }
            }
        }
        p=p->link;

    }
    cout<<endl;
}

void CongDT(List d1, List d2, List &d3)
{
    Init(d3);
    Node *p=d1.first, *q=d2.first;
    float tongHS;
    while (p&&q)
    {
        if (p->soMu==q->soMu)
        {
            tongHS=p->heSo+q->heSo;
            if (tongHS!=0)
                InsertLast(d3, tongHS, p->soMu);
            p= p->link;
            q= q->link;
        }
        else{
            if (p->soMu > q->soMu)
            {
                InsertLast(d3, p->heSo, p->soMu);
                p=p->link;
            }
            else
            {
                if (p->soMu < q->soMu)
                {
                    InsertLast(d3, q->heSo, q->soMu);
                    q=q->link;
                }
            }
        }
    }
    while(q)
    {
        InsertLast(d3, q->heSo, q->soMu);
        q=q->link;
    }
    while(p)
    {
        InsertLast(d3, p->heSo, p->soMu);
        p=p->link;
    }
}
void InterchangeSort(List &l)
{
    for (Node* p=l.first; p!=l.last; p=p->link)
        for (Node* q=p->link; q!=NULL; q=q->link)
            if (p->soMu < q->soMu)
            {
                swap(p->heSo, q->heSo);
                swap(p->soMu, q->soMu);
            }
}
