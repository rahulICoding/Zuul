//Rahul Iyer
//Room h code

#pragma once
#include "Item.h"
#include <vector>
#include <map>

using namespace std;
class Room{
 public: //functions
  Room(char*,char*);
  char* getInfo();
  char* getRoomName();
  void addItem(Item*);
  void printItems();
  void printExits();
  void addNeighbor(char*,Room*);
  Room* getNextRoom(char*);
  Item* getItem(char*);
  void removeItem(char*);
 private: //vairables only used in the functions and the variables used in the progrma are same but different.
  char* info;
  char* roomName;
  vector<Item*> items;
  map<char*,Room*> neighbors;
};