# SandBox
Trainings with new tools, techiques, features etc.


1. The Euler project tasks.
2. OpenCV
3. OpenGL
4. C++/STL/Boost
5. CMake
6. Unit Testing. TDD. Boost.Test. Google Test.
7. Python.   

and some future plans:

8. CUDA/TBB(Intel Threading Building Blocks), OpenMPI, multithreading programming.
9. GoLang.
10. OpenAI.
futher possible reading and research:
https://en.cppreference.com/w/cpp/links/libs - especially Physics and Simulations part.
https://wiki.python.org/moin/UsefulModules
https://github.com/golang/go/wiki/Projects
OpenAI, TensorFlow,


## OpenCV

[OpenCV](https://en.wikipedia.org/wiki/OpenCV) (Open source computer vision) is a library of programming functions 
mainly aimed at real-time computer vision.

### Project set-up on Windows

##### First Step
So at first You need __OpenCV__ binaries. 
The easiest way to get them is to download last release source archive from [official website](https://opencv.org/releases/) and 
build it in Debug/Release versions(x64 dlls). There are probably not all binaries from prebuild on official webiste.

##### Second Step
After build, you have to setup environmental variable OPENCV_DIR, to folder where you installed OpenCV.

PS: Visual Studio provide NuGet package manager, unfortunately last version of OpenCV there is 2.4 or wrappers for C#.

##### Third Step
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
