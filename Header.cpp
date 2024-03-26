#include <iostream>
#include "Header.h"
#include <stdlib.h>
#include <cmath>
#include<initializer_list>

using namespace std;


void set_pdataINITe(int sizeINIT, double* pdataINIT)
{
	cout << "¬ведите  вектор";
	for (int i = 0; i < sizeINIT; i++)
	{
		cin >> pdataINIT[i];
	}
	cout << endl;
}
template<typename T>
TVector<T> sum(TVector<T>& v1, TVector<T>& v2)


{
	int size = max(v1.m_size, v2.m_size);
	double* pdata1 = new T[size];


	TVector* pmax, * pmin;
	if (v1.m_size > v2.m_size)
	{
		pmax = &v1;
		pmin = &v2;

	}
	else
	{
		pmax = &v2;
		pmin = &v1;
	}

	for (int i = 0; i < pmin->m_size; i++)
	{
		pdata1[i] = pmin->m_pdata[i] + pmax->m_pdata[i];
	}

	for (int i = pmin->m_size; i < size; i++)
	{
		pdata1[i] = pmax->m_pdata[i];
	}
	TVector resS(size, pdata1);
	delete[]pdata1;
	return resS;
}
template<typename T>
TVector<T> dif(TVector<T>& v1, TVector<T>& v2)

{
	int size = max(v1.m_size, v2.m_size);
	double* pdata2 = new T[size];

	TVector* pmax, * pmin;
	if (v1.m_size > v2.m_size)
	{

		pmax = &v1;

		pmin = &v2;

		for (int i = 0; i < pmin->m_size; i++)

		{
			pdata2[i] = pmax->m_pdata[i] - pmin->m_pdata[i];
		}


		for (int i = pmin->m_size; i < size; i++)

		{
			pdata2[i] = pmax->m_pdata[i];
		}

	}
	else
	{
		pmax = &v2;

		pmin = &v1;

		for (int i = 0; i < pmin->m_size; i++)

		{
			pdata2[i] = pmin->m_pdata[i] - pmax->m_pdata[i];
		}


		for (int i = pmin->m_size; i < size; i++)

		{
			pdata2[i] = -pmax->m_pdata[i];
		}

	}



	TVector resD(size, pdata2);
	delete[]pdata2;
	return resD;

}
template<typename T>
T Scalar(TVector<T>& v1, TVector<T>& v2)

{
	int size = max(v1.m_size, v2.m_size);
	T S = 0;



	TVector* pmax, * pmin;
	if (v1.m_size > v2.m_size)
	{
		pmax = &v1;  //1 2 3 4 5
		pmin = &v2;  //1 2 3

	}
	else
	{
		pmax = &v2;
		pmin = &v1;
	}

	for (int i = 0; i < pmin->m_size; i++)
	{
		S += pmin->m_pdata[i] * pmax->m_pdata[i];

	}

	return S;
}
template<typename T>

T operator*(TVector<T>& v1, TVector<T>& v2)

{

	return Scalar(v1, v2);
}
template<typename T>

TVector<T> operator+(TVector<T>& v1, TVector<T>& v2)

{
	return sum(v1, v2);
}
template<typename T>

TVector<T> operator-(TVector<T>& v1, TVector<T>& v2)

{
	return dif(v1, v2);
}

template<typename T>

TVector<T>::TVector(const TVector& rv)
{
	init();
	copy(rv);
	cout << endl; cout << "Copy Constructor" << endl;
}
template<typename T>

TVector<T>::TVector(const int size, const T* pdata)
{
	init();
	copy(size, pdata);
}
template<typename T>
void TVector<T>::init() {
	m_size = 0;
	m_pdata = nullptr;

}

template<typename T>
void TVector<T>::close()
{
	if (m_pdata)
		delete[] m_pdata;
	init();

}

template<typename T>
int TVector<T>::copy(const TVector& rv)
{
	if (this == &rv)
		return m_size;
	return copy(rv.m_size, rv.m_pdata);
}

template<typename T>
int TVector<T>::copy(const int size, const T* pdata)
{
	if (m_pdata == pdata)
		return m_size;
	close();
	if (size)
	{
		m_pdata = new T[size];//перед выделение пам€ти обнулить
		if (m_pdata)
		{
			for (int i = 0; i < size; i++)
				m_pdata[i] = pdata[i];
			m_size = size;
		}
	}

	return m_size;

}

template<typename T>
void TVector<T>::output()
{
	cout << "Num: " << m_size << "  ";
	cout << "Data: ";
	for (int i = 0; i < m_size; i++)
	{
		cout << m_pdata[i] << " ";
	}
	cout << endl;

}



template<typename T>
void TVector<T>::voutput()

{
	output();
	cout << endl;
	cout << "TVector virtual void voutput()";
	cout << endl;
}
template<typename T>
void TVector<T>::add(TVector& v2)
{
	copy(sum(*this, v2));
}
template<typename T>
void TVector<T>::sub(TVector& v2)

{
	copy(dif(*this, v2));
}
template<typename T>
int TVector<T>::move(TVector&& rv)

{
	if (this != &rv) {
		close();
		m_size = rv.m_size;
		m_pdata = rv.m_pdata;
		rv.init();

	}
	cout << endl;

	///cout << " moove" << endl;

	return m_size;
}
template<typename T>
TVector<T>& TVector<T>::operator=(const TVector<T>& rv)
{
	copy(rv);
	cout << endl;
	cout << "Copy =" << endl;
	return *this;
}
template<typename T>
TVector<T>& TVector<T>::operator=(TVector<T>&& rv)
{
	move(std::move(rv));
	//copy(rv);
	cout << endl;
	cout << "Move =" << endl;

	return *this;
}
template<typename T>
T& TVector<T>::operator[](int i)
{
	return m_pdata[i];
}
template<typename T>
T& TVector<T>::operator[](int i) const
{
	return m_pdata[i];
}
template<typename T>
double TVector<T>::Length()
{
	return sqrt(Scalar(*this, *this));
}




template<typename T>
void TVector<T>::operator+=(TVector& v2)

{
	(*this).add(v2);
}
template<typename T>
void TVector<T>::operator-=(TVector& v2)

{
	(*this).sub(v2);

}

template<typename T>
double TVector<T>::operator()()
{
	return (*this).Length();

}
;
/**/
template<typename T>
T& TVector<T>::Iterator::operator+(int n)
{
	return *(cur + n);
}

template<typename T>
T& TVector<T>::Iterator::operator-(int n)
{
	return *(cur - n);
}

template<typename T>
T& TVector<T>::Iterator::operator++(int)
{
	return *cur++;
}

template<typename T>
T& TVector<T>::Iterator::operator--(int)
{
	return *cur--;
}

template<typename T>
T& TVector<T>::Iterator::operator++()
{
	return *++cur;
}

template<typename T>
T& TVector<T>::Iterator::operator--()
{
	return *--cur;
}

template<typename T>
bool TVector<T>::Iterator::operator!=(const Iterator& it)
{
	return cur != it.cur;
}

template<typename T>
bool TVector<T>::Iterator::operator==(const Iterator& it)
{
	return cur = it.cur;
}

template<typename T>
inline T& TVector<T>::Iterator::operator*()
{
	return *cur;
}

