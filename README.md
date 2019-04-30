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
https://en.cppreference.com/w/cpp/links/libs - __especially Physics and Simulations part.__
https://wiki.python.org/moin/UsefulModules
https://github.com/golang/go/wiki/Projects
OpenAI, TensorFlow,


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

### Linux.
Currently build is available only for Windows(Linux is not yet configured in CMake file). 
TODO

## OpenGL
Crossplatform graphic library. 
For each platform are used FreeGLUT, GLEW or GLFW and GLAD to use OpenGL. learnopengl.com suggests to use GLFW and GLAD pair, and I am suggesting it to, cos of Windows was hard to compile FreeGLUT.   
Lets descibed shortly each of this libraries:

#### [FreeGLUT](https://en.wikipedia.org/wiki/FreeGLUT)
Handles functionality of creating window containing OpenGL context on wide range of platforms.

#### [GLEW](https://en.wikipedia.org/wiki/OpenGL_Extension_Wrangler_Library)
It query and loads OpenGL extensions.

The same functionality provides
#### [GLFW](https://en.wikipedia.org/wiki/GLFW)
Handles side with windows, and

#### [GLAD](https://www.khronos.org/opengl/wiki/OpenGL_Loading_Library#glad_.28Multi-Language_GL.2FGLES.2FEGL.2FGLX.2FWGL_Loader-Generator.29)
Loader of OpenGL.

### Project set-up on Windows


