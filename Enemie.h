#ifndef ENEMIE_H
#define ENEMIE_H

#include "PersonnageBase.h"
#include <SFML/Graphics.hpp>
//#include "Flamme.h"

class Flamme;

//class PersonnageBase;

extern bool attaquer;

class Enemie :	public PersonnageBase
{
public:
	Enemie();
	Enemie(std::string nom,int x,int y,Map &map);
	Enemie(std::string nom,int x, int y, Map &map, bool boss);
	
	
virtual ~Enemie();


sf::Sprite boule_1;
sf::Sprite boule_2;



// ACCESSEURS

bool get_animDegatsON();
bool get_attacked();
bool get_demandeAttaque();
bool get_transeUP();
bool get_animTranseFini();
bool get_animAttaqueFini();
bool get_brulerArbreAnimFini();
Flamme* get_flamme();  //RECUPERE L'ADRESSE DU POINTEUR


//MUTATEURS

void set_demandeAttaque(bool demandeAttaque);
void set_transeUP(bool transUP);
void set_attacked(bool attacked);
void set_animDegatsOn(bool tekiAnim);
void set_animTranseFini(bool animTranseFini);
void set_animAttaqueFini(bool animAttaqueFini);
void set_brulerArbreAnimFini(bool brulerArbreAnimFini);
void set_autorisationShoot(bool autorisationShoot);



//METHODES

void attaque(sf::RenderWindow &window,Enemie *teki,Map &map);
void animTranse(sf::RenderWindow &window,Enemie *teki);
virtual void affichage(sf::RenderWindow &window, Enemie *teki) const;
void animDegats(sf::RenderWindow &window, Enemie *teki);
void deplacementAuto(Enemie *teki1,Enemie *teki2, Map &map);
void deplacementAuto(Enemie *teki, Map &map);
virtual void recevoirDegats(Enemie *perso);
void killFlamme();





private:
	

sf::Texture texture;
sf::Sprite teki1;
sf::Sprite teki2;
sf::Texture textPeppa;
sf::Sprite peppaSprite;
//sf::Sprite boule_1;  EN PUBLIC
//sf::Sprite boule_2;  EN PUBLIC
sf::Sprite transeSprite;

std::string m_nom;
bool m_animDegatsON;
bool m_attacked;
bool m_boss;
bool m_demandeAttaque; 
bool m_transeUP;
bool m_animTranseFini;
bool m_animAttaqueFini;
bool m_lastWasShoot;
float m_vitesseBoule;
bool m_brulerArbreAnimFini;
bool m_autorisationShoot;
sf::Clock tekiClock;
sf::Time b;

Flamme *m_flamme;

};

#endif

