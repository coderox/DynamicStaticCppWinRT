#pragma once

#ifdef _WINRT_DLL

#define UsingCppWinRTNamespace() \
using namespace Library::implementation;

#define CppWinRTNamespace() \
namespace winrt::Library::implementation

#define CppWinRTActivatableClass(className) \
struct className: className##T<className>

#define CppWinRTActivatableClassWithBasicFactory(className) \
namespace winrt::Library::factory_implementation\
{\
struct className : className##T<className, implementation::className> {}; \
}

#else

#define UsingCppWinRTNamespace() \
using namespace Library;

#define CppWinRTNamespace() \
namespace Library 

#define CppWinRTActivatableClass(className) \
struct className

#define CppWinRTActivatableClassWithBasicFactory(className)
#endif
