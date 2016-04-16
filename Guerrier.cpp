#include "Guerrier.h"
#include <cmath>
#include "Hache.h"


Guerrier::Guerrier() : Joueur()
{

	m_vie = 200;
	m_hacheUp = false;

	if (!textWar.loadFromFile("texture_3.png"))
	{
		std::cout << "Erreur de chargement de la texture du guerrier" << std::endl;


	}
	else
	{

		//Sprites du War
		spWarUp.setTexture(textWar);
		spWarUp_2.setTexture(textWar);
		spWarUp.setTextureRect(sf::IntRect(64,0,32,32));
		spWarUp_2.setTextureRect(sf::IntRect(96,0,32,32));

		
		

	}
	
}

Guerrier::Guerrier(Guerrier const& guerrier): Joueur()
{

	 
} //Fin Constructeur
 

Guerrier::~Guerrier()
{
}


/* ---------------  */

bool Guerrier::getHacheUp()
{

	return m_hacheUp;
}

void Guerrier::attaquer(sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer)
{

	if (m_hacheUp == false)
	{
		hache = new Hache(this, window,hacheClock);
		m_hacheUp = true;
		hacheClock.restart();
	}
	
	hache->deplacement(this,hacheClock, map, window, attaquer, m_hacheUp);


}

void Guerrier::attaquer(Enemie *teki1,Enemie *teki2,sf::Clock &hacheClock,Map &map,sf::RenderWindow &window,bool &attaquer)
{
	bool teki1Anim = teki1->get_animDegatsON();
	bool teki2Anim = teki2->get_animDegatsON();

	if (teki1Anim == true || teki2Anim == true)
	{
		return;
	}
	if (m_hacheUp == false && teki1Anim == false && teki2Anim == false)
	{
	hache = new Hache(this,window,hacheClock);
	m_hacheUp = true;
	}
	
	hache->deplacement(this,teki1,teki2,hacheClock, map,window,attaquer,m_hacheUp);

}


void Guerrier::attaquer(Enemie *teki,sf::Clock &hacheClock, Map &map, sf::RenderWindow &window, bool &attaquer)
{

	bool teki1Anim = teki->get_animDegatsON();
	
		if (teki1Anim == true)
		{
			return;
		}

		if (m_hacheUp == false && teki1Anim == false)
		{
			hache = new Hache(this,window,hacheClock);
			m_hacheUp = true;
		}
		

			hache->deplacement(this,teki,hacheClock,map,window,attaquer,m_hacheUp);

}


void Guerrier::affichage(sf::RenderWindow &window,Joueur *joueur)
{

	switch(m_direction)
		{

		case 'N':
			{
			spWarUp.setTexture(textWar);
			spWarUp_2.setTexture(textWar);
			spWarUp.setTextureRect(sf::IntRect(64,0,32,32));
			spWarUp_2.setTextureRect(sf::IntRect(96,0,32,32));
			spWarUp.setPosition((float)m_realX,(float)m_realY);
			spWarUp_2.setPosition((float)m_realX,(float)m_realY);
		
			if (int a =(int)(m_realY /32)%2 == 0)

			window.draw(spWarUp);
			else 
								
			window.draw(spWarUp_2);
			
			}
			break;
			

		case 'S':
			{
			spWarDown.setTexture(textWar);
			spWarDown_2.setTexture(textWar);
			spWarDown.setTextureRect(sf::IntRect(0,0,32,32));
			spWarDown_2.setTextureRect(sf::IntRect(32,0,32,32));
			spWarDown.setPosition((float)m_realX,(float)m_realY);
			spWarDown_2.setPosition((float)m_realX,(float)m_realY);
			
			if (int a =(int)(m_realY /32)%2 == 0)
			
			window.draw(spWarDown);
			
			else 
			
			window.draw(spWarDown_2);
			}

			break;

		case 'O':
			{
			spWarLeft.setTexture(textWar);
			spWarLeft.setTextureRect(sf::IntRect(128,0,32,32));
			spWarLeft_2.setTexture(textWar);
			spWarLeft_2.setTextureRect(sf::IntRect(160,0,32,32));
			spWarLeft.setPosition((float)m_realX,(float)m_realY);
			spWarLeft_2.setPosition((float)m_realX,(float)m_realY);
			
			if (int a =(int)(m_realX /32)%2 == 0)
			
			window.draw(spWarLeft);
			
			else
			
			window.draw(spWarLeft_2);
			}
			break;

		case 'E':
			{
			spWarRight.setTexture(textWar);
			spWarRight.setTextureRect(sf::IntRect(192,0,31,32));
			spWarRight_2.setTexture(textWar);
			spWarRight_2.setTextureRect(sf::IntRect(223,0,31,32));
			spWarRight.setPosition((float)m_realX,(float)m_realY);
			spWarRight_2.setPosition((float)m_realX,(float)m_realY);
			
			if (int a =(int)(m_realX /32)%2 == 0)
			
			window.draw(spWarRight);
			
			else
			
			window.draw(spWarRight_2);
			}
			break;

	}	
			
	
}


void Guerrier::set_xmoins1(Map &map,bool &deplacementOK)
{
	
	while (deplacementOK == true)
	{
		//if (map.okForMove(this,m_realX-8,m_realY,1))
		if (map.okForMove(this,'X',-8))
		{
		
				m_realX-=8;
				spWarLeft.setPosition((float)m_realX,(float)m_realY);
				if (m_tile == 0)

				m_tile = 1;
				else if (m_tile == 1)

					m_tile = 2;
			
		}

		deplacementOK = false;

	}

}

void Guerrier::set_xplus1(Map &map,bool &deplacementOK)
{
	while (deplacementOK == true)
	{
		//if (map.okForMove(this,m_realX+8,m_realY,0))
		if (map.okForMove(this,'X',8))
		{
	
				m_realX+=8;
				spWarRight.setPosition((float)m_realX,(float)m_realY);
				if (m_tile == 0)

				m_tile = 1;
				else if (m_tile == 1)

					m_tile = 2;
		}

		deplacementOK = false;

	}
}

void Guerrier::set_ymoins1(Map &map,bool &deplacementOK)
{
	//if (map.okForMove(this,m_realX,m_realY-8,1))
	if (map.okForMove(this,'Y',-8))
	{
		
				m_realY-=8;
				spWarUp.setPosition((float)m_realX,(float)m_realY);
	
		
		}

		deplacementOK = false;
}

void Guerrier::set_yplus1(Map &map,bool &deplacementOK)
{
	//if (map.okForMove(this,m_realX,m_realY+8,0))
	if (map.okForMove(this,'Y',8))
	{
				
				m_realY+=8;
				spWarDown.setPosition((float)m_realX,(float)m_realY);
					if (m_tile == 0)

				m_tile = 1;
				else if (m_tile == 1)

					m_tile = 2;
		
		}

		deplacementOK = false;
}


void Guerrier::supprimerHache()
{

	m_hacheUp = false;
	delete hache;
	hache = 0;

}

void Guerrier::recevoirDegats(PersonnageBase *perso)
{


}

