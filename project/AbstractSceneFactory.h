#pragma once
#include "BaseScene.h"
#include <string>

class AbstractSceneFactory
{
public:
	//仮想デストラクタ
	virtual ~AbstractSceneFactory() = default;
	//シーン生成
	virtual BaseScene* CreateScene(const std::string& sceneNama) = 0;
};
