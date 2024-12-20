//
//  main.cpp
//  LLTemplate
//
//  Created by James Shockey on 12/6/16.
//  Copyright © 2016 James Shockey. All rights reserved.
//


/*
 *
 * Linked List lab.
 * - Build a library for singly linked list.
 * - Replace the airport array in main with a Linked List.
 *  - sort the array.
 *
 */


#include <iostream>
#include <fstream>
#include <cmath>
#include "slist.h"


using namespace std;

class Airport
{
public:
    char    code[5];
    double   longitude;
    double   latitude;
   
};



void simpleSortTotal(Airport* s[], int c);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);

int main()
{
    ifstream infile;
    int i=0;
    char cNum[10] ;
    Slist airportArr = new Slist(); // Replace array with Linked List
    int   airportCount;
    //Airport* a[13500];
   
    infile.open ("USAirportCodes.txt", ifstream::in);
    if (infile.is_open())
    {
        int   c=0;
        while (infile.good())
        {
            Airport* airport= new Airport();
            infile.getline(airport->code, 256, ',');
            infile.getline(cNum, 256, ',');
            airport->longitude = atof(cNum);
            infile.getline(cNum, 256, '\n');
            airport->latitude = atof(cNum);
            airportArr.add((void*)airport);
            if (!(c % 1000)){
                //cout << airport->code << " long: " << airport->longitude << " lat: " << airport->latitude <<  endl;
}
            /*
            if (!(c % 1000))
            {
                cout << airportArr[c]->code << " long: " << airportArr[c]->longitude << " lat: " << airportArr[c]->latitude <<  endl;
                cout << airportArr[c+1]->code << endl; //" long: " << airportArr[c+1]->longitude << " lat: " << airportArr[c+1]->latitude <<  endl;                              
            }
            */

           
            i++ ;
            c++;
        }
        airportCount = c-1;
        infile.close();
         for (int c=0; c < airportCount; c++)
            {
                Airport* temp;
                Airport* nixon;
                temp = (Airport*)(((Node*)airportArr.get(c))->data);
                if(c==10657)
                {
                    Airport farthest;
                    for(int j = 0; j<5; j++) 
                    {
                        farthest.code[j] = temp->code[j];
                        farthest.latitude = temp->latitude;
                        farthest.longitude = temp->longitude;
                    }
                    for(int d = 2; d <airportCount; d++) {
                        nixon = (Airport*)(((Node*)airportArr.get(d))->data);
                        if(distanceEarth(nixon->latitude, nixon->longitude, temp->latitude, temp->longitude) <= 100)
                        {
                            cout << nixon->code<<endl;
                        }
        
                        if(distanceEarth(nixon->latitude, nixon->longitude, temp->latitude, temp->longitude)>distanceEarth(farthest.latitude, farthest.longitude, temp->latitude, temp->longitude))
                        {
                            for(int i = 0; i<5; i++) {
                                farthest.code[i] = nixon->code[i];
                                farthest.latitude = nixon->latitude;
                                farthest.longitude = nixon->longitude;
                            }
                        }
                        if(d==airportCount-1) {
                            cout<<"Farthest Airport from AUS: "<<farthest.code;
                        }
                        
                    }
                }
                
            }
            



    }
    else
    {
        cout << "Error opening file";
    }
 


   
}



#define pi 3.14159265358979323846
#define earthRadiusKm 6371.0

// This function converts decimal degrees to radians
double deg2rad(double deg) {
  return (deg * pi / 180);
}

//  This function converts radians to decimal degrees
double rad2deg(double rad) {
  return (rad * 180 / pi);
}


/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}


/*
Provide sort routine on linked list
*/
/*
void simpleSortTotal()
{

}
*/
