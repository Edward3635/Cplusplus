// Database.cpp

#include <iostream>
#include <stdexcept>
#include <string>

#include "database.h"

using namespace std;

namespace Records {

  Database::Database()
  {
    mNextSlot = 0;
    mNextId = kFirstPolicyId;
  }

  Database::~Database()
  {
  }

  InsurancePolicy& Database::addInsurancePolicy(double inCost, int inStartDate, double inPayment)
  {
    if (mNextSlot >= kMaxPolicies) {
      cerr << "There is no more room to add the new employee!" << endl;
      throw exception();
    }

    InsurancePolicy& policy = mInsurancePolicies[mNextSlot++];
    policy.setId(mNextId++);
    policy.setCost(inCost);
    policy.setPayment(inPayment);
    policy.setStartDate(inStartDate);

    return policy;
  }

  InsurancePolicy& Database::getInsurancePolicy(int inId)
  {
    for (int i = 0; i < mNextSlot; i++)
    {
      if (mInsurancePolicies[i].getId() == inId)
      {
          return mInsurancePolicies[i];
      }
    }

    cerr << "No employee with employee number " << inId << endl;
    throw exception();
  }

  void Database::displayAll()
  {
    for (int i = 0; i < mNextSlot; i++) {
      mInsurancePolicies[i].display();
    }
  }

  void Database::displayCurrent()
  {
    for (int i = 0; i < mNextSlot; i++)
    {
      if (!mInsurancePolicies[i].isExpired(20210223))
      {
          mInsurancePolicies[i].display();
      }
    }
  }

  void Database::displayNotPaid()
  {
    for (int i = 0; i < mNextSlot; i++)
    {
      if (!mInsurancePolicies[i].isPaid())
      {
          mInsurancePolicies[i].display();
      }
    }
  }
}
