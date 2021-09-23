#pragma once
#include"inc/Narco_Common.h"
#include"D3DUtil.h"
#include"Common.h"
#include"D3DHardware.h"
#include"D3DDisplay.h"

#include"MeshLoader.h"

#include"Narco_TextureManager.h"

#include<Windows.h>

namespace NARCO
{
	class Narco_Core
	{
	public:

		Narco_Core(HWND windowHandle, HINSTANCE handleInst);

		void Init();
		void Update(float delta);
		void Render(float delta);
		void Release();


	private:
		void clearScreen();


		HWND mWindowHandle;
		HINSTANCE mHandleInstance;

		D3DHardware* mHardware;
		D3DDisplay* mDisplay;

		Narco_TextureManager mTexManager;
		



	};

}