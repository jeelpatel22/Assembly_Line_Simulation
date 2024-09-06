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
#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Utilities.h"

using namespace std;

namespace sdds {
    class Station : public Utilities {
        // class Station {
    private:
        int m_id{};
        std::string m_name{};
        std::string m_description{};
        size_t m_nextSerialNumber{};
        size_t m_quantity{};

        static size_t m_widthField;
        static size_t id_generator;

    public:
        Station(const std::string& str);

        const std::string& getItemName() const { return m_name; }
        size_t getNextSerialNumber() { return m_nextSerialNumber++; }
        size_t getQuantity() const { return m_quantity; }

        void updateQuantity() {
            if (m_quantity > 0)
                m_quantity--;
        }

        void display(std::ostream& os, bool full) const;
    };
}  // namespace sdds

#endif