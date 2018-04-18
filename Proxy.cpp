//代理模式，以代购为例。

#include <iostream>
#include <string>

using namespace std;

class Item {
public:
	Item(string kind, bool fact) {
		this->fact = fact;
		this->kind = kind;
	}

	string getKind() {
		return this->kind;
	}

	bool getFact() {
		return this->fact;
	}

private:
	string kind;
	bool fact;
};

class Shopping {
public:
	virtual void buy(Item *item) = 0;
};

class USAShopping : public Shopping {
public:
	virtual void buy(Item *item) {
		cout << "buy from USA: " << item->getKind() << endl;
	}
};

class KoreaShopping : public Shopping {
public:
	virtual void buy(Item *item) {
		cout << "buy from Korea: " << item->getKind() << endl;
	}
};

class ShoppingProxy : public Shopping {
public:
	virtual void buy(Item *item) {
		//购买流程
		if (item->getFact() == true) {
			cout << "1 ready to buy" << endl;
			shopping->buy(item);
			cout << "2 has bounght it" << endl;
			cout << "3 go back home" << endl;
		}
		else {
			cout << "fake goods, do not buy it" << endl;
		}
	}

	ShoppingProxy(Shopping *shopping) { //接收一个具体的购买方式类指针
		this->shopping = shopping;
	}
private:
	Shopping *shopping;
};

int main() {
	Item it1 = Item("Nike", true);
	Item it2("Book", false);
	Shopping *usaShopping = new USAShopping;
	ShoppingProxy *shoppingProxy = new ShoppingProxy(usaShopping);
	shoppingProxy->buy(&it1);
	shoppingProxy->buy(&it2);
	return 0;
}
