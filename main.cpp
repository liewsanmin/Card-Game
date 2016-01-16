//
//  main.cpp
//  Card Game
//
//  Created by San Min Liew on 12/24/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#include "simpleDeck.hpp"
#include "traditionalDeck.h"
void simpleGameSimulation(simpleDeck sD);
void gameSimulation(traditionalDeck tD);

int main(int argc, const char * argv[])
{
    int deckOption;
    string input = "";
    
    while(true)
    {
        cout << "Please choose a deck to play!\n";
        cout << "1. Simple Deck\n";
        cout << "2. Traditional Deck\n";
        
        cout << endl;
        cin >> input;
        
        // converts string to number safely
        stringstream myStream(input);
        if (myStream >> deckOption)
        {
            if (deckOption >= 1 && deckOption <= 2)
            break;
        }
        cout << "Invalid input, try again\n\n";
    }
    
    if (deckOption == 1)
    {
        simpleDeck sD;
        simpleGameSimulation(sD);
    }
    
    else
    {
        traditionalDeck deck;
        gameSimulation(deck);
    }
    cout << "\nThank you for playing and see you again!\n";
    exit(0);
}

// simulation for simpleDeck
void simpleGameSimulation(simpleDeck sD)
{
    int option;
    string input = "";
    
    do
    {
        while(true)
        {
            cout << "\nChoose an option :)\n"
            << "1. Draw a card to hand\n"
            << "2. Place a card in hand on the deck\n"
            << "3. Shuffle the deck\n"
            << "4. Sort the deck\n"
            << "5. Print cards that exist in hand\n"
            << "6. Quit\n";
            cin >> input;
            
            // converts string to number safely
            stringstream myStream(input);
            if (myStream >> option)
            {
                if (option >= 1 && option <= 6)
                    break;
            }
            cout << "Invalid input, try again\n\n";
        }
        
        // switch case to handle the options
        switch (option)
        {
            case 1: // draw a card
                sD.drawSimpleDeck();
                break;
            case 2: // place card back to deck
                sD.placeCardToDeck();
                break;
            case 3: // shuffle
                sD.shuffle(sD.deck);
                break;
            case 4: // sort
            {
                sD.quickSort(sD.deck, 0, SIMPLE_SIZE - 1);
                cout << "Your deck is sorted\n";
            }
                break;
            case 5: // print card on hand
                sD.printCardOnHand();
                break;
            default:
                break;
        }
    }
    while (option != 6);
}

// simulation for traditionalDeck
void gameSimulation(traditionalDeck tD)
{

    int option;
    string input = "";
    
    do
    {
        while(true)
        {
            cout << "\nChoose an option :)\n"
            << "1. Draw a card to hand\n"
            << "2. Place a card in hand on the deck\n"
            << "3. Shuffle the deck\n"
            << "4. Sort the deck\n"
            << "5. Print cards that exist in hand\n"
            << "6. Quit\n";
            cin >> input;
            
            // converts string to number safely
            stringstream myStream(input);
            if (myStream >> option)
            {
                if (option >= 1 && option <= 6)
                    break;
            }
            cout << "Invalid input, try again\n\n";
        }
        
        // switch case to handle the options
        switch (option)
        {
            case 1:
                tD.drawCard();
                break;
            case 2:
                tD.placeCardToDeck();
                break;
            case 3:
                tD.shuffle(tD.deck);
                break;
            case 4:
            {
                tD.quickSort(tD.deck, 0, CARDS_PER_DECK - 1);
                cout << "Your deck is sorted\n";
            }
                break;
            case 5:
                tD.printCardOnHand();
                break;
            default:
                break;
        }
    }
    while(option != 6);
}
