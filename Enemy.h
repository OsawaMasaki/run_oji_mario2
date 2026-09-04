#pragma once
#include "Engine/GameObject.h"
#include "ground.h"

//class Ground; // 前方宣言

class Enemy :
	public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

private:
	int hModel_;//

	//Ground* ground_;//地面オブジェクトのポインタ
};

