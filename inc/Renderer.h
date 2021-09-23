#pragma once
#include"Component.h"
namespace NARCO
{
	class Renderer : public Component
	{
	public:
		Renderer();
		virtual ~Renderer();
	private:
		virtual void start() override;
		virtual void update(float delta) override;
		virtual void render(float delta) override;
		virtual void release() override;

		// Mesh Data
		// Material Data;
	}; 
}