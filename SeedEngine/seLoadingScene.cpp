#include "seLoadingScene.h"
#include "seRenderer.h"
#include "seSceneManager.h"
#include "seResources.h"
#include "seTexture.h"
#include "seApplication.h"
#include "seRenderer.h"
#include "seSceneManager.h"
#include "seTitleScene.h"
//#include "sePlayScene.h"

extern se::Application application;

namespace se
{
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
		, mMutualExclusion()
		, mResourcesLoadThread()
	{

	}

	LoadingScene::~LoadingScene()
	{
		mResourcesLoadThread->join();

		delete mResourcesLoadThread;
		mResourcesLoadThread = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutualExclusion));

	}

	void LoadingScene::Update()
	{

	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render()
	{
		if (mbLoadCompleted)
			SceneManager::LoadScene(L"PlayScene");
	}

	void LoadingScene::OnEnter()
	{

	}

	void LoadingScene::OnExit()
	{

	}

	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		while (true)
		{
			if (application.IsLoaded() == true)
				break;
		}

		m.lock();
		{
			Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\CloudOcean.png");

			SceneManager::CreateScene<TitleScene>(L"TitleScene");
			// SceneManager::CreateScene<PlayScene>(L"PlayScene");
		}
		m.unlock();

		// complete
		SceneManager::SetActiveScene(L"LoadingScene");
		mbLoadCompleted = true;
	}
}
