#include "SceneFactory.h"
#include "TitleScene.h"
#include "GameScene.h"

//シーン生成
BaseScene* SceneFactory::CreateScene(const std::string& sceneName) {
	//次のシーンの生成
	BaseScene* newScene = nullptr;

	if (sceneName == "TITLE") {
		newScene = new TitleScene();
	}
	else if (sceneName == "GAME") {
		newScene = new GameScene();
	}
	return newScene;
}