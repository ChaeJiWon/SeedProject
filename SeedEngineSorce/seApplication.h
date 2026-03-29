#pragma once
#include "CommonInclude.h"

namespace se
{
	class Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

	private:
		void Update();
		void LateUpdate();
		void Render();
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);

	private:
		HWND mHwnd;
		HDC mHdc;

		UINT mWidth;
		UINT mHeight;
	};
}
