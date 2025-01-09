#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include "primitives.cpp"

struct Roomba {
    double x, y;
    double vel;
    double bearing;
    double radius;
    float r, g, b;
    double mass;

    Roomba(double x, double y, double radius) {
        this->x = x;
        this->y = y;
        this->vel = 0;
        this->bearing = 0;
        this->radius = radius;
        this->mass = 2.0;

        // Pick a random color
        this->r = (135 + (random() % 135))/255.0;
        this->g = (135 + (random() % 135))/255.0;
        this->b = (135 + (random() % 135))/255.0;
    }
};

struct Wall {
    double x, y, w, h;

    Wall(double x, double y, double w, double h) {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }
};

// Does any part of the roomba overlap with any part of the wall?
bool does_roomba_touch_wall(Roomba* r, Wall* w) {
    float px = r->x;
    float py = r->y;
    px = fmax(px, w->x);
    px = fmin(px, w->x + w->w);
    py = fmax(py, w->y);
    py = fmin(py, w->y + w->h);
    
    return pow((r->y - py), 2) + pow(r->x - px, 2) < pow(r->radius, 2);
}

// Updates a roomba's movement, frame time dependent
void tick_roomba(Roomba* r, Wall* walls, int num_walls, double dt) {
   double x_comp = dt * r->vel * cos(r->bearing);
   double y_comp = dt * r->vel * sin(r->bearing);
   r->x += x_comp;

   // Check if the X component causes the roomba to hit the wall
   // if it does, don't add it
   for (int i=0; i<num_walls; i++)
       if (does_roomba_touch_wall(r, &(walls[i])))
           r->x -= x_comp;

   // Check if the Y component causes the roomba to hit the wall
   // if it does, don't add it
   r->y += y_comp;
   for (int i=0; i<num_walls; i++)
       if (does_roomba_touch_wall(r, &(walls[i])))
           r->y -= y_comp;
}

// Apply a force to a roomba (accelerate him)
void apply_roomba_force(Roomba* r, double amt, double dt) {
    r->vel += (amt/r->mass)*dt;
}

// Draw our lil' guy :)
void draw_roomba(Roomba* r) {
    // Main body gets to be a cool color
    glColor3f(r->r, r->g, r->b);
    draw_circle(r->x, r->y, r->radius);

    // Then we'll put a little dot so we know where he's facing
    glColor3f(255, 255, 255);
    draw_circle(r->x + r->radius*0.5*cos(r->bearing), r->y + r->radius*0.5*sin(r->bearing), 5);
}

void draw_wall(Wall* w) {
    draw_rect(w->x, w->y, w->w, w->h);
}

