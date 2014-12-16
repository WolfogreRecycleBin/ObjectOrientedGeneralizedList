#ifndef GENLIST_H
#define GENLIST_H
#define TCE template <class ET>
#include <iostream>
using namespace std;
TCE class GenList;
enum GenListNodeType{ HEAD, ATOM, LIST};
TCE struct GenListNode
{
	GenListNodeType tag;
	ET atom;
	GenList<ET> *list;
	GenListNode<ET> *next;
	GenListNode<ET>()
	{
		tag = HEAD;
		atom = 0;
		list = NULL;
		next = NULL;
	}
	GenListNode<ET> &operator=(const GenListNode<ET> gl)
	{
		list = NULL;
		next = NULL;
		tag = gl.tag;
		atom = gl.atom;
		if (gl.list)
		{
			list = new GenList<ET>(*(gl.list));
		}
	}
};
TCE class GenList
{
public:
	GenList();
	GenList(const GenList<ET> &gl);
	virtual ~GenList();
	bool IsEmpty() const;
	void Insert(const ET &e);
	void Insert(const GenList &gl);
	int GetDepth() const;
	int GetLength() const;
	void Show() const;
private:
	GenListNode<ET> *head;
};

TCE GenList<ET>::GenList()
{
	head = new GenListNode<ET>;
	head->next = NULL;
}

TCE GenList<ET>::GenList(const GenList<ET> &gl)
{

	head = new GenListNode<ET>;
	head->next = NULL;
	GenListNode<ET> *p,*pend;
	p = gl.head->next;
	pend = head;
	while (p)
	{
		if (p->tag == ATOM)
		{
			GenListNode<ET> *nd = new GenListNode < ET >;
			nd->atom = p->atom;
			nd->tag = ATOM;
			nd->next = pend->next;
			pend->next = nd;
			pend = nd;
		}
		if (p->tag == LIST)
		{
			GenList<ET> *nl = new GenList<ET>(*(p->list));
			GenListNode<ET> *nd = new GenListNode < ET >;
			nd->tag = LIST;
			nd->list = nl;
			nd->next = pend->next;
			pend->next = nd;
			pend = nd;
		}
		p = p->next;
	}
}
TCE GenList<ET>::~GenList()
{
	GenListNode<ET> *p;
	while (head)
	{
		p = head;
		head = head->next;
		delete p;
	}
}

TCE bool GenList<ET>::IsEmpty() const
{
	return head->next == NULL;
}

TCE void GenList<ET>::Insert(const ET &e)
{
	GenListNode<ET> *n = new GenListNode < ET > ;
	n->atom = e;
	n->tag = ATOM;
	n->next = head->next;
	head->next = n;
}

TCE void GenList<ET>::Insert(const GenList<ET> &gl)
{
	GenList<ET> *nl = new GenList<ET>(gl);
	GenListNode<ET> *nd = new GenListNode < ET > ;
	nd->tag = LIST;
	nd->list = nl;
	nd->next = head->next;
	head->next = nd;
}

TCE int GenList<ET>::GetDepth() const
{
	int depth = 0;
	GenListNode<ET> *p = head->next;
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
TCE int GenList<ET>::GetLength() const
{
	int length = 0;
	GenListNode<ET> *p = head->next;
	while (p)
	{
		length++;
		p = p->next;
	}
	return length;
}
TCE void GenList<ET>::Show() const
{
	cout << "(";
	GenListNode<ET> *p = head -> next;
	while (p)
	{
		if (p->tag == ATOM)
		{
			cout << p->atom;
			if(p->next)cout<< ',';
		}
		if (p->tag == LIST)	p->list->Show();
		p = p->next;
	}
	cout << ")";
}
#endif