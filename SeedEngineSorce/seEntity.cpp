#include "seEntity.h"

namespace se
{
	Entity::Entity()
		: mName(L"")
	{

	}
	Entity::Entity(const std::wstring& name)
		: mName(name)
	{
	}
	Entity::~Entity()
	{
	}
}