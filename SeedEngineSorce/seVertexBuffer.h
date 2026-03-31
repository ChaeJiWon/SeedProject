#pragma once
#include "seGraphicDevice_DX11.h"

namespace se::graphics
{
	class VertexBuffer : public GpuBuffer
	{
	public:
		VertexBuffer();
		virtual ~VertexBuffer();

		bool Create(const std::vector<Vertex>& vertexes);
		void Bind();
	};
}