#pragma once
#include <iostream>
using namespace std;

template <class T>
class Vector
{
	T* vect;
	int size;
public:
	Vector();
	explicit Vector(int);
	Vector(const T*, int);
	Vector(const Vector<T>&);
	~Vector();
	Vector<T>& operator = (const Vector<T>&);
	T& operator [] (int);
	int GetSize() const;
	void Clear();
	bool IsEmpty() const
	{
		return size == 0;
	}
	void Add(const T& item);
	void Insert(int index, const T& item);
	void Remove(int index);
};

template <class T>
Vector<T>::Vector()
{
	size = 0;
	vect = NULL;
}
template <class T>
Vector<T>::Vector(int n)
{
	size = n;
	vect = new T[size];
	for (int i = 0; i < size; i++)
		vect[i] = 0;
}
template <class T>
Vector<T>::Vector(const T* v, int n)
{
	size = n;
	vect = new T[size];
	for (int i = 0; i < size; i++)
		vect[i] = v[i];
}
template <class T>
Vector<T>::Vector(const Vector<T>& v)
{
	size = v.size;
	vect = new T[size];
	for (int i = 0; i < size; i++)
		vect[i] = v.vect[i];
}
template <class T>
Vector<T>::~Vector()
{
	delete[] vect;
}
template <class T>
Vector<T>& Vector<T>::operator = (const Vector<T>& v)
{
	if (&v == this)
		return *this;
	if (size != v.size && size != 0)
	{
		delete[] vect;
		size = v.size;
		vect = new T[size];
	}
	for (int i = 0; i < size; i++)
		vect[i] = v.vect[i];

	return *this;
}
template <class T>
T& Vector<T>::operator [] (int n)
{
	if (n < 0)
	{
		cout << "Index of array too small:\t use zeroth element\n";
		return vect[0];
	}
	else if (n > size - 1)
	{
		cout << "Index of array too big:\t use last element\n";
		return vect[size - 1];
	}
	else
		return vect[n];
}
template <class T>
int Vector<T>::GetSize() const
{
	return size;
}
template <class T>
void Vector<T>::Clear()
{
	if (size)
	{
		delete[] vect;
		vect = 0;
		size = 0;
	}
}
template <class T>
void Vector<T>::Add(const T& item)
{
	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++)
		temp[i] = vect[i];
	temp[size] = item;
	delete[] vect;
	vect = temp;
	size++;
}
template <class T>
void Vector<T>::Insert(int index, const T& item)
{
	if (index <0 || index>size)
		return;

	T* temp = new T[size + 1];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
			temp[i] = vect[i];
		else if (i >= index)
			temp[i + 1] = vect[i];
	}
	temp[index] = item;
	delete[] vect;
	vect = temp;
	size++;
}
template <class T>
void Vector<T>::Remove(int index)
{
	if (index >= size)
		return;

	if (size == 1)
	{
		delete[] vect;
		vect = 0;
	}
	else
	{
		T* temp = new T[size - 1];
		for (int i = 0; i < size; i++)
			if (i < index)
				temp[i] = vect[i];
			else if (i > index)
				temp[i - 1] = vect[i];
		delete[] vect;
		vect = temp;
	}
	size--;
}