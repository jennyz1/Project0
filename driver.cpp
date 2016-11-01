/*****************************************
 ** File: driver.cpp
 ** Project: CMSC 341 Project 0, Fall 2016
 ** Author: Jenny Zhang
 ** Date: 9/13/16
 ** Section: 03
 ** E-mail: jennyz1@umbc.edu
 **
 ** This file contains the implemtations of the Continent and Country class.
 ** It will read though a file to create Continent objects, then another
 ** file to create Country objects that will hold the statistics. It will
 ** place the countries into the right continents based on the file.
 ** When added Continent will change it's private variables. And after all
 ** countries are sorted, will output the highest statistics of each
 ** continent. 
 ***********************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <sstream>
using namespace std;

#include "Continent.h"
#include "Country.h"

int main() {
  
  vector<Continent> world;

  //read the second file and creates the continent objects.
  ifstream inFile2;
  inFile2.open("CountriesContinents.txt");
  if (inFile2.fail()) {
    cout << "The file was not successfully open." << endl;
    exit(1);
  }  
  //finds the lines with the continent names, parses them and push them into the world vector.
  string line2;
  string buf2;
  int numCont = 0;
  int lineNum = 0;
  //vector<int> lineOfContinent: a vector that holds the lines of where the continents were found on the file. For use when adding the countries to their corresponding continent vector.
  vector<int> lineOfContinent;
  while (getline(inFile2,line2)) {
    lineNum++;
    int lineOfCont = line2.find("--");
    if (lineOfCont != -1) {
      vector<string> continentName;
      stringstream ss(line2);
      while (ss >> buf2) {
	continentName.push_back(buf2);
	}
      Continent continent;
      continent.setName(continentName[0]);
      lineOfContinent.push_back(lineNum);
      world.push_back(continent);
      numCont++;
    }
  }
  lineOfContinent.push_back(lineNum);
  // opens the first document with the statistics. Creates the country object that holds the data.
  ifstream inFile;
  inFile.open("2013WorldBankEducationCensusData.txt");
  if (inFile.fail()) {
    cout << "The file was not successfully open." << endl;
    exit(1);
  }
  //reads the file line by line and seperates the line by spaces and placese those elements in a vector of strings
  string line;
  string buf;
  while (getline(inFile,line)) {
    stringstream ss(line);
    vector<string> data;
    int size = 0;
    while (ss >> buf) {
      data.push_back(buf);
      size++;
    }
    for (int i = 0; i < size; i++) {
      if (data[i] == "N/A" ) {
	data[i] = "-1";
      }
    }
    // sets the strings of data into their correct values
    string name = data[0];
    long population = atol(data[1].c_str());
    float lRate = atof(data[2].c_str());
    float pCFemale = atof(data[3].c_str());
    float pCMale = atof(data[4].c_str()); 
    float pCTotal = atof(data[5].c_str()); 
    float eGDPS = atof(data[6].c_str());
    float yLRFem = atof(data[7].c_str());
    float yLRMale = atof(data[8].c_str());
    
    Country country(name, population, lRate, pCFemale, pCMale, pCTotal, eGDPS, yLRFem, yLRMale);
    //resets the position in the file so it can be read again.
    inFile2.clear();
    inFile2.seekg(0, inFile2.beg);

    //moves the country to it's correct continent, setting the popoulation of the continent as well.
    int lineOfCountry = 1;
    while (getline(inFile2,line2)) {
      if (line2 == country.getName()) {
	int t = 0;
	while (t < (numCont + 1)) {
	  if ( lineOfCountry - lineOfContinent[t] < 0) {
	    //adds the country to the continents vector of countries.
	    world[t - 1].setVectorCountry(country);
	    // cout << country.getLiteracyRate() << endl;
	    //adds the the new population into the old one.
	    long newPopulation = world[t - 1].getPopulation() + country.getPopulation();   
	    world[t - 1].setPopulation(newPopulation);
	    world[t - 1].setHighestLiteracyRate(country);
	    Country highestLR = world[t - 1].getHighestLiteracyRate();
	    // cout << highestLR.getLiteracyRate() << endl;
	    t = numCont + 2;
	  }
	  else {
	    t++;
	  }
	}
      }
      else {
      lineOfCountry++;
      }
    }
  }  

  for (unsigned int l = 0; l < world.size(); l++) {
    cout << world[l]; 
  }
}





















