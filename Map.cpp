#include "Map.h"
#include <math.h>


using namespace std ;

Map::Map() : m_X(11) , m_Y(11) , m_boucle(0) {
}

Map::Map(Joueur *joueur1) : m_X(11) , m_Y(11) , m_boucle(0) {

     //cr�ation de la matrix
     level1 = NULL ;
     level1 = new char* [m_X] ;

     for (int i = 0 ; i < m_X ; i++)
     {
	  level1[i] = new char [m_Y] ;
     }

     //init a 0 de la matrix

     for (int i = 0 ; i < m_X ; i++)
     {
	  for (int j = 0 ; j < m_Y ; j++)
	  {

	       level1[i][j] = '0' ;

	  }

     }

     fstream stream("level1.txt") ;

     if (!stream)
     {
	  cout << "Erreur lors de l\'ouverture de la map." << endl ;
	  exit(1) ;


     }
     else
     {

	  //remplissage de la matrix

	  for (int y = 0 ; y < m_X ; y++)
	  {
	       for (int x = 0 ; x < m_X ; x++)
	       {

		    stream >> level1[x][y] ;


	       }


	  }
     }



}

Map::~Map() {
}

void Map::affichage(sf::RenderWindow &window) {



     if (!texture.loadFromFile("texture_7.png"))
     {
	  cout << "Erreur lors du chargement de la texture de la map" << endl ;

	  exit(1) ;

     }
     else
     {



	  sable.setTexture(texture) ;
	  sable.setTextureRect(sf::IntRect(0 , 0 , 32 , 32)) ;
	  arbre.setTexture(texture) ;
	  arbre.setTextureRect(sf::IntRect(32 , 0 , 32 , 32)) ;
	  //teki1.setTexture(texture);
	  //teki1.setTextureRect(sf::IntRect(64,0,32,32));
	  //teki2.setTexture(texture);
	  //teki2.setTextureRect(sf::IntRect(96,0,32,32));
	  montagne.setTexture(texture) ;
	  montagne.setTextureRect(sf::IntRect(128 , 0 , 32 , 32)) ;
	  mont_bas_droite.setTexture(texture) ;
	  mont_bas_droite.setTextureRect(sf::IntRect(160 , 0 , 32 , 32)) ;
	  mont_bas_gauche.setTexture(texture) ;
	  mont_bas_gauche.setTextureRect(sf::IntRect(192 , 0 , 32 , 32)) ;
	  mont_haut_gauche.setTexture(texture) ;
	  mont_haut_gauche.setTextureRect(sf::IntRect(224 , 0 , 32 , 32)) ;
	  mont_haut_droite.setTexture(texture) ;
	  mont_haut_droite.setTextureRect(sf::IntRect(256 , 0 , 32 , 32)) ;
	  arbreMort.setTexture(texture) ;
	  arbreMort.setTextureRect(sf::IntRect(288 , 0 , 32 , 32)) ;
	  arbreEnFeu_1.setTexture(texture) ;
	  arbreEnFeu_1.setTextureRect(sf::IntRect(416 , 0 , 32 , 32)) ;
	  arbreEnFeu_2.setTexture(texture) ;
	  arbreEnFeu_2.setTextureRect(sf::IntRect(448 , 0 , 32 , 32)) ;



	  for (int j = 0 ; j < m_Y ; j++)
	  {
	       for (int i = 0 ; i < m_X ; i++)
	       {

		    switch (level1[i][j]) {
			 case '0':
			      sable.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(sable) ;
			      break ;
			 case 'A':
			      arbre.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(arbre) ;
			      break ;
			 case '3':
			      montagne.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(montagne) ;
			      break ;
			 case '4':
			      mont_bas_gauche.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(mont_bas_gauche) ;
			      break ;
			 case '5':
			      mont_bas_droite.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(mont_bas_droite) ;
			      break ;
			 case '6':
			      mont_haut_gauche.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(mont_haut_gauche) ;
			      break ;
			 case '7':
			      mont_haut_droite.setPosition(i * 32.0f , j * 32.0f) ;
			      window.draw(mont_haut_droite) ;
			      break ;
			      /*case 'E':
				      //anim Teki
				      //teki1.setPosition(i*32.0f,j*32.0f);
				      //window.draw(teki1);
				      sable.setPosition(i*32.0f,j*32.0f);
				      window.draw(sable);
				      break;*/

		    } //fin switch

	       }
	  }
     }//fin else de texture
}

void Map::deleteMap() {
     for (int i = 0 ; i < m_X ; i++)
     {
	  delete [] level1[i] ;
	  level1[i] = 0 ;

     }

     delete [] level1 ;
     level1 = 0 ;

}

