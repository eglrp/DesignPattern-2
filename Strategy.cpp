//策略模式，以商品打折为例。

#include <iostream>
#include <string>

using namespace std;

class Discount {
public:
    virtual double discount(double price) = 0;
};

class DiscountA : public Discount {
public:
    virtual double discount(double price) {
        cout << "0.8" << endl;
        return 0.8 * price;
    }
};

class DiscountB : public Discount {
public:
    virtual double discount(double price) {
        cout << "200-100" << endl;
        if(price >= 200) {
            price -= 100;
        }
        return price;
    }
};

class Item {
public:
    Item(string str, double price) {
        this->str = str;
        this->price = price;
    }
    string getStr() {
        return str;
    }
    void setStrategy(Discount *dis) {
        this->dis = dis;
    }
    double saleDiscount() {
        return dis->discount(price);
    }
private:
    Discount *dis;
    string str;
    double price;
};

int main() {
    Item *item1 = new Item("Nike", 200);
    cout << "满200减100" << endl;
    Discount *disB = new DiscountB;
    item1->setStrategy(disB);
    cout << item1->getStr() << ": " << item1->saleDiscount() << endl;
    cout << "8折" << endl;
    Item *item2 = new Item("T-shirt", 100);
    Discount *disA = new DiscountA;
    item2->setStrategy(disA);
    cout << item2->getStr() << ": " << item2->saleDiscount() << endl;

    return 0;
}
