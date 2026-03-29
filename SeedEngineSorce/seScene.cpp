#include "seScene.h"
#include "seLayer.h"

namespace se
{
	Scene::Scene()
		: mLayers{}
	{
		
	}
	Scene::~Scene()
	{
		mGameObjects.clear();
	}
	void Scene::Initialize()
	{
		createLayers();
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->LateUpdate();
		}
	}
	void Scene::Render()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Render();
		}
	}
	void Scene::OnEnter()
	{
	}
	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[static_cast<UINT>(type)]->AddGameObject(gameObj);
	}
	void Scene::createLayers()
	{
		size_t layerCount = static_cast<size_t>(enums::eLayerType::Max);
		mLayers.resize(layerCount);
		for (size_t i = 0; i < layerCount; ++i)
		{
			mLayers[i] = new Layer();
		}
	}
	
}