#include "Cards.h"
#include "Player.h"
#include "Map.h"
#include <iostream>

int reinforceDriver() {

	//Create Deck object with 21 cards
	Deck deck(21);

	//Create Map and Player objects

	Continent* cont1 = new Continent(0, "cont1", 3);
	Continent* cont2 = new Continent(1, "cont2", 2);
	Continent* continentArray = new Continent[2];
	continentArray[0] = *cont1;
	continentArray[1] = *cont2;

	int varr0[3] = { 1,3,4 };
	int varr1[3] = { 2,3 };
	int varr2[2] = { 4,1 };
	int varr3[2] = { 0,2 };
	int varr4[2] = { 1,3 };

	Country* vc0 = new Country("c0", 0, varr0, 0, 3);
	Country* vc1 = new Country("c1", 1, varr1, 0, 2);
	Country* vc2 = new Country("c2", 2, varr2, 0, 2);
	Country* vc3 = new Country("c3", 3, varr3, 1, 2);
	Country* vc4 = new Country("c4", 4, varr4, 1, 2);

	Country* varrayCountry = new Country[5];
	varrayCountry[0] = *vc0;
	varrayCountry[1] = *vc1;
	varrayCountry[2] = *vc2;
	varrayCountry[3] = *vc3;
	varrayCountry[4] = *vc4;

	Map* map2 = new Map(continentArray, 2, varrayCountry, 5);

	//Setting the adjacency matrix
	map2->setMatrix();
	Player *player1 = new Player("Bojan", *map2, new CheaterPlayer());

	player1->addCountry(vc0);
	player1->addCountry(vc1);
	player1->addCountry(vc2);
	player1->addCountry(vc3);
	player1->addCountry(vc4);

	//testing observer
	vector<gameView*>* vectPlayer = new vector<gameView*>;
	vectPlayer->push_back(player1);
	gameObserver* obs = new gameObserver(*vectPlayer);

	//Fill player1 hand with 10 cards
	for (int i = 0; i < 10; i++) {
		deck.draw(player1->getHand());
	}

	//Print the hand after drawing 10 cards
	std::cout << "PLAYER1 HAND-----------";
	std::cout << "\n";
	for (int i = 0; i < player1->getHand()->getCards()->size(); i++) {
		std::cout << (*player1->getHand()->getCards())[i];
		std::cout << "\n";
	}

	//Call reinforce with 10 cards
	std::cout << ("Calling reinforce with 10 cards----------------------\n");

	//Uncomment to test the CheaterPlayer reinforce. Should output 0, 2, 4, 6, 8
	/*
	for (int i = 0; i < player1->getCountriesObjects()->size(); i++) {
		player1->getCountriesObjects()->at(i)->addArmy(i);
	}
	*/
	player1->reinforceUsingStrategy();

	return 0;
}

