/*************************
// Intro. to Object Oriented Programming
// Milestone 3
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name :Jeelkumar Vinodkumar Patel           Date : 02-12-2023           Reason
//Student ID: 115766222
//Student mail: jpatel391@myseneca.ca


//Authentication Declaration:

//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////
*************************/



#pragma once
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
#include "Station.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
    struct Item {
        std::string m_itemName;
        size_t m_serialNumber{ 0 };
        bool m_isFilled{ false };

        Item(const std::string& src) : m_itemName(src) {};
    };

    class CustomerOrder {
        // class CustomerOrder {
    private:
        std::string m_name{};
        std::string m_product{};
        size_t m_cntItem{ 0 };
        Item** m_lstItem{ nullptr };

        static size_t m_widthField;

    public:
        CustomerOrder() {};
        CustomerOrder(const std::string& str);

        // CustomerOrder(const CustomerOrder&) = delete;
        CustomerOrder(const CustomerOrder& src) {
            // throw false;
            throw "copy constructor is delete, cannot do that";
        }

        CustomerOrder& operator=(const CustomerOrder&) = delete;

        // CustomerOrder(CustomerOrder&& src) noexcept { *this = std::move(src); }
        CustomerOrder(CustomerOrder&& src) noexcept;
        CustomerOrder& operator=(CustomerOrder&& src) noexcept;

        bool isOrderFilled() const;
        bool isItemFilled(const std::string& itemName) const;
        void fillItem(Station& station, std::ostream& os);
        void display(std::ostream& os) const;

        ~CustomerOrder();
    };
}  // namespace sdds

#endif