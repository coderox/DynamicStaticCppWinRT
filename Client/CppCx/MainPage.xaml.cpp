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

	// call function
	component->DoWork();

	// get sync result
	OutputDebugString(component->Echo(L"Hello world!")->Data());

	// call async operation
	create_task(component->EchoAsync(L"Hello world!")).then([](String^ echoAsync) {
		OutputDebugString(echoAsync->Data());
	});
}
