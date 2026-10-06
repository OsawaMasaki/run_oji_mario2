#include "Box.h"
#include "Engine/Model.h"

Box::Box(GameObject* parent)
	: GameObject(parent, "Box"), hModel_(-1)
{
}

void Box::Initialize()
{
	hModel_ = Model::Load("Box.fbx");
}

void Box::Update()
{
}

void Box::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Box::Release()
{
}

AABB Box::GetCollider() const
{
	float halfWidth = 1.0f;
	float halfHeight = 0.5f;
	float halfDepth = 0.5f;

	AABB box;
	box.min = {
		transform_.position_.x - halfWidth,
		transform_.position_.y - halfHeight,
		transform_.position_.z - halfDepth
	};
	box.max = {
		transform_.position_.x + halfWidth,
		transform_.position_.y + halfHeight,
		transform_.position_.z + halfDepth
	};

	return box;
}