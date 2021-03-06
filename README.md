# SandBox

Trainings with new tools, techiques, features etc.

## Contetns

+ __Building and Running__
  + Vcpkg
  + Visual Studio
  + Linux
  + Cmake
+ __The Euler project tasks.__
+ __OpenCV__
+ __OpenGL__
+ __C++/STL/Boost__
+ __CMake__
+ __Unit Testing. TDD. Boost.Test. Google Test.__
+ __Python.__

and some future plans:

+ __CUDA/TBB(Intel Threading Building Blocks), OpenMPI, multithreading programming.__
+ __GoLang.__
+ __OpenAI.__

futher possible reading and research:  

+ [List Of OpenSource C++ Libraries](https://en.cppreference.com/w/cpp/links/libs) - __especially Physics and Simulations part.__
+ [Python Useful Modules](https://wiki.python.org/moin/UsefulModules)
+ [GoLang Projects](https://github.com/golang/go/wiki/Projects)
+ OpenAI.
+ TensorFlow.

And the last but not least:

+ __Supercomputers and highly parallel computations__.

---

## Building and Running

Project is mostly developed on Windows machine, but still it is quite interesting to try different build techinques on different machines. So called crossplatform application. At first project was developed in Visual Studio. To add support from Linux I have added CMake support. But CMake require packages and to get those packages on Windows or/and Linux is done in very different way. Linux gives very easy tool apt-get(or app - package manager) which resolves any dependencies very quickly. Windows is less straightforward to Linux. You can customly build libraries from source, or download chocolately, but recently there is great tool - __vcpkg__! Next section is about it.

### VCPKG

Some key notes:

+ Only cmake-gui works well with the package manager.
+ You have manually add new entry value _VCPKG_DEFAULT_TRIPLET_(or _VCPKG_TARGET_TRIPLET_) to specify build target(x86-windows, x64-windows-static etc).
+ You have to specify Toolchain File.
+ There is some problems with specifing _VCPKG_DEFAULT_TRIPLET_

some usefull links: [How to Use vcpkg With CMake On Windows](https://developerpaul123.github.io/c++/cmake/using-vcpkg-on-windows/), [official repo](https://github.com/microsoft/vcpkg)

---

## OpenCV

[OpenCV](https://en.wikipedia.org/wiki/OpenCV) (Open source computer vision) is a library of programming functions
mainly aimed at real-time computer vision.

### Project set-up on Windows

#### 1.First Step

So at first You need __OpenCV__ binaries.
The easiest way to get them is to download last release source archive from [official website](https://opencv.org/releases/) and
build it in Debug/Release versions(x64 dlls). There are probably not all binaries from prebuild on official webiste.

#### 2.Second Step

After build, you have to setup environmental variable OPENCV_DIR, to folder where you installed OpenCV.

PS: Visual Studio provide NuGet package manager, unfortunately last version of OpenCV there is 2.4 or wrappers for C#.

#### 3.Third Step

Configuring Visual Studio Project.

1. _Properties of project->VC++ Directories->Include Directories_ - Append path to include dirrectory of OpenCV. $(OPENCV_DIR)/include.
2. _Properties of project->VC++ Directories->Library Directories_ - Append path to binnaries dirrectory of OpenCV.     $(OPENCV_DIR)/x64/vc15/lib
3. _Properties of project->Linker->Input_ - Append list of all libs of OpenCV(from lib folder).

To workaroud setting path to location of dlls to global path, we use next macros:

_Properties of project->Debugging->Environment_ set to it next macros: Path=$(OPENCV_DIR)\x64\vc15\bin;%Path%;

Thats all, now You can run programs!

### Project set-up on Linux

Just type:
> sudo apt install libopencv-dev

And thats, all.
[Link to my OneNote notebook with more details](https://onedrive.live.com/view.aspx?resid=5B08D11D78362F2A%213880&id=documents&wd=target%28Computer%20Graphics.one%7C554D37D9-ACD6-4ED9-BB63-56C6EA66C736%2FOpenGL%7C15450641-1CD5-468E-91EE-6827900FBBBD%2F%29).

### VCPKG and CMake

`vcpkg install opencv`

#### Cuda support

Install [nvidia CUDA toolkit](https://developer.nvidia.com/cuda-downloads)

`vcpkg install opencv[cuda]`

---

## OpenGL

Crossplatform graphic library.
For each platform are used FreeGLUT, GLEW or GLFW and GLAD to use OpenGL. learnopengl.com suggests to use GLFW and GLAD pair, and I am suggesting it to, cos of Windows was hard to compile FreeGLUT.

### Lets descibed shortly each of this libraries

#### [FreeGLUT](https://en.wikipedia.org/wiki/FreeGLUT)

Handles functionality of creating window containing OpenGL context on wide range of platforms.

#### [GLEW](https://en.wikipedia.org/wiki/OpenGL_Extension_Wrangler_Library)

It query and loads OpenGL extensions.

The same functionality provides

#### [__GLFW__](https://en.wikipedia.org/wiki/GLFW)

Handles side with windows, and

#### [__GLAD__](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library#glad_.28Multi-Language_GL.2FGLES.2FEGL.2FGLX.2FWGL_Loader-Generator.29)

Loader of OpenGL.

### OpenGL set-up on Windows

Lets describe the easiest way using _GLFW_ and _GLAD_.

#### GLFW

Simply download Windows x64 binnaries from [official website](https://www.glfw.org/download.html).
Extract them and specify environmental variable __GLFW_DIR__.

#### GLAD

Download source files(only one header and one source) from [official site](https://glad.dav1d.de/).
gl -> Select latest version, Language -> C\C++, Specification -> OpenGL, Profile -> Core, Options -> Generate a Loader.
And press Generate. Copy downloaded files to your project.

### OpenGL set-up on Linux

#### GLFW Linux

> sudo apt install libglfw3-dev  

That's all!

#### GLAD Linux

Almost same setup as for windows.
Download source files(only one header and one source) from [official site](https://glad.dav1d.de/).
gl -> Select latest version, Language -> C\C++, Specification -> OpenGL, Profile -> Core, Options -> Generate a Loader.
And press Generate. Extract archive and setup envirnonmental variable __GLAD_DIR__ to target folder(for example /usr/local/glad).

### OpenGL: VCPKG and CMake

`vcpkg install glfw3`
`vcpkg install glad`

---

## Box2D

### Windowds(Visual Studio)

+ Setup Box2D using [instruction](https://github.com/erincatto/Box2D/blob/master/Building.md).
+ Separate build files by _include_, _lib_ and _bin_(optionaly) directories.
+ Setup environmental variable BOX2D_DIR.
+ Done.

### vcpkg

`vcpkg install box2d:x64-windows`

### Linux(Cmake)

also vcpkg manager can be used

`sudo apt install libbox2d-dev`
