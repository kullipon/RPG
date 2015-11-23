#include "Flamme.h"
int fBoucle = 0;

Flamme::Flamme() : m_posFlammeX(0), m_posFlammeY(0), m_autorisationCase(0), m_alive(true), m_direction(0),m_destructionArbre(false), m_posArbreX(0),m_posArbreY(0)
{
	m_verifPosX = 0;
	m_verifPosY = 0;
	m_time = m_clock.getElapsedTime();
	
	
}


Flamme::~Flamme()
{
}

int Flamme::get_autorisationCase()
{
	return m_autorisationCase;

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

Flamme::Flamme(sf::RenderWindow &window, Enemie *teki, Map &map, int x, int y, bool &brulerArbreAnimFini) : m_autorisationCase(0), m_deplacement(0.0), m_posFlammeX(x), m_posFlammeY(y),m_alive(true), m_direction(0), m_destructionArbre(false),m_posArbreX(0),m_posArbreY(0)
{

	

	m_verifPosX = m_posFlammeX;
	m_verifPosX %= 32;

	m_verifPosY = m_posFlammeY;
	m_verifPosY %= 32;

	m_time = m_clock.getElapsedTime();

	m_deplacement = m_time.asMilliseconds() * 0.064;



	char direction = teki->getDirection();

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

		if (m_verifPosY > 16)
		{
			m_verifCaseMap = map.getLevel1Pos((m_posFlammeX + 32 ) / 32, (m_posFlammeY + 32) / 32); //VERIF CASE X+32, Y+32

			if (m_verifCaseMap == 'A') // SI ARBRE UP
			{
				//BRULER ARBRE
				//brulerArbre(window, teki, map, m_posFlammeX + 32 + m_autorisationCase, m_posFlammeY + 32, brulerArbreAnimFini);
				m_destructionArbre = true;
				m_alive = false;
			}
			else if (m_verifCaseMap == '0') // SI DU SABLE DONC ON CHECK LA SUITE
			{
				m_verifCaseMap = map.getLevel1Pos((m_posFlammeX + 32 + m_autorisationCase) / 32, m_posFlammeY / 32); // CHECK LA CASE DU DESSUS SOIT X+32, Y

				if (m_verifCaseMap == 'A') // SI ARBRE UP
				{
					//BRULER ARBRE
					//brulerArbre(window, teki, map, m_posFlammeX + 32 + m_autorisationCase, m_posFlammeY, brulerArbreAnimFini);
					m_destructionArbre = true;
					m_alive = false;
					
				}
				else if (m_verifCaseMap == '0') // SINON AVANCE
				{
					//AUTORISATION AVANCER DE 1
					m_autorisationCase++;

					//ICI ON LANCE L'ANIM DE L'ATTAQUE

				}


			}


		}// FIN DU PREMIER IF

		else if (m_verifPosY <= 16)
		{
			m_verifCaseMap = map.getLevel1Pos((m_posFlammeX + 32 + m_autorisationCase) / 32, m_posFlammeY / 32); //VERIF CASE X+32, Y



			if (m_verifCaseMap == 'A') // ARBRE UP
			{
				//BRULER ARBRE
				brulerArbre(window, teki, map, m_posFlammeX + 32 + m_autorisationCase, m_posFlammeY, brulerArbreAnimFini);

			}
			else if (m_verifCaseMap == '0') // DU SABLE DONC ON CHECK LA SUITE
			{
				m_verifCaseMap = map.getLevel1Pos((m_posFlammeX + 32 + m_autorisationCase) / 32, (m_posFlammeY + 32) / 32); // CHECK LA CASE DU DESSUS SOIT X+32, Y+32

				if (m_verifCaseMap == 'A') // ARBRE UP
				{
					//BRULER ARBRE
					brulerArbre(window, teki, map, m_posFlammeX + 32 + m_autorisationCase, m_posFlammeX + 32, brulerArbreAnimFini);

				}
				else if (m_verifCaseMap == '0')
				{
					//AUTORISATION AVANCER DE 1
					m_autorisationCase++;

					//ICI ON LANCE L'ANIM DE L'ATTAQUE

					break;
				}

				case 'W':
					m_direction = 'W';

	
				break;


			}
		} //FIN DU DERNIER IF

	}//FIN SWITCH
}


void Flamme::brulerArbre(sf::RenderWindow &window, Enemie *teki, Map &map, int x, int y,bool &brulerArbreAnimFini)
{

	if (brulerArbreAnimFini == true)
	{
		brulerArbreAnimFini = false;

		map.arbreEnFeu_1.setPosition((float)x, (float)y);
		map.arbreEnFeu_2.setPosition((float)x, (float)y);
		fBoucle = 0;

	}

	if (m_time.asMilliseconds() < 800)
	{

		window.draw(map.arbreEnFeu_1);

	}
	else if (m_time.asMilliseconds() > 800 && m_time.asMilliseconds() < 1600)
	{

		window.draw(map.arbreEnFeu_2);

	}
	else if (m_time.asMilliseconds() > 1600)
	{

		m_clock.restart();
		fBoucle++;

		if (fBoucle == 2)
		{
			teki->set_demandeAttaque(false);
			teki->set_animAttaqueFini(true);
			brulerArbreAnimFini = true;
			m_autorisationCase = 0;
			m_alive = false;

			if (map.setPosArbreVersSable(x / 32, y / 32) == true)
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
