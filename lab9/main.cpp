#include <iostream>

class Player {
private:
	std::string name;
	float x;
	float y;
	unsigned hp;
	bool doing;
public:
	Player(std::string name_, float x_, float y_, unsigned hp_, bool doing_) {
		std::cout << "norm player created" << std::endl;
		name = name_;
		x = x_;
		y = y_;
		hp = hp_;
		doing = doing_;
	}
	Player() {
		std::cout << "afk player created" << std::endl;
		name = "Undefined";
		x = 0;
		y = 0;
		hp = 100;
		doing = 1;
	}
	Player(Player &p) {
		std::cout << "player copied" << std::endl;
		name = p.name;
		x = p.x;
		y = p.y;
		hp = p.hp;
		doing = p.doing;
	}
	~Player(){
		std::cout << "player cleared" << std::endl;
	}

	void printinfo() {
		std::cout << "Name: " << name << std::endl;
		std::cout << "X coord: " << x << std::endl;
		std::cout << "Y coord: " << y << std::endl;
		std::cout << "Hp: " << hp << std::endl;
		std::cout << "Doing: " << doing << std::endl;
	}

	std::string getName(std::string name) {
		return name;
	}
	float getX(float x) {
		return x;
	}
	float getY(float y) {
		return y;
	}
	unsigned getHp(unsigned hp) {
		return hp;
	}
	bool getDoing(bool doing) {
		return doing;
	}

	void setX(float newX) {
		x = newX;
	}
	void setY(float newY) {
		y = newY;
	}
	void setPos(float newX, float newY) {
		x = newX;
		y = newY;
	}

	void damage(int dmg) {
		if (doing == 0) {
			return;
		}
		if (dmg < 0) {
			return;
		}
		if (dmg >= hp) {
			hp = 0;
			doing = 0;
		}
		else {
			hp -= dmg;
		}
	}
	void heal(int heal) {
		if (doing = 0) {
			return;
		}
		if (heal < 0) {
			return;
		}
		hp += heal;
	}
};

float main() {
	Player alex;
	return 0;
}