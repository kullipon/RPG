#include <SFML/Graphics.hpp>
#include "Guerrier.h"
#include "Mage.h"
#include "Enemie.h"
#include "Map.h"
#include "PersonnageBase.h"
#include "Joueur.h"

#include "Flamme.h"

#include <iostream>
#include <time.h>
#include <cstdlib>


//#include <thread>
//#include <mutex>
#include "ObAttaquer.h"


bool deplacementOK(false);

sf::Clock hacheClock;

int main()
{
	srand(time(0));
	bool attaquer(false);
	sf::RenderWindow window(sf::VideoMode(352, 352), "Zelda Like", sf::Style::Resize);
	window.setFramerateLimit(60);

	Guerrier *toto = 0;
	toto = new Guerrier();

	Map map(toto);

	Enemie *teki1 = 0;
	teki1 = new Enemie(64, 128, map);

	Enemie *teki2 = 0;
	teki2 = new Enemie(256, 96, map);

	Enemie *peppa = 0;
	bool peppaPopped = false;
	bool hacheUp = toto->getHacheUp();

	//ObAttaquer ObAttaque;

	if (sf::Joystick::isConnected(0))
	{
		std::cout << "JOYSTICK 1 IS CONNECTED" << std::endl;
	}
	else
	{
		std::cout << "JOYSTICK 1 IS NOT CONNECTED" << std::endl;

	}

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
while (window.isOpen())
{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			// événement "fermeture demandée" : on ferme la fen�tre
			switch (event.type)
			{

			case sf::Event::Closed:
			{
				window.close();

			}
			break;

			//évenement "clavier préssé"
			case sf::Event::KeyPressed:
			{


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					deplacementOK = true;
					toto->set_xmoins1(map, deplacementOK);
					toto->set_direction('O');

				}


				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					deplacementOK = true;
					toto->set_xplus1(map, deplacementOK);
					toto->set_direction('E');

				}

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				{
					deplacementOK = true;
					toto->set_ymoins1(map, deplacementOK);
					toto->set_direction('N');

				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				{
					deplacementOK = true;
					toto->set_yplus1(map, deplacementOK);
					toto->set_direction('S');
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					attaquer = true;
				}
				
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}

				break;
			}
			case sf::Event::KeyReleased:
				{
					deplacementOK = false;

				}
				break;

			default:
				break;
			}//fin switch
			

 /*-----------------------  GESTION DU JOYSTICK ----------------------------------- */


			if (sf::Joystick::isButtonPressed(0, 0))
			{
				attaquer = true;				
			}

			float axeX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			float axeY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

			if (axeX == -100)
			{
				deplacementOK = true;
				toto->set_xmoins1(map, deplacementOK);
				toto->set_direction('O');

			}
			else if (axeX == 100)
			{
				deplacementOK = true;
				toto->set_xplus1(map, deplacementOK);
				toto->set_direction('E');

			}
			else if (axeY == -100)
			{
				deplacementOK = true;
				toto->set_ymoins1(map, deplacementOK);
				toto->set_direction('N');


			}
			else if (axeY == 100)
			{
				deplacementOK = true;
				toto->set_yplus1(map, deplacementOK);
				toto->set_direction('S');
			}

			else if (axeX == 0 && axeY == 0)
			{
				deplacementOK = false;
			}

		}//fin Event


/* --------------------------  DESSIN  ------------------------------------------ */

