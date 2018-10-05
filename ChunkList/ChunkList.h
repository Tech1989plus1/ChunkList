//
//  ChunkList.h
//  Assignment2_ChuckList
//
//  Created by Derrick Marshall on 4/13/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#ifndef ChunkList_h
#define ChunkList_h
#include "ItemType.h"



struct chunkLink{
	chunkLink *next;
	int size;
	ItemType value[ARRAY_SIZE];
};

class ChunkList{
private:
	chunkLink *head;
	chunkLink *currentPos;
	chunkLink *tail;
	int indexCurrent;
	int lenght;
	int index;
public:
	ChunkList();
	~ChunkList();
	
	
	int GetLenght();
	ItemType GetNextItem();
	
	void PutItem(ItemType item);
	void DeleteItem(ItemType item);
	void ResetList();
	void MakeEmpty();
	bool isFull();
	bool GetItem(ItemType item);

	
};




#endif /* ChunkList_h */
