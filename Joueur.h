#pragma once
#include "PersonnageBase.h"
#include <SFML/Graphics.hpp>
//class PersonnageBase;

class Joueur :	public PersonnageBase
{
public:

	Joueur();
	virtual ~Joueur();



//virtual void deplacement(Joueur *joueur,      &key);
virtual void affichage(sf::RenderWindow &window,Joueur *joueur);



};

