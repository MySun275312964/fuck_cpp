// FuckCpp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include<algorithm>

#include <vector>
#include <list>
#include <map>

using namespace std;

class A {
public:
	int i;
public:A(int i) {
	this->i = i;
}
};

void testVector() {
	cout << "testVector  begin...." << std::endl;

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

	//����1  for eachɾ��
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

	//����2  erase(remove)��Ϸ�ʽɾ��
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

	cout << "objContainer.size()" << objContainer.size() << std::endl;
	for (int i = 0; i < objContainer.size(); i++) {
		cout << objContainer[i]->i << ":";
	}
	cout << endl;
 
	A* objValue = objContainer[25];
	//����1  for eachɾ��
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

	//����2  erase(remove)��Ϸ�ʽɾ��
	objContainer.erase(remove(objContainer.begin(), objContainer.end(), objValue), objContainer.end());


	//cout << endl;
	cout << "objContainer.size()" << objContainer.size() << std::endl;

	for (int i = 0; i < objContainer.size(); i++) {
		cout << objContainer[i]->i << ":";
	}

	cout << "testVector  end...." << std::endl;
}

//vectorɾ����ʱ��ֻ��ʹ�� 
//it = intContainer.erase(it); ��ȱ
//intContainer.erase(iter++); ���ַ����ᵼ�³������

//list��mapɾ����ʱ��ȿ��� 
// intContainer.erase(iter++);
//Ҳ����ʹ�� 
//iter = intContainer.erase(iter);

void testList() {
	cout << "testList  begin...." << std::endl;

	list<int> intList;

	for (int i = 0; i < 30; i++) {
		intList.push_back(i);
	}

	list<int>::iterator iter;

	for (iter = intList.begin(); iter != intList.end(); iter++){
		//cout << *iter << endl;
		if (*iter == 3) {
			//listʹ��iter++����erase֮��iter=����ֵ���ǿ���
			//����1
			//intList.erase(iter++);
			//����2
			iter = intList.erase(iter);
		}
	}
	
	for (iter = intList.begin(); iter != intList.end(); iter++){
		cout << *iter << endl;
	}
 
	cout << "testList  end...." << std::endl;
}

void testMap() {
 
	cout << "testMap  end...." << std::endl;
	map<int, int> intMap;
	for (int i = 0; i < 30; i++) {
		intMap.insert(make_pair(i, i));
	}

	map<int, int>::iterator iter;
	for (iter = intMap.begin(); iter !=  intMap.end(); iter++){
		if (iter->second == 3){
			//intMap.erase(iter++);  
			iter = intMap.erase(iter);

		}
	}

	cout << "after intMap.size()"<< intMap.size() << std::endl;
	//for (int i = 0; i < intMap.size(); i++) {
	//	cout << intMap[i] << endl;
	//}

	for (iter = intMap.begin(); iter != intMap.end(); iter++) {
		cout << iter->first << " : " << iter->second << endl;
	}

	cout << "testMap  end...." << std::endl;
//�������mapɾ���ᵼ���ڴ�й©������ �����Ķ�����ƪ����
//http://blog.csdn.net/wangandy7811/article/details/4418145

}

int main()
{
	//testVector();

	//testList();
	
	testMap();

	getchar();

	return 0;
}

