#include <iostream>
#include "Room.h"
#include <vector>
#include <cstring>
using namespace std;

void printRoom(Room* toPrint, vector<Item*> inventoryy);
void addItem(Room* currentRoom, char* itemlistt, vector<Item*> &inventoryy);
void printInventory(vector<Item*> inventory);
void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory);

int main(){
  char north[10] =  "north";
  char south[10] = "south";
  char east[10] = "east";
  char west[10] = "west";
  vector<Item*> inventory;
  vector<Room*> rooms;

  char item[20] = "";
  
  char label[20] = "1";
  char description[150] = "You are in room numero uno";
  Room* uno = new Room(label, description);

  strcpy(label,"2");
  strcpy(description ,"You are in room numero dos");
  Room* dos = new Room(label,description);
  
  strcpy(label,"3");
  strcpy(description ,"You are in room numero tres");
  Room* tres = new Room(label,description);
  strcpy(item,"alien");
  Item* alien = new Item(item);
  tres->addItem(alien);
  
  strcpy(label,"4");
  strcpy(description ,"You are in room numero cuatro");
  Room* cuatro = new Room(label,description);
  
  strcpy(label,"5");
  strcpy(description ,"You are in room numero cince");
  Room* cinco = new Room(label,description);
  
  strcpy(label,"6");
  strcpy(description ,"You are in room numero seis");
  Room* seis = new Room(label,description);
  
  strcpy(label,"7");
  strcpy(description ,"You are in room numero siete");
  Room* siete = new Room(label,description);
  strcpy(item,"dog");
  Item* dog = new Item(item);
  siete->addItem(dog);
  
  strcpy(label,"8");
  strcpy(description ,"You are in room numero ocho");
  Room* ocho = new Room(label,description);
  
  strcpy(label,"9");
  strcpy(description ,"You are in room numero nueve");
  Room* nueve = new Room(label,description);
  
  strcpy(label,"10");
  strcpy(description ,"You are in room numero diez");
  Room* diez = new Room(label,description);
  strcpy(item,"monkey");
  Item* monkey = new Item(item);
  diez->addItem(monkey);
  
  strcpy(label,"11");
  strcpy(description ,"You are in room numero once");
  Room* once = new Room(label,description);
  strcpy(item,"trophy");
  Item* trophy = new Item(item);
  once->addItem(trophy);
  
  strcpy(label,"12");
  strcpy(description ,"You are in room numero doce");
  Room* doce = new Room(label,description);
  
  strcpy(label,"13");
  strcpy(description ,"You are in room numero trece");
  Room* trece = new Room(label,description);
  strcpy(item,"cat");
  Item* cat = new Item(item);
  trece->addItem(cat);
  
  strcpy(label,"14");
  strcpy(description ,"You are in room numero catorce");
  Room* catorce = new Room(label,description);
  
  strcpy(label,"15");
  strcpy(description ,"You are in room numero quince");
  Room* quince = new Room(label,description);

  uno->addNeighbor(north, dos);
  dos->addNeighbor(north, tres);
  dos->addNeighbor(south, uno);
  dos->addNeighbor(east, cinco);
  dos->addNeighbor(west, doce);
  tres->addNeighbor(east, cuatro);
  tres->addNeighbor(south, dos);
  cuatro->addNeighbor(west,tres);
  cuatro->addNeighbor(south,cinco);
  cinco->addNeighbor(north, cuatro);
  cinco->addNeighbor(west, dos);
  cinco->addNeighbor(south, seis);
  cinco->addNeighbor(east,siete);
  seis->addNeighbor(north, cinco);
  seis->addNeighbor(south, ocho);
  siete->addNeighbor(west,cinco);
  ocho->addNeighbor(north, seis);
  ocho->addNeighbor(east,trece);
  ocho->addNeighbor(west, nueve);
  nueve->addNeighbor(west, once);
  nueve->addNeighbor(south, diez);
  nueve->addNeighbor(east,ocho);
  diez->addNeighbor(north, nueve);
  once->addNeighbor(east, nueve);
  doce->addNeighbor(east, dos);
  doce->addNeighbor(north, quince);
  trece->addNeighbor(south, catorce);
  trece->addNeighbor(west, ocho);
  catorce->addNeighbor(north, trece);
  quince->addNeighbor(south, doce);

  rooms.push_back(uno);
  rooms.push_back(dos);
  rooms.push_back(tres);
  rooms.push_back(cuatro);
  rooms.push_back(cinco);
  rooms.push_back(seis);
  rooms.push_back(siete);
  rooms.push_back(ocho);
  rooms.push_back(nueve);
  rooms.push_back(diez);
  rooms.push_back(once);
  rooms.push_back(doce);
  rooms.push_back(trece);
  rooms.push_back(catorce);
  rooms.push_back(quince);

  Room* currentRoom = uno;
  bool won = false;
  char input[10];
  cout << "ZUUL"<< endl;
  while(!won){
    cout << endl;
    printRoom(currentRoom,inventory);
    
    cout << "type go, drop, add, or quit" << endl;
    cin.get(input,10);
    cin.get();
    if(input[0]=='q' || input[0]=='Q'){
      cout << "good game" << endl;
      break;
    }
    else if(input[0]=='g' || input[0]=='G'){
      char exit[10];
      cout << "type which exit you would like to use" << endl;
      cin.get(exit,10);
      cin.get();
      if(currentRoom->getNextRoom(exit)!=NULL){
	currentRoom = currentRoom->getNextRoom(exit);
      }
      else{
	cout << "no exit" << endl;
      }
    }
    else if(input[0]=='a' || input[0]=='A'){
      char itemName[10];
      cout << "what items do you want to pickup" << endl;
      cin.get(itemName,10);
      cin.get();
      addItem(currentRoom, itemName,inventory);
    }
    else if(input[0]=='d' || input[0]=='D'){
      char itemName[10];
      cout << "what items do you want to drop" << endl;
      cin.get(itemName,10);
      cin.get();
      dropItem(itemName,currentRoom, inventory);
    }
  }
    
  return 0;
}
void addItem(Room* currentRoom, char* itemName1, vector<Item*> &inventory1){
  if(currentRoom->getItem(itemName1)!= 0){
    inventory1.push_back(currentRoom->getItem(itemName1));
    currentRoom->removeItem(itemName1);
  }
  else{
    cout << "item not here" << endl;
  }
}

void printRoom(Room* toPrint, vector<Item*> inventory1){
  char print[150];
  strcpy(print,(toPrint->getInfo()));
  cout << endl;
  cout << endl;
  cout << print << endl;
  toPrint->printItems();
  cout << "Exits: " << endl;
  toPrint->printExits();
  cout << endl;
  cout << "Your inventory: " << endl;
  printInventory(inventory1);
  cout << endl;
  cout << endl;
}

void printInventory(vector<Item*> inventory){
  for(vector<Item*>::iterator itr=inventory.begin();                   itr!=inventory.end(); itr++){
    cout << (*itr)->getItemName() << " ";
  }
}

void dropItem(char* item, Room* currentRoom, vector<Item*> &inventory){

}