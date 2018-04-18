//装饰器模式，以给手机贴膜和装套为例。

#include <iostream>

using namespace std;

class Phone {
public:
    virtual void show()= 0;
};

class Iphone : public Phone {
public:
    virtual void show() {
        cout << "A iphone is shown" << endl;
    }
};

class Miui : public Phone {
public:
    virtual void show() {
        cout << "A miui is shown" << endl;
    }
};

class Decorator : public Phone {
public:
    Decorator(Phone *phone) {
        this->phone = phone;
    }

    virtual void show() = 0;
protected:
    Phone *phone;
};

class FilmDecorator : public Decorator {
public:
    FilmDecorator(Phone *phone) : Decorator(phone) {
        //this->phone = phone;
    }
    virtual void show() {
        this->phone->show();
        film();
    }
    void film() {
        cout << "This phone is filmed" << endl;
    }
//protected:
//  Phone *phone;
};

class CoverDecorator : public Decorator {
public:
    CoverDecorator(Phone *phone) : Decorator(phone) {}
    virtual void show() {
        this->phone->show();
        cover();
    }
    void cover() {
        cout << "This phone is covered" << endl;
    }
//protected:
//  Phone *phone;
};

int main() {
    Phone *iphone = new Iphone;
    iphone->show();
    cout << "--------" << endl;

    Phone *filmDecorator = new FilmDecorator(iphone);
    filmDecorator->show();
    cout << "--------" << endl;

    Phone *coverDecorator = new CoverDecorator(iphone);
    coverDecorator->show();
    cout << "--------" << endl;

    Phone *coverAndFilmDecorator = new CoverDecorator(filmDecorator);
    coverAndFilmDecorator->show();

    delete filmDecorator;
    delete coverDecorator;
    delete coverAndFilmDecorator;
    delete iphone;
    return 0;
}
//上例中
//Phone即Component
//Iphone、Miui即ConcreteComponent
//FilmDecorator、CoverDecorator即ConcreteDecorator
//可以发现，装饰器模式中主业务逻辑中全部是针对同一个抽象接口Component来编程
