#pragma once
#include <SFML/Graphics.hpp>
#include "Enemie.h"
#include "Map.h"




class Flamme
{
public:
	Flamme();
	Flamme(Enemie *teki,int x, int y);
	~Flamme();

	int get_autorisationCase();
	bool get_alive();
	char get_direction();
	bool get_destructionArbre();
	

                void brulerArbre(sf::RenderWindow &window, Enemie *teki, Map &map,bool &brulerArbreAnimFini);
                void verifDeplacement(sf::RenderWindow &window,Enemie *teki,Map &map,bool &brulerArbreAnimFini);
        


private:


	int m_posFlammeX;
	int m_posFlammeY;
	double m_deplacement;
	int m_verifPosX;
	int m_verifPosY;
	int m_autorisationCaseX;
                  int m_autorisationCaseY;
	char m_verifCaseMap;
	char m_direction;
	sf::Time m_time;
	sf::Clock m_clock;
	bool m_alive;
	bool m_destructionArbre;
	int m_posArbreX;
	int m_posArbreY;

};

