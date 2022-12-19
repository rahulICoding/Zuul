//Rahul Iyer
//Room cpp code

#include "Room.h"
#include <cstring>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
Room::Room(char* roomName1, char* info1){ //Room contrunction
 roomName = new char[20];
  strcpy(roomName, roomName1);
  info = new char[150];
  strcpy(info, info1);
}
Room* Room::getNextRoom(char* direction){ //finding the directions to go from room to room and moving rooms
  map<char*,Room*>::iterator itr;
  for(itr = neighbors.begin(); itr != neighbors.end(); itr++){
    if(strcmp((itr->first),direction)==0){
      return itr->second;
    }
  }
  return NULL;
}
void Room::printItems(){ //printing item in room function
  cout << "Items in the room: " << endl;
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    cout << (*itr)->getItemName() << " ";
  }
  cout << endl;
}
void Room::printExits(){ //printing the exits function
  map<char*,Room*>::iterator itr;
  for(itr = neighbors.begin(); itr != neighbors.end(); itr++){
    cout << itr->first << "  ";
  }
}
Item* Room::getItem(char* item){ // picking up an item
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    char* itemName = (*itr)->getItemName();
    if(strcmp(itemName,item)==0){
      return (*itr);
    }
  }
  return NULL;
}
void Room::removeItem(char* label){ //remvoing an item
  for(vector<Item*>::iterator itr = items.begin(); itr!=items.end(); itr++){
    char* itemName = (*itr)->getItemName();
    if(strcmp(itemName,roomName)==0){
      items.erase(itr);
      break;
    }
  }
}

void Room::addItem(Item* i){ //add item
  items.push_back(i);
}

char* Room::getInfo(){ //info on room
  return info;
}

char* Room::getRoomName(){ //room name
  return roomName;
}

void Room::addNeighbor(char* direction, Room* neighbor){ //direction of neighbor
  neighbors.insert({direction,neighbor});
}