/*------------------------- ATTAQUE --------------------- */
		while (attaquer) 
		{

			window.clear();

			map.affichage(window);

			toto->affichage(window, toto);

			// AFFICHAGE EN FONCTION DES ENEMIES EN VIE:

			if (teki1 == 0 && teki2 != 0) // ENEMIE 1 MORT et ENEMIE2 Encore en vie
			{
				map.temps(teki2, window);
				teki2->affichage(window, teki2);
			}
			else if (teki2 == 0 && teki1 != 0) // ENEMIE 2 MORT et Enemie 1 encore en vie
			{
				map.temps(teki1, window);
				teki1->affichage(window, teki1);
			}
			else if (teki1 != 0 && teki2 != 0) // LES 2 en vie
			{
				map.temps(teki1, teki2, window);
				teki1->affichage(window, teki1);
				teki2->affichage(window, teki2);
			}

			/*--------------*************-----------------*/	
			/*--------------*           *-----------------*/
			/*--------------*  ATTAQUE  *-----------------*/
			/*--------------*           *-----------------*/
			/*--------------*************-----------------*/

			if (teki1 == 0 && teki2 != 0) // TEKI 1 DEAD et TEKI 2 ALIVE
			{
				toto->attaquer(teki2, hacheClock,map, window, attaquer);
			}
			else if (teki2 == 0 && teki1 != 0) // TEKI 2 DEAD et TEKI 1 ALIVE
			{
				toto->attaquer(teki1, hacheClock, map, window, attaquer);

			}
			else if (teki1 != 0 && teki2 != 0) // LES DEUX ALIVE
			{
				toto->attaquer(teki1, teki2,hacheClock, map, window, attaquer);
			}
			else // ALL DEAD
			{
				toto->attaquer(hacheClock, map, window, attaquer);
			}

			if (teki1 != 0)
			{
				//CHECK ANIM HACHE
				if (teki1->get_animDegatsON() == true)
				{
					teki1->set_attacked(true);
					//ANIM DEGATS
					toto->supprimerHache();
					teki1->animDegats(window, teki1);
					//check DEAD
					if (teki1->get_vivant() == false)
					{
						attaquer = false;
						delete teki1;
						teki1 = 0;
					}
				}
			}
			if (teki2 != 0)
			{
				if (teki2->get_animDegatsON() == true)
				{
					teki2->set_attacked(true);
					//ANIM DEGATS
					toto->supprimerHache();
					teki2->animDegats(window, teki2);

					//check DEAD
					if (teki2->get_vivant() == false)
					{
						attaquer = false;
						delete teki2;
						teki2 = 0;
					}
				}
			}

			if (peppa != 0)
			{
				peppa->affichage(window, peppa);
			}

			//AFFICHAGE DURANT L'ATTAQUE
			window.display();

			
		} 
/*------------------------- FIN ATTAQUE --------------------- */


/*------------------------- AFFICHAGE --------------------- */


		window.clear();

		map.affichage(window);

		toto->affichage(window, toto);

		if (teki1 != 0 && teki2 == 0) //TEKI 1 ALIVE et TEKI 2 DEAD 
		{
			map.temps(teki1,window);
			teki1->affichage(window, teki1);
		}
		else if (teki2 != 0 && teki1 == 0)  //TEKI 1 DEAD et TEKI 2 ALIVE 
		{			
			map.temps(teki2, window);
			teki2->affichage(window, teki2);
		}
		else if (teki1 != 0 && teki2 != 0) // LES 2 EN VIE
		{			
			map.temps(teki1, teki2, window); // Fonction qui  SET demandeAttaque = TRUE 
			teki1->affichage(window, teki1);
			teki2->affichage(window, teki2);

			if (teki1->get_demandeAttaque() == true)
			{
				if (teki2->get_brulerArbreAnimFini() == true && teki2->get_animTranseFini() == true && teki2->get_animAttaqueFini() == true)
				{
					teki1->animTranse(window, teki1);
					teki1->attaque(window, teki1, map);

					if (teki1->get_animAttaqueFini())
					{
						teki2->set_autorisationShoot(true);
					}
				}
			}

			if (teki2->get_demandeAttaque() == true)
			{
				if (teki1->get_brulerArbreAnimFini() == true && teki1->get_animTranseFini() == true && teki1->get_animAttaqueFini() == true)
				{
					teki2->animTranse(window, teki2);
					teki2->attaque(window, teki2, map);

					if (teki2->get_animAttaqueFini())
					{
						teki1->set_autorisationShoot(true);
					}
				}
			}
		}
		else if (teki1 == 0 && teki2 == 0) // SI LES DEUX SONT MORTS
		{
			if (peppa == 0 && peppaPopped == false)
			{
				//POP PEPPA (boss de fin)
				peppa = new Enemie(96, 96, map, true);
				peppaPopped = true;
			}

			peppa->affichage(window, peppa);
		}
		window.display();
}

/* ----------------------- FIN DE BOUCLE DE JEU ----------------------------- */


	if (teki1 != 0)
	{
		if (teki1->get_flamme() != 0)
		{
			teki1->killFlamme();
		}
		delete teki1;
		teki1 = 0;

	}
	if (teki2 != 0)
	{
		if (teki2->get_flamme() != 0)
		{
			teki2->killFlamme();
		}
		delete teki2;
		teki2 = 0;
	}
	if (peppa != 0)
	{

		if (peppa->get_flamme() != 0)
		{
			peppa->killFlamme();
		}
		delete peppa;
		peppa = 0;

	}

	map.deleteMap();

	delete toto;
	toto = 0;



	return 0;

}
