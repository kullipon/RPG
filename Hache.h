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
	Hache(Guerrier *guerrier,sf::RenderWindow &window,sf::Clock &hacheClock);
	~Hache();
	
	void deplacement(Guerrier *toto, sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp);
	void deplacement(Guerrier *toto,Enemie *teki1,Enemie *teki2,sf::Clock &hacheClock,Map &map,sf::RenderWindow &window,bool &attaquer,bool &hacheUp);
	void deplacement(Guerrier *toto, Enemie *teki,sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp);
	bool contact(Enemie *teki);


	
	

private:

	int m_posX;
	int m_posY;
	char m_direction;
	int m_vitesse;
	int boucleH;
	bool alive;
	float m_angle;
	int m_lastPosX;
	int m_lastPosY;
	

sf::Texture textHache;
sf::Sprite spHache1;
sf::Sprite spHache2;
sf::Sprite spHache3;
sf::Sprite spHache4;
sf::Time hacheTime;




};

#endif