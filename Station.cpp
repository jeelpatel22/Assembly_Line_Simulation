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



#include "Station.h"

namespace sdds {

    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const std::string& str) {
        // Armchair,    654321,  10,  Upholstered Wing Chair
        // Filing Cabinet | 987654 |  5 | 3-drawer filing cabinet
        size_t pos = 0;
        bool more = true;

        m_id = ++id_generator;

        m_name = extractToken(str, pos, more);
        m_nextSerialNumber = stoul(extractToken(str, pos, more));
        m_quantity = stoul(extractToken(str, pos, more));
        m_description = extractToken(str, pos, more);

        if (m_widthField < getFieldWidth()) {
            m_widthField = (max(m_widthField, m_name.length()));
        }
    }

    void Station::display(std::ostream& os, bool full) const {
        // ID | NAME | SERIAL |
        // os << m_id << endl;
        os << setw(3) << setfill('0') << right << m_id << left << setfill(' ')
            << " | " << setw(m_widthField) << m_name << " | " << setw(6) << right
            << setfill('0') << m_nextSerialNumber << " | " << setfill(' ');
        if (full) {
            // ID | NAME | SERIAL | QUANTITY | DESCRIPTION
            os << setw(4) << m_quantity << left << " | " << m_description;
        }
        os << left << endl;
    }

}  // namespace sdds