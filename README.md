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

### Project set-up onLinux.
Currently build is available only for Windows(Linux is not yet configured in CMake file). 
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
TODO

---



