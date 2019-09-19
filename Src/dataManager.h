/*!
  \file   dataManager.h
  \brief  Import, save, and export all data.
*/
#include <vector>
#include <array>

using namespace std;

typedef struct serie {
  int week;
} serie;

class CourseData {
public:
  void write();
private:
  void askData;
  string name;
  string description;
  string notes;
  int exerciseDay;
  vector<array<string,2>> userContent;
  vector<serie> series;
};
