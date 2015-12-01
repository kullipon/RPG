#include "Hache.h"
#include "Guerrier.h"
#include "Map.h"


Hache::Hache()
{
m_posX=0;
m_posY=0;
m_direction='N';
m_vitesse=50;
alive = true;
}


Hache::~Hache()
{
}

Hache::Hache(Guerrier *guerrier,sf::RenderWindow &window,sf::Clock &clock) : m_vitesse(50) , alive(true), boucleH(0) , m_posX (0),m_posY(0),m_direction('N')
{

	

	if (!textHache.loadFromFile("texture_3.png"))
	{
		std::cout << "Erreur de chargement de la texture de la hache." << std::endl;


	}
	else
	{
		
		//Sprites de la Hache
		spHache1.setTexture(textHache);
		spHache1.setTextureRect(sf::IntRect(256,0,31,32));
		spHache2.setTexture(textHache);
		spHache2.setTextureRect(sf::IntRect(288,0,32,32));
		spHache3.setTexture(textHache);
		spHache3.setTextureRect(sf::IntRect(320,0,32,32));
		spHache4.setTexture(textHache);
		spHache4.setTextureRect(sf::IntRect(352,0,32,32));
	}

	char a = guerrier->getDirection();
	switch(a)
		{

		case 'N':
			{
			m_posX = guerrier->get_m_realX();
			//m_posX = (int)(m_posX/32);
			m_posY = guerrier->get_m_realY();
			//m_posY = (int)(m_posY/32);
			m_posY -= 32;
			m_direction = 'N';
			
			}
			break;
			

		case 'S':
			{
			m_posX = (int)guerrier->get_m_realX();
			m_posY = (int)(guerrier->get_m_realY()+32);
			m_direction = 'S';
			}

			break;

		case 'O':
			{
			m_posX = (int)(guerrier->get_m_realX()-32);
			m_posY = (int)guerrier->get_m_realY();
			m_direction = 'O';
			}
			break;

		case 'E':
			{
			m_posX = (int)(guerrier->get_m_realX()+32);
			m_posY =(int) guerrier->get_m_realY();
			m_direction = 'E';
			}
			break;

	}	

	//spHache1.setPosition((float)m_posX,(float)m_posY);
	//window.draw(spHache1);

	


}

bool Hache::contact(Enemie *teki)
{
	int tekiX = teki->get_m_realX();
	int tekiY = teki->get_m_realY();

	sf::IntRect maskTeki(tekiX,tekiY, 32, 32);
	sf::IntRect maskHache(m_posX, m_posY, 32, 32);

	if (maskHache.intersects(maskTeki))
	{

		return true;
	}
	else
	{
		return false;
	}
}
 // ICI ANIM SANS ENEMIES
void Hache::deplacement(sf::Clock &clock, Guerrier *toto, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{
	

	sf::Time a = clock.getElapsedTime();


	if (m_posY < 0 || m_posX < 0)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	switch (m_direction)
	{


	case 'N':
	{


		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}
			

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;

			}
			m_posY -= 32;


			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posY -= 64;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY -= 96;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posY -= 128;
			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'N'

	break;

	case 'E':
	{

		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;

			}

			m_posX += 32;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posX += 64;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX += 96;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX += 128;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'E'

	break;

	case 'O':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}

			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posX -= 32;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			

			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posX -= 64;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
		
			spHache3.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX -= 96;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
		
			spHache4.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX -= 128;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'W'
	break;

	case 'S':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}

			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posY += 32;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posY += 64;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache3.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY += 96;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache4.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}

			m_posY += 128;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'S'
	break;

	} // FIN SWITCH

}

// ****************    ANIM AVEC 2 ENEMIES *******************


