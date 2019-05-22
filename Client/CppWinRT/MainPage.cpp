#include "pch.h"
#include "MainPage.h"
#include "Component.h"
#include "AnotherComponent.h"
#include <ppltasks.h>

using namespace concurrency;
using namespace winrt;
using namespace Windows::UI::Xaml;


namespace winrt::CppWinRTClient::implementation
{
	MainPage::MainPage()
	{
		InitializeComponent();
	}

	fire_and_forget MainPage::Loaded(IInspectable const&, RoutedEventArgs const&)
	{
		Library::Component component;
		Library::AnotherComponent anotherComponent;

		// call function
		component.DoWork();

		// get sync result
		OutputDebugString(component.Echo(L"Hello world from C++/WinRT!").c_str());
		OutputDebugString(L"\n");

		// call async operation
		OutputDebugString((co_await anotherComponent.EchoAsync(L"Hello world from C++/WinRT!")).c_str());
		OutputDebugString(L"\n");
	}
}
