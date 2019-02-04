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

                // call function
                component.DoWork();

                // get sync result
                Debug.WriteLine(component.Echo("Hello world"));

                // call async operation
                Debug.WriteLine(await component.EchoAsync("Hello wordl!"));
            };
        }
    }
}
