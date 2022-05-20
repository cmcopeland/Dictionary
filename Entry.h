// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: Entry.h - 05/19/2021

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** A class of entry objects for an array-based implementation of the ADT dictionary.
    Listing 18-2.
 @file Entry.h */

#ifndef _ENTRY
#define _ENTRY

template <class KeyType, class ItemType>
class Entry
{
private:
    ItemType item;
    KeyType searchKey;

protected:
    void setKey(const KeyType& newKey);

public:
    Entry();
    Entry(ItemType newEntry, KeyType newKey);
    ItemType getItem() const;
    KeyType getKey() const;
    void setItem(const ItemType& newEntry);
};

#include "Entry.cpp"
#endif

