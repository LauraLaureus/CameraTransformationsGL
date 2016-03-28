//
//  View.c
//  3DPrototype
//
//  Created by Laura del Pino Díaz on 15/3/16.
//  Copyright © 2016 Laura del Pino Díaz. All rights reserved.
//

#include "View.h"

void InitGL(){
    
    if (gl_ancho / w_ancho != gl_alto / w_alto){
        fprintf(stderr,"La relación de aspecto no es correcta\n");
    }
    
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    // para cambiar el criterio de lo que se ve. LESS es el de defecto: se ve lo que tiene menor profundidad
    //glDepthFunc(GL_LESS);
    // TO DO
    
    //glViewport(0, 0, w_ancho, w_alto); // pordefecto ya se establece así en la inicialización
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-gl_ancho/2.0, gl_ancho/2.0, -gl_alto/2.0, gl_alto/2.0, gl_cerca, gl_lejos); // espacio de trabajo
    glMatrixMode(GL_MODELVIEW); // las futuras operaciones se refieren a las coordenadas de los modelos
}


void ReshapeSize(int ancho, int alto){
    
    float dx = gl_ancho;
    float dy = gl_alto;
    
    dx *= (float)ancho / (float)w_ancho;
    dy *= (float)alto / (float)w_alto;
    
    glViewport(0, 0, ancho, alto); // utiliza la totalidad de la ventana
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-dx / 2.0, dx / 2.0, -dy / 2.0, dy / 2.0, gl_cerca, gl_lejos); // espacio de trabajo
    glMatrixMode(GL_MODELVIEW); // futuras operaciones se refieren a modelos
    glutPostRedisplay();
}

// función de gestion de ventana
void Display(){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra todo lo existente en el framebuffer
    glLoadIdentity(); // a partie de aqui empieza poner modelos y transformarlos.
    // TO DO
    
    
    glFlush(); // actualiza el framebuffer
    glutSwapBuffers(); // en caso de animacion
}
