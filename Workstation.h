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
#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H

#include <deque>
#include <iostream>
#include <stdexcept>
#include <string>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation : public Station {
	private:
		std::deque<CustomerOrder> m_orders{};
		Workstation* m_pNextStation = nullptr;

	public:
		Workstation(std::string& src) : Station(src) { m_pNextStation = nullptr; };

		void fill(std::ostream& os);
		bool attemptToMoveOrder();
		void setNextStation(Workstation* station);
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

		// ~Workstation(){};
	};
}  // namespace sdds

#endif