#include "ImGuiManager.h"
#include "imgui_impl_win32.h"

//初期化
void ImGuiManager::Initialize(WindowsAPI* windowsAPI,DirectXBase* directxBase){
	//ImGuiのコンテキストを生成
	ImGui::CreateContext();
	//ImGuiのスタイルを設定
	ImGui::StyleColorsDark();
	//win32用初期化
	ImGui_ImplWin32_Init(windowsAPI->GetHwnd());
	//////DirectX12用初期化//////
	
	//DierctX12デバイス
	ImGui_ImplWin32_Init(directxBase->Getdevice().Get());
	//バックバッファの数
	ImGui_ImplWin32_Init(directxBase->);
	//RTVのフォーマット

	//SRV用デスクリプタヒープ

	//SRV用のCPUハンドル

	//SRV用のGPUハンドル

}
