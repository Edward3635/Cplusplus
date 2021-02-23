#include <iostream>
#include <stdexcept>
#include <string>

#include "database.h"

using namespace std;
using namespace Records;

int displayMenu();
void addNewPolicy(Database& inDB);
void getInformation(Database& inDB);

int main()
{
  Database employeeDB;
  bool done = false;

  while (!done) {
    int selection = displayMenu();

    switch (selection) {
    case 1:
      addNewPolicy(employeeDB);
      break;
    case 2:
      getInformation(employeeDB);
      break;
    case 3:
      employeeDB.displayAll();
      break;
    case 4:
      employeeDB.displayCurrent();
      break;
    case 5:
      employeeDB.displayNotPaid();
      break;
    case 0:
      done = true;
      break;
    default:
      cerr << "Unknown command." << endl;
    }
  }
}

int displayMenu()
{
  int selection;

  cout << endl;
  cout << "Employee Database" << endl;
  cout << "-----------------" << endl;
  cout << "1) Add new insurance policy" << endl;
  cout << "2) Get indormation about insurance policy" << endl;
  cout << "3) Display all insurance policies" << endl;
  cout << "4) Display active insurance policies" << endl;
  cout << "5) Display not paid insurance policies" << endl;
  cout << "0) Quit" << endl;
  cout << endl;
  cout << "---> ";

  cin >> selection;

  return selection;
}

void addNewPolicy(Database& inDB)
{
  double cost;
  double payment;
  int startdate;

  try
  {
    cout << "Cost? ";
    cin >> cost;
    cout << "Payment? ";
    cin >> payment;
    cout << "Start day in form yyyyMMdd";
    cin >> startdate;
  }
  catch(std::exception e)
  {
      cerr << "Bad arguments as input" << endl;
  }

  try {
    inDB.addInsurancePolicy(cost, startdate, payment);
  } catch (std::exception ex) {
    cerr << "Unable to add new policy!" << endl;
  }
}

void getInformation(Database& inDB)
{
  int id;

  try
  {
    cout << "Policy id? ";
    cin >> id;
  }
  catch(std::exception e)
  {
      cerr << "Bad arguments as input" << endl;
  }

  try {
    inDB.getInsurancePolicy(id).display();
  } catch (std::exception ex) {
    cerr << "Unable to find policy!" << endl;
  }
}

