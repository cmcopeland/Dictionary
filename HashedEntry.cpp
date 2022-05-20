// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: HashedEntry.cpp - 05/19/2021

template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry() {
	nextPtr = nullptr;
}




template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newKey) : Entry<KeyType, ItemType>(newEntry, newKey) {
	nextPtr = nullptr;
}



template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>::HashedEntry(ItemType newEntry, KeyType newKey, HashedEntry<KeyType, ItemType>* nextEntryPtr) : Entry<KeyType, ItemType>(newEntry, newKey) {
	nextPtr = nextEntryPtr;
}



template<class KeyType, class ItemType>
void HashedEntry<KeyType, ItemType>::setNext(HashedEntry<KeyType, ItemType>* nextEntryPtr) {
	nextPtr = nextEntryPtr;
}



template<class KeyType, class ItemType>
HashedEntry<KeyType, ItemType>* HashedEntry<KeyType, ItemType>::getNext() const {
	return nextPtr;
}
