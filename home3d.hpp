//
//  home3d.hpp
//  computer_graphics_hw1
//
//  Created by Fatih Selim YAKAR on 21.04.2021.
//

#ifndef HOME_3D_H

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;

GLfloat _rotate_angle_y = 240.0f;
GLfloat _rotate_angle_x = 0.0f;
GLfloat _rotate_angle_z = 0.0f;

GLfloat _scale_angle_y = 1.0f;
GLfloat _scale_angle_z = 1.0f;
GLfloat _scale_angle_x = 1.0f;

GLfloat _translate_angle_y = 0.0f;
GLfloat _translate_angle_z = -2.0f;
GLfloat _translate_angle_x = 0.5f;

void updateWithKeypress(unsigned char key, int x, int y);
void initialize();
void resizeFunction(int w, int h);
void makeScene();

#endif
