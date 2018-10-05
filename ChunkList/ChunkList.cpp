//
//  ChunkList.cpp
//  Assignment2_ChuckList
//
//  Created by Derrick Marshall on 4/13/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#include <stdio.h>
#include "ChunkList.h"


ChunkList::ChunkList(){
	indexCurrent = lenght = index = 0;
	head = tail = currentPos = NULL;
}

ChunkList :: ~ChunkList(){
	
}

void ChunkList:: ResetList(){
	currentPos = head;
	indexCurrent = index = 0;
}

bool ChunkList:: isFull(){
	chunkLink *tempIsFull;
	
	try {
		tempIsFull = new chunkLink();
		delete tempIsFull;
		return false;
	} catch (std :: bad_alloc exception) {
		return false;
	}
}

void ChunkList:: PutItem(ItemType item){
	
	if(head == NULL && tail == NULL){
		head = new chunkLink();
		tail = currentPos = head;
		head -> next = NULL;
		head -> value[0] = item;
		head -> size++;
		lenght++;
		currentPos++;
		return;
	}
	
	if(tail -> size < ARRAY_SIZE){
		tail -> value[tail -> size] = item;
		tail -> size++;
		currentPos++;
		lenght++;
	}else if(tail -> size == ARRAY_SIZE){
		chunkLink *newChunk = new chunkLink();
		newChunk -> value[newChunk ->size] = item;
		newChunk -> next = NULL;
		tail -> next = newChunk;
		currentPos = tail = newChunk;
		newChunk -> size++;
		indexCurrent++;
		lenght++;
	}
	
}

void ChunkList:: DeleteItem(ItemType item){
	index = 0;
	
	chunkLink *temp = new chunkLink();
	
	if (head == NULL) {
		return;
	}
	
	temp = head;
	
	while (item.ComparedTo(temp -> value[index]) != EQUAL){
		if(temp == tail && temp -> size == index){
			return;
		}else if (index == temp -> size) {
			temp = temp -> next;
			index = 0;
		}else
			index++;
	}

	temp -> value[index] = temp -> value[temp -> size - 1];
	temp -> size--;
	lenght--;
	
	if(temp -> size == 0){
		chunkLink *remmovePos = new chunkLink();
		
		remmovePos = temp;
		temp = head;
		
		while((temp -> next) -> size != 0)
			temp = temp -> next;
		
		temp -> next = (temp -> next) -> next;
		
		if(lenght == ARRAY_SIZE)
			tail = head;
		
		delete remmovePos;
	}
	
}

int ChunkList:: GetLenght(){
	return lenght;
}

bool ChunkList:: GetItem(ItemType item){
	indexCurrent = 0;
	
	if(head == NULL)
		return false;
	
	currentPos = head;
	
	
	while (item.ComparedTo(currentPos -> value[indexCurrent]) != EQUAL) {
		if(currentPos == tail && currentPos -> size == indexCurrent){
			return false;
		}else if (indexCurrent == currentPos -> size) {
			currentPos = currentPos -> next;
			indexCurrent = 0;
		}else
			indexCurrent++;
	}
	return true;
}

void ChunkList:: MakeEmpty(){
	chunkLink *tempChuck = new chunkLink();
	
	while (head != NULL) {
		tempChuck = head;
		head = head -> next;
		delete tempChuck;
	}
	tail = tail -> next;
	lenght = 0;
}

ItemType ChunkList:: GetNextItem(){
	ItemType val;
	
	if(indexCurrent == ARRAY_SIZE){
		currentPos = currentPos -> next;
		indexCurrent = 0;
		return currentPos -> value[indexCurrent++];
		
	}else{
		return currentPos -> value[indexCurrent++];
	}
	
}