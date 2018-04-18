//命令模式，或动作模式，或事务模式
//以病人到医院看病为例

#include <iostream>
#include <list>

using namespace std;

class Doctor {
public:
    void treatEyes() {
        cout << "doctor treat eyes" << endl;
    }
    void treatNose() {
        cout << "doctor treat nose" << endl;
    }
};

class Command {
public:
    Command(Doctor *doc) {
        this->doc = doc;
    }
    virtual void treat() = 0;
protected:
    Doctor *doc;
};

class CommandEyes :public Command {
public:
    CommandEyes(Doctor *doc) : Command(doc){}
    virtual void treat() {
        doc->treatEyes();
    }
};

class CommandNose : public Command {
public:
    CommandNose(Doctor *doc) : Command(doc){}
    virtual void treat() {
        doc->treatNose();
    }
};

class Nurse { //护士只能处理一张病单
public:
    Nurse(Command *cmd) {
        this->cmd = cmd;
    }
    void notify() {
        this->cmd->treat();
    }
private:
    Command *cmd;
};

class NurseBoss { //护士长能处理一堆病单
public:
    void setCmd(Command *cmd) {
        m_list.push_back(cmd);
    }
    void notify() {
        for(list<Command *>::iterator it = m_list.begin(); it != m_list.end(); it++) {
            (*it)->treat();
        }
    }
private:
    list<Command *> m_list;
};

int main() {
    Doctor *doc = new Doctor;
    Command *cmdEyes = new CommandEyes(doc);
//  Nurse *nur = new Nurse(cmdEyes);
//  nur->notify();
    Command *cmdNose = new CommandNose(doc);
    NurseBoss*nurBoss = new NurseBoss;
    nurBoss->setCmd(cmdEyes);
    nurBoss->setCmd(cmdNose);
    nurBoss->notify();
    return 0;
}
