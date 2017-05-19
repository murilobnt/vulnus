#ifndef _CUTSCENEDATABASE_HPP_
#define _CUTSCENEDATABASE_HPP_

// # External
#include <vector>
#include <string>

class CutsceneDatabase{
public:
  /**
   * Constructor.
   */
  CutsceneDatabase();

  /**
   * Get the cutscene based on its id.
   * @param id the id of the cutscene
   * @return the cutscene text with the id
   */
  std::vector<std::string> getCutsceneById(int id);
};

#endif
