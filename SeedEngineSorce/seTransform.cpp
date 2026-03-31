#include "seTransform.h"
#include "seGraphics.h"
#include "seCamera.h"

namespace se
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mParent(nullptr)
		, mWorldMatrix(Matrix::Identity)
		, mPosition(Vector3::Zero)
		, mRotation(Vector3::Zero)
		, mScale(Vector3::One)
		,mForward(Vector3::One)
		,mRight(Vector3::One)
		,mUp(Vector3::One)
	{
	}

	Transform::~Transform()
	{
	}

	void Transform::Initialize()
	{
	}

	void Transform::Update()
	{

	}

	void Transform::LateUpdate()
	{
		Matrix scale = Matrix::CreateScale(mScale.x, mScale.y, mScale.z);
		Matrix rotation = Matrix::CreateRotationX(math::Radian(mRotation.x));
		rotation *= Matrix::CreateRotationY(math::Radian(mRotation.y));
		rotation *= Matrix::CreateRotationZ(math::Radian(mRotation.z));
		Matrix translation = Matrix::CreateTranslation(mPosition);

		mWorldMatrix = scale * rotation * translation;

		mForward = Vector3::TransformNormal(Vector3::Forward, rotation);
		mRight = Vector3::TransformNormal(Vector3::Right, rotation);
		mUp = Vector3::TransformNormal(Vector3::Up, rotation);
	}

	void Transform::Render()
	{

	}

	void Transform::Bind() const
	{
		graphics::TransformCB cbData = {};
		cbData.World = GetWorldMatrix();
		cbData.View = Camera::GetGpuViewMatrix();
		cbData.Projection = Camera::GetGpuProjectionMatrix();

		// graphics::ConstantBuffer* cb = renderer::constantBuffers[CBSLOT_TRANSFORM];
		// 
		// cb->SetData(&cbData);
		// cb->Bind(eShaderStage::All);
	}
}