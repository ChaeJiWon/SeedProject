#pragma once
#include "seEntity.h"

namespace se
{
	class GameObject;
	class Layer;

	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType type);


	private:
		void createLayers();

	private:
		std::vector<GameObject*> mGameObjects;
		std::vector<Layer*> mLayers;
	};
}