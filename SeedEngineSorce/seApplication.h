#pragma once
#include "CommonInclude.h"

namespace se
{
	namespace graphics 
	{
		class GraphicDevice_DX11;
	}

	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd, UINT width, UINT height);
		void AdjustWindowRect(HWND hwnd, UINT width, UINT height);

		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void Present();
		void Destroy();
		void Release();

		HWND GetHwnd() const { return mHwnd; }

		UINT GetWidth() const { return mWidth; }
		UINT GetHeight() const { return mHeight; }

		bool IsLoaded() const { return mbLoaded; }
		void IsLoaded(const bool load) { mbLoaded = load; }

	private:
		bool mbLoaded;
		HWND mHwnd;
		std::unique_ptr<graphics::GraphicDevice_DX11> mGraphicDevice;

		UINT mWidth;
		UINT mHeight;
	};
}
