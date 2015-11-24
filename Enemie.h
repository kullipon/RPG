#ifndef ENEMIE_H
#define ENEMIE_H

#include "PersonnageBase.h"
#include <SFML/Graphics.hpp>
class Flamme;

//class PersonnageBase;

extern bool attaquer;

static bool brulerArbreAnimFini;

class Enemie :	public PersonnageBase
{
public:
	Enemie();
	Enemie(int x,int y,Map &map);
	Enemie(int x, int y, Map &map, bool boss);
	
	
virtual ~Enemie();






// ACCESSEURS

bool get_animDegatsON();
bool get_attacked();
bool get_demandeAttaque();
bool get_transeUP();
bool get_animTranseFini();
bool get_animAttaqueFini();


//MUTATEURS

void set_demandeAttaque(bool demandeAttaque);
void set_transeUP(bool transUP);
void set_attacked(bool attacked);
void set_animDegatsOn(bool tekiAnim);
void set_animTranseFini(bool animTranseFini);
void set_animAttaqueFini(bool animAttaqueFini);


//METHODES

void attaque(sf::RenderWindow &window,Enemie *teki,Map &map,Flamme *flamme1);
void animTranse(sf::RenderWindow &window,Enemie *teki);
virtual void affichage(sf::RenderWindow &window, Enemie *teki) const;
void animDegats(sf::RenderWindow &window, Enemie *teki);
void deplacementAuto(Enemie *enemie, Map &map);
virtual void recevoirDegats(Enemie *perso);




private:
	

sf::Texture texture;
sf::Sprite teki1;
sf::Sprite teki2;
sf::Texture textPeppa;
sf::Sprite peppaSprite;
sf::Sprite boule_1;
sf::Sprite boule_2;
sf::Sprite transeSprite;


bool animDegatsON;
bool m_attacked;
bool m_boss;
bool m_demandeAttaque; 
bool m_transeUP;
bool m_animTranseFini;
bool m_animAttaqueFini;
bool m_lastWasShoot;
float m_vitesseBoule;

};

#endif

