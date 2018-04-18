//抽象工厂模式，以组装一台电脑为例。


#include <iostream>

using namespace std;

class Graphic {
public:
	virtual void display() = 0;
};

class Memory {
public:
	virtual void storage() = 0;
};

class CPU {
public:
	virtual void calculate() = 0;
};

class IntelGraphic : public Graphic {
public:
	virtual void display() {
		cout << "I am a graphic from Intel" << endl;
	}
};

class NvidiaGraphic : public Graphic {
public:
	virtual void display() {
		cout << "I am a graphic from Nvidia" << endl;
	}
};

class KingstonGraphic : public Graphic {
public:
	virtual void display() {
		cout << "I am a graphic from Kingston" << endl;
	}
};

class IntelMemory : public Memory {
public:
	virtual void storage() {
		cout << "I am a memory from Intel" << endl;
	}
};

class NvidiaMemory : public Memory {
public:
	virtual void storage() {
		cout << "I am a memory from Nvidia" << endl;
	}
};

class KingstonMemory : public Memory {
public:
	virtual void storage() {
		cout << "I am a memory from Kingston" << endl;
	}
};

class IntelCPU : public CPU {
public:
	virtual void calculate() {
		cout << "I am a cpu from Intel" << endl;
	}
};

class NvidiaCPU : public CPU {
public:
	virtual void calculate() {
		cout << "I am a cpu from Nvidia" << endl;
	}
};

class KingstonCPU : public CPU {
public:
	virtual void calculate() {
		cout << "I am a cpu from Kingston" << endl;
	}
};

class Computer{ //抽象工厂
public:
	virtual Graphic *createGraphic() = 0;
	virtual Memory *createMemory() = 0;
	virtual CPU *createCPU() = 0;
};

class Assembly { //架构类
public:
	Assembly(CPU *cpu, Graphic *graphic, Memory *memory) {
		this->cpu = cpu;
		this->graphic = graphic;
		this->memory = memory;
	}
	void work() {
		this->cpu->calculate();
		this->graphic->display();
		this->memory->storage();
	}
private:
	CPU *cpu;
	Graphic *graphic;
	Memory *memory;
};

class IntelComputer : public Computer {
public:
	virtual Graphic *createGraphic() {
		return new IntelGraphic;
	}
	virtual Memory *createMemory() {
		return new IntelMemory;
	}
	virtual CPU *createCPU() {
		return new IntelCPU;
	}
};

class NvidiaComputer : public Computer {
public:
	virtual Graphic *createGraphic() {
		return new NvidiaGraphic;
	}
	virtual Memory *createMemory() {
		return new NvidiaMemory;
	}
	virtual CPU *createCPU() {
		return new NvidiaCPU;
	}
};

class KingstonComputer : public Computer {
public:
	virtual Graphic *createGraphic() {
		return new KingstonGraphic;
	}
	virtual Memory *createMemory() {
		return new KingstonMemory;
	}
	virtual CPU *createCPU() {
		return new KingstonCPU;
	}
};

int main() {
	Computer *intelComputer = new IntelComputer;
	CPU *intelCPU = intelComputer->createCPU();
	Graphic *intelGraphic = intelComputer->createGraphic();
	Memory *intelMemory = intelComputer->createMemory();
	/*intelCPU->calculate();
	intelGraphic->display();
	intelMemory->storage();*/
	Assembly *assem = new Assembly(intelCPU, intelGraphic, intelMemory);
	assem->work();
	delete intelCPU;
	delete intelGraphic;
	delete intelMemory;
	delete intelComputer;
	delete assem;

	cout << "-----------" << endl;

	Computer *intelComputer_1 = new IntelComputer;
	CPU *intelCPU_1 = intelComputer_1->createCPU();
	//intelCPU_1->calculate();
	Computer *nvidiaComputer_2 = new NvidiaComputer;
	Graphic *nvidiaGraphic_2 = nvidiaComputer_2->createGraphic();
	//nvidiaGraphic_2->display();
	Computer *kingstonComputer_3 = new KingstonComputer;
	Memory *kingstonMemory_3 = kingstonComputer_3->createMemory();
	//kingstonMemory_3->storage();
	assem = new Assembly(intelCPU_1, nvidiaGraphic_2, kingstonMemory_3);
	assem->work();
	delete intelCPU_1;
	delete nvidiaGraphic_2;
	delete kingstonMemory_3;
	delete intelComputer_1;
	delete nvidiaComputer_2;
	delete kingstonComputer_3;
	delete assem;

	return 0;
}
