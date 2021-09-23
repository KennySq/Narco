#pragma once
#include"D3DUtil.h"
#include"Common.h"
#include"Narco_Common.h"

#include"GameObject.h"

namespace NARCO
{
	class Narco_Core;
	typedef unsigned long long SceneID;

	class Scene
	{
		friend Narco_Core;

	public:
		Scene(const char* name);
		~Scene();



	private:

		void start();
		void update(float delta);
		void render(float delta);
		void release();

		void sceneRender();

		std::string mName;
		SceneID mSceneID;

		std::map<InstanceID, GameObject*> mGameObjects;
		
		// GameObject List
		// Cached Materials
		// 
	};
}