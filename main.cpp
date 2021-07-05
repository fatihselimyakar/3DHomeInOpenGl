//
//  main.cpp
//  computer_graphics_hw1
//
//  Created by Fatih Selim YAKAR on 21.04.2021.
//
#include "home3d.hpp"

void updateWithKeypress(unsigned char key, int x, int y) {
    if(key=='d'){
        _rotate_angle_y += 4.0;
    }
    else if(key=='a'){
        _rotate_angle_y -= 4.0;
    }
    else if(key=='s'){
        _rotate_angle_x += 4.0;
    }
    else if(key=='w'){
        _rotate_angle_x -= 4.0;
    }
    else if(key=='z'){
        _rotate_angle_z += 4.0;
    }
    else if(key=='q'){
        _rotate_angle_z -= 4.0;
    }
    else if(key=='1'){
        _scale_angle_x += 0.1;
        _scale_angle_y += 0.1;
        _scale_angle_z += 0.1;
    }
    else if(key=='2'){
        _scale_angle_x -= 0.1;
        _scale_angle_y -= 0.1;
        _scale_angle_z -= 0.1;
    }
    else if(key=='h'){
        _translate_angle_x += 0.1f;
    }
    else if(key=='f'){
        _translate_angle_x -= 0.1f;
    }
    else if(key=='t'){
        _translate_angle_y += 0.1f;
    }
    else if(key=='g'){
        _translate_angle_y -= 0.1f;
    }
    else if(key=='r'){
        _translate_angle_z += 0.1f;
    }
    else if(key=='v'){
        _translate_angle_z -= 0.1f;
    }
    else if(key==27){
        exit(0);
    }
    glutPostRedisplay();
}

void initialize() {
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    GLfloat specular[] = { 0.3, 0.3, 0.3, 0.3  };
    GLfloat shininess[] = { 90.0 };
    GLfloat ambient[] = { 0.1, 0.1, 0.1, 0.1 };
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void resizeFunction(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double) w / (double) h, 1.0, 200.0);
}

void makeScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-1.0f, -1.5f, -2.0f);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.0f, 1.0f, 0.0f);
    
    glTranslatef(_translate_angle_x,_translate_angle_y,_translate_angle_z);
    glRotatef(_rotate_angle_z, 0.0f, 0.0f, 1.0f);
    glRotatef(_rotate_angle_y, 0.0f, 1.0f, 0.0f);
    glRotatef(_rotate_angle_x, 1.0f, 0.0f, 0.0f);
    glScalef(_scale_angle_x, _scale_angle_y, _scale_angle_z);
    
    glColor3f(1.0, 0.25, 1.0);
    glColor3f (.5, 0.5, .25);
    glClear (GL_COLOR_BUFFER_BIT);
    
    /* Front Rectangle */
    glBegin(GL_POLYGON);
    glColor3f (.2, .75, .55);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (1, 0.1, 0.0);
    glVertex3f (1, 0.6, 0.0);
    glVertex3f (0.1, 0.6, 0.0);
    glEnd();
    
    
    /* Rear Rectangle */
    glBegin(GL_POLYGON);
    glColor3f (.2, .75, .55);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.6, 0.5);
    glVertex3f (0.1, 0.6, 0.5);
    glEnd();

    /* Right Rectangle */
    glBegin(GL_POLYGON);
    glColor3f (.35, 0.3, .5);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.1, 0.6, 0.0);
    glVertex3f (0.1, 0.6, 0.5);
    glEnd();

    /* Left Rectangle */
    glBegin(GL_POLYGON);
    glColor3f (.35, 0.3, .5);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.0);
    glVertex3f (1, 0.6, 0.0);
    glVertex3f (1, 0.6, 0.5);
    glEnd();

    /* Left Top Triangle */
    glBegin(GL_TRIANGLES);
    glColor3f (.35, 0.2, .5);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f (1, 0.6, 0.0);
    glVertex3f (1, 0.6, 0.5);
    glVertex3f (1, 0.8, 0.25);
    glEnd();

    /* Right Top Triangle */
    glBegin(GL_TRIANGLES);
    glColor3f (.35, 0.2, .5);
    glNormal3f(-1.0f, 0.0f, 0.0f);
    glVertex3f (0.1, 0.6, 0.0);
    glVertex3f (0.1, 0.6, 0.5);
    glVertex3f (0.1, 0.8, 0.25);
    glEnd();

    /* Front Roof */
    glBegin(GL_POLYGON);
    glColor3f (.55, 0.2, .2);
    glNormal3f(0.0f, 1.0f, -1.0f);
    glVertex3f (0.1, 0.6, 0.0);
    glVertex3f (1, 0.6, 0.0);
    glVertex3f (1, 0.8, 0.25);
    glVertex3f (0.1, 0.8, 0.25);
    glEnd();

    /* Rear Roof */
    glBegin(GL_POLYGON);
    glColor3f (.55, 0.2, .2);
    glNormal3f(0.0f, 1.0f, 1.0f);
    glVertex3f (0.1, 0.6, 0.5);
    glVertex3f (1, 0.6, 0.5);
    glVertex3f (1, 0.8, 0.25);
    glVertex3f (0.1, 0.8, 0.25);
    glEnd();

    /* Door */
    glBegin(GL_POLYGON);
    glColor3f (.3, 0.2, .1);
    glNormal3f(1.0f, 0.0f, 0.0f);
    glVertex3f (1.001, 0.1, 0.18);
    glVertex3f (1.001, 0.1, 0.32);
    glVertex3f (1.001, 0.40, 0.32);
    glVertex3f (1.001, 0.40, 0.18);
    glEnd();

    /* Window 1 */
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.4, .6);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f (0.65, 0.33, -0.0005);
    glVertex3f (0.8, 0.33, -0.0005);
    glVertex3f (0.8, 0.5, -0.0005);
    glVertex3f (0.65, 0.5, -0.0005);
    glEnd();

    /* Window 2 */
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.4, .6);
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f (0.3, 0.33, -0.0005);
    glVertex3f (0.45, 0.33, -0.0005);
    glVertex3f (0.45, 0.5, -0.0005);
    glVertex3f (0.3, 0.5, -0.0005);
    glEnd();
    
    /* Window 3 */
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.4, .6);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f (0.65, 0.33, 0.5005);
    glVertex3f (0.8, 0.33, 0.5005);
    glVertex3f (0.8, 0.5, 0.5005);
    glVertex3f (0.65, 0.5, 0.5005);
    glEnd();

    /* Window 4 */
    glBegin(GL_POLYGON);
    glColor3f (.15, 0.4, .6);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glVertex3f (0.3, 0.33, 0.5005);
    glVertex3f (0.45, 0.33, 0.5005);
    glVertex3f (0.45, 0.5, 0.5005);
    glVertex3f (0.3, 0.5, 0.5005);
    glEnd();

    /* Bottom Rectangle */
    glBegin(GL_POLYGON);
    glColor3f (0.2, 0.2, 0.6);
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f (0.1, 0.1, 0.0);
    glVertex3f (0.1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.5);
    glVertex3f (1, 0.1, 0.0);
    glEnd();

    glFlush ();
    glPopMatrix();
    glutSwapBuffers();
    
}

int main(int argc, char * * argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Computer Graphics HW1 - 3d Home");
    initialize();
    glutDisplayFunc(makeScene);
    glutKeyboardFunc(updateWithKeypress);
    glutReshapeFunc(resizeFunction);
    glutMainLoop();
    return 0;
}
