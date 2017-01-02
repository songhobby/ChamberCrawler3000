#include "style.h"
#include <vector>
#include <string>

const std::vector<std::string> name {
    "Aaron",
    "Shade",
    "Drow",
    "Vampire",
    "Troll",
    "Goblin",
    "H",
    "W",
    "L",
    "E",
    "O",
    "D",
    "M",
    "Small Gold",
    "Normal Gold",
    "Dragon Hoard",
    "Merchant Hoard",
    "RH",
    "BA",
    "BD",
    "PH",
    "WA",
    "WD",
    "Space",
    "Vertical Wall",
    "Horizontal Wall",
    "Door",
    "Tile",
    "Passage",
    "Stair",
    //new player
    "NightElf",
    "Eason",
    

    //new enemy
    "R",
    "B",
    "F"
};

std::string getString (Style style) {
	return name.at(style);
}
