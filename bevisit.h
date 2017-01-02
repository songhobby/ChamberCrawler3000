class Player;
class Enemy;


template<typename Visit, typename Bevisit, typename Type>
bool be_visit_by(Visit & v1, Bevisit & v2, Type t);



void be_attack(Player &player, Enemy &enemy);

void be_attack(Enemy &enemy, Player &player);  
