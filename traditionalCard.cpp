//
//  traditionalCard.cpp
//  Card Game
//
//  Created by San Min Liew on 12/28/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#include <stdio.h>
#include <iostream>

#include "traditionalCard.h"
using namespace std;

traditionalCard::traditionalCard() // default constructor
{}

// overloaded constructor
traditionalCard::traditionalCard(string cardFace, string cardSuit, int theRank)
{
    face = cardFace;
    suit = cardSuit;
    rank = theRank;
}

string traditionalCard::print()
{
    return (face + " of " + suit);
}

int traditionalCard::getRank()
{
    return rank;
}

string traditionalCard::getFace()
{
    return face;
}

string traditionalCard::getSuit()
{
    return suit;
}

