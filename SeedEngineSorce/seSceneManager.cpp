#include "seSceneManager.h"
#include "seScene.h"

namespace se
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		if (nullptr == mActiveScene)
			return;
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		if (nullptr == mActiveScene)
			return;
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render()
	{
		if (nullptr == mActiveScene)
			return;
		mActiveScene->Render();
	}
}