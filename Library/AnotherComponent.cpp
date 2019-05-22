#include "pch.h"
#include <chrono>
#include "AnotherComponent.h"

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;

#ifdef _WINRT_DLL
using namespace Library::implementation;
#else
using namespace Library;
#endif

void AnotherComponent::DoWork()
{
	OutputDebugString(L"Doing work in C++");
	OutputDebugString(L"\n");
}

hstring AnotherComponent::Echo(hstring const& message)
{
	return L"Echoing: " + message;
}

Windows::Foundation::IAsyncOperation<hstring> AnotherComponent::EchoAsync(hstring const& message)
{
	hstring result(L"Echoing async: " + message);
	co_await 2s;
	co_return hstring(result);
}
