// FuckCpp.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class A {
public:
	int i;
public:A(int i) {
	this->i = i;
}
};

int main()
{
	vector<int> intContainer;

	for (int i = 0; i < 30; i++) {
		intContainer.push_back(i);
	}

	for (int i = 0; i < 30; i++) {
		intContainer.push_back(i);

	}

	 
	cout << "intContainer.size()" << intContainer.size() << std::endl;
	for (int i = 0; i < intContainer.size(); i++) {
		cout << intContainer[i] << ":";
	}

	//int *intValue = &intContainer[25];
	//for (int i = 0; i < intContainer.size(); i++) {
	//	if (intValue == &intContainer[i]) {
	//		 
	//	}
	//}

	//int* intValue = &(intContainer[25]);
	//for (vector<int>::iterator it = intContainer.begin(); it != intContainer.end();)
	//{
	//	
	//	if (&(*it) == intValue) {
	//		cout << "*it: === "<<*it;
	//		//cout << "it:" << it;
	//		it = intContainer.erase(it);
	//		break;
	//	}
	//	else {
	//		it++;
	//	}
	//}

	//std::remove(intContainer.begin(), intContainer.end(), 25);

	intContainer.erase(remove(intContainer.begin(), intContainer.end(), 25), intContainer.end());


	cout << "intContainer.size()" << intContainer.size() << std::endl;
	for (int i = 0; i < intContainer.size(); i++) {
		cout << intContainer[i] << ":";
	}

	cout << endl;
	cout << "do Container obj" << endl;

	//////////////////////////////////////////////////////////////////////////////
	//obj vector 
	vector<A*> objContainer;
	for (int i = 0; i < 30; i++) {
		objContainer.push_back(new A(i));
	}

	for (int i = 0; i < 30; i++) {
		objContainer.push_back(new A(i));
	}

	cout << "objContainer.size()" << objContainer.size() <<std::endl;
	for (int i = 0; i < objContainer.size(); i++) {
		cout << objContainer[i]->i << ":";
	}

	cout << endl;

	//fangfa 1
	A* objValue = objContainer[25];


	//for (vector<A*>::iterator it = objContainer.begin(); it != objContainer.end();)
	//{
	//	
	//	if (*it == objValue) {
	//		cout << "*it: === "<<*it;
	//		//cout << "it:" << it;
	//		it = objContainer.erase(it);
	//	}
	//	else {
	//		it++;
	//	}
	//}

	//fangfa 2
	objContainer.erase(remove(objContainer.begin(), objContainer.end(), objValue), objContainer.end());


	//cout << endl;
	cout << "objContainer.size()" << objContainer.size() << std::endl;

	for (int i = 0; i < objContainer.size(); i++) {
		cout << objContainer[i]->i << ":";
	}

	getchar();
    return 0;
}

