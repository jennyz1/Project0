/*****************************************
 ** File: Country.cpp
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author: Jenny Zhang
 ** Date: 9/13/16
 ** Section: 03
 ** E-mail: jennyz1@umbc.edu
 **
 ** This file contains the methods for the Country class. Which the Country
 ** object is made with pre-entered parameters. It hold the methods that 
 ** will allow the inheritated class , Continent, access private variables
 ** of Country objects.
 ***********************************************/
#include <iostream>
#include <string>
using namespace std;

#include "Country.h"
Country::Country () {
}

Country::Country(string name, long population, float LRate, float PCFemale, float PCMale, float PCTotal, float EGDPS, float YLRFemale, float YLRMale) {
  m_name = name;
  m_population = population;
  m_literacyRate = LRate;
  m_primaryCompletionFemale = PCFemale;
  m_primaryCompletionMale = PCMale;
  m_primaryCompletionTotal = PCTotal;
  m_educationGDPSpent = EGDPS;
  m_youthLitRateFem = YLRFemale;
  m_youthLitRateMale = YLRMale;
}
								     
//getter functions

string Country::getName() const {
  return m_name;
}

long Country::getPopulation() const {
  return m_population;
}

float Country::getLiteracyRate() const {
  return m_literacyRate;
}
float Country::getPrimaryCompletionFemale() const {
  return m_primaryCompletionFemale;
}

float Country::getPrimaryCompletionMale() const {
  return m_primaryCompletionMale;
}

float Country::getPrimaryCompletionTotal() const {
  return m_primaryCompletionTotal;
}

float Country::getEducationGDPSpent() const {
  return m_educationGDPSpent;
}

float Country::getYouthLitRateFem() const {
  return m_youthLitRateFem;
}
float Country::getYouthLitRateMale() const {
  return m_youthLitRateMale;
}

//setter functions
void Country::setName( const string name) {
  m_name = name;
}

void Country::setPopulation( const long population) {
  m_population = population;
}

void Country::setLiteracyRate (const float LRate) {
  m_literacyRate = LRate;
}
void Country::setPrimaryCompletionFemale( const float PCFemale ) {
  m_primaryCompletionFemale = PCFemale;
}

void Country::setPrimaryCompletionMale( const float PCMale ) {
  m_primaryCompletionMale = PCMale;
}

void Country::setPrimaryCompletionTotal( const float PCTotal ) {
  m_primaryCompletionTotal = PCTotal;
}

void Country::setEducationGDPSpent( const float EGDPS) {
  m_educationGDPSpent = EGDPS;
}

void Country::setYouthLitRateFem( const float YLRFemale) {
  m_youthLitRateFem = YLRFemale;
}

void Country::setYouthLitRateMale( const float YLRMale) {
  m_youthLitRateMale = YLRMale;
}
