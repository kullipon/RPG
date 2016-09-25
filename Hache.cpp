#include "Hache.h"
#include "Guerrier.h"
#include "Map.h"
#include <cmath>

int test = 0;

Hache::Hache()
{
m_posX=0;
m_posY=0;
m_direction='N';
m_vitesse=50;
alive = true;
m_angle = 0;
m_lastPosX = 0;
m_lastPosY = 0;
}


Hache::~Hache()
{
}

Hache::Hache(Guerrier *guerrier,sf::RenderWindow &window,sf::Clock &hacheClock) : m_vitesse(50) , alive(true), boucleH(0) , m_posX (0),m_posY(0),m_direction('N'),m_angle(0)
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
			m_lastPosY = m_posY;
			
			}
			break;		

		case 'S':
			{
			m_posX = (int)guerrier->get_m_realX();
			m_posY = (int)(guerrier->get_m_realY()+32);
			m_direction = 'S';
			m_lastPosY = m_posY;
			}

			break;

		case 'O':
			{
			spHache1.setTextureRect(sf::IntRect(288, 0, -31, 32)); // MAJ FLIP X (decalage +32 et longueur -31)
			m_posX = (int)(guerrier->get_m_realX()-32);
			m_posY = (int)guerrier->get_m_realY();
			m_direction = 'O';
			m_lastPosX = m_posX;
			}
			break;

		case 'E':
			{
			m_posX = (int)(guerrier->get_m_realX()+32);
			m_posY =(int) guerrier->get_m_realY();
			m_direction = 'E';
			m_lastPosX = m_posX;
			}
			break;
	}
}

bool Hache::contact(Enemie *teki)
{
	int tekiX = teki->get_m_realX();
	int tekiY = teki->get_m_realY();

	sf::IntRect maskTeki(tekiX,tekiY, 32, 32);
	sf::IntRect maskHache(m_posX, m_posY, 32, 32);//+16 = axe de rotation au centre soit 16px

	if (maskHache.intersects(maskTeki))
	{
		return true;
	}
	else
	{
		return false;
	}
}
// ***************   ICI ANIM SANS ENEMIES *******************
void Hache::deplacement(Guerrier *toto, sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{
	hacheTime = hacheClock.getElapsedTime();
	std::cout << hacheTime.asSeconds() << std::endl;

	if (m_posY < 0 || m_posX < 0 || m_posX > 320 || m_posY > 320)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	if (boucleH == 0)
	{
		boucleH = 1;
		hacheClock.restart();
		hacheTime = hacheClock.getElapsedTime();
	}


	if (hacheTime.asSeconds() > 5.0f)
	{
		boucleH = 0;
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	switch (m_direction)
	{
	case 'N':
	{
		m_posY -= (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posY + m_lastPosY >= 32)
		{
			m_lastPosY = m_posY;
		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX + 16.0f, (float)m_posY);

		window.draw(spHache1);

		/*

		---VIEUX CODE ANIM---

		if (hacheTime.asMilliseconds() >= 0 && hacheTime.asMilliseconds() <= 1000)
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

		spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlevé
		window.draw(spHache1);

		}
		else if (hacheTime.asMilliseconds() >= 1000 && hacheTime.asMilliseconds() <= 2000)
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
		else if (hacheTime.asMilliseconds() >= 2000 && hacheTime.asMilliseconds() <= 3000)
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
		else if (hacheTime.asMilliseconds() >= 3000 && hacheTime.asMilliseconds() <= 4000)
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
		else if (hacheTime.asMilliseconds() >= 4000 && hacheTime.asMilliseconds() <= 5000)
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

		else if (hacheTime.asMilliseconds() >= 5000)
		{
		attaquer = false;
		toto->supprimerHache();

		}

		*/

	} // FIN CASE 'N'

	break;

	case 'E':
	{
		m_posX += (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosX + m_posX >= 32)
		{
			m_lastPosX = m_posX;			
		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX, (float)m_posY + 16.0f);

		window.draw(spHache1);


	} // FIN CASE 'E'

	break;

	case 'O':
	{
		m_posX -= (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posX + m_lastPosX >= 32)
		{
			m_lastPosX = m_posX;
		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX, (float)m_posY + 16.0f);

		window.draw(spHache1);
	}
	break;

	case 'S':
	{
		m_posY += (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosY + m_posY >= 32)
		{
			m_lastPosY = m_posY;
		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX + 16.0f, (float)m_posY);

		window.draw(spHache1);


	} // FIN CASE 'S'
	break;

	} // FIN SWITCH
	
}

// ****************    ANIM AVEC 2 ENEMIES *******************
void Hache::deplacement(Guerrier *toto,Enemie *teki1,Enemie *teki2,sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{
	hacheTime = hacheClock.getElapsedTime();
	//std::cout << hacheTime.asSeconds() << std::endl;

	if (m_posY < 0 || m_posX < 0 || m_posX > 320 || m_posY > 320)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	if (boucleH == 0)
	{
		boucleH = 1;
		hacheClock.restart();
		hacheTime = hacheClock.getElapsedTime();
	}
	
	
	if (hacheTime.asSeconds() > 5.0f)
	{
		boucleH = 0;
		attaquer = false;
		toto->supprimerHache();		
		return;
	}		

	switch (m_direction)
	{
	case 'N':
	{
		m_posY -= (int)(hacheTime.asSeconds()+1) * 3; //past -> *5

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posY + m_lastPosY >= 32 )
		{
			m_lastPosY = m_posY;

			if (contact(teki1))
			{			
				//ANIM DEGATS
				teki1->set_animDegatsOn(true);
				return;
			}
			else if (contact(teki2))
			{				
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX+16.0f, (float)m_posY);
		
		window.draw(spHache1);

		/*
		if (hacheTime.asMilliseconds() >= 0 && hacheTime.asMilliseconds() <= 1000)
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

			spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlevé
			window.draw(spHache1);

		}
		else if (hacheTime.asMilliseconds() >= 1000 && hacheTime.asMilliseconds() <= 2000)
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
		else if (hacheTime.asMilliseconds() >= 2000 && hacheTime.asMilliseconds() <= 3000)
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
		else if (hacheTime.asMilliseconds() >= 3000 && hacheTime.asMilliseconds() <= 4000)
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
		else if (hacheTime.asMilliseconds() >= 4000 && hacheTime.asMilliseconds() <= 5000)
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

		else if (hacheTime.asMilliseconds() >= 5000)
		{
			attaquer = false;
			toto->supprimerHache();

		}

		*/
	
	} // FIN CASE 'N'

		break;

	case 'E':
	{
		m_posX += (int)(hacheTime.asSeconds() + 1) * 5;
	
		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosX + m_posX >= 32)
		{
			m_lastPosX = m_posX;

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

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX , (float)m_posY + 16.0f);

		window.draw(spHache1);


	} // FIN CASE 'E'

	break;

	case 'O':
	{
		m_posX -= (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posX + m_lastPosX >= 32)
		{
			m_lastPosX = m_posX;

			if (contact(teki1))
			{
				hacheUp = false;
				teki1->set_animDegatsOn(true);
				return;
			}
			else if (contact(teki2))
			{
				hacheUp = false;
				//ANIM DEGATS
				teki2->set_animDegatsOn(true);
				return;
			}

		}
		m_angle = hacheTime.asSeconds() * -180.0f;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		//spHache1.scale(-1.0f, 1.0f);		
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX , (float)m_posY + 16.0f);

		window.draw(spHache1);
	}
	break;

	case 'S':
	{
		m_posY += (int)(hacheTime.asSeconds() + 1) * 5;
	
		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosY + m_posY >= 32)
		{
			m_lastPosY = m_posY;

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

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX + 16.0f, (float)m_posY);

		window.draw(spHache1);
	

	} // FIN CASE 'S'
	 break;

	} // FIN SWITCH
}

