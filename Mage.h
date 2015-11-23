#pragma once
#include "Joueur.h"
#include "PersonnageBase.h"
//class PersonnageBase;
//class Joueur;

class Mage : public Joueur
{
public:
	Mage();
	virtual ~Mage();

virtual void  affichage(sf::RenderWindow &window,Joueur *joueur);



private:


int m_mana;

virtual void deplacement(Mage &mage);
virtual void recevoirDegats(PersonnageBase *perso);


//sorts

};

