#pragma once

namespace NARCO
{
	class IFileSystem
	{
	public:
		virtual void Load() = 0;
		virtual void Reload() = 0;
		virtual void Release() = 0;
	};
}