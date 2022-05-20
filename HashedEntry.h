// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: HashedEntry.h - 05/19/2021

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

// Listing 18-5.

/** A class of entry objects for a hashing implementation of the
    ADT dictionary.
 @file HashedEntry.h */

#ifndef _HASHED_ENTRY
#define _HASHED_ENTRY

#include "Entry.h"

template<class KeyType, class ItemType>
class HashedEntry : public Entry<KeyType, ItemType>
{
private:
    HashedEntry<KeyType, ItemType>* nextPtr;

public:
    HashedEntry();
    HashedEntry(ItemType newEntry, KeyType newKey);
    HashedEntry(ItemType newEntry, KeyType newKey, HashedEntry<KeyType, ItemType>* nextEntryPtr);
    void setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr);
    HashedEntry<KeyType, ItemType>* getNext() const;
}; 

#include "HashedEntry.cpp"
#endif

