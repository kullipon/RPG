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

	int get_autorisationCaseX();
                  int get_autorisationCaseY();
	bool get_alive();
	char get_direction();
	bool get_destructionArbre();
	

                void brulerArbre(sf::RenderWindow &window, Enemie *teki, Map &map);
                void verifDeplacement(Enemie *teki,Map &map);
                 void affichage(sf::RenderWindow &window, Enemie *teki,Map &map);
        


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
	
	bool m_alive;
	bool m_destructionArbre;
	int m_posArbreX;
	int m_posArbreY;
                  int m_boucleAff;
                  sf::Clock fClock;

};


