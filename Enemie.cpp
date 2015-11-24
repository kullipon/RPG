#include "Enemie.h"
#include "Map.h"

#include "Flamme.h"


int bBoucle = 0;
sf::Time b;
sf::Clock bClock;






Enemie::Enemie(): PersonnageBase(), m_attacked(false), animDegatsON(false), m_boss(false), m_vitesseBoule(10.0f), m_demandeAttaque(false),m_transeUP(false),m_animTranseFini(true),m_animAttaqueFini(true),m_lastWasShoot(false)
{
	
if (!texture.loadFromFile("texture_7.png"))
	{
		std::cout << "Erreur lors du chargement de la texture des enemies" << std::endl;

		exit(1);

	}
	else
	{

		teki1.setTexture(texture);
		teki1.setTextureRect(sf::IntRect(64,0,32,32));
		teki2.setTexture(texture);
		teki2.setTextureRect(sf::IntRect(96,0,32,32));
		boule_1.setTexture(texture);
		boule_1.setTextureRect(sf::IntRect(320, 0, 32, 32));
		boule_2.setTexture(texture);
		boule_2.setTextureRect(sf::IntRect(352, 0, 32, 32));
		transeSprite.setTexture(texture);
		transeSprite.setTextureRect(sf::IntRect(384, 0, 32, 32));
		
		
	}
		

}

Enemie::Enemie(int x, int y, Map &map) : PersonnageBase(), m_attacked(false), animDegatsON(false), m_boss(false), m_vitesseBoule(10.0f), m_demandeAttaque(false), m_transeUP(false), m_animTranseFini(true), m_animAttaqueFini(true), m_lastWasShoot(false)
{
	
	m_realX = x;
	m_realY = y;


	if (!texture.loadFromFile("texture_7.png"))
	{
		std::cout << "Erreur lors du chargement de la texture des enemies" << std::endl;

		exit(1);

	}
	else
	{

		teki1.setTexture(texture);
		teki1.setTextureRect(sf::IntRect(64,0,32,32));
		teki2.setTexture(texture);
		teki2.setTextureRect(sf::IntRect(96,0,32,32));
		boule_1.setTexture(texture);
		boule_1.setTextureRect(sf::IntRect(320, 0, 32, 32));
		boule_2.setTexture(texture);
		boule_2.setTextureRect(sf::IntRect(352, 0, 32, 32));
		transeSprite.setTexture(texture);
		transeSprite.setTextureRect(sf::IntRect(384, 0, 32, 32));
		
	}
	


}
Enemie::Enemie(int x, int y, Map &map, bool boss): PersonnageBase() , m_attacked(false), animDegatsON(false), m_boss(true), m_vitesseBoule(10.0f), m_demandeAttaque(false), m_transeUP(false), m_animTranseFini(true)
{
	m_realX = x;
	m_realY = y;
	boss = true;

	if (!textPeppa.loadFromFile("peppa.png"))
	{
		std::cout << "Erreur lors du chargement de la texture de Peppa" << std::endl;

		exit(1);

	}
	else
	{
		peppaSprite.setTexture(textPeppa);
		peppaSprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
		peppaSprite.setPosition((float)m_realX, (float)m_realY);
	}




}

Enemie::~Enemie()
{

}

bool Enemie::get_animDegatsON()
{
	return animDegatsON;
}

void Enemie::set_animDegatsOn(bool tekiAnim)
{
	animDegatsON = tekiAnim;

}
void Enemie::set_attacked(bool attacked)
{
	m_attacked = attacked;

}
bool Enemie::get_attacked()
{
	return m_attacked;

}
void Enemie::set_transeUP(bool transeUP)
{
	m_transeUP = transeUP;

}
bool Enemie::get_animAttaqueFini()
{
	return m_animAttaqueFini;

}

void Enemie::set_animAttaqueFini(bool animAttaqueFini)
{

	m_animAttaqueFini = animAttaqueFini;

}

