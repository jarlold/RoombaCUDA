#include <GL/glut.h>
#include <GL/glu.h>
#include "roomba_simulator.cpp"

#define NUM_WALLS 2
#define NUM_ROOMBAS 2

Roomba* roombas[] = { new Roomba(250, 100, 20), new Roomba(250, 200, 20) };
Wall* walls[] = { new Wall(0, 0, 500, 10), new Wall(0, 500-10, 500, 10) };

void update_roombas() {
    for (int i = 0; i < NUM_ROOMBAS; i++) {
        tick_roomba(roombas[i], *walls, NUM_WALLS, 1.0f);
        roombas[i]->vel = 0.2;
        roombas[i]->bearing += 0.002;
    }
}

void display( void ) {
    // clear all pixels
    glClear( GL_COLOR_BUFFER_BIT );

    // draw the walls
    for (int i = 0 ; i < NUM_WALLS; i++) {
        draw_wall(walls[i]);
    }

    // draw the roombas
    for (int i =0 ; i < NUM_ROOMBAS; i++) {
        draw_roomba(roombas[i]);
    }

    update_roombas();

    glFlush();
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
}

void init( void ) {
    // select clearing color
    glClearColor( 0.0, 0.0, 0.0, 0.0 );

    // initialize viewing values
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}

int main( int argc, char** argv ) {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize( 500, 500 );
    glutInitWindowPosition( 100, 100 );
    glutCreateWindow( "Roomba Simulation" );
    init();
    glutDisplayFunc( display );
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;  
}




