#include "Flamme.h"
int fBoucle = 0;
sf::Time fTime;
#include <cmath>


Flamme::Flamme() : m_posFlammeX(0), m_posFlammeY(0), m_autorisationCaseX(0), m_autorisationCaseY(0), m_alive(true), m_direction(0), m_destructionArbre(false), m_posArbreX(0), m_posArbreY(0), m_boucleAff(0)
{
	m_verifPosX = 0;
	m_verifPosY = 0;
	tempsPasse = 0;
	//m_time = m_clock.getElapsedTime();


}


Flamme::~Flamme()
{
}

int Flamme::get_autorisationCaseX()
{
	return m_autorisationCaseX;

}

int Flamme::get_autorisationCaseY()
{

	return m_autorisationCaseY;

}

bool Flamme::get_alive()
{
	return m_alive;

}

char Flamme::get_direction()
{

	return m_direction;

}

bool Flamme::get_destructionArbre()
{
	return m_destructionArbre;


}

Flamme::Flamme(Enemie *teki, int x, int y) : m_autorisationCaseX(0), m_autorisationCaseY(0), m_deplacement(0.0), m_posFlammeX(x), m_posFlammeY(y), m_alive(true), m_direction(0), m_destructionArbre(false), m_posArbreX(0), m_posArbreY(0), m_boucleAff(0)
{


	tempsPasse = 0;
	m_verifPosX = m_posFlammeX;
	m_verifPosX %= 32;

	m_verifPosY = m_posFlammeY;
	m_verifPosY %= 32;


	m_deplacement = fTime.asMilliseconds() * 0.064;

	char direction = 0;

	direction = teki->getDirection();

	switch (direction)
	{

	case 'N':
		m_direction = 'N';

		break;

	case 'S':
		m_direction = 'S';
		break;

	case 'E':

		m_direction = 'E';
		break;
	case 'W':
		m_direction = 'W';
		break;

	}//FIN SWITCH



}


void Flamme::brulerArbre(sf::RenderWindow &window, Enemie *teki, Map &map)
{
	//  fClock = teki->get_flamme()->fClock;
	fTime = fClock.getElapsedTime();
	m_posArbreX = teki->get_flamme()->m_posArbreX;
	m_posArbreY = teki->get_flamme()->m_posArbreY;


	if (teki->get_brulerArbreAnimFini() == true)
	{
		teki->set_brulerArbreAnimFini(false);
		fTime = fClock.restart();

		map.arbreEnFeu_1.setPosition((float)m_posArbreX, (float)m_posArbreY);
		map.arbreEnFeu_2.setPosition((float)m_posArbreX, (float)m_posArbreY);
		fBoucle = 0;


	}

	if (fTime.asMilliseconds() < 800)
	{

		window.draw(map.arbreEnFeu_1);

	}
	else if (fTime.asMilliseconds() > 800 && fTime.asMilliseconds() < 1600)
	{

		window.draw(map.arbreEnFeu_2);

	}
	else if (fTime.asMilliseconds() > 1600)
	{

		fClock.restart();
		fBoucle++;

		if (fBoucle == 2)
		{
			//teki->set_demandeAttaque(false);
			teki->set_animAttaqueFini(true);
			teki->set_brulerArbreAnimFini(true);
			m_alive = false;

			if (map.setPosArbreVersSable((int)(m_posArbreX / 32), (int)(m_posArbreY / 32)) == true)
			{
				std::cout << "ARBRE REMPLACED PAR SABLE !" << std::endl;

			}
			else
			{
				std::cout << "ECHEC DU REMPLACEMENT DE L'ARBRE PAR LE SABLE" << std::endl;

			}
		}

	}


}

