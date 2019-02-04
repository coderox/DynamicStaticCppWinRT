#pragma once

#ifdef _WINRT_DLL

#include "Component.g.h"

namespace winrt::Library::implementation
{
	struct Component : ComponentT<Component>

#else

#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
namespace Library
{
	struct Component

#endif
	{
		Component() = default;

		void DoWork();
		winrt::hstring Echo(winrt::hstring const& message);
		winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> EchoAsync(winrt::hstring const& message);
	};
}

#ifdef _WINRT_DLL
namespace winrt::Library::factory_implementation
{
	struct Component : ComponentT<Component, implementation::Component>
	{
	};
}
#endif