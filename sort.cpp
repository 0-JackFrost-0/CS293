#include "sort.h"
#include <iostream>

// Code up the functions defined in sort.cpp
SorterTree::SorterTree(int choice, int l)
{
    this->choice = choice;
    this->l = l;
    array = new Journey[l];
}

void SorterTree::addJourney(int code, int price, int idx)
{
    array[idx].JourneyCode = code;
    array[idx].price = price;
}

bool SorterTree::Quicksort(int start, int finish)
{
    // Call appropriate pivot function based on choice
    // Split into 2 parts based on pivot choice
    // Recursively keep sorting
    if (start < finish){
        int pivot = Partition(start, finish);
        Quicksort(start, pivot);
        Quicksort(pivot+1, finish)
    }
    
}
int SorterTree::Partition(int start, int finish)
{
    switch(choice)
    {
        case 1:
            Journey* x = choose_one(array, start, finish);
            break;
        case 2:
            Journey* x = choose_two(array, start, finish);
            break;
        case 3:
            Journey* x = choose_three(array, start, finish);
            break;
        case 4:
            Journey* x = choose_four(array, start, finish);
            break;
    }
    int i = start - 1;
    int j =  finish + 1;
    while(true){
        while(array[j] < *x && array[j].getJourneyCode() == x->getJourneyCode()){
            j--;
            comparisons++;
        }
        while(!(array[i] < *x)){
            i++;
            comparisons++;
        }
        if(i < j){
            comparisons++;
            Journey temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            return j;
        }  
    }
}
bool SorterTree::QuicksortWithBSTInsert(int start, int finish)
{
    // Call appropriate pivot function based on choice
    // Split into 2 parts based on pivot choice
    // Recursively keep sorting
    // Insert chosen pivot into the tree appropriately
}

bool SorterTree::printArray()
{
    for (int i = 0; i < l; i++)
    {
        std::cout<<"Journey code: "<<array[i].getJourneyCode()<<"\tJourney Price:"<<array[i].getPrice()<<std::endl;
    }
}