void Flamme::verifDeplacement(Enemie *teki, Map &map)
{

	int posX = m_posFlammeX + m_autorisationCaseX + 32;

	if ((int)(posX / 32) >= 10)           //AVANT TOUTE VERIF ON CHECK SI ON SORT PAS DU CADRE DE JEU
	{

		teki->get_flamme()->m_alive = false;
		teki->set_demandeAttaque(false);
		teki->set_animAttaqueFini(true);
		return;
	}
	
	if (m_verifPosY > 16)
	{
		m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + 32 + m_autorisationCaseX) / 32), (int)((m_posFlammeY + 32) / 32)); //VERIF CASE X+32, Y+32

		if (m_verifCaseMap == 'A') // SI ARBRE UP
		{
			//BRULER ARBRE
			m_destructionArbre = true;
			m_posArbreX = m_posFlammeX + 32 + m_autorisationCaseX;
			m_posArbreY = m_posFlammeY + 32;
			m_posArbreX = floor(m_posArbreX / 32) * 32;
			m_posArbreY = ceil(m_posArbreY / 32) * 32;
		}
		else if (m_verifCaseMap == '0') // SI DU SABLE DONC ON CHECK LA SUITE
		{

			m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + 32 + m_autorisationCaseX) / 32), (int)(m_posFlammeY / 32)); // CHECK LA CASE DU DESSUS SOIT X+32, Y

			if (m_verifCaseMap == 'A') // SI ARBRE UP
			{
				//BRULER ARBRE

				m_destructionArbre = true;
				m_posArbreX = m_posFlammeX + 32 + m_autorisationCaseX;
				m_posArbreY = m_posFlammeY;
				m_posArbreX = floor(m_posArbreX / 32) * 32;
				m_posArbreY = ceil(m_posArbreY / 32) * 32;

			}
			else if (m_verifCaseMap == '0') // SINON AVANCE
			{
				//AUTORISATION AVANCER DE 1
				m_autorisationCaseX += 32;
			}

		}
		else // AUTRE CAS (MONTAGNE...)
		{

			m_alive = false;
			m_destructionArbre = false;
			teki->set_animAttaqueFini(true);
		}

	}// FIN DU PREMIER IF

	else if (m_verifPosY <= 16)
	{
		m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + 32 + m_autorisationCaseX) / 32), (int)(m_posFlammeY / 32)); //VERIF CASE X+32, Y

		if (m_verifCaseMap == 'A') // ARBRE UP
		{
			//BRULER ARBRE

			m_destructionArbre = true;
			m_posArbreX = m_posFlammeX + 32 + m_autorisationCaseX;
			m_posArbreY = m_posFlammeY;
			m_posArbreY = floor(m_posArbreY / 32) * 32;
			m_posArbreX = floor(m_posArbreX / 32) * 32;
		}
		else if (m_verifCaseMap == '0') // DU SABLE DONC ON CHECK LA SUITE
		{
			m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + 32 + m_autorisationCaseX) / 32), (int)((m_posFlammeY + 32) / 32)); // CHECK LA CASE DU DESSUS SOIT X+32, Y+32

			if (m_verifCaseMap == 'A') // ARBRE UP
			{
				//BRULER ARBRE
				m_destructionArbre = true;
				m_posArbreX = m_posFlammeX + 32 + m_autorisationCaseX;
				m_posArbreY = m_posFlammeY + 32;
				m_posArbreY = floor(m_posArbreY / 32) * 32;
				m_posArbreX = floor(m_posArbreX / 32) * 32;
			}
			else if (m_verifCaseMap == '0')
			{
				//AUTORISATION AVANCER DE 1
				m_autorisationCaseX += 32;
			}

		}
		else // AUTRE CAS (MONTAGNE...)
		{
			teki->get_flamme()->m_alive = false;

			m_destructionArbre = false;
		}
	} //FIN DU DERNIER IF
}


void Flamme::affichage(sf::RenderWindow& window, Enemie* teki, Map& map)
{
	bool destructionArbre;
	bool alive;

	destructionArbre = teki->get_flamme()->m_destructionArbre;
	alive = teki->get_flamme()->m_alive;

	if (destructionArbre == true || alive == false)
	{
		return;
	}
	//m_boucleAff = teki->get_flamme()->m_boucleAff;


	if (tempsPasse > 1000)
	{
	
		fTime = fClock.restart();
	}

	fTime = this->fClock.getElapsedTime();
	tempsPasse = fTime.asMilliseconds();
	m_deplacement = tempsPasse * 0.032;

	
		teki->boule_1.setPosition((float)(m_posFlammeX + m_deplacement + m_autorisationCaseX), (float)m_posFlammeY);

		window.draw(teki->boule_1);
	
		/*
		teki->boule_2.setPosition((float)(m_posFlammeX + m_deplacement + m_autorisationCaseX), (float)m_posFlammeY);

		window.draw(teki->boule_2);
	
	*/
	








}