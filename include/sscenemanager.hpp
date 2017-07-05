#ifndef _SSCENEMANAGER_HPP_
#define _SSCENEMANAGER_HPP_

#include "scenecatalog.hpp"

class SSceneManager{
private:
	bool imcool;

public:
	virtual void changeScene(SceneCatalog sceneCatalog) = 0;
};

#endif