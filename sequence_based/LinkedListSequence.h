#ifndef LINKED_LIST_SEQUENCE
#define LINKED_LIST_SEQUENCE
#include "..\based_struct\Sequence.h"

template<class T>
class LinkedListSequence :public Sequence<T>
{
	typedef struct Node
	{
		SmrtPtr<Node> next, previous;
		T item;
	}node;

	SmrtPtr<node> first, last;
	size_t length;

public:
	LinkedListSequence()
	{
		length = 0;
	}
	LinkedListSequence(const LinkedListSequence<T>& List)
	{
		SmrtPtr<node> ptr = List.first;
		
		for (size_t i = 0; i < List.length; i++)
		{
			this->Append(ptr.get().item);
			ptr = ptr.get().next;
		}
	}
	virtual ~LinkedListSequence() 
	{
		SmrtPtr<node> subNode = first;
		for (size_t i = 0; i < length; i++)
		{
			subNode.~SmrtPtr();
			subNode = subNode.get().next;
		}
		last.~SmrtPtr();
	}

	T& Get(int Index)
	{
		if (length == 0)
			throw std::exception("EmptyList");
		if (Index < 0 || Index >= length)
			throw std::exception("IndexOutOfRange");

		SmrtPtr<node> out = first;
		for (size_t i = 0; i < Index; i++)
		{
			out = out.get().next;
		}
		return out.get().item;
	}
	T& GetFirst()
	{
		return first.get().item;
	}
	T& GetLast()
	{
		return last.get().item;
	}
	const size_t GetLenght()
	{
		return length;
	}

	void Append(T Item)
	{
		node subNode;
		subNode.previous = last;
		subNode.item = Item;
		if (length != 0)
		{
			last.get().next.make(subNode);
			last = last.get().next;
			if (length == 1)
			{
				first.get().next = last;
			}
		}
		else
		{
			first.make(subNode);
			last = first;
		}
		length++;
	}
	void Prepend(T Item)
	{
		node subNode;
		subNode.next = first;
		subNode.item = Item;
		if (length != 0)
		{
			first.get().previous.make(subNode);
			first = first.get().previous;
			if (length == 1)
			{
				last.get().previous = first;
			}
		}
		else
		{
			first.make(subNode);
			last = first;
		}
		length++;
	}
	void InsertAt(T Item, int Index)
	{
		if (Index < 0 || Index > length)
			throw std::exception("IndexOutOfRange");

		if (Index == length)
		{
			this->Append(Item);
			return;
		}

		if (Index == 0)
		{
			this->Prepend(Item);
			return;
		}

		node subNode;
		SmrtPtr<node> indexPosition = first;
		for (size_t i = 0; i < Index; i++)
		{
			indexPosition = indexPosition.get().next;
		}

		subNode.next = indexPosition;
		subNode.previous = indexPosition.get().previous;
		subNode.item = Item;

		SmrtPtr<node> subNodePtr;
		subNodePtr.make(subNode);
		indexPosition.get().previous.get().next = subNodePtr;
		indexPosition.get().previous = subNodePtr;

		length++;
	}
	Sequence<T>* Concat(LinkedListSequence<T>* List)
	{
		/*LinkedListSequence<T>* listS = new LinkedListSequence<T>;
		delete listS->list;
		listS->list = new LinkedList<T>(this->list->Concat(*List->list));
		return listS;*/
	}
};

#endif 