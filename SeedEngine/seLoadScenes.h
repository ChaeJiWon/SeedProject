#pragma once
#include "..//SeedEngineSorce//seSceneManager.h"

#include "seLoadingScene.h"
//#include "sePlayScene.h"
//#include "seTitleScene.h"


namespace se
{
	void LoadScenes()
	{
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}
