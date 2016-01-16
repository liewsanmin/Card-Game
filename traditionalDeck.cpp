//
//  traditionalDeck.cpp
//  Card Game
//
//  Created by San Min Liew on 12/28/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "traditionalDeck.h"
#include <time.h>
using namespace std;

// default contrustor
traditionalDeck::traditionalDeck()
{
    string faces[] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven",
        "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    
    deck = new traditionalCard[CARDS_PER_DECK];
    
    for (int i = 0; i < CARDS_PER_DECK; i++)
        deck[i] = traditionalCard(faces[i % 13], suits[i / 13], i);
}

void traditionalDeck::drawCard()
{
    int count = 0;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        if (deck[i].getFace() == "")
            count++;
    }
    
    if (count == CARDS_PER_DECK)
        cout << "Your deck is empty!" << endl;
    else
    {
        // go throught the array from 0th as the top of deck
        for (int i = 0; i < CARDS_PER_DECK; i++)
        {
            if (deck[i].getFace() != "") // to find a card
            {
                cardOnHand.push_back(deck[i]);
                cout << "You have drawn " << deck[i].print() << " to your hand" << endl;
                deck[i] = traditionalCard("", "", -1); // set that slot to empty flag = "empty" & -1
                break;
            }
        }
    }
}

void traditionalDeck::printCardOnHand()
{
    if (cardOnHand.empty())
        cout << "You currently have no cards";
    else
    {
        cout << "Your cards on hand currently are : " << endl;
        for (list<traditionalCard>::iterator it = cardOnHand.begin(); it != cardOnHand.end(); it++)
            cout << it->print() << ", ";
    }
    cout << endl;
}

void traditionalDeck::shuffle(traditionalCard *original)
{
    // to check if deck array is empty
    int count = 0;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        if (deck[i].getFace() == "")
            count++;
    }
    
    if (count == CARDS_PER_DECK)
        cout << "Your deck is empty!" << endl;
    else
    {
        srand(time(0));
        // shuffle array
        int C[CARDS_PER_DECK][2];
        for (int i = 0; i < CARDS_PER_DECK; i++)
        {
            C[i][0] = i;
            C[i][1] = rand();
        }
        
        bubbleSort(C, CARDS_PER_DECK);
        traditionalCard *copy = new traditionalCard[CARDS_PER_DECK];
        
        // make a copy of shuffled deck 1st
        for (int i = 0; i < CARDS_PER_DECK; i++)
            copy[i] = original[C[i][0]];
        
        // overwrite the orginial array to become a shuffled deck
        for (int i = 0; i < CARDS_PER_DECK; i++)
            original[i] = copy[i];
        cout << "Your deck is shuffled\n";
    }
}

void traditionalDeck::bubbleSort(int array[][2], int size) // bubble sort to sort the 2D array
{
    int tempC1, tempC2;
    for(int i = 0; i < size - 1 ; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if (array[j - 1][1] > array[j][1])
            {
                tempC1 = array[j - 1][0];
                tempC2 = array[j - 1][1];
                
                array[j - 1][0] = array[j][0];
                array[j - 1][1] = array[j][1];
                
                array[j][0] = tempC1;
                array[j][1] = tempC2;
            }
        }
    }
}

void traditionalDeck::quickSort(traditionalCard *deck, int left, int right) // to sort the deck
{
    // to check if deck array is empty
    int count = 0;
    for (int i = 0; i < CARDS_PER_DECK; i++)
    {
        if (deck[i].getFace() == "")
            count++;
    }
    
    if (count == CARDS_PER_DECK)
        cout << "Your deck is empty!" << endl;
    else
    {
        int i = left, j = right;
        traditionalCard tmp;
        int pivot = deck[(left + right) / 2].getRank();
        
        // partition
        while (i <= j)
        {
            while (deck[i].getRank() < pivot)
                i++;
            while (deck[j].getRank() > pivot)
                j--;
            if (i <= j)
            {
                tmp = deck[i];
                deck[i] = deck[j];
                deck[j] = tmp;
                i++;
                j--;
            }
        };
        
        // recursion
        if (left < j)
            quickSort(deck, left, j);
        if (i < right)
            quickSort(deck, i, right);
    }
}

void traditionalDeck::placeCardToDeck()
{
    if (cardOnHand.empty())
        cout << "You have no more cards in your hand!\n";
    else
    {
        for (int i = 0; i < CARDS_PER_DECK; i++)
        {
            if (deck[i].getFace() == "") // find empty spot
            {
                deck[i] = cardOnHand.front();
                deck[i] = traditionalCard(cardOnHand.front().getFace(), cardOnHand.front().getSuit(), cardOnHand.front().getRank());
                cout << "You have placed " << cardOnHand.front().print() << " back to deck.\n";
                cardOnHand.pop_front(); // pop the front of list after placing into deck
                break;
            }
        }
        
    }
}
