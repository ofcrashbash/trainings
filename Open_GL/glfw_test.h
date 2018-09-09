#pragma once
#include <glad/glad.h>//this one should be before glfw
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cerrno>
#include <streambuf>


using namespace std;

int glfw_window(int argc, char** argv);