//单例模式

#include <iostream>

using namespace std;

class Singleton {
public:
	static Singleton *getInstance() {
		if (instance == NULL) {
			instance = new Singleton;
		}
		m_count++;
		return instance;
	}
	int getCount() { //为什么不是静态成员函数
		return m_count;
	}
private:
	Singleton() {
		instance = NULL;
		m_count = 0;
		cout << "constructor started" << endl;
	}
	static Singleton *instance;
	static int m_count;
};
Singleton *Singleton::instance = NULL;
int Singleton::m_count = 0;
//Singleton *Singleton::instance = new Singleton;

int main() {
	Singleton *s1 = Singleton::getInstance();
	cout << s1->getCount() << endl;
	Singleton *s2 = Singleton::getInstance();
	cout << s2->getCount() << endl;
	if (s1 == s2) {
		cout << "s1 == s2, 懒汉式" << endl;
	}
	else {
		cout << "s1 != s2" << endl;
	}
	delete s1;
	//delete s2;

	return 0;
}
