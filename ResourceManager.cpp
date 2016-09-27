#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

bool ResourceManager::isLoaded()
{
	return false;
}

size_t ResourceManager::getSize()
{
	return sizeof(this);
}
