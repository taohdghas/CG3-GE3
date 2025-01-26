#pragma once
class BaseScene
{
public:
	//初期化
	virtual void Initialize() = 0;
	//終了
	virtual void Finalize() = 0;
	//更新
	virtual void Update() = 0;
	//描画
	virtual void Draw() = 0;
	//仮想デストラクタ
	virtual ~BaseScene() = default;
};

