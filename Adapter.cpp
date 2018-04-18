//适配器模式
//以手机充电为例

#include <iostream>

using namespace std;

class Charge5V {
public:
	virtual void use5V() = 0;
};

class Charge200V {
public:
	void use200V() {
		cout << "use 200v to charge" << endl;
	}
};

class Adapter : public Charge5V {
public:
	virtual void use5V() {
		cout << "use adapter to charge" << endl;
		charge200.use200V();
	}
private:
	Charge200V charge200;
};

class Phone {
public:
	Phone() {
		charge5Adapter = new Adapter; //父类指针指向子类对象（多态）
	}
	~Phone() {
		if (charge5Adapter != NULL) {
			delete charge5Adapter;
		}
	}
	void charge() {
		cout << "Charging" << endl;
		charge5Adapter->use5V(); //调用实现类的方法
	}
private:
	Charge5V *charge5Adapter;
};

int main() {
	Phone iphone;
	iphone.charge();
	return 0;
}
