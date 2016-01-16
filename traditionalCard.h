//
//  traditionalCard.h
//  Card Game
//
//  Created by San Min Liew on 12/28/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#ifndef traditionalCard_h
#define traditionalCard_h

#include <iostream>
using namespace std;

class traditionalCard
{
public:
    traditionalCard(string cardFace, string cardSuit, int theRank);
    string print();
    traditionalCard();
    string getFace();
    string getSuit();
    int getRank();
    
private:
    string face;
    string suit;
    int rank;
};
#endif /* traditionalCard_h */
