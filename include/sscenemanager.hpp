#ifndef _SSCENEMANAGER_HPP_
#define _SSCENEMANAGER_HPP_

#include "scenecatalog.hpp"

class Scene;

class SSceneManager{
private:
	bool imcool;

public:
	virtual void changeScene(SceneCatalog sceneCatalog) = 0;
	virtual void changeToRuntimeScene(SceneCatalog sceneCatalog) = 0;
	virtual void setLastScene() = 0;
	virtual void setScene(Scene* scene) = 0;
};

#endif