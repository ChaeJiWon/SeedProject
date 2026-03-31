#pragma once
#include "seResource.h"
#include "seShader.h"
#include "seTexture.h"

namespace se
{
	class Material : public Resource
	{
	public:
		struct Data //Texture names
		{
			std::wstring albedo; //diffuse
		};

		Material();
		virtual ~Material();

		HRESULT Save(const std::wstring& path) override;
		HRESULT Load(const std::wstring& path) override;

		void Bind();
		void BindShader();
		void BindTextures();

		void SetAlbedoTexture(graphics::Texture* texture);
		void SetShader(graphics::Shader* shader) { mShader = shader; }


	private:
		graphics::eRenderingMode mMode;
		Data mData;

		graphics::Texture* mAlbedoTexture;
		graphics::Shader* mShader;
	};
}