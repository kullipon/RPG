#include "Flamme.h"
int fBoucle = 0;
sf::Time fTime;
#include <cmath>

unsigned char accent = 0x90;

Flamme::Flamme() : m_posFlammeX(0), m_posFlammeY(0), m_autorisationCaseX(0), m_autorisationCaseY(0), m_alive(true), m_direction(0), m_destructionArbre(false), m_posArbreX(0), m_posArbreY(0), m_boucleAff(0)
{
	m_verifPosX = 0;
	m_verifPosY = 0;
	tempsPasse = 0.0f;
	//m_time = m_clock.getElapsedTime();
	m_rotaAngle = 0.0f;
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

Flamme::Flamme(Enemie *teki, int x, int y) : m_autorisationCaseX(0), m_autorisationCaseY(0), m_deplacement(0.0), m_posFlammeX((float)x), m_posFlammeY((float)y), m_alive(true), m_direction(0), m_destructionArbre(false), m_posArbreX(0), m_posArbreY(0), m_boucleAff(0)
{

	fClock.restart();
	tempsPasse = 0;

	m_verifPosX = x % 32;	
	m_verifPosY = y % 32;

	m_deplacement = fTime.asMilliseconds() * 0.064;

	char direction = 0;

	direction = teki->getDirection();

	//Temporaire
	m_posFlammeX += 32;

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

		//On indique qu'on ne veut plus le sprite de l'arbre
		//map.setPosArbreEnFeu((int)m_posArbreX/32, (int)m_posArbreY/32);
		if (map.setPosArbreVersSable((int)m_posArbreX / 32, (int)m_posArbreY / 32))
		{
			std::cout << "ARBRE REMPLAC" << accent << " PAR SABLE !" << std::endl;
		}
		else
		{
			std::cout << "ECHEC DU REMPLACEMENT DE L'ARBRE PAR LE SABLE" << std::endl;
		}
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
		/*	
			if (map.setPosArbreVersSable((int)(m_posArbreX / 32), (int)(m_posArbreY / 32)) == true)
			{
				std::cout << "ARBRE REMPLAC" << accent << " PAR SABLE !" << std::endl;

			}
			else
			{
				std::cout << "ECHEC DU REMPLACEMENT DE L'ARBRE PAR LE SABLE" << std::endl;

			}*/
		}

	}


}

void Flamme::testDeplacement(Enemie *teki, Map &map)
{
	int posX = (int)m_posFlammeX + CHECK_DISTANCE; //m_autorisationCaseX + 32;	

	if ((int)(posX / 32) >= 10)           //AVANT TOUTE VERIF ON CHECK SI ON SORT PAS DU CADRE DE JEU
	{

		teki->get_flamme()->m_alive = false;
		teki->set_demandeAttaque(false);
		teki->set_animAttaqueFini(true);
		return;
	}

	m_autorisationCaseX += CHECK_DISTANCE;


}

void Flamme::verifDeplacement(Enemie *teki, Map &map)
{

	int posX = m_posFlammeX + CHECK_DISTANCE;  //check a 10px

	if ((int)(posX / 32) >= 10)           //AVANT TOUTE VERIF ON CHECK SI ON SORT PAS DU CADRE DE JEU
	{

		teki->get_flamme()->m_alive = false;
		teki->set_demandeAttaque(false);
		teki->set_animAttaqueFini(true);
		return;
	}
	
	if (m_verifPosY > 16)
	{
		m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + CHECK_DISTANCE) / 32), (int)((m_posFlammeY + 32) / 32)); //VERIF CASE X+32, Y+32

		if (m_verifCaseMap == 'A') // SI ARBRE UP
		{
			//BRULER ARBRE
			m_destructionArbre = true;
			m_posArbreX = m_posFlammeX + CHECK_DISTANCE;
			m_posArbreY = m_posFlammeY + 32;
			m_posArbreX = floor(m_posArbreX / 32) * 32;
			m_posArbreY = ceil(m_posArbreY / 32) * 32;
		}
		else if (m_verifCaseMap == '0') // SI DU SABLE DONC ON CHECK LA SUITE
		{

			m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + CHECK_DISTANCE) / 32), (int)(m_posFlammeY / 32)); // CHECK LA CASE DU DESSUS SOIT X+32, Y

			if (m_verifCaseMap == 'A') // SI ARBRE UP
			{
				//BRULER ARBRE

				m_destructionArbre = true;
				m_posArbreX = m_posFlammeX + CHECK_DISTANCE;
				m_posArbreY = m_posFlammeY;
				m_posArbreX = floor(m_posArbreX / 32) * 32;
				m_posArbreY = ceil(m_posArbreY / 32) * 32;

			}
			else if (m_verifCaseMap == '0') // SINON AVANCE
			{
				//AUTORISATION AVANCER DE 1
				m_autorisationCaseX += CHECK_DISTANCE;
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
		m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + CHECK_DISTANCE) / 32), (int)(m_posFlammeY / 32)); //VERIF CASE X+32, Y

		if (m_verifCaseMap == 'A') // ARBRE UP
		{
			//BRULER ARBRE

			m_destructionArbre = true;
			m_posArbreX = m_posFlammeX + CHECK_DISTANCE;
			m_posArbreY = m_posFlammeY;
			m_posArbreY = floor(m_posArbreY / 32) * 32;
			m_posArbreX = floor(m_posArbreX / 32) * 32;
		}
		else if (m_verifCaseMap == '0') // DU SABLE DONC ON CHECK LA SUITE
		{
			m_verifCaseMap = map.getLevel1Pos((int)((m_posFlammeX + CHECK_DISTANCE) / 32), (int)((m_posFlammeY + 32) / 32)); // CHECK LA CASE DU DESSUS SOIT X+32, Y+32

			if (m_verifCaseMap == 'A') // ARBRE UP
			{
				//BRULER ARBRE
				m_destructionArbre = true;
				m_posArbreX = m_posFlammeX + CHECK_DISTANCE;
				m_posArbreY = m_posFlammeY + 32;
				m_posArbreY = floor(m_posArbreY / 32) * 32;
				m_posArbreX = floor(m_posArbreX / 32) * 32;
			}
			else if (m_verifCaseMap == '0')
			{
				//AUTORISATION AVANCER DE 1
				m_autorisationCaseX += CHECK_DISTANCE;
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

	if (m_destructionArbre == true || m_alive == false)
	{
		return;
	}
	//m_boucleAff = teki->get_flamme()->m_boucleAff;
	fTime = fClock.getElapsedTime();
	tempsPasse = fTime.asSeconds();		
	
	m_deplacement = tempsPasse * 2.5f; //Vitesse	

	m_posFlammeX = m_posFlammeX + m_deplacement;  //+ (float)m_autorisationCaseX; //+ 32;
	
			m_rotaAngle = 10.0f;		
		
			teki->boule_1.rotate(m_rotaAngle);
			teki->boule_1.setPosition(m_posFlammeX, m_posFlammeY+17.0f);
			window.draw(teki->boule_1);
		
		
	
		/*
		teki->boule_2.setPosition((float)(m_posFlammeX + m_deplacement + m_autorisationCaseX), (float)m_posFlammeY);

		window.draw(teki->boule_2);
	
	*/
	








}