#include "player.hpp"
#include <iostream>
#include <cstdlib>

Player::Player() {
		std::cout << "afk player created" << std::endl;
		name = "Undefined";
		items.push_back("");
		hp = 100;
		x = 0.0;
		y = 0.0;
	}
Player::Player(const Player& p) {
    std::cout << "player copied" << std::endl;
    name = p.name;
    items = p.items;
    hp = p.hp;
    x = p.x;
    y = p.y;
}
Player::Player(std::string name_, std::vector<std::string> items_, unsigned hp_, float x_, float y_) {
		std::cout << "norm player created" << std::endl;
		name = name_;
		items = items_;
		hp = hp_;
		x = x_;
		y = y_;
	}
Player::~Player(){
		std::cout << "player cleared" << std::endl;
	}
	
void Player::printinfo() const {
		std::cout << "Name: " << name << std::endl;
		std::cout << "X coord: " << x << std::endl;
		std::cout << "Y coord: " << y << std::endl;
		std::cout << "Hp: " << hp << std::endl;
		std::cout << "items: ";
		if (items.empty()) {
			std::cout << "Inventory is empty";
		} else {
			for (size_t i = 0; i < items.size(); i++) {
				std::cout << items[i];
				if (i + 1 < items.size())
					std::cout << ", ";
			}
		}
		std::cout << std::endl;
	
	}

const std::string& Player::getName() const {
    return name;
}
const std::vector<std::string>& Player::getItems() const {
    return items;
}
float Player::getX() const {
    return x;
}
float Player::getY() const {
    return y;
}
unsigned Player::getHp() const {
    return hp;
}
void Player::setX(float newX) {
    x = newX;
}
void Player::setY(float newY) {
    y = newY;
}
void Player::setPos(float newX, float newY) {
    x = newX;
    y = newY;
}
void Player::addItem(const std::string& newItem) {
    items.push_back(newItem);
}

void Player::damage(int dmg) {
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
void Player::heal(int heal) {
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
std::string Player::randomName() {
    return "Player_" + std::to_string(rand() % 100000);
}

void Player::removeDuplicates(std::vector<std::string>& v) {		
    for (size_t i = 0; i < v.size(); i++) {
        for (size_t j = i + 1; j < v.size(); ) {
            if (v[j] == v[i]) {
                v.erase(v.begin() + j);
            } else {
                j++;
            }
        }
    }
}

Player Player::operator+(const Player& other) const{
    Player res;
    res.name = res.randomName();
    res.x = (this->x + other.x) / 2.0f;
    res.y = (this->y + other.y) / 2.0f;
    res.hp = this->hp;
    res.items = this->items;
    for (size_t i = 0; i < other.items.size(); i++) {
        res.items.push_back(other.items[i]);
    }
    res.removeDuplicates(res.items);

    return res;
}
Player Player::operator-(const Player& other) const{
    Player res = *this;

    res.name = res.randomName();

    if (rand() % 2 == 0) {
        res.x = this->x;
        res.y = this->y;
    } else {
        res.x = other.x;
        res.y = other.y;
    }
    res.hp = this->hp;



    for (size_t i = 0; i < res.items.size(); ) {
        bool inOther = false;
        for (size_t j = 0; j < other.items.size(); j++) {
            if (res.items[i] == other.items[j]) {
                inOther = true;
                break;
            }
        }

        if (inOther && (rand() % 2 == 0)) { 
            res.items.erase(res.items.begin() + i);
        } else {
            i++;
        }
    }

    return res;
    }

Player Player::operator/(const Player& other) const{
    Player res;
    res.name = res.randomName();
    res.x = this->x * other.x;
    res.y = this->y * other.y;
    res.hp = this->hp;
    res.items.clear();
    size_t halfThis = this->items.size() / 2;       
    size_t halfOther = other.items.size() / 2; 
    for (size_t i = 0; i < halfThis; i++) {
        res.items.push_back(this->items[i]);
    }
    for (size_t i = halfOther; i < other.items.size(); i++) {
        res.items.push_back(other.items[i]);
    }
    res.removeDuplicates(res.items);

    return res;
}