void Enemie::deplacementAuto(Enemie *enemie,Map &map)
{

	if (enemie->get_demandeAttaque() == true || enemie->get_animAttaqueFini() == false) // SI ATTAQUE EN COURS OU ANIM DE L'ATTAQUE EN COURS ON SORT
	{
		return;

	}

	unsigned int a = rand() % 5;


	switch (a)
	{

		case 0: //UP
		{

			m_direction = 'N';

			if (map.okForMove(enemie, 'Y', -10))
			{
				enemie->m_realY -= 10;
				enemie->teki1.setPosition((float)m_realX, (float)m_realY);
				enemie->m_lastWasShoot = false;


			}
		}
		break;

		case 1: //DOWN
		{
			m_direction = 'S';

			if (map.okForMove(enemie, 'Y', 10))
			{
				enemie->m_realY += 10;
				enemie->teki1.setPosition((float)m_realX, (float)m_realY);
				enemie->m_lastWasShoot = false;

			}
		}
		break;

		case 2: //LEFT
		{
			m_direction = 'O';

			if (map.okForMove(enemie, 'X', -10))
			{
				enemie->m_realX -= 10;
				enemie->teki1.setPosition((float)m_realX - 8, (float)m_realY);
				enemie->m_lastWasShoot = false;


			}
		}
		break;

		case 3: //RIGHT
		{
			m_direction = 'E';

			if (map.okForMove(enemie, 'X', 10))
			{
				enemie->m_realX += 10;
				enemie->teki1.setPosition((float)m_realX + 8, (float)m_realY);
				enemie->m_lastWasShoot = false;


			}
		}
		break;

		case 4: //ATTAQUER
		{
			
				if (enemie->m_lastWasShoot == false)
				{

					enemie->set_demandeAttaque(true);
					enemie->m_lastWasShoot = true;
				}
				else
				{
					std::cout << "LAST SHOOT TRUE -> demandeAttaque passe a FALSE" << std::endl;
					enemie->set_demandeAttaque(false);
					enemie->m_lastWasShoot = false;
				}
				
			


		

		}
		break;



	} // fin switch



}


void Enemie::recevoirDegats(Enemie *perso)
{
		
	perso->m_vie -= 50;

}

bool Enemie::get_demandeAttaque()
{
	return m_demandeAttaque;

}

void Enemie::set_demandeAttaque(bool demandeAttaque)
{

	m_demandeAttaque = demandeAttaque;

}
bool Enemie::get_transeUP()
{
	return m_transeUP;

}
bool Enemie::get_animTranseFini()
{
	return m_animTranseFini;

}
void Enemie::set_animTranseFini(bool animTranseFini)
{

	m_animTranseFini = animTranseFini;

}


void Enemie::affichage(sf::RenderWindow &window,Enemie *teki) const
{

	if (m_boss == false)
	{

		window.draw(teki->teki1);
	}
	else
	{

		window.draw(peppaSprite);
	}

}

void Enemie::animDegats(sf::RenderWindow &window, Enemie *teki)
{

	//animation degats

	
	b = bClock.getElapsedTime();


	if (b.asMilliseconds() <= 500)
	{
		if (bBoucle== 0)
		{
			
			bBoucle++;
		}
		teki2.setPosition((float)m_realX, (float)m_realY);
		window.draw(teki2);

	}
	

	else if (b.asMilliseconds() > 500 && b.asMilliseconds() <= 1000)
	{
		if (bBoucle == 1)
		{
			
			bBoucle++;
		}
		teki1.setPosition((float)m_realX, (float)m_realY);
		window.draw(teki1);
	}
	
	else if (b.asMilliseconds() > 1000) 
	{
		if (bBoucle == 2) 
		{
			//retirer PV
			teki->recevoirDegats(teki);
			bBoucle++;
		}
		//check DEAD
		if (teki->checkDead(teki))
		{
			teki->m_vivant = false;
			teki->set_attacked(false);
		}
		
		
		teki->set_attacked(false);

		bBoucle = 0;
		bClock.restart();
	}

} 

