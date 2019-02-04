#pragma once

#include "Utilities.h"
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>

#ifdef _WINRT_DLL
#include "Component.g.h"
#endif

CppWinRTNamespace()
{
	CppWinRTActivatableClass(Component)
	{
		Component() = default;

		void DoWork();
		winrt::hstring Echo(winrt::hstring const& message);
		winrt::Windows::Foundation::IAsyncOperation<winrt::hstring> EchoAsync(winrt::hstring const& message);
	};
}

CppWinRTActivatableClassWithBasicFactory(Component)
