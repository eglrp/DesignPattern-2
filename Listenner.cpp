//观察者模式，以以下例题为例：
江湖中有多个帮派，还有一名无人不知，无事不晓的百晓生。当江湖中 
发生武林打斗事件，百晓生作为天生的大嘴巴会广播武林消息，每个帮派的门 
第对于事件的处理方式均不同，同帮派被欺负，要报仇，同帮派欺负别人，叫 
好。用观察者模式模拟场景。

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Notifier;

//抽象观察者，根据通知者的广播信息做出相应动作
class Listenner {
public:
	//揍人，并且让通知者知道
	virtual void fight(Listenner *another, Notifier *notifier) = 0;
	//有人被揍
	virtual void fighted(Listenner *one, Listenner *another/*, Notifier *notifier*/) = 0;
	virtual string getName() = 0;
	virtual string getParty() = 0;
};

//抽象通知者
class Notifier {
public:
	//添加观察者
	virtual void addListenner(Listenner *listenner) = 0;
	//删除观察者
	virtual void delListenner(Listenner *listenner) = 0;
	//通知每个观察者
	virtual void notify(Listenner *one, Listenner *another) = 0;
};

//具体观察者
class Hero : public Listenner {
public:
	Hero(string name, string party) {
		this->name = name;
		this->party = party;
	}
	virtual string getName() {
		return name;
	}
	virtual string getParty() {
		return party;
	}
	virtual void fight(Listenner *another, Notifier *notifier) {
		cout << name << "[" << party << "]" << " fight "
			<< another->getName() << "[" << another->getParty() << "]" << endl;
		//让百晓生知道，并广播这次事件
		notifier->notify(this, another);
	}
	virtual void fighted(Listenner *one, Listenner *another/*, Notifier *baixiao*/) {
		if (one->getName() != name && another->getName() != name) {
			//不是当事人
			if (one->getParty() == party) {
				//本帮人揍了别人
				cout << name << " 发现本帮人揍了 " << another->getName() 
					<< "[" << another->getParty() << "]" << " ,拍手叫好 " << endl;
			} else if(another->getParty() == party) {
				//本帮人被别人揍了
				cout << name << "[" << party << "]" << " 发现本帮人被 " 
					<< one->getName() << "[" << one->getParty() << "]"" 揍了，要报仇" << endl;
				//fight(one, baixiao); //此句不可加，否则又触发一次新的广播事件，导致循环调用
			}
		}
	}
private:
	string name;
	string party;
};

//具体通知者
class Baixiao : public Notifier {
public:
	virtual void addListenner(Listenner *listenner) {
		m_vector.push_back(listenner);
	}
	virtual void delListenner(Listenner *listenner) {
		m_vector.remove(listenner);
	}
	virtual void notify(Listenner *one, Listenner *another) {
		for (auto it : m_vector) {
			it->fighted(one, another/*, this*/);
		}
	}
private:
	list<Listenner *> m_vector;
};

int main() {
	Listenner *hong7 = new Hero("洪七公", "丐帮");
	Listenner *huangrong = new Hero("黄蓉", "丐帮");
	Listenner *zhangsanfeng = new Hero("张三丰", "武当");
	Listenner *zhangwuji = new Hero("张无忌", "武当");

	Baixiao *baixiao = new Baixiao;

	baixiao->addListenner(hong7);
	baixiao->addListenner(huangrong);
	baixiao->addListenner(zhangsanfeng);
	baixiao->addListenner(zhangwuji);
	//以上初始化完毕
	//出现一个新的事件，通知者通知所有观察者
	hong7->fight(zhangwuji, baixiao);
	cout << "-----------" << endl;
	zhangsanfeng->fight(hong7, baixiao);
	return 0;
}
