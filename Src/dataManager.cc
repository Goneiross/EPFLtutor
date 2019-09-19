/*!
  \file   dataManager.cc
  \brief  Import, save, and export all data.
*/
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#include "dataManager.h"

void CourseData::write() {
 askData();

}

void CourseData::askData() {
  cout<<"what is the course name ?"<<endl;
  cin>>name;
  system("cls");

  cout<<"what is the course description ?"<<endl;
  cin>>description;
  system("cls");

  do{
    cout<<"on wich day the exercices take place ?"<<endl
     <<"0=Monday --> 4=Friday"<<endl;
    cin>>exerciseDay;
    if(exerciseDay > 5 || exerciseDay < 0){
      cout<<exerciseDay<<" is not a valid day."<<endl;
    }
  }while(!(exerciseDay < 5 && exerciseDay >= 0));
  system("cls");

  char userIntent;
  cout<<"do you want to save specific informations about this course ? y/n"<<endl;
  cin>>userIntent;
  for (int i = 0 ; userIntent == 'y' ; i++) {
    array<string,2> temp;
    cout<<"info name ?"<<endl;
    cin>>temp[0];
    cout<<"information content ?"<<endl;
    cin>>temp[1];
    cout<<temp[0]<<" : "<<temp[1]<<endl;
    userContent.push_back(temp);
    cout<<"do you want to save more informations ? y/n"<<endl;
    cin>>userIntent;
    system("cls");
  }

  cout<<"how many week for this course ?"<<endl;
  unsigned weeks;
  cin>>weeks;
  series.resize(weeks);
  system("cls");

  cout<<"informations saved successfully!"<<endl;
}
