//
//  ItemType.h
//  Assignment2_ChuckList
//
//  Created by Derrick Marshall on 4/13/17.
//  Copyright © 2017 Derrick Marshall. All rights reserved.
//

#ifndef ItemType_h
#define ItemType_h

#include <fstream>
const int ARRAY_SIZE = 8;

enum RelationType {LESS, GREATER, EQUAL};

class ItemType{
private:
	int value;

public:
	ItemType();
	ItemType(int value);
	RelationType ComparedTo(ItemType) const;
	void Print(std:: ostream&) const;
	void Initialize(int number);
	ItemType getValue();
};


#endif /* ItemType_h */
