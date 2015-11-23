#include "PersonnageBase.h"
#include "Map.h"


PersonnageBase::PersonnageBase() : m_vie(100), m_direction('N'), m_vivant(true), m_realX(160), m_realY(320), m_tile(0) 
{
	
	
}



PersonnageBase::~PersonnageBase()
{

}


void PersonnageBase::recevoirDegats(PersonnageBase *perso)
{
	


}

void PersonnageBase::set_direction(char dir)
{
	m_direction = dir;

}

bool PersonnageBase::get_vivant() const
{
	return m_vivant;

}

void PersonnageBase::set_xplus1(Map &map,bool &deplacementOK)
{

}

void PersonnageBase::set_xmoins1(Map &map,bool &deplacementOK)
{


}


void PersonnageBase::set_yplus1(Map &map,bool &deplacementOK)
{

}
void PersonnageBase::set_ymoins1(Map &map,bool &deplacementOK)
{


}


char PersonnageBase::getDirection() const
{
	return m_direction;

}
int PersonnageBase::get_m_realX() const
{

	return m_realX;
}
int PersonnageBase::get_m_realY() const
{

	return m_realY;
}

bool PersonnageBase::checkDead(PersonnageBase *perso)
{

	if (perso->m_vie <= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}