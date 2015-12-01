#include "Enemie.h"
#include "Map.h"

#include "Flamme.h"
#include <stdexcept>


int bBoucle = 0;
sf::Time b;
sf::Clock bClock;




Enemie::Enemie(): PersonnageBase(), m_attacked(false), m_animDegatsON(false), m_boss(false), m_vitesseBoule(10.0f), m_demandeAttaque(false),m_transeUP(false),m_animTranseFini(true),m_animAttaqueFini(true),m_lastWasShoot(false), m_brulerArbreAnimFini(true),m_autorisationShoot(true)
{
    
    m_flamme = 0;
	
if (!texture.loadFromFile("texture_7.png"))
	{
		std::cout << "Erreur lors du chargement de la texture des teki1s" << std::endl;

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

Enemie::Enemie(int x, int y, Map &map) : PersonnageBase(), m_attacked(false), m_animDegatsON(false), m_boss(false), m_vitesseBoule(10.0f), m_demandeAttaque(false), m_transeUP(false), m_animTranseFini(true), m_animAttaqueFini(true), m_lastWasShoot(false),m_brulerArbreAnimFini(true),m_autorisationShoot(true)
{
	
	m_realX = x;
	m_realY = y;
                  m_flamme = 0;
        


	if (!texture.loadFromFile("texture_7.png"))
     	{
		std::cout << "Erreur lors du chargement de la texture des teki1s" << std::endl;
			 
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
Enemie::Enemie(int x, int y, Map &map, bool boss): PersonnageBase() , m_attacked(false), m_animDegatsON(false), m_boss(true), m_vitesseBoule(10.0f), m_demandeAttaque(false), m_transeUP(false), m_animTranseFini(true),m_brulerArbreAnimFini(true),m_autorisationShoot(true)
{
	m_realX = x;
	m_realY = y;
                  m_flamme = 0;
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
	return m_animDegatsON;
}

void Enemie::set_animDegatsOn(bool tekiAnim)
{
	m_animDegatsON = tekiAnim;

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

void Enemie::set_brulerArbreAnimFini(bool brulerArbreAnimFini)
{
    
    m_brulerArbreAnimFini = brulerArbreAnimFini;
    
}

bool Enemie::get_animTranseFini()
{
     return m_animTranseFini;
     
}

void Enemie::set_autorisationShoot(bool autorisationShoot)
{
     m_autorisationShoot = autorisationShoot;
     
}

bool Enemie::get_brulerArbreAnimFini()
{
    return m_brulerArbreAnimFini;
    
}

Flamme* Enemie::get_flamme()
{
    
    return m_flamme;
    
}

void Enemie::killFlamme()
{
    delete m_flamme;
    m_flamme = 0;
    
    
}

void Enemie::deplacementAuto(Enemie *teki1,Enemie *teki2,Map &map)
{

	if (teki1->m_animAttaqueFini == false || teki1->m_animTranseFini == false || teki1->m_brulerArbreAnimFini == false) // SI ANIM DE L'ATTAQUE EN COURS ON SORT
	{
		return;
		
	}
	
	unsigned int a = 0;
	
	if (teki1->m_autorisationShoot == true)
	{
	    a =  rand() % 5;
	}
	else
	{
	     a= rand() % 4;
	}
	


	switch (a)
	{

		case 0: //UP
		{

			m_direction = 'N';

			if (map.okForMove(teki1, 'Y', -10))
			{
				teki1->m_realY -= 10;
				teki1->teki1.setPosition((float)m_realX, (float)m_realY);
				teki1->m_lastWasShoot = false;


			}
		}
		break;

		case 1: //DOWN
		{
			m_direction = 'S';

			if (map.okForMove(teki1, 'Y', 10))
			{
				teki1->m_realY += 10;
				teki1->teki1.setPosition((float)m_realX, (float)m_realY);
				teki1->m_lastWasShoot = false;

			}
		}
		break;

		case 2: //LEFT
		{
			m_direction = 'O';

			if (map.okForMove(teki1, 'X', -10))
			{
				teki1->m_realX -= 10;
				teki1->teki1.setPosition((float)m_realX - 8, (float)m_realY);
				teki1->m_lastWasShoot = false;


			}
		}
		break;

		case 3: //RIGHT
		{
			m_direction = 'E';

			if (map.okForMove(teki1, 'X', 10))
			{
				teki1->m_realX += 10;
				teki1->teki1.setPosition((float)m_realX + 8, (float)m_realY);
				teki1->m_lastWasShoot = false;


			}
		}
		break;

		case 4: //ATTAQUER
		{
		
		    teki1->m_demandeAttaque = true;
		    teki1->m_lastWasShoot = true;
		    teki2->m_autorisationShoot = false;
	
		}
		break;



	} // fin switch

}

void Enemie::deplacementAuto(Enemie *teki,Map &map)
{

	if (teki->m_animAttaqueFini == false || teki->m_animTranseFini == false) // SI ANIM DE L'ATTAQUE EN COURS ON SORT
	{
		return;
		
	}

	unsigned int a = rand() % 5;


	switch (a)
	{

		case 0: //UP
		{

			m_direction = 'N';

			if (map.okForMove(teki, 'Y', -10))
			{
				teki->m_realY -= 10;
				teki->teki1.setPosition((float)m_realX, (float)m_realY);
				teki->m_lastWasShoot = false;


			}
		}
		break;

		case 1: //DOWN
		{
			m_direction = 'S';

			if (map.okForMove(teki, 'Y', 10))
			{
				teki->m_realY += 10;
				teki->teki1.setPosition((float)m_realX, (float)m_realY);
				teki->m_lastWasShoot = false;

			}
		}
		break;

		case 2: //LEFT
		{
			m_direction = 'O';

			if (map.okForMove(teki, 'X', -10))
			{
				teki->m_realX -= 10;
				teki->teki1.setPosition((float)m_realX - 8, (float)m_realY);
				teki->m_lastWasShoot = false;


			}
		}
		break;

		case 3: //RIGHT
		{
			m_direction = 'E';

			if (map.okForMove(teki, 'X', 10))
			{
				teki->m_realX += 10;
				teki->teki1.setPosition((float)m_realX + 8, (float)m_realY);
				teki->m_lastWasShoot = false;


			}
		}
		break;

		case 4: //ATTAQUER
		{
			
				if (teki->m_lastWasShoot == false)
				{

					teki->m_demandeAttaque = true;
					teki->m_lastWasShoot = true;
					teki->m_demandeAttaque = false;
				}
				else
				{
					std::cout << "LAST SHOOT TRUE -> demandeAttaque passe a FALSE" << std::endl;
					teki->m_demandeAttaque = false;
					teki->m_lastWasShoot = false;
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
			teki->m_attacked = false;
		}
		
		
		teki->m_attacked = false;

		bBoucle = 0;
		bClock.restart();
	}

} 

void Enemie::attaque(sf::RenderWindow &window, Enemie *teki, Map &map)
{
	
                   
                   

	if (teki->m_animTranseFini == false) // SI ANIM TRANSE EN COURS: ON SORT
	{

		return;
	}

	if (teki->m_animAttaqueFini == true && teki->m_demandeAttaque == true) // INIT ANIM ATTAQUE
	{
		m_realX = teki->m_realX;
		m_realY = teki->m_realY;
		teki->m_brulerArbreAnimFini = true;

		teki->m_animAttaqueFini = false;       // FALSE CAR ON COMMENCE L'ATTAQUE
		bClock.restart();

		if (teki->m_flamme == 0 ) // SI FLAMME == 0 , ON LA CREER
		{
                                       
                                         teki->m_flamme = new Flamme(teki, m_realX, m_realY);
                                     
                                           
                                        std::cout << "La flamme EST UP" << std::endl;
                        
                                       teki->m_flamme->verifDeplacement(teki,map);

		}
                                    else
                                    {
                                     std::cout << "erreur avec le pointeur Flamme1 qui existe deja." << std::endl;
                                    }
                
                   } // FIN INIT
        
                  else if (teki->m_animAttaqueFini == false  && teki->m_demandeAttaque == true) // SINON ATTAQUE EN COURS = UPDATE ATTAQUE
                  {
        
		 if (teki->m_flamme != 0 && teki->m_flamme->get_alive() == true) //ON VERIFIE SI IL FLAMME EST BIEN ALIVE 
		{
                                            /* -----------  ANIMATION ---------------   */
                                               
                                    teki->m_flamme->verifDeplacement(teki,map); 
                                    teki->m_flamme->affichage(window,teki,map);
                 
		}
                
	 }	 
		 
	if (teki->m_flamme != 0 && m_flamme->get_alive() == true && teki->m_flamme->get_destructionArbre() == true) //SINON SI DESTRUCTION ARBRE EST TRUE
	{
            
                        //ON BRULE L'ARBRE => ANIM BRULE ARBRE
                                    
                        teki->m_flamme->brulerArbre(window,teki,map);	 //SET ALIVE = FALSE
                         
			
	}
   
	
                    if (teki->m_flamme != 0 && teki->m_flamme->get_alive() == false  ) //SI FLAMME DEAD ON CHECK
	{
		    
		//ON KILL LA FLAMME
                      
                            delete teki->m_flamme ;
                            teki->m_flamme = 0;
			    
	        std::cout << "La FLAMME EST DOWN" << std::endl;
                      
	}

}


void Enemie::animTranse(sf::RenderWindow &window, Enemie *teki)
{
                
	

	if (teki->m_animAttaqueFini == false || teki->m_brulerArbreAnimFini == false) // SI L'ANIM ATTAQUE N'EST PAS FINI  OU ANIM BRULER ARBRE NON FINI: ON SORT
	{
		return;

	}
	

	if (teki->m_transeUP == false ) // INIT ANIM TRANSE
	{
                                      
		teki->m_transeUP = true;
		teki->m_animTranseFini = false; //False car l'anim commence
                                    teki->tekiClock.restart();
	}
        
                    b = teki->tekiClock.getElapsedTime();


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
		teki->m_animTranseFini = true;
		teki->m_transeUP = false;
		teki->tekiClock.restart();

	}


}





