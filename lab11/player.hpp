#pragma once
#include "lootbox.hpp"
class Player {
private:
	std::string name;
	std::vector<item> inv;
	unsigned hp;
	float x;
	float y;
public:
	Player ();
	Player(const Player& p);
	Player(const std::string& name_, const std::vector<item>& inv_, unsigned hp_, float x_, float y_);
	~Player();
	void printinfo() const;
	const std::string& getName() const;
	const std::vector<item>& getItems() const;
	float getX() const;
	float getY() const;
	unsigned getHp() const;
	void setX(float newX);
	void setY(float newY);
	void setPos(float newX, float newY);
	void addItem(const item& newItem);
	void damage(int dmg);
	void heal(int heal);
	std::string randomName();
	void removeDuplicates(std::vector<item>& v);
	Player operator+(const Player& other) const;
	Player operator-(const Player& other) const;
	Player operator/(const Player& other) const;
	void openBox(const lootbox& box);
};