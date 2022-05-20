// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: HashedDictionary.h - 05/19/2021


#ifndef _HASHED_DICTIONARY
#define _HASHED_DICTIONARY

#include "DictionaryInterface.h"
#include "HashedEntry.h"
#include <iostream>
#include <string>

template<class KeyType, class ItemType>
class HashedDictionary : public DictionaryInterface<KeyType, ItemType>
{
private:
	HashedEntry<KeyType, ItemType>** hashTable;
	int itemCount;
	int hashTableSize;
	static const int DEFAULT_SIZE = 101;
public:
	HashedDictionary();
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);
	int getHashIndex(const KeyType& searchKey);
	bool isEmpty() const;
	int getNumberOfItems() const;
	void clear();
	ItemType getItem(const KeyType& searchKey) const;
	bool contains(const KeyType& searchKey) const;
	void display() const;
};

#include "HashedDictionary.cpp"
#endif