void Hache::deplacement(sf::Clock &clock, Guerrier *toto,Enemie *teki1,Enemie *teki2, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{
	
	sf::Time a = clock.getElapsedTime();


	if (m_posY < 0 || m_posX < 0)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	switch (m_direction)
	{


	case 'N':
	{


		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}
				if (contact(teki1))
				{
					
					teki1->set_attacked(true);
					hacheUp = false;
					teki1->set_animDegatsOn(true);

					
					return;

				}
				else if (contact(teki2))
				{
					
					teki2->set_attacked(true);
					hacheUp = false;
					//ANIM DEGATS
					teki2->set_animDegatsOn(true);
					return;

				


			}

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
				
			}
			m_posY -= 32;
			

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				toto->supprimerHache();
				//ANIM DEGATS
				teki1->animDegats(window, teki1);
				return;

			}
			if (contact(teki2))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki2->animDegats(window, teki2);
				return;

			}
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posY -= 64;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki1->animDegats(window, teki1);
				return;

			}
			if (contact(teki2))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki2->animDegats(window, teki2);
				return;

			}
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY -= 96;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki1->animDegats(window, teki1);
				return;

			}
			else if (contact(teki2))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki2->animDegats(window, teki2);
				return;

			}
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posY -= 128;
			if (m_posY < 0 )
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki1->animDegats(window, teki1);
				return;

			}
			else if (contact(teki2))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki2->animDegats(window, teki2);
				return;

			}
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'N'

		break;

	case 'E':
	{

		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}
				if (contact(teki1))
				{

					teki1->set_attacked(true);
					hacheUp = false;
					teki1->set_animDegatsOn(true);


					return;

				}
				else if (contact(teki2))
				{

					teki2->set_attacked(true);
					hacheUp = false;
					//ANIM DEGATS
					teki2->set_animDegatsOn(true);
					return;

				


			}

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;

			}

			m_posX += 32;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;

			}
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posX += 64;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;

			}
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX += 96;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;

			}
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX += 128;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;

			}
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'E'

	break;

	case 'O':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}

			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posX -= 32;

			if ( m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}

			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posX -= 64;

			if ( m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache3.setPosition((float)m_posX , (float)m_posY );
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX -= 96;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache4.setPosition((float)m_posX , (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX -= 128;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'W'
	break;

	case 'S':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}

			spHache1.setPosition((float)m_posX , (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posY += 32;

			if (m_posY > 320 )
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posY += 64;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache3.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY += 96;

			if (m_posY > 320 )
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache4.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}

			m_posY += 128;

			if (m_posY > 320 )
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki1))
			{

				teki1->set_attacked(true);
				hacheUp = false;
				teki1->set_animDegatsOn(true);


				return;

			}
			else if (contact(teki2))
			{

				teki2->set_attacked(true);
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}
			spHache1.setPosition((float)m_posX , (float)m_posY );
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'S'
	 break;

	} // FIN SWITCH




}

/*
					*      ************************				*
					*	**										*
					*											*
				    * ICI ON PASSE A L'ANIM avec 1 ENEMIE !!!
					*
					*
					*
					*		*********************
								
*/		


void Hache::deplacement(sf::Clock &clock, Guerrier *toto, Enemie *teki, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{

	sf::Time a = clock.getElapsedTime();


	if (m_posY < 0 || m_posX < 0)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	switch (m_direction)
	{


	case 'N':
	{


		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;

				if (contact(teki))
				{

					teki->set_attacked(true);
					hacheUp = false;
					teki->set_animDegatsOn(true);


					return;

				}
				


			}

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;

			}

			m_posY -= 32;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki->animDegats(window, teki);
				return;

			}
			
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posY -= 64;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki->animDegats(window, teki);
				return;

			}
		
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY -= 96;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki->animDegats(window, teki);
				return;

			}
			
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posY -= 128;

			if (m_posY < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				toto->supprimerHache();

				//ANIM DEGATS
				teki->animDegats(window, teki);
				return;

			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'N'

	break;

	case 'E':
	{

		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;

				if (contact(teki))
				{

					teki->set_attacked(true);
					hacheUp = false;
					teki->set_animDegatsOn(true);


					return;

				}
				
			}

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlev�
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;

			}

			m_posX += 32;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			
			spHache2.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;

			}
			m_posX += 64;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			
			spHache3.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX += 96;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			
			spHache4.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX += 128;

			if (m_posX > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			
			spHache1.setPosition((float)m_posX, (float)m_posY);//*32 enlev�
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'E'

	break;

	case 'O':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			

			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posX -= 32;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posX -= 64;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache3.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posX -= 96;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache4.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}
			m_posX -= 128;

			if (m_posX < 0)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'W'
	break;

	case 'S':
	{
		if (a.asMilliseconds() >= 0 && a.asMilliseconds() <= 500)
		{
			if (boucleH == 0)
			{
				boucleH++;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);

		}
		else if (a.asMilliseconds() >= 500 && a.asMilliseconds() <= 1000)
		{

			if (boucleH == 1)
			{
				boucleH++;
			}

			m_posY += 32;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache2.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache2);

		}
		else if (a.asMilliseconds() >= 1000 && a.asMilliseconds() <= 1500)
		{

			if (boucleH == 2)
			{
				boucleH++;
			}
			m_posY += 64;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache3.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache3);

		}
		else if (a.asMilliseconds() >= 1500 && a.asMilliseconds() <= 2000)
		{

			if (boucleH == 3)
			{
				boucleH++;
			}
			m_posY += 96;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache4.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache4);

		}
		else if (a.asMilliseconds() >= 2000 && a.asMilliseconds() <= 2500)
		{
			if (boucleH == 4)
			{
				boucleH++;
			}

			m_posY += 128;

			if (m_posY > 320)
			{
				attaquer = false;
				toto->supprimerHache();
				return;
			}
			if (contact(teki))
			{

				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);


				return;

			}
			spHache1.setPosition((float)m_posX, (float)m_posY);
			window.draw(spHache1);
		}

		else if (a.asMilliseconds() >= 2500)
		{
			attaquer = false;
			toto->supprimerHache();

		}

	} // FIN CASE 'S'
	break;

	} // FIN SWITCH


}
