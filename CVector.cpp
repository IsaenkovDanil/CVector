

#include <iostream>
#include "Header.h"
#include <stdlib.h>
#include <iterator>
#include <vector>
#include <algorithm>    // std::for_each
#include <stdio.h>    // std::for_each
#include<initializer_list>

using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	int szvec1;
	cout << "Введите размер 1 вектора" << endl;;
	cin >> szvec1;
	double* vec1massiv = new double[szvec1];
	set_pdataINITe(szvec1, vec1massiv);
	TVector<double> vec1(szvec1, vec1massiv);
	vec1.output();
	cout << endl;
	int szvec2;
	cout << "Введите размер 2 вектора" << endl;;
	cin >> szvec2;
	double* vec2massiv = new double[szvec2];
	set_pdataINITe(szvec2, vec2massiv);
	TVector<double> vec2(szvec2, vec2massiv);
	vec2.output();
TVector<double> vec3 = vec2+vec1;

	cout << endl;
	cout << "Скалярное произведение " << Scalar(vec1, vec2);
	cout << endl;
	cout << "Модуль 1 вектора " << vec1.Length();
	cout << endl;
	cout << "Модуль 2 вектора " << vec2.Length() << endl;
	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	cout << "Скаляр через * : " << vec1 * vec2 << endl;

	cout << "-----------------" << endl;
	cout << "Сумма через + : " << endl;
	(vec1 + vec2).output();
	cout << endl;
	cout << "-----------------" << endl;
	cout << "Разность через - : " << endl;
	(vec1 - vec2).output();
	cout << endl;
	
	sum(vec1, vec2).output();
	cout << endl;
	dif(vec1, vec2).output();




	vec1.output();	cout << endl;
	vec2.output();

	cout << "-----------------" << endl;
	/////vec2 = vec1;//присваивание;
	vec1.output();	cout << endl;
	vec2.output();
	cout << "-----------------" << endl;

	cout << " Введите элемент который нужно вывести из 1 вектора" << endl;
	int i1, i2;
	cin >> i1;
	cout << "Элемент :" << vec1[i1 - 1] << endl;
	cout << " Введите элемент который нужно вывести из 2 вектора" << endl;
	cin >> i2;
	cout << "Элемент :" << vec2[i2 - 1] << endl;

	

	cout << "-----------------" << endl;
	cout << "Модуль через () : " << endl;
	cout << endl;

	cout << "Модуль 1 вектора " << vec1();
	cout << endl;
	cout << "Модуль 2 вектора " << vec2() << endl;
	cout << endl;

	cout << "vec1 += vec2;" << endl;
	vec1 += vec2;
	//vec1.add(vec2);
	vec1.output();
	cout << endl;
	//vec1.sub(vec2);
	cout << "vec1 -= vec2;" << endl;

	vec1 -= vec2;
	vec1.output();



	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	cout << "------vec1.voutput()--------" << endl;

	vec1.voutput();

	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	cout << "-----------------" << endl;

	/*int szV2;
	cout << "Введите размер v2 вектора" << endl;;
	cin >> szV2;
	double* V2massiv = new double[szV2];
	set_pdataINITe(szV2, V2massiv);
	TVector2<double> V2(szV2, V2massiv);
	V2.output();

	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	cout << "-----------------" << endl;
	int szV3;
	cout << "Введите размер v3 вектора" << endl;;
	cin >> szV3;
	double* V3massiv = new double[szV3];
	set_pdataINITe(szV3, V3massiv);
	TVector3<double> V3(szV3, V3massiv);
	V3.voutput();*/



	TVector<double>* pv11 = &vec1;
	TVector<double>* pv12 = &vec2;
	cout << "-----pv11->output();---------" << endl;
	pv11->output();
	cout << "-----pv12->voutput();------" << endl;
	pv12->voutput();

	TVector<double>& pv21 = vec1;
	TVector<double>& pv22 = vec2;
	cout << "-----pv21.output(); ---------" << endl;
	pv21.output();
	cout << "-----pv22.voutput();------" << endl;
	pv22.voutput();





	cout << endl;

	cout << "-----------------" << endl;
	cout << endl;

	cout << "-----------------" << endl;

	TVector<double> a(vec1);
	a.output();


	cout << endl;

	cout << "------TVector a(vec1);---a.output();----" << endl;
	cout << endl;


	cout << "------	TVector b(a);---b.output();-" << endl;
	TVector<double> b(a);
	b.output();

	TVector<double> c;
	c = a;
	cout << endl;

	cout << "------	c = a;--------" << endl;
	c.output();

	c = a + b;
	cout << endl;

	cout << "-------c = a + b;-------" << endl;
	c.output();










 
/*auto it = TVector<double>::Iterator(vec1.begin());
for (auto i=it;i!= TVector<double>::Iterator(vec1.end());i++)
{ 
cout << *it << endl;
it++;

}
 */

//LAB  8
for (auto i = vec1.begin(); i != vec1.end(); i++)
{
	cout << *i << endl;
}
for (auto i:vec1)
{
	cout << i << endl;
}
//LAB  9
cout << "----------" << endl;
TVector<double> t { 50,48949,194894,14894 }; 
t.output();
cout <<  endl;
for (auto i : t)
{
	cout << i << endl;
}


	delete[] vec1massiv;
	delete[] vec2massiv;

}
