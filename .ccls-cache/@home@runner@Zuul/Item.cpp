#include "Item.h"
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

Item::Item(char* item1) {
  item = new char[20];
  strcpy(item, item1);
}

char* Item::getItemName() {
  return item;
}