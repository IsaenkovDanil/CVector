#pragma once
#include <iostream>
#include <utility>
#include<initializer_list>
using namespace std;

template<typename T>

class TVector

{
protected:
	int m_size;
	T* m_pdata;
public:
	TVector(const TVector& rv);/*
	{
		init();
		copy(rv);
		cout << endl; cout << "Copy Constructor" << endl;
	}*/
	//TVector(TVector&& rv)
	/*
	{
		m_size = rv.m_size;
		m_pdata = rv.m_pdata;
		rv.init();
		cout << endl; cout << "Move Constructor" << endl;
	}*/	
	TVector(const int size = 0, const T* pdata = nullptr);/*
	{
		init();
		copy(size, pdata);
	}*/	
	~TVector()
	{
		close();
	}
protected:	
	void init();/*
	{
		m_size = 0;
		m_pdata = nullptr;
	}*/
public:	
	void close();/* {
		if (m_pdata)
			delete[] m_pdata;
		init();
	}*/	
	int copy(const TVector& rv);/*
	{
		if (this == &rv)
			return m_size;
		return copy(rv.m_size, rv.m_pdata);
	}*/	
	int copy(const int size, const T* pdata);
	//	{if (m_pdata == pdata)
	//		return m_size;
	//	close();
	//	if (size)
	//	{
	//		m_pdata = new T[size];//перед выделение памяти обнулить
	//		if (m_pdata)
	//		{
	//			for (int i = 0; i < size; i++)
	//				m_pdata[i] = pdata[i];
	//			m_size = size;
	//		}
	//	}

	//	return m_size;
	//}
	void output();/*
	{
		cout << "Num: " << m_size << "  ";
		cout << "Data: ";
		for (int i = 0; i < m_size; i++)
		{
			cout << m_pdata[i] << " ";
		}
		cout << endl;
	}*/






friend	TVector sum(TVector& v1, TVector& v2) {
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
friend TVector dif(TVector& v1, TVector& v2){
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
	friend double Scalar(TVector& v1, TVector& v2){
		 int size = max(v1.m_size, v2.m_size);
		 double S = 0;



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
	

	virtual void voutput();

	void add(TVector& v2);
	
	void sub(TVector& v2);
	int move(TVector&& rv);



	TVector& operator = (const TVector& rv);
	TVector& operator = (TVector&& rv);
	T& operator[](int i);
	
	T& operator [](int i)const;
	

	double Length();
	friend T operator * (TVector& v1, TVector& v2) { return Scalar(v1, v2); }

	friend TVector operator + (TVector& v1, TVector& v2) { return sum(v1, v2); }

	void operator += (TVector& v2);
	void operator -= (TVector& v2);

	friend TVector operator - (TVector& v1, TVector& v2) { return dif(v1, v2); }
	double operator()();



	public:
		typedef T* iterator;
		iterator begin() { return m_pdata; }
		iterator end() { return m_pdata+m_size; }
		/*class Iterator;
	
		class Iterator
		{
			T* cur;
		public:
			Iterator(T* first):cur(first){}
			Iterator() {};
			T& operator+(int n);//{ return *(cur + n); }
			T& operator-(int n);// { return *(cur - n); }
			T& operator++(int); //{ return *cur++; }
			T& operator--(int); //{ return *cur--; }
			T& operator++(); //{ return *++cur; }
			T& operator--();//{ return *--cur; }
			bool operator!= (const Iterator& it); //{ return cur != it.cur; }
			bool operator== (const Iterator& it); //{ return cur = it.cur; }

			T& operator*(); //{ return *cur; }

		};


		protected:
			int mCapacity=0;

*/

		public:

	
			
			TVector(std::initializer_list<T>il)
			{
				init();				//m_pdata = new T[size];//перед выделение памяти обнулить
				m_size = il.size();
				m_pdata = new T[m_size];//перед выделение памяти обнулить
				int i = 0;
				for (auto v : il)
				{

				//	for (int i = 0; i < m_size; i++)
						m_pdata[i] = v;
						i++;

				}
			}


		

};
void set_pdataINITe(int sizeINIT, double* pdataINIT);
