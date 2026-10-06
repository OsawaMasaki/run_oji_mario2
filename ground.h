#pragma once
#include "Engine/GameObject.h"
#include <vector>

class Box; // 前方宣言

class Ground : public GameObject
{
public:
	Ground(GameObject* parent);
	~Ground() override = default;

	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	std::vector<std::vector<int>> GetMapData() { return mapData_; }

	// 生成された全Boxのリストを取得する関数
	const std::vector<Box*>& GetBoxes() const { return pBoxes_; }

private:
	int hModel_;
	std::vector<std::vector<int>> mapData_;
	int mapWidth_;
	int mapHeight_;

	std::vector<Box*> pBoxes_; // 生成したBoxのポインタ配列
};