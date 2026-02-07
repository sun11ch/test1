#pragma once
#include <string>
#include <vector>
class Player {
private:
	std::string name;
	std::vector<std::string> items;
	unsigned hp;
	float x;
	float y;
public:
	Player ();
	Player(const Player& p);
	Player(std::string name_, std::vector<std::string> items_, unsigned hp_, float x_, float y_);
	~Player();
	void printinfo() const;
	const std::string& getName() const;
	const std::vector<std::string>& getItems() const;
	float getX() const;
	float getY() const;
	unsigned getHp() const;
	void setX(float newX);
	void setY(float newY);
	void setPos(float newX, float newY);
	void addItem(const std::string& newItem);
	void damage(int dmg);
	void heal(int heal);
	std::string randomName();
	void removeDuplicates(std::vector<std::string>& v);
	Player operator+(const Player& other) const;
	Player operator-(const Player& other) const;
	Player operator/(const Player& other) const;
};