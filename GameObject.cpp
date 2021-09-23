#include"inc/GameObject.h"

namespace NARCO
{
	void GameObject::start()
	{
		for (auto c : mComponents)
		{
			Component* comp = c.second;

			comp->start();
		}
	}

	void GameObject::update(float delta)
	{
		for (auto c : mComponents)
		{
			Component* comp = c.second;

			comp->update(delta);
		}
	}

	void GameObject::render(float delta)
	{
		for (auto c : mComponents)
		{
			Component* comp = c.second;

			comp->render(delta);
		}
	

	}

	void GameObject::release()
	{
		for (auto c : mComponents)
		{
			Component* comp = c.second;

			comp->release();
		}
	}
}