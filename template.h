#ifndef __TEMPLATE__
#define __TEMPLATE__

template <typename T>
bool be_visit (T &player, Type type) {
	if (type == MOVE) {
		player.getPlayerInfo().gold += T::getGold();
		return true;
	} else return false;
}	
