#pragma once
#include "BaseScene.h"
#include <string>
#include <memory>

class AbstractSceneFactory
{
public:
	//仮想デストラクタ
	virtual ~AbstractSceneFactory() = default;
	//シーン生成
	virtual std::unique_ptr<BaseScene> CreateScene(const std::string& sceneNama) = 0;
};
