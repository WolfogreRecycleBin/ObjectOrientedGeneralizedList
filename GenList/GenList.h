#ifndef GENLIST_H
#define GENLIST_H
#include <iostream>
using namespace std;

template <class ElemType> class GenList;
enum GenListNodeType{ HEAD, ATOM, LIST};

template <class ElemType> 
struct GenListNode
{
	GenListNodeType tag;
	ElemType atom;
	GenList<ElemType> *list;
	GenListNode<ElemType> *next;

	GenListNode<ElemType>()
	{
		tag = HEAD;
		atom = 0;
		list = NULL;
		next = NULL;
	}
	~GenListNode<ElemType>()
	{
		if (list) delete list;
	}
};
template <class ElemType> 
class GenList
{
public:
	GenList();
	GenList(const GenList<ElemType> &gl);
	virtual ~GenList();
	bool IsEmpty() const;
	void Insert(const ElemType &e);
	void Insert(const GenList &gl);
	int GetDepth() const;
	int GetLength() const;
	void Show() const;
private:
	GenListNode<ElemType> *head;
};

template <class ElemType> 
GenList<ElemType>::GenList()
{
	head = new GenListNode<ElemType>;
	head->next = NULL;
}

template <class ElemType> 
GenList<ElemType>::GenList(const GenList<ElemType> &gl)
{

	head = new GenListNode<ElemType>;
	head->next = NULL;
	GenListNode<ElemType> *p,*pend;
	p = gl.head->next;
	pend = head;
	while (p)
	{
		if (p->tag == ATOM)
		{
			GenListNode<ElemType> *nd = new GenListNode < ElemType >;
			nd->atom = p->atom;
			nd->tag = ATOM;
			nd->next = pend->next;
			pend->next = nd;
			pend = nd;
		}
		if (p->tag == LIST)
		{
			GenList<ElemType> *nl = new GenList<ElemType>(*(p->list));
			GenListNode<ElemType> *nd = new GenListNode < ElemType >;
			nd->tag = LIST;
			nd->list = nl;
			nd->next = pend->next;
			pend->next = nd;
			pend = nd;
		}
		p = p->next;
	}
}
template <class ElemType> 
GenList<ElemType>::~GenList()
{
	GenListNode<ElemType> *p;
	while (head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

template <class ElemType> 
bool GenList<ElemType>::IsEmpty() const
{
	return head->next == NULL;
}

template <class ElemType> 
void GenList<ElemType>::Insert(const ElemType &e)
{
	GenListNode<ElemType> *n = new GenListNode < ElemType > ;
	n->atom = e;
	n->tag = ATOM;
	n->next = head->next;
	head->next = n;
}

template <class ElemType> 
void GenList<ElemType>::Insert(const GenList<ElemType> &gl)
{
	GenList<ElemType> *nl = new GenList<ElemType>(gl);
	GenListNode<ElemType> *nd = new GenListNode < ElemType > ;
	nd->tag = LIST;
	nd->list = nl;
	nd->next = head->next;
	head->next = nd;
}

template <class ElemType> 
int GenList<ElemType>::GetDepth() const
{
	int depth = 0;
	GenListNode<ElemType> *p = head->next;
	while (p)
	{
		if (p->tag == LIST)
		{
			int p_depth = p->list->GetDepth();
			if (p_depth > depth) depth = p_depth;
		}
		p = p->next;
	}
	return ++depth;
}
template <class ElemType> 
int GenList<ElemType>::GetLength() const
{
	int length = 0;
	GenListNode<ElemType> *p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}
template <class ElemType> 
void GenList<ElemType>::Show() const
{
	cout << "(";
	GenListNode<ElemType> *p = head -> next;
	while (p)
	{
		if (p->tag == ATOM)
		{
			cout << p->atom;
			if(p->next)cout<< ',';
		}
		if (p->tag == LIST)
		{
			p->list->Show();
			if (p->next)cout << ',';
		}
		p = p->next;
	}
	cout << ")";
}
#endif