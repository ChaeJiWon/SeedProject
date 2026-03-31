#include "seCamera.h"
#include "seGameObject.h"
#include "seTransform.h"
#include "seApplication.h"

namespace se
{
	Matrix Camera::ViewMatrix = Matrix::Identity;
	Matrix Camera::ProjectionMatrix = Matrix::Identity;

	Camera::Camera(HWND hwnd)
		: Component(eComponentType::Camera)
		, mHwnd(hwnd)
		, mProjectionType(eProjectionType::Perspective)
		, mViewMatrix(Matrix::Identity)
		, mProjectionMatrix(Matrix::Identity)
		, mAspectRatio(0.0f)
		, mNear(1.0f)
		, mFar(1000.0f)
		, mSize(1.0f)
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::Initialize()
	{
		
	}

	void Camera::Update()
	{
	}

	void Camera::LateUpdate()
	{
		CreateViewMatrix();
		CreateProjectionMatrix(mProjectionType);

		ViewMatrix = mViewMatrix;
		ProjectionMatrix = mProjectionMatrix;
	}

	void Camera::Render()
	{
	}

	void Camera::CreateViewMatrix()
	{
		const Transform* tr = GetOwner()->GetComponent<Transform>();

		const Vector3 pos = tr->GetPosition();
		const Vector3 up = tr->Up();
		const Vector3 forward = tr->Forward();

		mViewMatrix = Matrix::CreateLookToLH(pos, forward, up);


	}

	void Camera::CreateProjectionMatrix(eProjectionType type)
	{
		RECT winRect = {};
		GetClientRect(mHwnd, &winRect);

		const float width = static_cast<float>(winRect.right - winRect.left);
		const float height = static_cast<float>(winRect.bottom - winRect.top);
		mAspectRatio = width / height;

		switch (type)
		{
		case eProjectionType::Perspective:
			mProjectionMatrix = Matrix::CreatePerspectiveFieldOfViewLH(XM_2PI / 6.0f, mAspectRatio, mNear, mFar);
			break;
		case eProjectionType::Orthographic:
			mProjectionMatrix = Matrix::CreateOrthographicLH(width / mSize, height / mSize, mNear, mFar);
			break;
		}
	}
}