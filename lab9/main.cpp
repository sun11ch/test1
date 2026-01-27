#include <iostream>
#include <string>
class Player {
private:
	std::string name;
	std::string doing;
	unsigned hp;
	float x;
	float y;
//protected:
	//float x;
	//float y;
	//unsigned hp
public:
	Player() {
		std::cout << "afk player created" << std::endl;
		name = "Undefined";
		doing = "Nothing";
		hp = 100;
		x = 0.0;
		y = 0.0;
	}
	Player(const Player& p) {
		std::cout << "player copied" << std::endl;
		name = p.name;
		doing = p.doing;
		hp = p.hp;
		x = p.x;
		y = p.y;
	}
	Player(std::string name_, std::string doing_, unsigned hp_, float x_, float y_) {
		std::cout << "norm player created" << std::endl;
		doing = doing_;
		name = name_;
		hp = hp_;
		x = x_;
		y = y_;
	}
	~Player(){
		std::cout << "player cleared" << std::endl;
	}

	void printinfo() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "X coord: " << x << std::endl;
		std::cout << "Y coord: " << y << std::endl;
		std::cout << "Hp: " << hp << std::endl;
		std::cout << "Doing: " << doing << std::endl;
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
	std::string getDoing() const {
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
		if (dmg < 0 ) {
			return;
		}
		if (dmg >= hp) {
			hp = 0;
		}
		else {
			hp -= dmg;
		}
	}
	void heal(int heal) {
		if (heal < 0) {
			return;
		}
		if ( (heal + hp) > 100) {
			hp = 100;
		}
		if (hp == 100) {
			std::cout << "hp already 100";
		}
		else{
			hp += heal;
		}
		
	}
};

int main() {
	Player alex1;
	Player alex2(alex1);
	Player alex3("df", "nothing", 100, 1,1);
	alex3.damage(40);
	alex3.printinfo();
	alex3.heal(90);
	alex3.damage(40);
	alex3.printinfo();

	return 0;
}