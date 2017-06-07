#include "cutscenedatabase.hpp"

CutsceneDatabase::CutsceneDatabase(){

}

std::vector<std::string> CutsceneDatabase::getCutsceneById(int id) const{
  std::vector<std::string> cutsceneContent;
  std::string currentContent;

  switch (id) {
    case 0:
    currentContent = "This is where it starts... (Press X to continue)";
    cutsceneContent.push_back(currentContent);
    currentContent = "I remember this... I saw this before already.";
    cutsceneContent.push_back(currentContent);
    currentContent = "No, this doesn't make any sense at all.\n I'm only trying to show a cutscene";
    cutsceneContent.push_back(currentContent);
    return cutsceneContent;
    case 1:
    currentContent = "Well, I'm up here!";
    cutsceneContent.push_back(currentContent);
    currentContent = "I feel a little cold, but it's cool";
    cutsceneContent.push_back(currentContent);
    return cutsceneContent;
    default:
    currentContent = "I_AM_AN_ERROR";
    cutsceneContent.push_back(currentContent);
    return cutsceneContent;
  }
}
