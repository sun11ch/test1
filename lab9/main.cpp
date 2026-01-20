#include <iostream>
#include <string>
class Player {
private:
	std::string name;
	float x;
	float y;
	unsigned hp;
	bool doing;
public:
	Player() {
		std::cout << "afk player created" << std::endl;
		name = "Undefined";
		x = 0;
		y = 0;
		hp = 100;
		doing = 1;
	}
	Player(const Player& p) {
		std::cout << "player copied" << std::endl;
		name = p.name;
		x = p.x;
		y = p.y;
		hp = p.hp;
		doing = p.doing;
	}
	Player(std::string name_, float x_, float y_, unsigned hp_, bool doing_) {
		std::cout << "norm player created" << std::endl;
		name = name_;
		x = x_;
		y = y_;
		hp = hp_;
		doing = doing_;
	}
	~Player(){
		std::cout << "player cleared" << std::endl;
	}

	void printinfo() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "X coord: " << x << std::endl;
		std::cout << "Y coord: " << y << std::endl;
		std::cout << "Hp: " << hp << std::endl;
		std::cout << "Doing (is alive): " << doing << std::endl;
	}

	std::string getName() const {
		return name;
	}
	float getX() const {
		return x;
	}
	float getY() const {
		return y;
	}
	unsigned getHp() const {
		return hp;
	}
	bool getDoing() const {
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
		if ((doing == 0) or (dmg <0 )) {
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
		if ((doing == 0) or (heal < 0)) {
			return;
		}
		if ( (heal + hp) > 100) {
			hp = 100;
		}
		else{
			hp += heal;
		}
		
	}
};

int main() {
	Player alex1;
	Player alex2(alex1);
	Player alex3("sanya", 0.3, 0.1, 50, 1);
	alex3.damage(40);
	alex3.printinfo();
	alex3.heal(90);
	alex3.damage(40);
	alex3.printinfo();

	return 0;
}