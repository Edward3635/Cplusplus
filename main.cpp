#include <iostream>
#include "InsurancePolicy.h"
 #include <ctime>

using namespace std;


int main()
{
    InsurancePolicy policy;// stack based
    policy.setId(2);
    policy.setCost(5999);
    policy.setPayment(8000);
    policy.setIsExoired(true);
    policy.setIsPaid(true);
    policy.setPolicyTypeId(935);
    policy.setClientId(654);
    policy.setEmployeeId(577);
    int price = policy.calculatePriceWithPolicyType();
    int id = policy.getId();
    int PolTypeId = policy.getPolicyTypeId();
    int idEmp = policy.getEmployeeId();
    cout <<"Your police id - " <<id <<". It will be cost $" <<price
        <<". Policy Type id - "<<PolTypeId << ". Id employee - "
       <<idEmp << "." <<endl;



    //do some assignments (sets)
    //print something to console

    InsurancePolicy* policy2;// heap based
    policy2 = new InsurancePolicy();
    policy2->setId(6);
    policy2->setCost(13000);
    policy2->setPayment(25000);
    policy2->setIsExoired(true);
    policy2->setIsPaid(false);
    policy2->setPolicyTypeId(654);
    policy2->setClientId(164);
    policy2->setEmployeeId(437);
    int price2 = policy2->calculatePriceWithPolicyType();
    int id2 = policy2->getId();
    int PolTypeId2 = policy2->getPolicyTypeId();
    int idEmp2 = policy2->getEmployeeId();
    cout <<"Your police id - " <<id2 <<". It will be cost $" <<price2
        <<". Policy Type id - "<<PolTypeId2 << ". Id employee - "
       <<idEmp2 << "." <<endl;
    delete policy2;
}
