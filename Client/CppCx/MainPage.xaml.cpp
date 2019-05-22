#include "pch.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>

using namespace Client;
using namespace concurrency;
using namespace Platform;
using namespace Windows::UI::Xaml;

MainPage::MainPage()
{
	InitializeComponent();
}

void Client::MainPage::OnLoaded(Object^ sender, RoutedEventArgs^ e)
{
	auto component = ref new Library::Component();
	auto anotherComponent = ref new Library::AnotherComponent();

	// call function
	component->DoWork();

	// get sync result
	OutputDebugString(component->Echo(L"Hello world from C++/CX!")->Data());
	OutputDebugString(L"\n");

	// call async operation
	create_task(anotherComponent->EchoAsync(L"Hello world from C++/CX!")).then([](String^ echoAsync) {
		OutputDebugString(echoAsync->Data());
		OutputDebugString(L"\n");
	});
}
