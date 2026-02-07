#pragma once
#include "item.hpp"
class lootbox{
private:
    std::string caseName;
    std::vector<item> caseItems;
public:
    lootbox();
    lootbox(const lootbox& other);
    lootbox(const std::string& caseName_, const std::vector<item>& caseItems_);
    ~lootbox();
    void printLootbox() const;
    item returnRandItem() const;
};