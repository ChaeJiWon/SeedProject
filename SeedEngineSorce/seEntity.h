#pragma once
#include "CommonInclude.h"

namespace se
{
	class Entity
	{
	public:
		Entity();
		Entity(const std::wstring& name);
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }

	private:
		std::wstring mName;
	};
}