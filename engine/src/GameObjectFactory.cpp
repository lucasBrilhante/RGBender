#include "GameObjectFactory.h"

#include "BaseCreator.h"
#include "Log.h"
#include <string>
#include <iostream>
#include <map>

using namespace std;
using namespace engine;
bool GameObjectFactory::registerType(string typeID, BaseCreator* pCreator){
	map<string, BaseCreator*>::iterator it = m_creators.find(typeID);

	// if the type is already registered, do nothing
	if(it != m_creators.end()){
		delete pCreator;
		return false;
	} else {
		m_creators[typeID] = pCreator;
		return true;
	}
}

GameObject* GameObjectFactory::create(string typeID){
	map<string, BaseCreator*>::iterator it = m_creators.find(typeID);
	if(it == m_creators.end()){
		INFO("Could not find type " + typeID);
		return NULL;
	} else {
		BaseCreator* pCreator = (*it).second;
		return pCreator->createGameObject();
	}
}


