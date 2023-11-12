#ifndef SMART_POINTER
#define SMART_POINTER
#include <algorithm>

template<typename T>
class SmrtPtr
{
public:

	//4 constructors
	SmrtPtr();
	SmrtPtr(T* ptr);
	SmrtPtr(const SmrtPtr<T>& sPtr);

	template<typename P>
	SmrtPtr(const SmrtPtr<P>& sPtr);
	
	//1 destructor
	~SmrtPtr();

	//make and get functions
	void make(const T& item);
	T& get();

	//2 operators (1 overloaded)
	T& operator*();
	void operator=(SmrtPtr<T>& sPtr);
	template<typename P>
	void operator=(SmrtPtr<P>& sPtr);

private:
	T* ptr;
	size_t* counter;
	friend class SmrtPtr;
};

//constructors realizations
template<typename T>
SmrtPtr<T>::SmrtPtr()
{
	this->ptr = NULL;
	this->counter = NULL;
}

template<typename T>
SmrtPtr<T>::SmrtPtr(T* ptr)
{
	this->ptr = ptr;
	if (ptr != NULL) counter = new size_t(1);
	else counter = NULL;
}

template<typename T>
SmrtPtr<T>::SmrtPtr(const SmrtPtr<T>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

template<typename T> template<typename P>
SmrtPtr<T>::SmrtPtr(const SmrtPtr<P>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::exception("Class P is not subclass of class T");
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
};

//destructor realization
template<typename  T>
SmrtPtr<T>::~SmrtPtr()
{
	if (this->counter == NULL)return;

	(*this->counter)--;
	if (*this->counter == 0)
	{
		delete ptr;
		delete counter;
	}
}

//get/make realizations
template<typename T>
T& SmrtPtr<T>::get()
{
	if (this->ptr == NULL)
	{
		throw(std::exception("Empty pointer"));
	}
	return *(this->ptr);
}

template <typename T>
void SmrtPtr<T>:: make(const T& item)
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			(* (this->counter)) = 1;
		}
		else
		{
			counter = new size_t(1);
		}
	}
	else
	{
		counter = new size_t(1);
	}
	this->ptr = new T(item);
};

//operators realizations
template<typename T>
T& SmrtPtr<T>::operator*()
{
	return this->get();
}

template<typename T>
void SmrtPtr<T>::operator=(SmrtPtr<T>& sPtr)
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			delete counter;
		}
	}
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

template<typename T> template<typename P>
void SmrtPtr<T>::operator=(SmrtPtr<P>& sPtr)
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			delete counter;
		}
	}

	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::exception("Class P is not subclass of class T");
	else
		this->counter = sPtr.counter;
}


//next class is for arrays

template<typename T>
class SmrtPtr<T[]>
{
public:

	//4 constructors
	SmrtPtr();
	SmrtPtr(size_t size);
	SmrtPtr(const SmrtPtr<T[]>& sPtr);

	template<typename P>
	SmrtPtr(const SmrtPtr<P[]>& sPtr);

	//1 destructor
	~SmrtPtr();

	//make and get functions
	void make(const size_t size);
	T& get(size_t index);

	//sort function
	void sort(size_t length, bool(*comp)(T a, T b));

	//2 operators (1 overloaded)
	T& operator[](size_t index);
	void operator=(SmrtPtr<T[]>& sPtr);

	template<typename P>
	void operator=(SmrtPtr<P[]>& sPtr);
private:
	T* ptr;
	size_t* counter;
	friend class SmrtPtr;
};

//constructors realizations
template<typename T>
SmrtPtr<T[]>::SmrtPtr()
{
	this->counter = NULL;
	this->ptr = NULL;
}

template<typename T>
SmrtPtr<T[]>::SmrtPtr(size_t size)
{
	this->counter = new size_t(1);
	this->ptr = new T[size];
}

template<typename T>
SmrtPtr<T[]>::SmrtPtr(const SmrtPtr<T[]>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

template<typename T> template<typename P>
SmrtPtr<T[]>::SmrtPtr(const SmrtPtr<P[]>& sPtr)
{
	if (sPtr.counter == NULL)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::exception("Class P is not subclass of class T");
	this->counter = sPtr.counter;
	(*sPtr.counter)++;
}

//destructor realization
template<typename  T>
SmrtPtr<T[]>::~SmrtPtr()
{
	if (this->counter == NULL)return;

	(*this->counter)--;
	if (*this->counter == 0)
	{
		delete[] ptr;
		delete counter;
	}
}

//get/make realization
template<typename T>
T& SmrtPtr<T[]>::get(size_t index)
{
	if (this->ptr == NULL)
	{
		throw(std::exception("Empty pointer"));
	}
	return (this->ptr)[index];
}

template<typename T>
void SmrtPtr<T[]>::make(const size_t size)
{
	if (size == 0)
	{
		this->ptr = NULL;
		this->counter = NULL;
		return;
	}
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			(*(this->counter)) = 1;
		}
		else
		{
			counter = new size_t(1);
		}
	}
	else
	{
		counter = new size_t(1);
	}
	this->ptr = new T[size];
}

//operators realization
template<typename T>
T& SmrtPtr<T[]>::operator[](size_t index)
{
	return (this->ptr)[index];
}

template<typename T>
void SmrtPtr<T[]>::operator=(SmrtPtr<T[]>& sPtr)
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			delete counter;
		}
	}
	this->ptr = sPtr.ptr;
	this->counter = sPtr.counter;
}

template<typename T> template<typename P>
void SmrtPtr<T[]>::operator=(SmrtPtr<P[]>& sPtr)
{
	if (this->ptr != NULL)
	{
		(*this->counter)--;
		if (*this->counter == 0)
		{
			delete ptr;
			delete counter;
		}
	}

	this->ptr = dynamic_cast<T*>(sPtr.ptr);
	if (this->ptr == NULL)
		throw std::exception("Class P is not subclass of class T");
	else
		this->counter = sPtr.counter;
}

//sort with std::sort
template<typename T>
void SmrtPtr<T[]>::sort(size_t length, bool(*comp)(T a, T b))
{
	std::sort(ptr, ptr + length, comp);
}
#endif // !SMART_POINTER