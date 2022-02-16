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
    
    void addNumDisks() {
      do {
        system("clear");
        cout << "Type a digit between 3 and 7:" << endl;
        cin >> option;
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
      switch(option) {
        case 1:
          if (towerLeft.showEmpty()) {
            system("clear");
            cout << "Left Tower is Empty..." << endl;
            showTowers();
            moveDisk();
          } else {
            cout << "You select the Left Tower." << endl;
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
      if ( option == 1 ) {
        tempDisk = towerLeft.showTop();
        towerLeft.popItem();
      } else if ( option == 2 ) {
        tempDisk = towerMiddle.showTop();
        towerMiddle.popItem();
      } else if ( option == 3 ) {
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
          cout << "You place the disk in the Left Tower." << endl;
          towerLeft.pushItem(tempDisk); 
          break;
        case 2:
          cout << "You place the disk in the Middle Tower." << endl;
          towerMiddle.pushItem(tempDisk); 
          break;
        case 3:
          cout << "You place the disk in the Right Tower." << endl;
          towerRight.pushItem(tempDisk); 
          break;
        default:
          cout << "Invalid option." << endl;
      }
      showTowers();
      moveDisk();
    }
};

int main() {
  HanoiGame myGame;
  myGame.addNumDisks();
  myGame.showTowers();
  myGame.moveDisk();
  return 0;
}
