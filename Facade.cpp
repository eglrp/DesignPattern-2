//外观模式

#include <iostream>

using namespace std;

class TV {
public:
	void On() {
		cout << "tv is turned on" << endl;
	}
	void Off() {
		cout << "tv is turned off" << endl;
	}
};

class Light {
public:
	void On() {
		cout << "light is turned on" << endl;
	}
	void Off() {
		cout << "light is turned off" << endl;
	}
};

class Audio {
public:
	void On() {
		cout << "audio is turned on" << endl;
	}
	void Off() {
		cout << "audio is turned off" << endl;
	}
};

class Microphone {
public:
	void On() {
		cout << "microphone is turned on" << endl;
	}
	void Off() {
		cout << "microphone is turned off" << endl;
	}
};

class DVD {
public:
	void On() {
		cout << "dvd is turned on" << endl;
	}
	void Off() {
		cout << "dvd is turned off" << endl;
	}
};

class GamePlayer {
public:
	void On() {
		cout << "gameplayer is turned on" << endl;
	}
	void Off() {
		cout << "gameplayer is turned off" << endl;
	}
};

class HomeTheater {
public:
	HomeTheater() {
		tv = new TV;
		light = new Light;
		audio = new Audio;
		microphone = new Microphone;
		dvd = new DVD;
		gameplayer = new GamePlayer;
	}
	/*HomeTheater(TV *tv, Light *light, Audio *audio, Microphone *microphone, DVD *dvd, GamePlayer *gameplayer) {
		this->tv = tv;
		this->light = light;
		this->audio = audio;
		this->microphone = microphone;
		this->dvd = dvd;
		this->gameplayer = gameplayer;
	}*/
	~HomeTheater() {
		delete tv;
		delete light;
		delete audio;
		delete microphone;
		delete dvd;
		delete gameplayer;
	}
	void KTV() {
		tv->On();
		light->Off();
		audio->On();
		microphone->On();
		dvd->On();
	}
	void game() {
		tv->On();
		audio->On();
		gameplayer->On();
	}

private:
	TV *tv;
	Light *light;
	Audio *audio;
	Microphone *microphone;
	DVD *dvd;
	GamePlayer *gameplayer;
};

int main() {
	HomeTheater *home = new HomeTheater;
	cout << "游戏模式" << endl;
	home->game();
	cout << "KTV模式" << endl;
	home->KTV();
	home->~HomeTheater();
}
