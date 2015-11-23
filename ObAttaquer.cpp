#include "ObAttaquer.h"


ObAttaquer::ObAttaquer()
{
}

ObAttaquer::ObAttaquer(sf::RenderWindow &window, Guerrier *toto, Enemie *teki1, Enemie *teki2, Map &map, sf::Time &time, sf::Clock &clock, sf::Clock &clockJoueur, bool &attaquer, bool &hacheUp)
{
	m_window = NULL;
	m_window = &window;

	m_toto = NULL;
	m_toto = toto;

	m_teki1 = NULL;
	m_teki1 = teki1;

	m_teki2 = NULL;
	m_teki2 = teki2;

	m_map = NULL;
	m_map = &map;

	m_time = NULL;
	m_time = &time;

	m_clock = NULL;
	m_clock = &clock;

	m_clockJoueur = NULL;
	m_clockJoueur = &clockJoueur;

	m_attaquer = NULL;
	m_attaquer = &attaquer;

	m_hacheUp = NULL;
	m_hacheUp = &hacheUp;

		
	

}


ObAttaquer::~ObAttaquer()
{
}

void ObAttaquer::attaque(bool &attaquer)
{
	
	while (attaquer == true)
	{


		m_window->clear(sf::Color::Black);

		m_map->affichage(*m_window);

		m_toto->affichage(*m_window, m_toto);

		//m_map->temps(m_teki1, m_teki2, *m_time, *m_clock, *m_window);

		m_teki1->affichage(*m_window, m_teki1);

		m_teki2->affichage(*m_window, m_teki2);

		//ATTAQUE

		//bool hacheUp = toto->getHacheUp();
		//m_toto->attaquer(*m_clockJoueur, *m_map, *m_window, *m_attaquer, *m_hacheUp);

		//AFFICHAGE DURANT L'ATTAQUE

		m_window->display();
	}

}