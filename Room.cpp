#include "Room.h"
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
Room::Room(char* roomName1, char* info1){
 roomName = new char[20];
  strcpy(roomName, roomName1);
  info = new char[150];
  strcpy(info, info1);
}
void Room::printItems(){
  cout << "Items in the room: " << endl;
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    cout << (*itr)->getItemName() << " ";
  }
  cout << endl;
}
void Room::printExits(){
  map<char*,Room*>::iterator itr;
  for(itr = neighbors.begin(); itr != neighbors.end(); itr++){
    cout << itr->first << "  ";
  }
}
Room* Room::getNextRoom(char* direction){
  map<char*,Room*>::iterator itr;
  for(itr = neighbors.begin(); itr != neighbors.end(); itr++){
    if(strcmp((itr->first),direction)==0){
      return itr->second;
    }
  }
  return NULL;
}
Item* Room::getItem(char* item){
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    char* itemName = (*itr)->getItemName();
    if(strcmp(itemName,item)==0){
      return (*itr);
    }
  }
  return NULL;
}
void Room::removeItem(char* label){
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    char* itemName = (*itr)->getItemName();
    if(strcmp(itemName,roomName)==0){
      items.erase(itr);
      break;
    }
  }
}

void Room::addItem(Item* i){
  items.push_back(i);
}

char* Room::getInfo(){
  return info;
}

char* Room::getRoomName(){
  return roomName;
}

void Room::addNeighbor(char* direction, Room* neighbor){
  neighbors.insert({direction,neighbor});
}