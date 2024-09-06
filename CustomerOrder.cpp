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



#include "CustomerOrder.h"

namespace sdds {

    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& record) {
        Utilities util;
        size_t pos = 0;
        bool more = true;

        m_name = util.extractToken(record, pos, more);
        m_product = util.extractToken(record, pos, more);

        m_cntItem = std::count(record.begin(), record.end(), util.getDelimiter()) - 1;
        m_lstItem = new Item * [m_cntItem];

        for (auto i = 0u; i < m_cntItem; i++) {
            m_lstItem[i] = new Item(util.extractToken(record, pos, more));
        }

        // if (m_widthField < getFieldWidth()) {
        //   m_widthField = (max(m_widthField, m_name.length()));
        // }

        if (m_widthField < util.getFieldWidth()) {
            m_widthField = util.getFieldWidth();
        }
    }

    CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
        *this = std::move(src);
    }

    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) noexcept {
        if (this != &src) {
            for (auto i = 0u; i < m_cntItem; i++) {
                delete m_lstItem[i];
            }
            delete[] m_lstItem;

            m_name = src.m_name;
            m_product = src.m_product;
            m_cntItem = src.m_cntItem;
            m_lstItem = src.m_lstItem;

            src.m_name = "";
            src.m_product = "";
            src.m_cntItem = 0;
            src.m_lstItem = nullptr;
        }
        return *this;
    }

    bool CustomerOrder::isOrderFilled() const {
        bool res{ true };
        for (auto i = 0u; i < m_cntItem; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                res = false;
            }
        }
        return res;
    }

    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        for (auto i = 0u; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
                return false;
            }
        }
        // If the item doesn't exist in the order, this query returns true
        return true;
    }

    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        bool haveSeen{ false };
        for (auto i = 0u; i < m_cntItem && !haveSeen; i++) {
            // if (station.getItemName() == m_lstItem[i]->m_itemName &&
            // !m_lstItem[i]->m_isFilled && m_cntItem > 0) {
            if (station.getItemName() == m_lstItem[i]->m_itemName &&
                !m_lstItem[i]->m_isFilled) {
                if (station.getQuantity() > 0) {
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    station.updateQuantity();
                    haveSeen = true;

                    os << "    Filled " << m_name << ", " << m_product << " ["
                        << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
                else {
                    os << "    Unable to fill " << m_name << ", " << m_product << " ["
                        << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }

    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (auto i = 0u; i < m_cntItem; i++) {
            os << "[" << std::setw(6) << std::setfill('0') << right
                << m_lstItem[i]->m_serialNumber << "] " << std::setfill(' ')
                << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName
                << " - ";
            if (m_lstItem[i]->m_isFilled) {
                os << "FILLED" << std::endl;
            }
            else {
                os << "TO BE FILLED" << std::endl;
            }
        }
    }

    CustomerOrder::~CustomerOrder() {
        for (auto i = 0u; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
    }

}  // namespace sdds