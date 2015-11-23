#ifndef HACHE_H
#define HACHE_H

#include <SFML/Graphics.hpp>

class Guerrier;
class Map;
class Enemie;

class Hache
{
public:
	Hache();
	Hache(Guerrier *guerrier,sf::RenderWindow &window,sf::Clock &clock);
	~Hache();
	
	void deplacement(sf::Clock &clock, Guerrier *toto, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp);
	void deplacement(sf::Clock &clock,Guerrier *toto,Enemie *teki1,Enemie *teki2,Map &map,sf::RenderWindow &window,bool &attaquer,bool &hacheUp);
	void deplacement(sf::Clock &clock, Guerrier *toto, Enemie *teki, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp);
	bool contact(Enemie *teki);
	

private:

	int m_posX;
	int m_posY;
	char m_direction;
	int m_vitesse;
	sf::Time a;
	int boucleH;
	bool alive;
	

sf::Texture textHache;
sf::Sprite spHache1;
sf::Sprite spHache2;
sf::Sprite spHache3;
sf::Sprite spHache4;



};

#endif