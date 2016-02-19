#include "CutsceneDatabase.h"

CutsceneDatabase::CutsceneDatabase(){

}

std::vector<std::string> CutsceneDatabase::getCutsceneById(int id){
  std::vector<std::string> cutsceneContent;
  std::string currentContent;

  switch (id) {
    case 0:
    currentContent = "This is where it starts... (Press X to continue)";
    cutsceneContent.push_back(currentContent);
    currentContent = "I remember this... I saw this before already.";
    cutsceneContent.push_back(currentContent);
    currentContent = "No, this don't make any sense at all.\n I'm only trying to show a cutscene";
    cutsceneContent.push_back(currentContent);
    return cutsceneContent;
    break;
    case 1:
    currentContent = "Bom... Cheguei aqui em cima!";
    cutsceneContent.push_back(currentContent);
    currentContent = "Sinto um pouco de frio, mas nada muito forte...";
    cutsceneContent.push_back(currentContent);
    return cutsceneContent;
  }
}
