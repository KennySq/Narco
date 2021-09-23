#include"inc/Scene.h"

namespace NARCO
{
	Scene::Scene(const char* name)
		: mName(name), mSceneID(MakeHash(mName))
	{
	}
	Scene::~Scene()
	{
	}
	void Scene::start()
	{
		for (auto i : mGameObjects)
		{
			GameObject* inst = i.second;

			inst->start();
		}
	}
	void Scene::update(float delta)
	{
		for (auto i : mGameObjects)
		{
			GameObject* inst = i.second;

			inst->update(delta);
			
		}

	}
	void Scene::render(float delta)
	{
		for (auto i : mGameObjects)
		{
			GameObject* inst = i.second;

			inst->render(delta);
		}
	}
	void Scene::release()
	{
		for (auto i : mGameObjects)
		{
			GameObject* inst = i.second;

			inst->release();
		}

	}
	void Scene::sceneRender()
	{

	}
}