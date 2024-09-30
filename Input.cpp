#include "Input.h"
#include <cassert>

#pragma comment(lib,"dinput8.lib")
#pragma comment(lib,"dxguid.lib")

void Input::Initialize(HINSTANCE hInstance,HWND hwnd) {
	HRESULT result;

	//DirectInputのインスタンス生成
	result = DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8,
		(void**)&directInput, nullptr);
	assert(SUCCEEDED(result));
	//キーボードデバイス生成
	result = directInput->CreateDevice(GUID_SysKeyboard, &keyboard, NULL);
	assert(SUCCEEDED(result));
	//入力データ形式のセット
	result = keyboard->SetDataFormat(&c_dfDIKeyboard);
	assert(SUCCEEDED(result));
	//排他制御レベルのセット
	result = keyboard->SetCooperativeLevel(hwnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE | DISCL_NOWINKEY);
	assert(SUCCEEDED(result));
}

void Input::Update() {
	//前回のキー入力を保存
	memcpy(keyPre, key, sizeof(key));
	//キーボード情報の取得開始
	keyboard->Acquire();
	keyboard->GetDeviceState(sizeof(key), key);
}

bool Input::PushKey(BYTE keyNumber) {
	//指定キーを押していればtrueを返す
	if (key[keyNumber]) {
		return true;
	}
	return false;
}

bool Input::TriggerKey(BYTE keyNumber) {
	if (keyPre[keyNumber] == 0 && key[keyNumber] != 0) {
		return true;
	}
	return false;
}