bool Map::okForMove(PersonnageBase *perso , char direction , int variation) {
     if (direction == 'X' || direction == 'x')
     {
	  int x = 0 ;
	  if (variation > 0)
	  {
	       x = (int) ceil(float((perso->get_m_realX() + variation)) / 32) ;
	  }
	  else
	  {
	       x = (int) floor(float((perso->get_m_realX() + variation)) / 32) ;
	  }

	  int y = (int) perso->get_m_realY() / 32 ;


	  if (x < 0 || y < 0)
	  {
	       return false ;

	  }

	  if (x > 10 || y > 10)
	  {
	       return false ;

	  }

	  if (level1[x][y] == '0')
	  {
	       if (perso->get_m_realY() % 32 == 0)
	       {
		    return true ;
	       }
	       else
	       {
		    if (level1[x][y + 1] == '0')
		    {
			 return true ;
		    }
		    return false ;
	       }
	  }

	  return false ;
     }
     else if (direction == 'Y' || direction == 'y')
     {
	  int y = 0 ;
	  int x = (int) floor((float) perso->get_m_realX() / 32) ;
	  if (variation > 0)
	  {
	       y = (int) ceil(float((perso->get_m_realY() + variation)) / 32) ;
	  }
	  else
	  {
	       y = (int) floor(float((perso->get_m_realY() + variation)) / 32) ;

	  }
	  if (x < 0 || y < 0)
	  {
	       return false ;

	  }
	  if (x > 10 || y > 10)
	  {
	       return false ;

	  }
	  if (level1[x][y] == '0')
	  {
	       if (perso->get_m_realX() % 32 == 0)
	       {
		    return true ;
	       }
	       else
	       {
		    if (level1[x + 1][y] == '0')
		    {
			 return true ;
		    }
		    return false ;
	       }

	  }

	  return false ;
     }

     return false ;

}

char
Map::getLevel1Pos(int x , int y) {
     return level1[x][y] ;

}

bool
Map::setEnemiePos(int x , int y) {

     if (level1[x][y] == '0')
     {

	  level1[x][y] = 'E' ;
	  return true ;

     }

     return false ;
}

bool
Map::setPostoZero(int x , int y) {

     if (level1[x][y] == 'E')
     {
	  level1[x][y] = '0' ;
	  return true ;

     }
     else
	  return false ;


}

bool
Map::setPosArbreVersSable(int x , int y) {
     if (level1[x][y] == 'A')
     {

	  level1[x][y] = '0' ;
	  return true ;

     }
     else
     {
	  return false ;

     }


}

void
Map::temps(Enemie *teki1 , Enemie *teki2 , sf::Time &time , sf::Clock &clock , sf::RenderWindow &window) {

     time = clock.getElapsedTime() ;


     if (time.asMilliseconds() <= 500)
     {
	  if (m_boucle == 0)
	  {
	       if (teki1->get_attacked() == false) //SI TEKI 1 NON ATTACKED ET TEKI 2 ATTAQUE PAS
	       {


		    teki1->deplacementAuto(teki1 , teki2, *this) ;

	       }
	       else  if (teki2->get_attacked() == false)
	       {
		 
		    teki2->deplacementAuto(teki2 , teki1, *this) ;
	       }

	       m_boucle++ ;
	  }

     }
     else if (time.asMilliseconds() > 500 && time.asMilliseconds() <= 1000)
     {
	  if (m_boucle == 1)
	  {
	       if (teki1->get_attacked() == false)
	       {
		    teki1->deplacementAuto(teki1 ,teki2, *this) ;

	       }
	       if (teki2->get_attacked() == false)
	       {
		    teki2->deplacementAuto(teki2 ,teki1, *this) ;
	       }

	       m_boucle++ ;
	  }
     }
     else if (time.asMilliseconds() > 1000 && time.asMilliseconds() <= 1500)
     {
	  if (m_boucle == 2)
	  {
	       if (teki1->get_attacked() == false)
	       {
		    teki1->deplacementAuto(teki1 , teki2, *this) ;

	       }
	       if (teki2->get_attacked() == false)
	       {
		    teki2->deplacementAuto(teki2 ,teki1 , *this) ;
	       }

	       m_boucle++ ;
	  }
     }
     else if (time.asMilliseconds() > 1500)
     {

	  time = clock.restart() ;
	  m_boucle = 0 ;


     }
}

void
Map::temps(Enemie *teki , sf::Time &time , sf::Clock &clock , sf::RenderWindow &window) {

     time = clock.getElapsedTime() ;


     if (time.asMilliseconds() <= 500)
     {
	  if (m_boucle == 0)
	  {
	       if (teki->get_attacked() == false)
	       {
		    teki->deplacementAuto(teki , *this) ;

	       }


	       m_boucle++ ;
	  }

     }
     else if (time.asMilliseconds() >= 500 && time.asMilliseconds() < 1000)
     {
	  if (m_boucle == 1)
	  {
	       if (teki->get_attacked() == false)
	       {
		    teki->deplacementAuto(teki , *this) ;

	       }


	       m_boucle++ ;
	  }
     }
     else if (time.asMilliseconds() >= 1000 && time.asMilliseconds() < 1500)
     {
	  if (m_boucle == 2)
	  {
	       if (teki->get_attacked() == false)
	       {
		    teki->deplacementAuto(teki , *this) ;

	       }


	       m_boucle++ ;
	  }
     }
     else if (time.asMilliseconds() > 1500)
     {
	  std::cout << time.asMilliseconds() << endl ;
	  time = clock.restart() ;
	  m_boucle = 0 ;


     }

}