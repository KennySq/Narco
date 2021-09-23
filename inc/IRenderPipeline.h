#pragma once
#include"Common.h"
#include"D3DUtil.h"
#include"Narco_Common.h"

namespace NARCO
{
	typedef class IRenderPipeline
	{
	public:
		virtual void Start() = 0;
		virtual void Update(float delta) = 0;
		virtual void Render(float delta) = 0;
		virtual void Release() = 0;

	private:

	} IRP;
}