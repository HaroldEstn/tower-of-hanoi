#include <iostream>
#include <stack>
using namespace std;

class MyTower {
  public:
    stack<int> tower;
    stack<int> auxTower;
    void pushItem(int item) {
      tower.push(item);
    }

    void popItem() {
      tower.pop();
    }

    void showItem() {
      auxTower = tower;
      while (!auxTower.empty()) {
        cout << auxTower.top() << endl;
        auxTower.pop();
      }
    }

    int showTop() {
      return tower.top();
    }
    
    bool showEmpty() {
      return tower.empty();
    }
    
};


class HanoiGame: public MyTower {
  public:
    
    MyTower towerLeft;
    MyTower towerMiddle;
    MyTower towerRight;
    int option;
    int disk;
    int tempDisk;
    int auxDisk;
    
    void addNumDisks() {
      do {
        system("clear");
        cout << "Type a digit between 3 and 7:" << endl;
        cin >> option;
        system("clear");
      } while (option < 3 || option > 7);

      for (int i = option; i >= 1; i--) {
        towerLeft.pushItem(i);
      }
    }

    void showTowers() {
      cout << "Left Tower:" << endl;
      towerLeft.showItem();
      cout << "-_-_-_-_-_" << endl;
      cout << endl;
      cout << "Middle Tower:" << endl;
      towerMiddle.showItem();
      cout << "-_-_-_-_-_" << endl;
      cout << endl;
      cout << "Right Tower:" << endl;
      towerRight.showItem();
      cout << "-_-_-_-_-_" << endl;
      cout << endl;

    }

    void moveDisk() {
      cout << "Type the disk to move:" << endl;
      cout << "1. Left Tower." << endl;
      cout << "2. Middle Tower." << endl;
      cout << "3. Right Tower." << endl;
      cin >> option;
      system("clear");
      switch(option) {
        case 1:
          if (towerLeft.showEmpty()) {
            system("clear");
            cout << "Left Tower is Empty..." << endl;
            showTowers();
            moveDisk();
          } else {
            cout << "You select the Left Tower." << endl;
            auxDisk = 0;
            setDisk();
          }
          break;
        case 2:
          if (towerMiddle.showEmpty()) {
            system("clear");
            cout << "Middle Tower is Empty..." << endl;
            showTowers();
            moveDisk();
          } else {
            auxDisk = 0;
            cout << "You select the Middel Tower." << endl;
            setDisk();
          }
          break;
        case 3:
          if (towerRight.showEmpty()) {
            system("clear");
            cout << "Right Tower is Empty..." << endl;
            showTowers();
            moveDisk();
          } else {
            auxDisk = 0;
            cout << "You select the Right Tower." << endl;
            setDisk();
          }
          break;
        default:
          cout << "Invalid option..." << endl;
          moveDisk();
      }
    }

    void setDisk() {
      showTowers();
      if ( option == 1 && auxDisk == 0 ) {
        tempDisk = towerLeft.showTop();
        towerLeft.popItem();
      } else if ( option == 2 && auxDisk == 0 ) {
        tempDisk = towerMiddle.showTop();
        towerMiddle.popItem();
      } else if ( option == 3 && auxDisk == 0) {
        tempDisk = towerRight.showTop();
        towerRight.popItem();
      }

      cout << endl;
      cout << "Type tower to place the disk" << endl;
      cout << "1. Left Tower." << endl;
      cout << "2. Middle Tower." << endl;
      cout << "3. Right Tower." << endl;
      cin >> option;
      switch( option ){
        case 1:
          system("clear");
          if ( towerLeft.showEmpty() || towerLeft.showTop() > tempDisk ) {
            cout << "You place the disk in the Left Tower." << endl;
            towerLeft.pushItem(tempDisk); 
          } else {
            cout << "You can't place the disk " << tempDisk << " here try in another Tower." << endl;
            auxDisk = 1;
            setDisk();
          }
          break;
        case 2:
          system("clear");
          if ( towerMiddle.showEmpty() || towerMiddle.showTop() > tempDisk ) {
            cout << "You place the disk in the Middle Tower." << endl;
            towerMiddle.pushItem(tempDisk); 
          } else {
            cout << "You can't place the disk " << tempDisk << " here try in another Tower." << endl;
            auxDisk = 1;
            setDisk();
          }
          break;
        case 3:
          system("clear");
          if ( towerRight.showEmpty() || towerRight.showTop() > tempDisk ) {
            cout << "You place the disk in the Right Tower." << endl;
            towerRight.pushItem(tempDisk); 
          } else {
            cout << "You can't place the disk " << tempDisk << " here try in another Tower." << endl;
            auxDisk = 1;
            setDisk();
          }
          break;
        default:
          cout << "Invalid option." << endl;
      }
      if ( (towerLeft.showEmpty() && towerMiddle.showEmpty()) || (towerLeft.showEmpty() && towerRight.showEmpty()) ) {
        cout << "You Win!!!" << endl;
      } else {
      showTowers();
      moveDisk();
      }
    }
};

int main() {
  HanoiGame myGame;
  myGame.addNumDisks();
  myGame.showTowers();
  myGame.moveDisk();
  return 0;
}
