//Rahul Iyer
//Item cpp code

#include "Item.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
//functions that the item will carry out
Item::Item(char* item1) {
  item = new char[20];
  strcpy(item, item1);
}

char* Item::getItemName() {
  return item;
}