/***************************************** 
** File: Continent.cpp 
** Project: CMSC 341 Project 0, Fall 2016 
** Author: Jenny Zhang 
** Date: 9/13/16 
** Section: 03
** E-mail: jennyz1@umbc.edu 
** 
** This file contains the methods for the Continent Class. 
** It will create the Continent object and hold the countries that are 
** in it. Has the overloaded << operator that will print the result in 
** the correct format.
***********************************************/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Continent.h"

Continent::Continent() : Country() {
  
}

//getters
vector<Country> Continent::getVectorCountry() const{
  return countriesInContinent;
}
Country Continent::getHighestPopulation() const {
  return m_highestPopulation;
}
Country Continent::getHighestGDPSpend() const {
  return m_highestGDPSpent;
}
Country Continent::getHighestLiteracyRate() const {
  return m_highestLiteracyRate;
}

//setters
void Continent::setVectorCountry(const Country country) {
  countriesInContinent.push_back(country);
}
void Continent::setHighestPopulation(const Country highestPopulation) {
  m_highestPopulation = highestPopulation;
}
void Continent::setHighestGDPSpend(const Country highestGDPSpend) {
  m_highestGDPSpent = highestGDPSpend;
}
void Continent::setHighestLiteracyRate(const Country highestLiteracyRate) {
  m_highestLiteracyRate = highestLiteracyRate;
}

ostream& operator <<(ostream &outStream, const Continent& continent) {
  cout << continent.getName() << endl;
  /*int size = continent.countriesInContinent.size();
  vector<Country> countryList = continent.countriesInContinent;
  for (int i = 0; i < size; i++) { 
    cout << countryList[i].getName() << endl;
    }*/
  //  Country highestPopulation = continent.getHighestPopulation;
  cout << "Population: " << continent.getPopulation() << endl;
  cout << "Country with the highest literacy rate: " << endl;
  cout << "Country with the highest GPD expenditure on education: " << endl;
  cout << "Country with the highest population: " << /*continent.getHighestPopulation().getName() << "with a population of " << continent.getHighestPopulation().getPopulation()<< " and a literacy rate of " << continent.getHighestPopulation().getLiteracyRate() << "."  << */endl;
  return outStream;
}
