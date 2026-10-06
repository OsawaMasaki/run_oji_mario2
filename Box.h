#pragma once
#include "Engine/GameObject.h"
#include "Engine/Transform.h"

struct AABB {
	XMFLOAT3 min;
	XMFLOAT3 max;
};

class Box : public GameObject {
public:
	Box(GameObject* parent);
	~Box() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	AABB GetCollider() const;

private:
	int hModel_;
};