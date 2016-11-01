/*****************************************
 ** File: Continent.h
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author: Jenny Zhang
 ** Date: 9/13/16
 ** Section: 03
 ** E-mail: jennyz1@umbc.edu
 **
 ** This file contains the implementations of the Continent Class, which is 
 ** derived from the Country class. Continent hold a vectors with the 
 ** countries in it. 
***********************************************/
#ifndef CONTINENT_H
#define CONTINENT_H

#include "Country.h"

class Continent: public Country {
 public:
  //constructor
 Continent();

  //getters
  vector<Country> getVectorCountry() const;
  Country getHighestPopulation() const;
  Country getHighestGDPSpend() const;
  Country getHighestLiteracyRate() const;

  //setters
  void setVectorCountry(const Country country);
  void setHighestPopulation(const Country highestPopulation);
  void setHighestGDPSpend(const Country highestGDPSpend);
  void setHighestLiteracyRate(const Country highestLiteracyRate);

  friend ostream& operator <<(ostream &outStream, const Continent& continent);

 private:
  vector<Country> countriesInContinent;
  Country m_highestPopulation;
  Country m_highestGDPSpent;
  Country m_highestLiteracyRate;
};

#endif
