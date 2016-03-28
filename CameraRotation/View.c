//
//  View.c
//  3DPrototype
//
//  Created by Laura del Pino Díaz on 15/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"



void setViewport(){
    int ancho = glutGet(GLUT_WINDOW_WIDTH);
    int alto = glutGet(GLUT_WINDOW_HEIGHT);
    glViewport(0, 0, ancho, alto);
}

void setProjection(){
    int ancho = glutGet(GLUT_WINDOW_WIDTH);
    int alto = glutGet(GLUT_WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(gl_fovy, (float)ancho / (float)alto, gl_cerca, gl_lejos);
}

void setModelView(){
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}



void InitGL(){
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    setViewport();
    setProjection();
}


void ReshapeSize(int ancho, int alto){
    
    setViewport();
    setProjection();
    glutPostRedisplay();
}

void MousePosition(int x, int y){
    int ancho = glutGet(GLUT_WINDOW_WIDTH);
    int alto = glutGet(GLUT_WINDOW_HEIGHT);
    theta = M_PI*(double)y/(double)alto;
    phi = - M_PI + 2*M_PI * (double)x/(double)ancho;
    glutPostRedisplay();
}

void Display(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra todo lo existente en el framebuffer
    setModelView();
    
    // TO DO
    glTranslatef(0.0f, 0.0f, -gl_center);
    
    float x = (float)(radio*sin(theta)*sin(phi));
    float y = (float)(radio*cos(theta));
    float z = (float)(radio*sin(theta)*cos(phi));
    
    gluLookAt(x, y, z, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    
    glutWireTeapot(10.0f);
    
    glFlush(); // actualiza el framebuffer
    glutSwapBuffers(); // en caso de animacion
}