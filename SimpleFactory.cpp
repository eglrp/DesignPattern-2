//简单工厂模式
//以生产水果为例。

#include <iostream>
#include <string>

using namespace std;

class Fruit {
public:
	virtual void getName() = 0;
};

class Apple :public Fruit {
public:
	virtual void getName() {
		cout << "I am a apple" << endl;
	}
};

class Banana : public Fruit {
public:
	virtual void getName() {
		cout << "I am a banana" << endl;
	}
};

class Factory {
public:
	Factory(string kind) {
		this->kind = kind;
	}

	Fruit *createFruit(string kind) {
		Fruit *fruit = NULL;
		if (kind == "Apple") {
			fruit = new Apple;
		}
		else if (kind == "Banana") {
			fruit = new Banana;
		}

		return fruit;
	}

private:
	string kind;
};

int main() {
	Fruit *fruit = NULL;
	Factory *factory = NULL;

	fruit = factory->createFruit("Apple");
	fruit->getName();
	delete fruit;
	fruit = NULL;

	fruit = factory->createFruit("Banana");
	fruit->getName();
	delete fruit;
	fruit = NULL;

	delete factory;

	return 0;
}
