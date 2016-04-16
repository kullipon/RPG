#ifndef GUERRIER_H
#define GUERRIER_H

#include "Joueur.h"
#include "PersonnageBase.h"
#include "Map.h"
#include "Hache.h"

//class Hache;
//class Enemie;
//class Map;

class Guerrier : public Joueur
{
public:
	Guerrier();
	Guerrier(Guerrier const& guerrier);
	virtual ~Guerrier();

void attaquer(sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer);
void attaquer(Enemie *teki1,Enemie *teki2,sf::Clock &hacheClock,Map &map,sf::RenderWindow &window,bool &attaquer);
void attaquer(Enemie *teki, sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer);
void supprimerHache();
bool getHacheUp();

virtual void  affichage(sf::RenderWindow &window,Joueur *joueur);
virtual void set_xplus1(Map &map,bool &deplacementOK);
virtual void set_xmoins1(Map &map,bool &deplacementOK);
virtual void set_yplus1(Map &map,bool &deplacementOK);
virtual void set_ymoins1(Map &map,bool &deplacementOK);






private:

sf::Texture textWar;
sf::Sprite spWarUp;
sf::Sprite spWarUp_2;
sf::Sprite spWarDown;
sf::Sprite spWarDown_2;
sf::Sprite spWarLeft;
sf::Sprite spWarLeft_2;
sf::Sprite spWarRight;
sf::Sprite spWarRight_2;

virtual void recevoirDegats(PersonnageBase *perso);


Hache *hache;
bool m_hacheUp;








};
#endif