void Enemie::attaque(sf::RenderWindow &window, Enemie *teki, Map &map,Flamme *flamme1)
{
	

	if (teki->get_animTranseFini() == false || teki->get_demandeAttaque() == false) // SI ANIM TRANSE EN COURS OU ATTAQUE FINI: ON SORT
	{

		return;
	}

	if (teki->get_animAttaqueFini() == true && teki->get_demandeAttaque() == true) // INIT ANIM ATTAQUE
	{
		m_realX = teki->m_realX;
		m_realY = teki->m_realY;
		brulerArbreAnimFini = true;

		teki->set_animAttaqueFini(false);
		bClock.restart();

		if (flamme1 == 0 ) // SI FLAMME == 0 , ON LA CREER
		{
                                        flamme1 = new Flamme(teki, m_realX, m_realY);
                        
                                        flamme1->verifDeplacement(sf::RenderWindow &window,Enemie *teki,Map &map,brulerArbreAnimFini);

		}
                
                   } // FIN INIT
        
                  else if (teki->get_animAttaqueFini() == false  && teki->get_demandeAttaque() == true) // ATTAQUE EN COURS = UPDATE ATTAQUE
                  {
        
		 if (flamme1 != 0 && flamme1->get_alive() == true) //ON VERIFIE SI IL FLAMME EST BIEN ALIVE ET ON VERIF DEPLACEMENT
		{
			/* -----------  ANIMATION ---------------   */
                                               
                                     flamme1->verifDeplacement(sf::RenderWindow &window,Enemie *teki,Map &map,brulerArbreAnimFini);
			
		}
		else if (flamme1 != 0 && flamme1->get_alive() == false && flamme1->get_destructionArbre() == true) //SI FLAMME NOT ALIVE ET ORDRE DE DESTRUCTION ARBRE EST TRUE
		{

			//ON BRULE L'ARBRE

			
		}

		if (flamme1 != 0 && flamme1->get_alive() == false && brulerArbreAnimFini == true) //SI FLAMME DEAD ET ANIM ARBRE EN FEU EST FINI: 
		{
			//ON KILL LA FLAMME

			delete flamme1;
			flamme1 = 0;

		}
	
                       } 

	b = bClock.getElapsedTime();
	char test = '1';
	

	//deplacement = b.asMilliseconds() * 0.064;
	double posBoule = 0.0;
	int verifPosY = 0;


	char verifCaseMap = 0;
	


	
	
	
	/* ------------ REFLEXION ------------  */

			// PENSER A KILL LE POINTEUR


	







}


void Enemie::animTranse(sf::RenderWindow &window, Enemie *teki)
{

	b = bClock.getElapsedTime();

	if (teki->get_animAttaqueFini() == false) // SI L'ANIM ATTAQUE N'EST PAS FINI : ON SORT
	{
		return;

	}
	

	if (teki->get_transeUP() == false ) // INIT ANIM TRANSE
	{
		teki->set_transeUP(true);
		teki->set_animTranseFini(false); //False car l'anim commence
	}


	if (b.asMilliseconds() <= 500) // ANIMATION
	{
		
			transeSprite.setPosition((float)m_realX, (float)m_realY);
			window.draw(transeSprite);
		

	}


	else if (b.asMilliseconds() > 500 && b.asMilliseconds() <= 1000)
	{
		
			teki1.setPosition((float)m_realX, (float)m_realY);
			window.draw(teki1);
		
	}

	else if (b.asMilliseconds() > 1000 && b.asMilliseconds() <= 1500)
	{


		transeSprite.setPosition((float)m_realX, (float)m_realY);
		window.draw(transeSprite);


	}
	else if (b.asMilliseconds() > 1500 && b.asMilliseconds() <= 3500)
	{
	

		teki1.setPosition((float)m_realX, (float)m_realY);
		window.draw(teki1);

	
	}
	else if (b.asMilliseconds() > 3500)
	{
		teki->set_animTranseFini(true);
		teki->set_transeUP(false);
		bClock.restart();

	}


}








