#pragma once
#include <Windows.h>
class WindowsAPI
{
public:
	//静的メンバ関数
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
public:
	//初期化
	void Initialize();
	//更新
	void Update();
private:

};

