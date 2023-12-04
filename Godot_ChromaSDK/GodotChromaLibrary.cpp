#include <tchar.h>
#include "GodotChromaLibrary.h"
#include "NodeChromaSDK.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/godot.hpp>

void InitializeGodotChromaLibrary(godot::ModuleInitializationLevel p_level)
{
	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}

	godot::ClassDB::register_class<godot::NodeChromaSDK>();

	ChromaSDK::ChromaAnimationAPI::InitAPI();

	if (!ChromaSDK::ChromaAnimationAPI::GetIsInitializedAPI())
	{
		ChromaSDK::APPINFOTYPE appInfo = {};

		_tcscpy_s(appInfo.Title, 256, _T("Godot Sample Application"));
		_tcscpy_s(appInfo.Description, 1024, _T("A sample application using Razer Chroma SDK"));
		_tcscpy_s(appInfo.Author.Name, 256, _T("Razer"));
		_tcscpy_s(appInfo.Author.Contact, 256, _T("https://developer.razer.com/chroma"));

		//appInfo.SupportedDevice = 
		//    0x01 | // Keyboards
		//    0x02 | // Mice
		//    0x04 | // Headset
		//    0x08 | // Mousepads
		//    0x10 | // Keypads
		//    0x20   // ChromaLink devices
		//    ;
		appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
		appInfo.Category = 1;

		if (ChromaSDK::ChromaAnimationAPI::InitSDK(&appInfo) == 0)
		{
			//fprintf(stderr, "Loaded Chroma SDK Plugin!\r\n");
		}
		else
		{
			fprintf(stderr, "Failed to loaded Chroma SDK Plugin!\r\n");
		}
	}
}

void UninitializeGodotChromaLibrary(godot::ModuleInitializationLevel p_level) {

	if (p_level != godot::MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		return;
	}

	if (ChromaSDK::ChromaAnimationAPI::GetIsInitializedAPI())
	{
		if (ChromaSDK::ChromaAnimationAPI::IsInitialized())
		{
			ChromaSDK::ChromaAnimationAPI::StopAll();
			ChromaSDK::ChromaAnimationAPI::CloseAll();
			ChromaSDK::ChromaAnimationAPI::Uninit();
		}
	}
}

extern "C"
{
	// Initialization.
	GDExtensionBool GDE_EXPORT chromasdk_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, const GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization)
	{
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(InitializeGodotChromaLibrary);
		init_obj.register_terminator(UninitializeGodotChromaLibrary);
		init_obj.set_minimum_library_initialization_level(godot::MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
