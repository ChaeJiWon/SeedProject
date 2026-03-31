#include "seApplication.h"
#include "seGraphicDevice_DX11.h"
#include "seSceneManager.h"
#include "seRenderer.h"
#include "seResources.h"

namespace se
{
	Application::Application() : mHwnd(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mbLoaded(false)
	{

	}

	Application::~Application()
	{
	}
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;

		AdjustWindowRect(hwnd, width, height);
		// Input::Initialize();
		// Time::Initialize();

		mGraphicDevice = std::make_unique<graphics::GraphicDevice_DX11>();
		mGraphicDevice->Initialize(hwnd, width, height);
	
		renderer::Initialize();
		// Fmod::Initialize();
		// CollisionManager::Initialize();
		// UIManager::Initialize();
		SceneManager::Initialize();
	}

	void Application::AdjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		RECT rect = { 0, 0, static_cast<LONG>(width), static_cast<LONG>(height) };
		::AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(hwnd, true);
	}

	void Application::Run()
	{
		if (mbLoaded == false)
			mbLoaded = true;

		Update();
		LateUpdate();
		Render();

		Destroy();
	}
	void Application::Update()
	{
		// Input::Update();
		// Time::Update();
		// 
		// CollisionManager::Update();
		// UIManager::Update();
		SceneManager::Update();
	}
	void Application::LateUpdate()
	{
		// CollisionManager::LateUpdate();
		// UIManager::LateUpdate();
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		graphics::GetDevice()->ClearRenderTargetView();
		graphics::GetDevice()->ClearDepthStencilView();
		graphics::GetDevice()->BindViewPort(mWidth, mHeight);
		graphics::GetDevice()->BindDefaultRenderTarget();

		// Time::Render();
		// CollisionManager::Render();
		// UIManager::Render();
		SceneManager::Render();
	}
	void Application::Present()
	{
		graphics::GetDevice()->Present();
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release()
	{
		SceneManager::Release();
		// UIManager::Release();
		Resources::Release();
		renderer::Release();
	}
}