using System;
using System.Diagnostics;
using Windows.UI.Xaml.Controls;

namespace Client.CSharp
{
    public sealed partial class MainPage : Page
    {
        public MainPage()
        {
            this.InitializeComponent();

            Loaded += async delegate
            {
                var component = new Library.Component();
                var anotherComponent = new Library.AnotherComponent();

                // call function
                component.DoWork();

                // get sync result
                Debug.WriteLine(component.Echo("Hello world from C#!"));

                // call async operation
                Debug.WriteLine(await anotherComponent.EchoAsync("Hello world from C#!"));
            };
        }
    }
}
