//
//  simpleDeck.cpp
//  Card Game
//
//  Created by San Min Liew on 12/24/15.
//  Copyright © 2015 San Min Liew. All rights reserved.
//

#include "simpleDeck.hpp"
#include <iostream>
#include <list>
#include <time.h>

using namespace std;

// default constructor
simpleDeck::simpleDeck()
{
    for (int i = 0; i < SIMPLE_SIZE; i++)
        deck[i] = i;
}


int simpleDeck::random(int min, int max)
{
    srand(time(NULL));
    return  rand() % (max - min + 1) + min;
}

void simpleDeck::drawSimpleDeck()
{
    int count = 0;
    for (int i = 0; i < SIMPLE_SIZE; i++)
    {
        if (deck[i] == -1)
            count++;
    }
    
    if (count == SIMPLE_SIZE)
        cout << "Your deck is empty!" << endl;
    else
    {
        // go throught the array from 0th as the top of deck
        for (int i = 0; i < SIMPLE_SIZE; i++)
        {
            if (deck[i] != -1) // to find a card
            {
                cardOnHand.push_back(deck[i]);
                cout << "You have drawn card no. " << deck[i] << " to your hand" << endl;
                deck[i] = -1; // set that slot to empty flag = -1
                break;
            }
        }
    }
}

void simpleDeck::placeCardToDeck()
{
    if (cardOnHand.empty())
            cout << "You have no more cards in your hand!\n";
    else
    {
        for (int i = 0; i < SIMPLE_SIZE; i++)
        {
            if (deck[i] == -1) // find empty spot
            {
                deck[i] = cardOnHand.front();
                cout << "You have placed card no. " << cardOnHand.front() << " back to deck.\n";
                cardOnHand.pop_front(); // pop the front of list after placing into deck
                break;
            }
        }
        
    }
}

void simpleDeck::printCardOnHand()
{
    if (cardOnHand.empty())
        cout << "You currently have no cards";
    else
    {
        cout << "Your cards on hand currently are : " << endl;
        for (list<int>::iterator it = cardOnHand.begin(); it != cardOnHand.end(); it++)
            cout << *it << ' ';
    }
    cout << endl;
}

void simpleDeck::quickSort(int arr[], int left, int right) // to sort the deck
{
    // to check if deck array is empty
    int count = 0;
    for (int i = 0; i < SIMPLE_SIZE; i++)
    {
        if (deck[i] == -1)
            count++;
    }
    
    if (count == SIMPLE_SIZE)
        cout << "Your deck is empty!" << endl;
    else
    {
        int i = left, j = right;
        int tmp;
        int pivot = arr[(left + right) / 2];
        
        // partition
        while (i <= j)
        {
            while (arr[i] < pivot)
                i++;
            while (arr[j] > pivot)
                j--;
            if (i <= j)
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
                i++;
                j--;
            }
        };
        
        // recursion
        if (left < j)
            quickSort(arr, left, j);
        if (i < right)
            quickSort(arr, i, right);
    }
}

void simpleDeck::shuffle(int original[])
{
    // to check if deck array is empty
    int count = 0;
    for (int i = 0; i < SIMPLE_SIZE; i++)
    {
        if (deck[i] == -1)
            count++;
    }
    
    if (count == SIMPLE_SIZE)
        cout << "Your deck is empty!" << endl;
    else
    {
        srand(time(0));
        // shuffle array
        int C[SIMPLE_SIZE][2];
        for (int i = 0; i < SIMPLE_SIZE; i++)
        {
            C[i][0] = i;
            C[i][1] = rand();
        }
        
        bubbleSort(C, SIMPLE_SIZE);
        int copy[SIMPLE_SIZE];
        
        // make a copy of shuffled deck 1st
        for (int i = 0; i < SIMPLE_SIZE; i++)
            copy[i] = original[C[i][0]];
        
        // overwrite the orginial array to become a shuffled deck
        for (int i = 0; i < SIMPLE_SIZE; i++)
            original[i] = copy[i];
        cout << "Your deck is shuffled\n";
    }
}

void simpleDeck::bubbleSort(int array[][2], int size) // bubble sort to sort the 2D array
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





