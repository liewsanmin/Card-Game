//
//  traditionalDeck.h
//  Card Game
//
//  Created by San Min Liew on 12/28/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#ifndef traditionalDeck_h
#define traditionalDeck_h
#include "traditionalCard.h"
#include <list>

#include <iostream>
using namespace std;

const int CARDS_PER_DECK = 52;

class traditionalDeck
{
public:
    traditionalDeck();
    void drawCard();
    void printCardOnHand();
    void shuffle(traditionalCard *original);
    void bubbleSort(int array[][2], int size);
    void quickSort(traditionalCard *deck, int left, int right);
    void placeCardToDeck();
    traditionalCard *deck; 
    
private:

    list<traditionalCard> cardOnHand; // card on hand as linked list
    
};

#endif /* traditionalDeck_h */


