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
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, enums::eLayerType type);
		void EraseGameObject(GameObject* gameObj);
		Layer* GetLayer(const enums::eLayerType type) const { return mLayers[static_cast<UINT>(type)]; }

	private:
		void createLayers();

		std::vector<Layer*> mLayers;
	};



}