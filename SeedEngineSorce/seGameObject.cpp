#include "seGameObject.h"
#include "seComponent.h"

namespace se
{
	GameObject::GameObject()
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Initialize()
	{
		for (Component* component : mComponents)
		{
			if (nullptr == component)
				continue;

			component->Initialize();
		}
	}
	void GameObject::Update()
	{
		for (Component* component : mComponents)
		{
			if (nullptr == component)
				continue;

			component->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		for (Component* component : mComponents)
		{
			if (nullptr == component)
				continue;

			component->LateUpdate();
		}
	}
	void GameObject::Render()
	{
		for (Component* component : mComponents)
		{
			if (nullptr == component)
				continue;

			component->Render();
		}
	}
}