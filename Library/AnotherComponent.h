#pragma once

#ifdef _WINRT_DLL
#include "AnotherComponent.g.h"
#endif

#ifdef _WINRT_DLL
namespace winrt::Library::implementation
#else
namespace Library
#endif
{
#ifdef _WINRT_DLL
	struct AnotherComponent : AnotherComponentT<AnotherComponent>
#else
	struct AnotherComponent
#endif
	{
		AnotherComponent() = default;

		void DoWork();
		winrt::hstring Echo(winrt::hstring const& message);
		winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> EchoAsync(winrt::hstring const& message);
	};
}

#ifdef _WINRT_DLL
namespace winrt::Library::factory_implementation
{
	struct AnotherComponent : AnotherComponentT<AnotherComponent, implementation::AnotherComponent>
	{
	};
}
#endif
