#pragma once
#include "D3DResourceLeakChecker.h"
#include "WindowsAPI.h"
#include "DirectXBase.h"
#include "Input.h"
#include "SpriteBase.h"
#include "SrvManager.h"
#include "Object3dBase.h"
#include "TextureManager.h"
#include "ModelManager.h"
#include "ImGuiManager.h"
#include "Camera.h"
#include "ParticleManager.h"
#include "ParticleEmitter.h"

class Framework
{
public:
	//初期化
	virtual void Initialize();
    //終了
	virtual void Finalize();
	//毎フレーム更新
	virtual void Update();
	//描画
	virtual void Draw() = 0;
	//終了チェック
	virtual bool IsEndRequst() { return endRequst_; }
    //デストラクタ
	virtual ~Framework() = default;
public:
	//実行
	void Run();
protected:
	D3DResourceLeakChecker leakCheck;
	//WindowsAPIポインタ
	WindowsAPI* windowsAPI = nullptr;
	//DirectXBaseポインタ
	DirectXBase* directxBase = nullptr;
	//Inputポインタ
	Input* input = nullptr;
	//SRVマネージャ
	SrvManager* srvManager = nullptr;
	//ImGuiマネージャ
	ImGuiManager* imguimanager = new ImGuiManager();
	//カメラ
	Camera* camera = new Camera();
	//パーティクルエミッター
	ParticleEmitter* particleEmitter = new ParticleEmitter();
	//ゲーム終了フラグ
	bool endRequst_ = false;
};

