// Camille Copeland - CS10C Dave Harden - Assignment 15 - File Name: Entry.cpp - 05/19/2021


template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setKey(const KeyType& newKey) {
	searchKey = newKey;
}



template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry() {}



template <class KeyType, class ItemType>
Entry<KeyType, ItemType>::Entry(ItemType newEntry, KeyType newKey) {
	searchKey = newKey;
	item = newEntry;
}



template <class KeyType, class ItemType>
ItemType Entry<KeyType, ItemType>::getItem() const {
	return item;
}



template <class KeyType, class ItemType>
KeyType Entry<KeyType, ItemType>::getKey() const {
	return searchKey;
}



template <class KeyType, class ItemType>
void Entry<KeyType, ItemType>::setItem(const ItemType& newEntry) {
	item = newEntry;
}