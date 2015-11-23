#ifndef PERSONNAGE_BASE_H
#define PERSONNAGE_BASE_H

#include <iostream>
//#include <SFML\Config.hpp>
class Map;


class PersonnageBase
{

public:
	PersonnageBase();
	virtual ~PersonnageBase();


void set_direction(char dir);

virtual void set_xplus1(Map &map,bool &deplacementOK);
virtual void set_xmoins1(Map &map,bool &deplacementOK);
virtual void set_yplus1(Map &map,bool &deplacementOK);
virtual void set_ymoins1(Map &map,bool &deplacementOK);

char getDirection() const;
int get_m_realX() const;
int get_m_realY() const;
bool get_vivant() const;




protected:


int m_realX,m_realY;
int m_vie;
char m_direction;
bool m_vivant;
int m_tile;





virtual void recevoirDegats(PersonnageBase *perso);
bool checkDead(PersonnageBase *perso);







};
#endif



