#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Enemie.h"
#include "Joueur.h"
#include "PersonnageBase.h"


class Map
{
public:
	Map();
	Map(Joueur *joueur1);
	~Map();

	void affichage(sf::RenderWindow &window);
	void deleteMap();
	char getLevel1Pos(int x, int y);
	bool setEnemiePos(int x,int y);
	bool setPostoZero(int x,int y);
	bool setPosArbreVersSable(int x, int y);
	//bool moveEnemiePos(Enemie *teki,int x,int y,int axe);
	//bool okForMove(PersonnageBase *perso,int x, int y,int axe);

	bool okForMove(PersonnageBase *perso,char direction,int variation);
	void temps(Enemie *enemie, Enemie *teki2, sf::Time &time, sf::Clock &clock, sf::RenderWindow &window);
	void temps(Enemie *teki, sf::Time &time, sf::Clock &clock, sf::RenderWindow &window);
	
	sf::Sprite arbreEnFeu_1;
	sf::Sprite arbreEnFeu_2;

private:

	//longueur de map en X
	int const m_X; 
	//longueur de map en Y
	int const m_Y; 
	//MATRIX DE LA MAP
	char ** level1; 

	//boucle du temps
	int m_boucle;

	//Pointeurs vers les joueurs et enemies
	Joueur * joueur1;
	Enemie * enemieDeBase;

	//textures et sprites

	sf::Texture texture;
	sf::Sprite sable;
	sf::Sprite arbre;
	sf::Sprite teki1;
	sf::Sprite teki2;
	sf::Sprite montagne;
	sf::Sprite mont_bas_droite;
	sf::Sprite mont_bas_gauche;
	sf::Sprite mont_haut_gauche;
	sf::Sprite mont_haut_droite;
	sf::Sprite arbreMort;
	



};
#endif

