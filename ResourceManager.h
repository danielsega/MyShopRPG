#ifndef _RESOURCE_MANAGER_
#define _RESOURCE_MANAGER_

#include "cocos2d.h"

enum class ResourceType
{
	RESOURCE_NULL = 0,
	RESOURCE_GRAPHIC = 1,
	RESOURCE_MUSIC = 2,
	RESOURCE_AUDIO = 3,
	RESOURCE_TEXT = 4,
};

class ResourceManager
{
public:
	ResourceManager();
	virtual ~ResourceManager();

	bool isLoaded();
	size_t getSize();

	bool load();
	bool reload();
	bool unload();

	void clear();
	void findSourceByID();
};

#endif
