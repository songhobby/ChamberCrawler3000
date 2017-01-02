#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
class Potion;

struct PlayerInfo {
    int gold;
    int level;
    std::shared_ptr<Potion> potion;
    std::string action;
};

#endif
