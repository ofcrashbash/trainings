# SandBox
Trainings with new tools, techiques, features etc.


## Contetns:

1. __The Euler project tasks.__
2. __OpenCV__
3. __OpenGL__
4. __C++/STL/Boost__
5. __CMake__
6. __Unit Testing. TDD. Boost.Test. Google Test.__
7. __Python.__   

and some future plans:

8. __CUDA/TBB(Intel Threading Building Blocks), OpenMPI, multithreading programming.__
9. __GoLang.__
10. __OpenAI.__

futher possible reading and research:  

11. https://en.cppreference.com/w/cpp/links/libs - __especially Physics and Simulations part.__
12. https://wiki.python.org/moin/UsefulModules
13. https://github.com/golang/go/wiki/Projects
14. OpenAI. 
15. TensorFlow.

And the last but not least:

16. __Supercomputers and highly parallel computations__.

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

### Project set-up on Linux.
Just type:
> sudo apt install libopencv-dev

And thats, all.
[Link to my OneNote notebook with more details](https://onedrive.live.com/view.aspx?resid=5B08D11D78362F2A%213880&id=documents&wd=target%28Computer%20Graphics.one%7C554D37D9-ACD6-4ED9-BB63-56C6EA66C736%2FOpenGL%7C15450641-1CD5-468E-91EE-6827900FBBBD%2F%29).

---
## OpenGL
Crossplatform graphic library. 
For each platform are used FreeGLUT, GLEW or GLFW and GLAD to use OpenGL. learnopengl.com suggests to use GLFW and GLAD pair, and I am suggesting it to, cos of Windows was hard to compile FreeGLUT.   
Lets descibed shortly each of this libraries:

#### [FreeGLUT](https://en.wikipedia.org/wiki/FreeGLUT)
Handles functionality of creating window containing OpenGL context on wide range of platforms.

#### [GLEW](https://en.wikipedia.org/wiki/OpenGL_Extension_Wrangler_Library)
It query and loads OpenGL extensions.

The same functionality provides
#### [__GLFW__](https://en.wikipedia.org/wiki/GLFW)
Handles side with windows, and

#### [__GLAD__](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library#glad_.28Multi-Language_GL.2FGLES.2FEGL.2FGLX.2FWGL_Loader-Generator.29)
Loader of OpenGL.

### Project set-up on Windows
Lets describe the easiest way using _GLFW_ and _GLAD_.

#### GLFW:
Simply download Windows x64 binnaries from [official website](https://www.glfw.org/download.html).
Extract them and specify environmental variable __GLFW_DIR__.

#### GLAD:
Download source files(only one header and one source) from [official site](https://glad.dav1d.de/). 
gl -> Select latest version, Language -> C\C++, Specification -> OpenGL, Profile -> Core, Options -> Generate a Loader.
And press Generate. Copy downloaded files to your project.

### Project set-up on Linux.

#### GLFW
> sudo apt install libglfw3-dev  

That's all!

#### GLAD
Almost same setup as for windows.
Download source files(only one header and one source) from [official site](https://glad.dav1d.de/). 
gl -> Select latest version, Language -> C\C++, Specification -> OpenGL, Profile -> Core, Options -> Generate a Loader.
And press Generate. Extract archive and setup envirnonmental variable __GLAD_DIR__ to target folder(for example /usr/local/glad).

---
## Boost.TEST
### Setup on windows and visual studion(vcpkg doesn't support visual studio yet)
At first You should setup [VCpkg](https://github.com/Microsoft/vcpkg) pakage manager and then
use this [instruction](https://docs.microsoft.com/en-us/visualstudio/test/how-to-use-boost-test-for-cpp?view=vs-2019)

~Boost.Test extension for VS has problems and [problem](https://github.com/MicrosoftDocs/visualstudio-docs/issues/3209) was reported.~
Instruction works well, simply read patiently.

~Another way was to setup Boost.Test as regular project, but VS Test Explorer doesn't recognize it.~
~Details of this setup:~
* ~Boost from [SourceForge](https://sourceforge.net/projects/boost/files/latest/download) or build from repo.~
* ~Setup _Boost_DIR_ environmental variable.~
* ~Create _reference_ to project which generates __library__.~
* ~Build.~

### Installing Boost on Windows
~Download and install [Boost binnaries](https://sourceforge.net/projects/boost/files/boost-binaries).~
~Next specify to them Boost_DIR environmetal variable.~
Use of __Vcpkg package manager__ is the simplest way in this case.

### Linux(CMake)

>sudo apt install liboost-all-dev
TODO implement CTest in CMake file..


---

## Box2D

### Windowds(Visual Studio)
* Setup Box2D using [instruction](https://github.com/erincatto/Box2D/blob/master/Building.md).
* Separate build files by _include_, _lib_ and _bin_(optionaly) directories.
* Setup environmental variable BOX2D_DIR.
* Done.

### Linux(Cmake)

TODO add CMake to project and describe setup process



