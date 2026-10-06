#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Box.h"

namespace
{
	using std::vector;
	const float GROUND_WIDTH = 20.0f;
	const float GROUND_Y = 0.0f;
	const float GROUND_Z = 1.0f;
	const float GROUND_ROTATE_X = -90.0f;
	const float BLOCK_INTERVAL_X = 2.0f;
	const float BLOCK_INTERVAL_Y = 1.0f;
	const float BACK_SIZE = 2.222f;
}

Ground::Ground(GameObject* parent)
	: GameObject(parent, "Ground"), hModel_(-1), mapWidth_(-1), mapHeight_(-1)
{
	CsvReader csvData;
	csvData.Load("map.csv");
	mapWidth_ = csvData.GetWidth();
	mapHeight_ = csvData.GetHeight();

	mapData_ = vector<vector<int>>(mapHeight_, vector<int>(mapWidth_, 0));
	for (int x = 0; x < mapWidth_; x++)
	{
		for (int y = 0; y < mapHeight_; y++)
		{
			mapData_[y][x] = csvData.GetValue(x, y);
		}
	}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("haikei.fbx");

	// CSVデータを元にBoxオブジェクトを生成
	for (int j = 0; j < mapHeight_; j++) {
		for (int i = 0; i < mapWidth_; i++) {
			if (mapData_[j][i] == 1) 
			{
				Box* box = new Box(this);

				// 直接 transform_ を触らずに関数でセットする
				box->SetPosition({
					i * BLOCK_INTERVAL_X,
					(mapHeight_ - 1 - j) * BLOCK_INTERVAL_Y,
					0.0f
					});

				box->Initialize();
				pBoxes_.push_back(box);
			}
		}
	}
}

void Ground::Update()
{
}

void Ground::Draw()
{
	// 背景の描画
	for (int i = 0; i < 3; i++) {
		transform_.position_ = { 0 + GROUND_WIDTH * i, GROUND_Y, GROUND_Z };
		transform_.scale_ = { BACK_SIZE, BACK_SIZE, BACK_SIZE };
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
	}
}

void Ground::Release()
{
	// 生成したBoxのメモリ解放（親クラスで自動削除されない場合）
	for (Box* box : pBoxes_) {
		if (box) {
			box->Release();
			delete box;
		}
	}
	pBoxes_.clear();
}