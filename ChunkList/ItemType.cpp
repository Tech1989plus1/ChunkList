//
//  ItemType.cpp
//  Assignment2_ChuckList
//
//  Created by Derrick Marshall on 4/13/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "ItemType.h"

ItemType:: ItemType(){
	value = 0;
}

ItemType:: ItemType(int val){
	value = val;
}

RelationType ItemType:: ComparedTo(ItemType otherItem) const{
	if(value < otherItem.value)
		return LESS;
	else if (value > otherItem.value)
		return GREATER;
	else
		return EQUAL;
}

void ItemType:: Initialize(int number){
	value = number;
}

void ItemType:: Print(std::ostream &out) const{
	out << value;
}

ItemType ItemType:: getValue(){
	return value;
}

