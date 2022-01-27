#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//class
class ToDoItem
{
  private:
  string itemText;
  bool status;
  public:
  ToDoItem()
  {
    setStatus(false);
    setItemText("unknown");
  }
  void setStatus(bool status)
  {
    this -> status = status;
  }
  void setItemText(string itemText)
  {
    this -> itemText = itemText;
  }
  string getItemText()
  {
    return itemText;
  }
  bool getStatus()
  {
    return status;
  }
};
//menu
void menu() 
{
  cout << "\t\tTo Do List:\n";
  cout << "\n 1. Add item\n";
  cout << "\n 2. Toggle item status\n";
  cout << "\n 3. Exit list\n";
  cout << ">>";
}
void sizeincrease(ToDoItem *& items, int size)
{
  ToDoItem *dbl = new ToDoItem[size*2];
  for(int i = 0; i < size; i++)
  {
    dbl[i] = items[i];
  }
  delete[] items;
  items = dbl;
}
//variables
int main()
{
  char choice;
  int size = 5;
  ToDoItem *list = new ToDoItem[size];
  int index = 0;
  do 
  {
    menu();
    cin >> choice;
    cin.ignore();
    switch(choice)
    {
    {
      case '1':
      cout << "Enter your item: ";
      string str;
      getline(cin, str);
      if(index == size)
      {
        sizeincrease(list, size);
        list[index++].setItemText(str);
      }
      else
      {
        list[index++].setItemText(str);
      }
      break;
    }
    case '2':
    {
      int ch, i;
      do
      {
        cout << "Toggle item completion:\n";
        for(i = 0; i < index; i++)
        {
          cout << i+1 << "|" << " ";
          if(list[i].getStatus() == false)
          {
            cout << "Unfinished| ";
          }
          else
          {
            cout << "Finished| ";
          }
          cout << list[i].getItemText() << "\n";
        }
        cout << i+1 << "|" << " Return to menu... \n";
        cout << ">> ";
        cin >> ch;
        ch--;
        if(ch < i)
        {
          if(list[ch].getStatus() == false)
          {
            list[ch].setStatus(true);
          }
          else 
          {
            cout << "Already finished\n";
          }
        }
        else if(ch==i)
        {
          break;
        }
        else
        {
          cout << "Wrong choice\n";
        }
      }
      while(ch!=i);
      break;
      }
      case '3':
      {
        cout << "\t\tList Status:\n";
        cout << "Items\t\t\t\tItem Status\n";
        for(int i = 0; i < index; i++)
        {
          cout << list[i].getItemText() << " ";
          cout << setw(20);
          if(list[i].getStatus() == false)
          {
            cout << "\t\t\tUnfinished ";
          }
          else
          {
            cout << "\tFinished ";
          }
          cout << "\n";
        }
        break;
      }
      case '4':
      {
        cout << "Done\n";
        break;
      }
      default:
      cout << "You enter the wrong choice\n";
      }
    } while(choice!='4');
  }
