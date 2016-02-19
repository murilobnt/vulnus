#ifndef _CUTSCENEDATABASE_H_
#define _CUTSCENEDATABASE_H_

#include <vector>
#include <string>

class CutsceneDatabase{
public:
  CutsceneDatabase();
  std::vector<std::string> getCutsceneById(int id);
};

#endif
