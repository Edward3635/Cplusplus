#ifndef INSURANCEPOLICY_H
#define INSURANCEPOLICY_H

#include <ctime>
#include <iostream>

class InsurancePolicy
{
    public:
        InsurancePolicy();
        ~InsurancePolicy();

        int getId() const;
        void setId(int id);

        std::time_t getStartDate() const;
        void setStartDate(std::time_t startDate);

        std::time_t getEndDate() const;
        void setEndDate(std::time_t endDate);

        double getCost() const;
        void setCost(double cost);

        double getPayment() const;
        void setPayment(double payment);

        bool isExpired() const;
        void setIsExoired(bool isExpired);

        bool isPaid() const;
        void setIsPaid(bool isPaid);

        int getPolicyTypeId() const;
        void setPolicyTypeId(int id);

        int getClientId() const;
        void setClientId(int id);

        int getEmployeeId() const;
        void setEmployeeId(int id);

        std::string toString() const;

        std::string sendMessage();

        double calculatePriceWithPolicyType();

    protected:
        int pId;
        std::time_t pStartDate;
        std::time_t pEndDate;
        double pCost;    // вартість
        double pPayment; // виплата
        bool pIsExpired;
        bool pIsPaid;
        int pPolicyTypeId;
        int pClinetId;
        int pEmployeeId;
};

#endif // INSURANCEPOLICY_H