// ****************    ANIM AVEC 1 ENEMIE *******************
void Hache::deplacement(Guerrier *toto, Enemie *teki, sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer, bool &hacheUp)
{
	hacheTime = hacheClock.getElapsedTime();
	std::cout << hacheTime.asSeconds() << std::endl;

	if (m_posY < 0 || m_posX < 0 || m_posX > 320 || m_posY > 320)
	{
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	if (boucleH == 0)
	{
		boucleH = 1;
		hacheClock.restart();
		hacheTime = hacheClock.getElapsedTime();
	}


	if (hacheTime.asSeconds() > 5.0f)
	{
		boucleH = 0;
		attaquer = false;
		toto->supprimerHache();
		return;
	}

	switch (m_direction)
	{
	case 'N':
	{
		m_posY -= (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posY + m_lastPosY >= 32)
		{
			m_lastPosY = m_posY;

			if (contact(teki))
			{
				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);
				return;
			}

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX + 16.0f, (float)m_posY);

		window.draw(spHache1);

		/*
		if (hacheTime.asMilliseconds() >= 0 && hacheTime.asMilliseconds() <= 1000)
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

		spHache1.setPosition((float)m_posX, (float)m_posY); //*32 enlevé
		window.draw(spHache1);

		}
		else if (hacheTime.asMilliseconds() >= 1000 && hacheTime.asMilliseconds() <= 2000)
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
		else if (hacheTime.asMilliseconds() >= 2000 && hacheTime.asMilliseconds() <= 3000)
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
		else if (hacheTime.asMilliseconds() >= 3000 && hacheTime.asMilliseconds() <= 4000)
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
		else if (hacheTime.asMilliseconds() >= 4000 && hacheTime.asMilliseconds() <= 5000)
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

		else if (hacheTime.asMilliseconds() >= 5000)
		{
		attaquer = false;
		toto->supprimerHache();

		}

		*/

	} // FIN CASE 'N'

	break;

	case 'E':
	{
		m_posX += (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosX + m_posX >= 32)
		{
			m_lastPosX = m_posX;

			if (contact(teki))
			{
				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);
				return;
			}

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX, (float)m_posY + 16.0f);

		window.draw(spHache1);


	} // FIN CASE 'E'

	break;

	case 'O':
	{
		m_posX -= (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_posX + m_lastPosX >= 32)
		{
			m_lastPosX = m_posX;

			if (contact(teki))
			{
				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);
				return;
			}
			

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition((float)m_posX, (float)m_posY + 16.0f);

		window.draw(spHache1);
	}
	break;

	case 'S':
	{
		m_posY += (int)(hacheTime.asSeconds() + 1) * 5;

		//on verifie a chaque espace de 32 si un enemie est présent
		if (m_lastPosY + m_posY >= 32)
		{
			m_lastPosY = m_posY;

			if (contact(teki))
			{
				teki->set_attacked(true);
				hacheUp = false;
				teki->set_animDegatsOn(true);
				return;
			}
			

		}
		m_angle = hacheTime.asSeconds() * 180;

		int angle = 0;
		if (m_angle > 360.0f)
		{
			angle = (int)std::round(m_angle);
			angle %= 360;
			m_angle = (float)angle;
		}
		spHache1.setOrigin(16.0f, 16.0f);
		spHache1.setRotation(m_angle);
		spHache1.setPosition(m_posX + 16.0f, (float)m_posY);

		window.draw(spHache1);


	} // FIN CASE 'S'
	break;

	} // FIN SWITCH
}

