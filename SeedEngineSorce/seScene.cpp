#include "seScene.h"
#include "seLayer.h"
#include "seSceneManager.h"
#include "seGameObject.h"

namespace se
{
	Scene::Scene()
		: mLayers{}
	{
		createLayers();
	}

	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		const std::wstring& sceneName = GetName();
		SceneManager::SetActiveScene(sceneName);
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

	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}

	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType type)
	{
		mLayers[static_cast<UINT>(type)]->AddGameObject(gameObj);
	}

	void Scene::EraseGameObject(GameObject* gameObj)
	{
		enums::eLayerType layerType = gameObj->GetLayerType();
		mLayers[static_cast<UINT>(layerType)]->EraseGameObject(gameObj);
	}

	void Scene::createLayers()
	{
		size_t size = static_cast<UINT>(enums::eLayerType::Max);
		mLayers.resize(size);
		for (size_t i = 0; i <size; i++)
		{
			mLayers[i] = new Layer();
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
		// CollisionManager::Clear();
	}
}