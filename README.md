# Latest

* Note: Visit the [Chroma Animation Guide](https://chroma.razer.com/ChromaGuide/) to find the latest supported plugin for Chroma RGB.

# Godot Chroma SDK Plugin

Note: The Chroma SDK for Godot plugin is for the *Windows* platform only!

**Table of Contents**

* [See Also](#see-also)
* [About](#about)
* [Quick Start](#quick-start)
* [Project Setup](#project-setup)

<a name="see-also"></a>
## See Also

**Docs:**

- [Chroma Animation Guide](http://chroma.razer.com/ChromaGuide/) - Visual examples of the Chroma Animation API methods

**Plugins:**

- [CChromaEditor](https://github.com/RazerOfficial/CChromaEditor) - C++ native MFC library for playing and editing Chroma animations

<a name="about"></a>
## About

* [GodotHello](GodotHello)

The `GodotHello` project is a Godot sample app that shows the animations from the [Chroma Animation Guide](http://chroma.razer.com/ChromaGuide/).

**Screenshot:**

![image_1](images/image_1.png)

**Video:**

**[OLD VIDEO] Godot Native Plugin - Chroma SDK**

<a target="_blank" href="https://www.youtube.com/watch?v=U50sp-QumDg">![video](https://img.youtube.com/vi/U50sp-QumDg/0.jpg)</a>


## Quick Start

* Install [Synapse](https://www.razer.com/synapse-3)

* Make sure the Chroma Connect module is installed.

![image_3](images/image_3.png)

* If you don't have Chroma hardware, you can see Chroma effects with the [Chroma Emulator](https://github.com/razerofficial/ChromaEmulator)

* Download a prebuilt binary from [releases](https://github.com/razerofficial/Godot_ChromaSDK/releases/) and place in the project folder

![image_2](images/image_2.png)

* `Animations` - Sample folder for `Chroma` animation files

* `CChromaEditorLibrary64.dll` - Adds `Chroma` animation support and uses the `ChromaSDK`

* `Godot_ChromaSDK.dll` - Native Godot library that makes the `ChromaAnimation` library available

* `chromasdk.gdextension` - Godot GDExtension

* `NodeSample.gd` - Sample `gdscript` that uses the `ChromaAnimation` API

## Project Setup

These are the steps to build the `Godot_ChromaSDK.dll` library.

* First generate the Godot include files

* Reference: [GDExtension C++ example](https://docs.godotengine.org/en/stable/tutorials/scripting/gdextension/gdextension_cpp_example.html)

* Pick a starting point:

```
cd C:\Public
```

* Clone the Godot project (3.0 is actually the old version so get the main version)

```
mkdir gdextension_cpp_example
cd gdextension_cpp_example
git init
git submodule add -b 4.1 https://github.com/godotengine/godot-cpp
cd godot-cpp
git submodule update --init
cd ..
```

* Update the submodules from the `gdextension_cpp_example` folder

```
cd gdextension_cpp_example
git submodule update --init
```

* Download the 64-bit standard version of [Godot](https://godotengine.org/download/windows)

* Build the C++ bindings from the `gdextension_cpp_example` folder

```
"%USERPROFILE%\Downloads\Godot\Godot_v3.2.1-stable_win64.exe" --dump-extension-api
```

* Install [Python 2.7 or better](https://www.python.org/)

* Install [PIP](https://pip.pypa.io/en/stable/installing/)

* Download [Scons 3.1.2](https://scons.org/tag/releases.html)

* ... or install scons with *pip*

```
c:\Python27\python.exe -m pip install scons
```

* Make sure your target *Python* version is first in the path if you have multiple versions installed.

```
SET PATH=C:\Python27;%PATH%
```

## Debug Build

* Generate the C++ bindings from the `gdextension_cpp_example` folder

```
cd godot-cpp
"%USERPROFILE%\Downloads\Godot\scons-3.1.2\script\scons.bat" platform=windows custom_api_file=<PATH_TO_FILE> -j4
```

* Add C++ include folders to the project

**C:\Public\gdextension_cpp_example\godot-cpp\include;C:\Public\gdextension_cpp_example\godot-cpp\gen\include;C:\Public\gdextension_cpp_example\godot-cpp\gdextension**

* Add the godot library to the project

```
libgodot-cpp.windows.template_debug.x86_64.lib
```

## Release Build

* Generate the C++ bindings from the `gdextension_cpp_example` folder

```
cd godot-cpp
"%USERPROFILE%\Downloads\Godot\scons-3.1.2\script\scons.bat" platform=windows target=template_release custom_api_file=<PATH_TO_FILE> -j4
```

* Add C++ include folders to the project

**C:\Public\gdextension_cpp_example\godot-cpp\include;C:\Public\gdextension_cpp_example\godot-cpp\gen\include;C:\Public\gdextension_cpp_example\godot-cpp\gdextension**

* Add the godot library to the project

```
libgodot-cpp.windows.template_release.x86_64.lib
```

## All

* Add to `Linker` General `Additional Library Directories`

```
C:\Public\gdnative_cpp_example\godot-cpp\bin
```
