#include "pch.h"
#include "MainPage.h"
#include "Component.h"
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

		// call function
		component.DoWork();

		// get sync result
		OutputDebugString(component.Echo(L"Hello world!").c_str());

		// call async operation
		OutputDebugString((co_await component.EchoAsync(L"Hello world!")).c_str());
	}
}
