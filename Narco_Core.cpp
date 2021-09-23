#include "inc/Narco_Core.h"

using namespace NARCO;

namespace NARCO
{
	Narco_Core::Narco_Core(HWND windowHandle, HINSTANCE handleInst)
		: mWindowHandle(windowHandle), mHandleInstance(handleInst), mHardware(new D3DHardware()),
		mDisplay(new D3DDisplay(windowHandle, mHardware->GetDevice(), NARCO_INIT_APP_WIDTH, NARCO_INIT_APP_HEIGHT))
	{
		ID3D11Device* device = mHardware->GetDevice();
		unsigned int width = NARCO_INIT_APP_WIDTH;
		unsigned int height = NARCO_INIT_APP_HEIGHT;

		mTexManager.AddTexture2D(new D3DTexture2D(device, DXGI_FORMAT_R32G32B32A32_FLOAT, D3D11_BIND_RENDER_TARGET, D3D11_USAGE_DEFAULT, width, height, 0));
		mTexManager.AddDepthStencil(new D3DDepthStencil(device, D3D11_BIND_SHADER_RESOURCE, D3D11_USAGE_DEFAULT, width, height, 0));


		// 테스트 코드 영역입니다.
		MeshLoader loader(device);

		loader.SetPath("C:/Users/odess/Desktop/Project/Narco/x64/Debug/resources/shiba/shiba.fbx");
		loader.Load();

		Mesh* mesh_shiba = loader.ConvertMesh();
		
	}
	void Narco_Core::Init()
	{
	}
	void Narco_Core::Update(float delta)
	{
		static ID3D11DeviceContext* context = mHardware->GetImmediateContext();

		clearScreen();

	}
	void Narco_Core::Render(float delta)
	{

		mDisplay->Present();

	}
	void Narco_Core::Release()
	{
		delete mHardware;
		delete mDisplay;
	}
	void Narco_Core::clearScreen()
	{
		static ID3D11DeviceContext* context = mHardware->GetImmediateContext();
		static ID3D11RenderTargetView* renderTargetView = mDisplay->GetRenderTargetView();
		
		context->ClearRenderTargetView(renderTargetView, DirectX::Colors::Red);


	}
}
