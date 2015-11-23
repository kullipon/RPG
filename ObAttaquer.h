#pragma once
#include <SFML/Graphics.hpp>
#include "Guerrier.h"
#include "Enemie.h"
#include "Map.h"



class ObAttaquer
{
public:
	ObAttaquer();
	ObAttaquer(sf::RenderWindow &window, Guerrier *toto, Enemie *teki1, Enemie *teki2, Map &map, sf::Time &time, sf::Clock &clock, sf::Clock &clockJoueur, bool &attaquer, bool &hacheUp);
	~ObAttaquer();

	void attaque(bool &attaquer);


private:

	sf::RenderWindow *m_window;
	Guerrier *m_toto;
	Enemie *m_teki1;
	Enemie *m_teki2;
	Map *m_map;
	sf::Time *m_time;
	sf::Clock *m_clock;
	sf::Clock *m_clockJoueur;
	bool *m_attaquer;
	bool *m_hacheUp;



};
