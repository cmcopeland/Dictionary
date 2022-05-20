//  Created by Frank M. Carrano and Tim Henry.
//  Edited by David Harden
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.



template <class KeyType, class ItemType>
HashedDictionary<KeyType, ItemType>::HashedDictionary() {
    itemCount = 0;
    hashTableSize = DEFAULT_SIZE;
    hashTable = new HashedEntry<KeyType, ItemType> * [hashTableSize];
    for (int i = 0; i < hashTableSize; i++) {
        hashTable[i] = nullptr;
    }
}



template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
    // Create entry to add to dictionary
    HashedEntry<KeyType, ItemType>* entryToAddPtr =
        new HashedEntry<KeyType, ItemType>(newItem, searchKey);
    
    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);

    // Add the entry to the chain at itemHashIndex
    if (hashTable[itemHashIndex] == nullptr)
    {
        hashTable[itemHashIndex] = entryToAddPtr;
    }
    else
    {
        entryToAddPtr->setNext(hashTable[itemHashIndex]);
        hashTable[itemHashIndex] = entryToAddPtr;
    }

    itemCount++;

    return true;
}






template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::remove(const KeyType& searchKey) {
    bool itemFound = false;

    // Compute the hashed index into the array
    int itemHashIndex = getHashIndex(searchKey);
    if (hashTable[itemHashIndex] != nullptr)
    {
        // Special case - first node has target
        if (searchKey == hashTable[itemHashIndex]->getKey())
        {
            HashedEntry<KeyType, ItemType>* entryToRemovePtr =
                hashTable[itemHashIndex];
            hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
            delete entryToRemovePtr;
            entryToRemovePtr = nullptr; // For safety
            itemFound = true;
            itemCount--;
        }
        else // Search the rest of the chain
        {
            HashedEntry<KeyType, ItemType>* prevPtr = hashTable[itemHashIndex];
            HashedEntry<KeyType, ItemType>* curPtr = prevPtr->getNext();
            while ((curPtr != nullptr) && !itemFound)
            {
                // Found item in chain so remove that node
                if (searchKey == curPtr->getKey())
                {
                    prevPtr->setNext(curPtr->getNext());
                    delete curPtr;
                    curPtr = nullptr; // For safety
                    itemFound = true;
                    itemCount--;
                }
                else // Look at next entry in chain
                {
                    prevPtr = curPtr;
                    curPtr = curPtr->getNext();
                }
            }
        }
    }

    return itemFound;
}


template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getHashIndex(const KeyType& searchKey) {
    int x = 0;
    int index = 0;

    for (int i = 0; i < searchKey.length(); i++) {
        x = (toupper(searchKey[i]) - 64);
        index += (static_cast<int>(x * pow(32, 4 - i - 1)));
    }

    index %= 101;

    return index;
}



template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::isEmpty() const {
    return itemCount == 0;
}



template <class KeyType, class ItemType>
int HashedDictionary<KeyType, ItemType>::getNumberOfItems() const {
    return itemCount;
}



// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: HashedDictionary.cpp - 05/19/2021

template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::clear() {
    for (int i = 0; i < hashTableSize; i++) {
        while (hashTable[i] != nullptr) {
            remove(hashTable[i]->getKey());
        }
    }
}



template <class KeyType, class ItemType>
ItemType HashedDictionary<KeyType, ItemType>::getItem(const KeyType& searchKey) const {
    for (int i = 0; i < hashTableSize; i++) {
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];
        while (curPtr != nullptr) {
            if (curPtr->getKey() == searchKey) {
                return curPtr->getItem();
            }
            curPtr = curPtr->getNext();
        }
    }
}



template <class KeyType, class ItemType>
bool HashedDictionary<KeyType, ItemType>::contains(const KeyType& searchKey) const {
    for (int i = 0; i < hashTableSize; i++) {
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];
        while (curPtr != nullptr) {
            if (curPtr->getKey() == searchKey) {
                return true;
            }
            curPtr = curPtr->getNext();
        }
    }
    return false;
}



template <class KeyType, class ItemType>
void HashedDictionary<KeyType, ItemType>::display() const {
    for (int i = 0; i < hashTableSize; i++) {
        HashedEntry<KeyType, ItemType>* curPtr = hashTable[i];
        while (curPtr != nullptr) {
            std::cout << curPtr->getItem();
            std::cout << std::endl;
            curPtr = curPtr->getNext();
        }
    }
}
