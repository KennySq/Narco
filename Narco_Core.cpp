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

		mGBuffer = new GBuffer(device, width, height);

		// 테스트 코드 영역입니다.
		MeshLoader loader(device);

		loader.SetPath("C:/Users/odess/Desktop/Project/Narco/x64/Debug/resources/shiba/shiba.fbx");
		loader.Load();

		Mesh* mesh_shiba = loader.ConvertMesh();

		mSelectedScene = new Scene("Sample Scene");
	}
	void Narco_Core::Init()
	{
		mSelectedScene->start();

	}
	void Narco_Core::Update(float delta)
	{
		static ID3D11DeviceContext* context = mHardware->GetImmediateContext();
		static ID3D11RenderTargetView* const * rtv = mGBuffer->GetRenderTargets();
		static ID3D11DepthStencilView* dsv = mGBuffer->GetDepthStencil();
		static D3D11_VIEWPORT viewports[] = { mDisplay->GetMainViewport() };
		//static unsigned int gbufferCount = mTexManager
		clearScreen();

		context->OMSetRenderTargets(mGBuffer->GetBufferCount(), rtv, dsv);
		context->RSSetViewports(1, viewports);
		


		mSelectedScene->update(delta);

	}
	void Narco_Core::Render(float delta)
	{
		
		mSelectedScene->render(delta);
		mDisplay->Present();
		
	}
	void Narco_Core::Release()
	{
		mSelectedScene->release();

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
