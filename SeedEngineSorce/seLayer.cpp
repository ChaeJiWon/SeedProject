#include "seLayer.h"
#include "seGameObject.h"

namespace se
{
	Layer::Layer()
		: mGameObjects{}
	{

	}
	Layer::~Layer()
	{

	}
	void Layer::Initialize()
	{
		for (GameObject* object : mGameObjects)
		{
			if (nullptr == object)
				continue;

			object->Initialize();
		}
	}
	void Layer::Update()
	{
		for (GameObject* object : mGameObjects)
		{
			if (nullptr == object)
				continue;

			object->Update();
		}
	}
	void Layer::LateUpdate()
	{
		for (GameObject* object : mGameObjects)
		{
			if (nullptr == object)
				continue;

			object->LateUpdate();
		}
	}
	void Layer::Render()
	{
		for (GameObject* object : mGameObjects)
		{
			if (nullptr == object)
				continue;

			object->Render();
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (nullptr == gameObject)
			return;

		mGameObjects.push_back(gameObject);
	}
}