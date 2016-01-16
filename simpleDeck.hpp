//
//  simpleDeck.hpp
//  Card Game
//
//  Created by San Min Liew on 12/24/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#ifndef simpleDeck_hpp
#define simpleDeck_hpp
#include <list>
#include <iostream>
#define SIMPLE_SIZE 60
using namespace std;
#include <stdio.h>

class simpleDeck
{
    public:
    simpleDeck();
    
    void quickSort(int arr[], int left, int right);
    void bubbleSort(int array[][2], int size);
    void shuffle(int original[]);
    void placeCardToDeck();
    void drawSimpleDeck();
    void printCardOnHand();
    int random(int min, int max);

    list<int> cardOnHand; // card on hand as linked list
    int deck[SIMPLE_SIZE]; // deck array
};

#endif /* simpleDeck_hpp */
