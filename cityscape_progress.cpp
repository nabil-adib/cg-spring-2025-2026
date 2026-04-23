// things to add
// night stars, , park bench, shop banner, reverse car,

#include <windows.h>
#include <GL/glut.h>
#include <math.h>

float _cloud9001Move = 0.0f;
float _cloud9002Move = 0.0f;

float _car7001Move = 0.0f;
float _car7002Move = 0.0f;
float _car7003Move = 0.0f;
float _car7004Move = 0.0f;
float _car7005Move = 0.0f;
float _wheelAngle = 0.0f;

int trafficLight = 2;  // 0=red, 1=yellow, 2=GREEN

float speed = 1.0f;   //car speed for mouse

float _portalAngle = 0.0f;

bool isNight = false;

void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);
    for (int i = 0; i < 200; i++)
    {
        glColor3ub(r, g, b);
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float r = radius;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + xc, y + yc);
    }
    glEnd();
}

void drawWheel(float cx, float cy)
{
    glPushMatrix();
    glTranslatef(cx, cy, 0);
    glRotatef(_wheelAngle, 0, 0, 1);

    circle(0.9, 0, 0, 77, 71, 52);

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.9, 0);
    glVertex2f(0.9, 0);
    glEnd();

    glPopMatrix();
}

void id0001()
{ // Sky (Day/Night) id 0001
    if (isNight)
        glColor3ub(10, 10, 40); // dark blue night
    else
        glColor3ub(170, 216, 250); // day sky

    // top right sky
    glBegin(GL_QUADS);
    glVertex2f(92.0f, 49.0f);
    glVertex2f(92.0f, 80.0f);
    glVertex2f(150.0f, 80.0f);
    glVertex2f(150.0f, 49.0f);
    glEnd();

    // top left sky
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 49.0f);
    glVertex2f(0.0f, 80.0f);
    glVertex2f(60.5f, 80.0f);
    glVertex2f(60.5f, 49.0f);
    glEnd();
}
void id0002()
{ // Sun / Moon id 0002
    if (isNight)
    {
        // moon
        circle(4, 142, 74, 230, 230, 230);
    }
    else
    {
        // sun
        circle(4, 142, 74, 250, 235, 127);
    }
}

// Cloud 9000
void id9001()
{ // cloud1
    // cloud1
    circle(2, 20, 70, 233, 243, 252);
    circle(2, 24, 70, 233, 243, 252);
    circle(2, 28, 70, 233, 243, 252);
    circle(2, 22, 72, 233, 243, 252);
    circle(2, 26, 72, 233, 243, 252);
}
void id9002()
{ // cloud2
    // cloud2
    circle(2, 39, 75, 233, 243, 252);
    circle(2, 43, 75, 233, 243, 252);
    circle(2, 47, 75, 233, 243, 252);
    circle(2, 41, 77, 233, 243, 252);
    circle(2, 45, 77, 233, 243, 252);
}

// Road id 8000
void id8001()
{ // vertical road
    // vertical road
    glBegin(GL_QUADS);
    glColor3ub(155, 164, 169);
    glVertex2f(66.0f, 80.0f);
    glVertex2f(86.0f, 80.0f);
    glVertex2f(86.0f, 0.0f);
    glVertex2f(66.0f, 0.0f);
    glEnd();
}
void id8002()
{ // horizontal road
    // horizontal road
    glBegin(GL_QUADS);
    glColor3ub(155, 164, 169);
    glVertex2f(0.0f, 43.0f);
    glVertex2f(0.0f, 20.0f);
    glVertex2f(150.0f, 20.0f);
    glVertex2f(150.0f, 43.0f);
    glEnd();
}
void id8003()
{ // vertical road divider 1
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(75.5f, 80.0f);
    glVertex2f(76.5f, 80.0f);
    glVertex2f(76.5f, 44.0f);
    glVertex2f(75.5f, 44.0f);
    glEnd();
}
void id8004()
{ // vertical road divider 2
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(75.0f, 19.0f);
    glVertex2f(76.0f, 19.0f);
    glVertex2f(76.0f, 0.0f);
    glVertex2f(75.0f, 0.0f);
    glEnd();
}
void id8005()
{ // horizontal road divider 1
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(0.0f, 31.0f);
    glVertex2f(58.0f, 31.0f);
    glVertex2f(58.0f, 32.0f);
    glVertex2f(0.0f, 32.0f);
    glEnd();
}
void id8006()
{ // horizontal road divider 2
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(95.0f, 31.0f);
    glVertex2f(150.0f, 31.0f);
    glVertex2f(150.0f, 32.0f);
    glVertex2f(95.0f, 32.0f);
    glEnd();
}

void id1001()
{ // top left footpath (left)
    // top left footpath (left)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(0.0f, 49.0f);
    glVertex2f(0.0f, 43.0f);
    glVertex2f(66.0f, 43.0f);
    glVertex2f(60.5f, 49.0f);
    glEnd();
}
void id1002()
{ // top left footpath (up)
    // top left footpath (up)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(60.5f, 49.0f);
    glVertex2f(60.5f, 80.0f);
    glVertex2f(66.0f, 80.0f);
    glVertex2f(66.0f, 43.0f);
    glEnd();
}
void id1003()
{ // top right footpath (right)
    // top right footpath (right)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(86.0f, 43.0f);
    glVertex2f(92.0f, 49.0f);
    glVertex2f(150.0f, 49.0f);
    glVertex2f(150.0f, 43.0f);
    glEnd();
}
void id1004()
{ // top right footpath (up)
    // top right footpath (up)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(86.0f, 43.0f);
    glVertex2f(92.0f, 49.0f);
    glVertex2f(92.0f, 80.0f);
    glVertex2f(86.0f, 80.0f);
    glEnd();
}
void id1005()
{ // bottom right footpath (right)
    // bottom right footpath (right)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(86.0f, 15.0f);
    glVertex2f(86.0f, 20.0f);
    glVertex2f(150.0f, 20.0f);
    glVertex2f(150.0f, 15.0f);
    glEnd();
}
void id1006()
{ // bottom right footpath (bottom)
    // bottom right footpath (bottom)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(86.0f, 15.0f);
    glVertex2f(97.0f, 15.0f);
    glVertex2f(97.0f, 0.0f);
    glVertex2f(86.0f, 0.0f);
    glEnd();
}
void id1007()
{ // bottom left footpath (left)
    // bottom left footpath (left)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(66.0f, 15.0f);
    glVertex2f(66.0f, 20.0f);
    glVertex2f(0.0f, 20.0f);
    glVertex2f(0.0f, 15.0f);
    glEnd();
}
void id1008()
{ // bottom left footpath (bottom)
    // bottom left footpath (bottom)
    glBegin(GL_QUADS);
    glColor3ub(216, 216, 215);
    glVertex2f(59.0f, 0.0f);
    glVertex2f(66.0f, 0.0f);
    glVertex2f(66.0f, 15.0f);
    glVertex2f(59.0f, 15.0f);
    glEnd();
}

void id0003()
{ // zebra crossing    id 0003
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 40.0f);
    glVertex2f(60.0f, 41.0f);
    glVertex2f(65.0f, 41.0f);
    glVertex2f(65.0f, 40.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 37.0f);
    glVertex2f(60.0f, 38.0f);
    glVertex2f(65.0f, 38.0f);
    glVertex2f(65.0f, 37.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 33.0f);
    glVertex2f(60.0f, 34.0f);
    glVertex2f(65.0f, 34.0f);
    glVertex2f(65.0f, 33.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 30.0f);
    glVertex2f(60.0f, 31.0f);
    glVertex2f(65.0f, 31.0f);
    glVertex2f(65.0f, 30.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 27.0f);
    glVertex2f(60.0f, 28.0f);
    glVertex2f(65.0f, 28.0f);
    glVertex2f(65.0f, 27.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(60.0f, 24.0f);
    glVertex2f(60.0f, 25.0f);
    glVertex2f(65.0f, 25.0f);
    glVertex2f(65.0f, 24.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 40.0f);
    glVertex2f(88.0f, 41.0f);
    glVertex2f(93.0f, 41.0f);
    glVertex2f(93.0f, 40.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 37.0f);
    glVertex2f(88.0f, 38.0f);
    glVertex2f(93.0f, 38.0f);
    glVertex2f(93.0f, 37.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 33.0f);
    glVertex2f(88.0f, 34.0f);
    glVertex2f(93.0f, 34.0f);
    glVertex2f(93.0f, 33.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 30.0f);
    glVertex2f(88.0f, 31.0f);
    glVertex2f(93.0f, 31.0f);
    glVertex2f(93.0f, 30.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 27.0f);
    glVertex2f(88.0f, 28.0f);
    glVertex2f(93.0f, 28.0f);
    glVertex2f(93.0f, 27.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(251, 253, 250);
    glVertex2f(88.0f, 24.0f);
    glVertex2f(88.0f, 25.0f);
    glVertex2f(93.0f, 25.0f);
    glVertex2f(93.0f, 24.0f);
    glEnd();
}\
void id0004()
{ // Energy portal id 0004
    // portal
    circle(6, 138, 7, 163, 1, 246);
    circle(4, 138, 7, 5, 0, 16);
    circle(2, 138, 7, 1, 204, 207);
    circle(1, 138, 7, 255, 255, 255);
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(138,7);
    glVertex2f(144,7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(132,7);
    glVertex2f(138,7);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(138,7);
    glVertex2f(138,1);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(138,7);
    glVertex2f(138,13);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(134,11);
    glVertex2f(135,10);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(134,3);
    glVertex2f(135,4);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(141,4);
    glVertex2f(142,3);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(0,255,255);
    glVertex2f(141,10);
    glVertex2f(142,11);
    glEnd();
}
void id0005()
{ // Park id 0005
    // bottom left garden / park
    glBegin(GL_QUADS); // plants
    glColor3ub(123, 176, 53);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 15.0f);
    glVertex2f(59.0f, 15.0f);
    glVertex2f(59.0f, 0.0f);
    glEnd();
    glBegin(GL_QUADS); // soil
    glColor3ub(118, 84, 12);
    glVertex2f(4.0f, 2.0f);
    glVertex2f(4.0f, 12.0f);
    glVertex2f(56.0f, 12.0f);
    glVertex2f(56.0f, 2.0f);
    glEnd();
    glBegin(GL_QUADS); // waterbody
    glColor3ub(35, 138, 221);
    glVertex2f(12.0f, 4.0f);
    glVertex2f(12.0f, 10.0f);
    glVertex2f(24.0f, 10.0f);
    glVertex2f(24.0f, 4.0f);
    glEnd();
    // bush1
    circle(1, 34, 8, 76, 134, 8);
    circle(1, 34.5, 9, 76, 134, 8);
    circle(1, 35.5, 8, 76, 134, 8);
    circle(1, 36, 9, 76, 134, 8);
    circle(1, 37, 8, 76, 134, 8);
    // bush2
    circle(1, 41, 4, 76, 134, 8);
    circle(1, 41.5, 5, 76, 134, 8);
    circle(1, 42.5, 4, 76, 134, 8);
    circle(1, 43, 5, 76, 134, 8);
    circle(1, 44, 4, 76, 134, 8);
    // bush3
    circle(1, 48, 9, 76, 134, 8);
    circle(1, 49, 10, 76, 134, 8);
    circle(1, 50, 9, 76, 134, 8);
    circle(1, 51, 10, 76, 134, 8);
    circle(1, 52, 9, 76, 134, 8);
}
void id0006()
{ // top right background soil
    // top right background soil
    glBegin(GL_QUADS);
    glColor3ub(192, 169, 135);
    glVertex2f(107.5f, 49.0f);
    glVertex2f(107.5f, 54.0f);
    glVertex2f(138.0f, 54.0f);
    glVertex2f(138.0f, 49.0f);
    glEnd();
}
void id0007()
{ // bottom right background
    // bottom right background
    glBegin(GL_QUADS);
    glColor3ub(32, 33, 38);
    glVertex2f(97.0f, 0.0f);
    glVertex2f(97.0f, 15.0f);
    glVertex2f(150.0f, 15.0f);
    glVertex2f(150.0f, 0.0f);
    glEnd();
}

// Modern buildings with windows id 2000
void id2001()
{ // building1
    // building1
    glBegin(GL_QUADS); // roof
    glColor3ub(122, 159, 195);
    glVertex2f(92.0f, 65.0f);
    glVertex2f(92.0f, 72.0f);
    glVertex2f(107.5f, 72.0f);
    glVertex2f(107.5f, 65.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(92.0f, 65.0f);
    glVertex2f(92.0f, 72.0f);
    glVertex2f(107.5f, 72.0f);
    glVertex2f(107.5f, 65.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(91, 126, 154);
    glVertex2f(92.0f, 49.0f);
    glVertex2f(92.0f, 65.0f);
    glVertex2f(107.5f, 65.0f);
    glVertex2f(107.5f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(92.0f, 49.0f);
    glVertex2f(92.0f, 65.0f);
    glVertex2f(107.5f, 65.0f);
    glVertex2f(107.5f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // windows top-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(95.0f, 60.0f);
    glVertex2f(95.0f, 62.0f);
    glVertex2f(97.0f, 62.0f);
    glVertex2f(97.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(95.0f, 60.0f);
    glVertex2f(95.0f, 62.0f);
    glVertex2f(97.0f, 62.0f);
    glVertex2f(97.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // windows top-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(101.0f, 60.0f);
    glVertex2f(101.0f, 62.0f);
    glVertex2f(103.0f, 62.0f);
    glVertex2f(103.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(101.0f, 60.0f);
    glVertex2f(101.0f, 62.0f);
    glVertex2f(103.0f, 62.0f);
    glVertex2f(103.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // windows bottom-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(95.0f, 56.0f);
    glVertex2f(95.0f, 58.0f);
    glVertex2f(97.0f, 58.0f);
    glVertex2f(97.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(95.0f, 56.0f);
    glVertex2f(95.0f, 58.0f);
    glVertex2f(97.0f, 58.0f);
    glVertex2f(97.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // windows bottom-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(101.0f, 56.0f);
    glVertex2f(101.0f, 58.0f);
    glVertex2f(103.0f, 58.0f);
    glVertex2f(103.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(101.0f, 56.0f);
    glVertex2f(101.0f, 58.0f);
    glVertex2f(103.0f, 58.0f);
    glVertex2f(103.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(96, 95, 91);
    glVertex2f(99.0f, 49.0f);
    glVertex2f(99.0f, 54.0f);
    glVertex2f(101.0f, 54.0f);
    glVertex2f(101.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(99.0f, 49.0f);
    glVertex2f(99.0f, 54.0f);
    glVertex2f(101.0f, 54.0f);
    glVertex2f(101.0f, 49.0f);
    glEnd();
}
void id2002()
{ // building2
    // building2
    glBegin(GL_QUADS); // roof
    glColor3ub(227, 213, 178);
    glVertex2f(0.0f, 65.0f);
    glVertex2f(0.0f, 72.0f);
    glVertex2f(15.5f, 72.0f);
    glVertex2f(15.5f, 65.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.0f, 65.0f);
    glVertex2f(0.0f, 72.0f);
    glVertex2f(15.5f, 72.0f);
    glVertex2f(15.5f, 65.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(193, 174, 136);
    glVertex2f(0.0f, 49.0f);
    glVertex2f(0.0f, 65.0f);
    glVertex2f(15.5f, 65.0f);
    glVertex2f(15.5f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(0.0f, 49.0f);
    glVertex2f(0.0f, 65.0f);
    glVertex2f(15.5f, 65.0f);
    glVertex2f(15.5f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // window top-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(3.0f, 60.0f);
    glVertex2f(3.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);
    glVertex2f(5.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(3.0f, 60.0f);
    glVertex2f(3.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);
    glVertex2f(5.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(3.0f, 56.0f);
    glVertex2f(3.0f, 58.0f);
    glVertex2f(5.0f, 58.0f);
    glVertex2f(5.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(3.0f, 56.0f);
    glVertex2f(3.0f, 58.0f);
    glVertex2f(5.0f, 58.0f);
    glVertex2f(5.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // window top-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(3.0f, 60.0f);
    glVertex2f(3.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);
    glVertex2f(5.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(3.0f, 60.0f);
    glVertex2f(3.0f, 62.0f);
    glVertex2f(5.0f, 62.0f);
    glVertex2f(5.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // window top-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(9.0f, 60.0f);
    glVertex2f(9.0f, 62.0f);
    glVertex2f(11.0f, 62.0f);
    glVertex2f(11.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(9.0f, 60.0f);
    glVertex2f(9.0f, 62.0f);
    glVertex2f(11.0f, 62.0f);
    glVertex2f(11.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(9.0f, 56.0f);
    glVertex2f(9.0f, 58.0f);
    glVertex2f(11.0f, 58.0f);
    glVertex2f(11.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(9.0f, 56.0f);
    glVertex2f(9.0f, 58.0f);
    glVertex2f(11.0f, 58.0f);
    glVertex2f(11.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(179, 219, 237);
    glVertex2f(6.0f, 49.0f);
    glVertex2f(6.0f, 54.0f);
    glVertex2f(8.0f, 54.0f);
    glVertex2f(8.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(6.0f, 49.0f);
    glVertex2f(6.0f, 54.0f);
    glVertex2f(8.0f, 54.0f);
    glVertex2f(8.0f, 49.0f);
    glEnd();
}
void id2003()
{ // building3
    // building3
    glBegin(GL_QUADS); // roof
    glColor3ub(227, 213, 178);
    glVertex2f(45.0f, 65.0f);
    glVertex2f(45.0f, 72.0f);
    glVertex2f(60.5f, 72.0f);
    glVertex2f(60.5f, 65.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(45.0f, 65.0f);
    glVertex2f(45.0f, 72.0f);
    glVertex2f(60.5f, 72.0f);
    glVertex2f(60.5f, 65.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(193, 174, 136);
    glVertex2f(45.0f, 49.0f);
    glVertex2f(45.0f, 65.0f);
    glVertex2f(60.5f, 65.0f);
    glVertex2f(60.5f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(45.0f, 49.0f);
    glVertex2f(45.0f, 65.0f);
    glVertex2f(60.5f, 65.0f);
    glVertex2f(60.5f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // window top-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(48.0f, 60.0f);
    glVertex2f(48.0f, 62.0f);
    glVertex2f(50.0f, 62.0f);
    glVertex2f(50.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(48.0f, 60.0f);
    glVertex2f(48.0f, 62.0f);
    glVertex2f(50.0f, 62.0f);
    glVertex2f(50.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom-left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(48.0f, 56.0f);
    glVertex2f(48.0f, 58.0f);
    glVertex2f(50.0f, 58.0f);
    glVertex2f(50.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(48.0f, 56.0f);
    glVertex2f(48.0f, 58.0f);
    glVertex2f(50.0f, 58.0f);
    glVertex2f(50.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // window top-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(54.0f, 60.0f);
    glVertex2f(54.0f, 62.0f);
    glVertex2f(56.0f, 62.0f);
    glVertex2f(56.0f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(54.0f, 60.0f);
    glVertex2f(54.0f, 62.0f);
    glVertex2f(56.0f, 62.0f);
    glVertex2f(56.0f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom-right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(54.0f, 56.0f);
    glVertex2f(54.0f, 58.0f);
    glVertex2f(56.0f, 58.0f);
    glVertex2f(56.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(54.0f, 56.0f);
    glVertex2f(54.0f, 58.0f);
    glVertex2f(56.0f, 58.0f);
    glVertex2f(56.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(179, 219, 237);
    glVertex2f(52.0f, 49.0f);
    glVertex2f(52.0f, 54.0f);
    glVertex2f(54.0f, 54.0f);
    glVertex2f(54.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(52.0f, 49.0f);
    glVertex2f(52.0f, 54.0f);
    glVertex2f(54.0f, 54.0f);
    glVertex2f(54.0f, 49.0f);
    glEnd();
}

// Trees id 3000
void id3001()
{ // top right tree1
    // top right tree1
    glBegin(GL_QUADS); // trunk
    glColor3ub(101, 81, 59);
    glVertex2f(114.0f, 49.0f);
    glVertex2f(114.0f, 62.0f);
    glVertex2f(116.0f, 62.0f);
    glVertex2f(116.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(114.0f, 49.0f);
    glVertex2f(114.0f, 62.0f);
    glVertex2f(116.0f, 62.0f);
    glVertex2f(116.0f, 49.0f);
    glEnd();
    // leafs
    circle(2, 112, 63, 74, 130, 79);
    circle(2, 115, 63, 74, 130, 79);
    circle(2, 117, 63, 74, 130, 79);
    circle(2, 114, 64, 97, 152, 58);
    circle(2, 116, 64, 74, 130, 79);
    circle(2, 112, 66, 74, 130, 79);
    circle(2, 115, 66, 74, 130, 79);
    circle(2, 118, 66, 74, 130, 79);
    circle(2, 114, 68, 97, 152, 58);
    circle(2, 116, 68, 97, 152, 58);
}
void id3002()
{ // top right tree2
    // top right tree2
    glBegin(GL_QUADS); // trunk
    glColor3ub(103, 81, 57);
    glVertex2f(126.0f, 49.0f);
    glVertex2f(126.0f, 62.0f);
    glVertex2f(128.0f, 62.0f);
    glVertex2f(128.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(126.0f, 49.0f);
    glVertex2f(126.0f, 62.0f);
    glVertex2f(128.0f, 62.0f);
    glVertex2f(128.0f, 49.0f);
    glEnd();
    // leafs
    circle(2, 124, 62, 74, 130, 79);
    circle(2, 127, 63, 74, 130, 79);
    circle(2, 130, 62, 74, 130, 79);
    circle(2, 123, 65, 97, 152, 58);
    circle(2, 125.5, 65, 97, 152, 58);
    circle(2, 128.5, 65, 74, 130, 79);
    circle(2, 131, 65, 97, 152, 58);
    circle(2, 124, 68, 97, 152, 58);
    circle(2, 127, 68, 74, 130, 79);
    circle(2, 130, 68, 97, 152, 58);
}

void id4001()
{ // Street lights id 4001
    // lamp
    glBegin(GL_QUADS);
    glColor3ub(151, 163, 178);
    glVertex2f(61.0f, 12.5f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(61.8f, 18.0f);
    glVertex2f(61.8f, 12.5f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(61.0f, 12.5f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(61.8f, 18.0f);
    glVertex2f(61.8f, 12.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(151, 163, 178);
    glVertex2f(61.0f, 17.6f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(64.0f, 18.0f);
    glVertex2f(64.0f, 17.6f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(61.0f, 17.6f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(64.0f, 18.0f);
    glVertex2f(64.0f, 17.6f);
    glEnd();
    glBegin(GL_TRIANGLES);
    if (isNight)
        glColor3ub(246, 233, 130); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(63.5f, 17.6f);
    glVertex2f(64.0f, 16.6f);
    glVertex2f(64.5f, 17.6f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(63.5f, 17.6f);
    glVertex2f(64.0f, 16.6f);
    glVertex2f(64.5f, 17.6f);
    glEnd();
}

void id4002()
{ // Street lights id 4002

    glPushMatrix();
    glTranslatef(26.0f,35.5f,0.0f);
    // Street lights id 4001
    // lamp
    glBegin(GL_QUADS);
    glColor3ub(151, 163, 178);
    glVertex2f(61.0f, 12.5f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(61.8f, 18.0f);
    glVertex2f(61.8f, 12.5f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(61.0f, 12.5f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(61.8f, 18.0f);
    glVertex2f(61.8f, 12.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(151, 163, 178);
    glVertex2f(61.0f, 17.6f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(64.0f, 18.0f);
    glVertex2f(64.0f, 17.6f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(61.0f, 17.6f);
    glVertex2f(61.0f, 18.0f);
    glVertex2f(64.0f, 18.0f);
    glVertex2f(64.0f, 17.6f);
    glEnd();
    glBegin(GL_TRIANGLES);
    if (isNight)
        glColor3ub(246, 233, 130); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(63.5f, 17.6f);
    glVertex2f(64.0f, 16.6f);
    glVertex2f(64.5f, 17.6f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(63.5f, 17.6f);
    glVertex2f(64.0f, 16.6f);
    glVertex2f(64.5f, 17.6f);
    glEnd();

    glPopMatrix();
}

// Shops id 5000
void id5001()
{ // shop1
    // shop1
    glBegin(GL_QUADS); // Roof
    glColor3ub(143, 146, 154);
    glVertex2f(138.0f, 56.0f);
    glVertex2f(138.0f, 58.0f);
    glVertex2f(150.0f, 58.0f);
    glVertex2f(150.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(138.0f, 56.0f);
    glVertex2f(138.0f, 58.0f);
    glVertex2f(150.0f, 58.0f);
    glVertex2f(150.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // Main Wall
    glColor3ub(105, 112, 123);
    glVertex2f(138.0f, 49.0f);
    glVertex2f(138.0f, 56.0f);
    glVertex2f(150.0f, 56.0f);
    glVertex2f(150.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(138.0f, 49.0f);
    glVertex2f(138.0f, 56.0f);
    glVertex2f(150.0f, 56.0f);
    glVertex2f(150.0f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // Left Window
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(140.0f, 52.0f);
    glVertex2f(140.0f, 54.0f);
    glVertex2f(142.0f, 54.0f);
    glVertex2f(142.0f, 52.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(140.0f, 52.0f);
    glVertex2f(140.0f, 54.0f);
    glVertex2f(142.0f, 54.0f);
    glVertex2f(142.0f, 52.0f);
    glEnd();
    glBegin(GL_QUADS); // Right Window
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(146.0f, 52.0f);
    glVertex2f(146.0f, 54.0f);
    glVertex2f(148.0f, 54.0f);
    glVertex2f(148.0f, 52.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(146.0f, 52.0f);
    glVertex2f(146.0f, 54.0f);
    glVertex2f(148.0f, 54.0f);
    glVertex2f(148.0f, 52.0f);
    glEnd();
    glBegin(GL_QUADS); // Door
    glColor3ub(94, 74, 76);
    glVertex2f(143.0f, 49.0f);
    glVertex2f(143.0f, 55.0f);
    glVertex2f(145.0f, 55.0f);
    glVertex2f(145.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(143.0f, 49.0f);
    glVertex2f(143.0f, 55.0f);
    glVertex2f(145.0f, 55.0f);
    glVertex2f(145.0f, 49.0f);
    glEnd();
}
void id5002()
{ // shop2
    // shop2
    glBegin(GL_QUADS); // roof
    glColor3ub(211, 202, 190);
    glVertex2f(32.0f, 60.0f);
    glVertex2f(32.0f, 66.0f);
    glVertex2f(15.5f, 66.0f);
    glVertex2f(15.5f, 60.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(32.0f, 60.0f);
    glVertex2f(32.0f, 66.0f);
    glVertex2f(15.5f, 66.0f);
    glVertex2f(15.5f, 60.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(166, 158, 152);
    glVertex2f(32.0f, 49.0f);
    glVertex2f(32.0f, 60.0f);
    glVertex2f(15.5f, 60.0f);
    glVertex2f(15.5f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(32.0f, 49.0f);
    glVertex2f(32.0f, 60.0f);
    glVertex2f(15.5f, 60.0f);
    glVertex2f(15.5f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // window top
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(18.0f, 56.0f);
    glVertex2f(18.0f, 58.0f);
    glVertex2f(24.5f, 58.0f);
    glVertex2f(24.5f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(18.0f, 56.0f);
    glVertex2f(18.0f, 58.0f);
    glVertex2f(24.5f, 58.0f);
    glVertex2f(24.5f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(18.0f, 52.0f);
    glVertex2f(18.0f, 54.0f);
    glVertex2f(24.5f, 54.0f);
    glVertex2f(24.5f, 52.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(18.0f, 52.0f);
    glVertex2f(18.0f, 54.0f);
    glVertex2f(24.5f, 54.0f);
    glVertex2f(24.5f, 52.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(96, 97, 106);
    glVertex2f(26.0f, 49.0f);
    glVertex2f(26.0f, 56.0f);
    glVertex2f(30.0f, 56.0f);
    glVertex2f(30.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(26.0f, 49.0f);
    glVertex2f(26.0f, 56.0f);
    glVertex2f(30.0f, 56.0f);
    glVertex2f(30.0f, 49.0f);
    glEnd();
}
void id5003()
{ // shop3
    // shop3
    glBegin(GL_QUADS); // roof
    glColor3ub(155, 129, 108);
    glVertex2f(32.0f, 56.0f);
    glVertex2f(32.0f, 58.0f);
    glVertex2f(45.0f, 58.0f);
    glVertex2f(45.0f, 56.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(32.0f, 56.0f);
    glVertex2f(32.0f, 58.0f);
    glVertex2f(45.0f, 58.0f);
    glVertex2f(45.0f, 56.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(114, 91, 78);
    glVertex2f(32.0f, 49.0f);
    glVertex2f(32.0f, 56.0f);
    glVertex2f(45.0f, 56.0f);
    glVertex2f(45.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(32.0f, 49.0f);
    glVertex2f(32.0f, 56.0f);
    glVertex2f(45.0f, 56.0f);
    glVertex2f(45.0f, 49.0f);
    glEnd();
    glBegin(GL_QUADS); // window left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(34.0f, 52.0f);
    glVertex2f(34.0f, 54.0f);
    glVertex2f(36.0f, 54.0f);
    glVertex2f(36.0f, 52.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(34.0f, 52.0f);
    glVertex2f(34.0f, 54.0f);
    glVertex2f(36.0f, 54.0f);
    glVertex2f(36.0f, 52.0f);
    glEnd();
    glBegin(GL_QUADS); // window right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(40.0f, 52.0f);
    glVertex2f(40.0f, 54.0f);
    glVertex2f(42.0f, 54.0f);
    glVertex2f(42.0f, 52.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(40.0f, 52.0f);
    glVertex2f(40.0f, 54.0f);
    glVertex2f(42.0f, 54.0f);
    glVertex2f(42.0f, 52.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(80, 63, 51);
    glVertex2f(37.0f, 49.0f);
    glVertex2f(37.0f, 55.0f);
    glVertex2f(39.0f, 55.0f);
    glVertex2f(39.0f, 49.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(37.0f, 49.0f);
    glVertex2f(37.0f, 55.0f);
    glVertex2f(39.0f, 55.0f);
    glVertex2f(39.0f, 49.0f);
    glEnd();
}
void id5004()
{ // shop4
    // shop4
    glBegin(GL_QUADS); // roof
    glColor3ub(155, 129, 108);
    glVertex2f(97.0f, 7.0f);
    glVertex2f(97.0f, 9.0f);
    glVertex2f(109.0f, 9.0f);
    glVertex2f(109.0f, 7.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(97.0f, 7.0f);
    glVertex2f(97.0f, 9.0f);
    glVertex2f(109.0f, 9.0f);
    glVertex2f(109.0f, 7.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(114, 91, 78);
    glVertex2f(97.0f, 0.0f);
    glVertex2f(97.0f, 7.0f);
    glVertex2f(109.0f, 7.0f);
    glVertex2f(109.0f, 0.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(97.0f, 0.0f);
    glVertex2f(97.0f, 7.0f);
    glVertex2f(109.0f, 7.0f);
    glVertex2f(109.0f, 0.0f);
    glEnd();
    glBegin(GL_QUADS); // window left
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(99.0f, 3.0f);
    glVertex2f(99.0f, 5.0f);
    glVertex2f(101.0f, 5.0f);
    glVertex2f(101.0f, 3.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(99.0f, 3.0f);
    glVertex2f(99.0f, 5.0f);
    glVertex2f(101.0f, 5.0f);
    glVertex2f(101.0f, 3.0f);
    glEnd();
    glBegin(GL_QUADS); // window right
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(105.0f, 3.0f);
    glVertex2f(105.0f, 5.0f);
    glVertex2f(107.0f, 5.0f);
    glVertex2f(107.0f, 3.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(105.0f, 3.0f);
    glVertex2f(105.0f, 5.0f);
    glVertex2f(107.0f, 5.0f);
    glVertex2f(107.0f, 3.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(80, 63, 51);
    glVertex2f(102.0f, 0.0f);
    glVertex2f(102.0f, 6.0f);
    glVertex2f(104.0f, 6.0f);
    glVertex2f(104.0f, 0.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(102.0f, 0.0f);
    glVertex2f(102.0f, 6.0f);
    glVertex2f(104.0f, 6.0f);
    glVertex2f(104.0f, 0.0f);
    glEnd();
}
void id5005()
{ // shop5
    // shop5
    glBegin(GL_QUADS); // roof
    glColor3ub(156, 155, 160);
    glVertex2f(109.0f, 11.0f);
    glVertex2f(109.0f, 17.0f);
    glVertex2f(125.5f, 17.0f);
    glVertex2f(125.5f, 11.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(109.0f, 11.0f);
    glVertex2f(109.0f, 17.0f);
    glVertex2f(125.5f, 17.0f);
    glVertex2f(125.5f, 11.0f);
    glEnd();
    glBegin(GL_QUADS); // wall
    glColor3ub(98, 96, 97);
    glVertex2f(109.0f, 0.0f);
    glVertex2f(109.0f, 11.0f);
    glVertex2f(125.5f, 11.0f);
    glVertex2f(125.5f, 0.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(109.0f, 0.0f);
    glVertex2f(109.0f, 11.0f);
    glVertex2f(125.5f, 11.0f);
    glVertex2f(125.5f, 0.0f);
    glEnd();
    glBegin(GL_QUADS); // window top
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(111.5f, 7.0f);
    glVertex2f(111.5f, 9.0f);
    glVertex2f(117.5f, 9.0f);
    glVertex2f(117.5f, 7.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(111.5f, 7.0f);
    glVertex2f(111.5f, 9.0f);
    glVertex2f(117.5f, 9.0f);
    glVertex2f(117.5f, 7.0f);
    glEnd();
    glBegin(GL_QUADS); // window bottom
    if (isNight)
        glColor3ub(255, 240, 150); // night
    else
        glColor3ub(86, 104, 116); // day
    glVertex2f(111.5f, 3.0f);
    glVertex2f(111.5f, 5.0f);
    glVertex2f(117.5f, 5.0f);
    glVertex2f(117.5f, 3.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(111.5f, 3.0f);
    glVertex2f(111.5f, 5.0f);
    glVertex2f(117.5f, 5.0f);
    glVertex2f(117.5f, 3.0f);
    glEnd();
    glBegin(GL_QUADS); // door
    glColor3ub(93, 72, 75);
    glVertex2f(119.5f, 0.0f);
    glVertex2f(119.5f, 7.0f);
    glVertex2f(123.5f, 7.0f);
    glVertex2f(123.5f, 0.0f);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex2f(119.5f, 0.0f);
    glVertex2f(119.5f, 7.0f);
    glVertex2f(123.5f, 7.0f);
    glVertex2f(123.5f, 0.0f);
    glEnd();
}

void id6001()
{ // Traffic signal id 6001
    // traffic light
    glBegin(GL_QUADS);
    glColor3ub(60, 61, 58);
    glVertex2f(63.5f, 44.0f);
    glVertex2f(63.5f, 51.5f);
    glVertex2f(64.0f, 51.5f);
    glVertex2f(64.0f, 44.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(60, 61, 58);
    glVertex2f(64.5f, 51.5f);
    glVertex2f(64.5f, 56.0f);
    glVertex2f(63.0f, 56.0f);
    glVertex2f(63.0f, 51.5f);
    glEnd();

    //red
    if (trafficLight == 0)
        circle(0.5, 63.8, 55.3, 255, 0, 0);
    else
        circle(0.5, 63.8, 55.3, 60, 0, 0);

    //yellow
    if (trafficLight == 1)
        circle(0.5, 63.8, 53.9, 255, 255, 0);
    else
        circle(0.5, 63.8, 53.9, 80, 80, 0);

    //green
    if (trafficLight == 2)
        circle(0.5, 63.8, 52.5, 0, 255, 0);
    else
        circle(0.5, 63.8, 52.5, 0, 80, 0);

}
void id6002()
{ // Traffic signal id 6002

    glPushMatrix();
    glTranslatef(26.5f, -39.5f, 0.0f);
    // traffic light id6001
    glBegin(GL_QUADS);
    glColor3ub(60, 61, 58);
    glVertex2f(63.5f, 44.0f);
    glVertex2f(63.5f, 51.5f);
    glVertex2f(64.0f, 51.5f);
    glVertex2f(64.0f, 44.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(60, 61, 58);
    glVertex2f(64.5f, 51.5f);
    glVertex2f(64.5f, 56.0f);
    glVertex2f(63.0f, 56.0f);
    glVertex2f(63.0f, 51.5f);
    glEnd();
    //red
    if (trafficLight == 0)
        circle(0.5, 63.8, 55.3, 255, 0, 0);
    else
        circle(0.5, 63.8, 55.3, 60, 0, 0);

    //yellow
    if (trafficLight == 1)
        circle(0.5, 63.8, 53.9, 255, 255, 0);
    else
        circle(0.5, 63.8, 53.9, 80, 80, 0);

    //green
    if (trafficLight == 2)
        circle(0.5, 63.8, 52.5, 0, 255, 0);
    else
        circle(0.5, 63.8, 52.5, 0, 80, 0);

    glPopMatrix();
}




// Cars id 7000
void id7001()
{ // car1
    // car1
    glBegin(GL_QUADS);
    glColor3ub(239, 238, 241);
    glVertex2f(76.0f, 7.0f);
    glVertex2f(76.0f, 9.5f);
    glVertex2f(79.0f, 9.5f);
    glVertex2f(79.0f, 7.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(187, 188, 193);
    glVertex2f(76.0f, 9.5f);
    glVertex2f(76.0f, 13.0f);
    glVertex2f(79.0f, 13.0f);
    glVertex2f(79.0f, 9.5);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(77.5f, 9.5f);
    glVertex2f(77.5f, 7.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);
    glVertex2f(76.0f, 7.0f);
    glVertex2f(76.0f, 7.5f);
    glVertex2f(79.0f, 7.5f);
    glVertex2f(79.0f, 7.0f);
    glEnd();
}
void id7002()
{ // car2
    // car2
    glBegin(GL_QUADS);
    glColor3ub(129, 35, 36);
    glVertex2f(70.0f, 55.0f);
    glVertex2f(70.0f, 57.5f);
    glVertex2f(73.0f, 57.5f);
    glVertex2f(73.0f, 55.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(211, 64, 57);
    glVertex2f(70.0f, 57.5f);
    glVertex2f(70.0f, 61.0f);
    glVertex2f(73.0f, 61.0f);
    glVertex2f(73.0f, 57.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(100, 100, 100);
    glVertex2f(71.5f, 57.5f);
    glVertex2f(71.5f, 55.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(10, 10, 10);
    glVertex2f(70.0f, 55.0f);
    glVertex2f(70.0f, 55.5f);
    glVertex2f(73.0f, 55.5f);
    glVertex2f(73.0f, 55.0f);
    glEnd();
}
void id7003()
{ // car3
    // car3
    glBegin(GL_QUADS); // body
    glColor3ub(200, 167, 36);
    glVertex2f(12.5f, 36.5f);
    glVertex2f(12.5f, 38.0f);
    glVertex2f(22.5f, 38.0f);
    glVertex2f(22.5f, 36.5f);
    glEnd();
    glBegin(GL_POLYGON); // bonnet
    glColor3ub(247, 215, 55);
    glVertex2f(12.5f, 38.0f);
    glVertex2f(12.5f, 39.0f);
    glVertex2f(15.0f, 40.0f);
    glVertex2f(22.5f, 40.0f);
    glVertex2f(22.5f, 38.0f);
    glEnd();
    glBegin(GL_QUADS); // roof
    glColor3ub(247, 215, 55);
    glVertex2f(16.5f, 38.5f);
    glVertex2f(16.5f, 41.0f);
    glVertex2f(20.0f, 41.0f);
    glVertex2f(20.0f, 38.5f);
    glEnd();
    glBegin(GL_QUADS); // car_windows
    glColor3ub(70, 80, 84);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(15.0f, 40.0f);
    glVertex2f(16.5f, 41.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(21.0f, 38.0f);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(21.0f, 38.0f);
    glVertex2f(21.0f, 40.0f);
    glVertex2f(20.0f, 41.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(247, 215, 55);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(247, 215, 55);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(21.0f, 38.0f);
    glEnd();
    // wheel
    drawWheel(14.5, 36.5);
    drawWheel(21, 36.5);
}

void id7004()
{ // car4
    glPushMatrix();
    glTranslatef(116.5f, -2.5f, 0.0f);
    // car3
    glBegin(GL_QUADS); // body
    glColor3ub(47, 112, 172);
    glVertex2f(12.5f, 36.5f);
    glVertex2f(12.5f, 38.0f);
    glVertex2f(22.5f, 38.0f);
    glVertex2f(22.5f, 36.5f);
    glEnd();
    glBegin(GL_POLYGON); // bonnet
    glColor3ub(83, 165, 225);
    glVertex2f(12.5f, 38.0f);
    glVertex2f(12.5f, 39.0f);
    glVertex2f(15.0f, 40.0f);
    glVertex2f(22.5f, 40.0f);
    glVertex2f(22.5f, 38.0f);
    glEnd();
    glBegin(GL_QUADS); // roof
    glColor3ub(83, 165, 225);
    glVertex2f(16.5f, 38.5f);
    glVertex2f(16.5f, 41.0f);
    glVertex2f(20.0f, 41.0f);
    glVertex2f(20.0f, 38.5f);
    glEnd();
    glBegin(GL_QUADS); // car_windows
    glColor3ub(70, 80, 84);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(15.0f, 40.0f);
    glVertex2f(16.5f, 41.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(21.0f, 38.0f);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(21.0f, 38.0f);
    glVertex2f(21.0f, 40.0f);
    glVertex2f(20.0f, 41.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83, 165, 225);
    glVertex2f(15.0f, 38.0f);
    glVertex2f(16.5f, 39.0f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(83, 165, 225);
    glVertex2f(20.0f, 39.0f);
    glVertex2f(21.0f, 38.0f);
    glEnd();
    // wheel
    drawWheel(14.5, 36.5);
    drawWheel(21, 36.5);

    glPopMatrix();
}
void id7005()
{ // car5
    glBegin(GL_QUADS); // body
    glColor3ub(62, 150, 66);
    glVertex2f(46.0f, 25.5f);
    glVertex2f(46.0f, 24.0f);
    glVertex2f(56.0f, 24.0f);
    glVertex2f(56.0f, 25.5f);
    glEnd();
    glBegin(GL_POLYGON); // bonnet
    glColor3ub(115, 202, 102);
    glVertex2f(46.0f, 25.5f);
    glVertex2f(46.0f, 27.5f);
    glVertex2f(53.0f, 27.5f);
    glVertex2f(56.0f, 27.5f);
    glVertex2f(56.0f, 25.5f);
    glEnd();
    glBegin(GL_QUADS); // roof
    glColor3ub(115, 202, 102);
    glVertex2f(48.0f, 26.5f);
    glVertex2f(48.0f, 28.5f);
    glVertex2f(52.0f, 28.5f);
    glVertex2f(52.0f, 26.5f);
    glEnd();
    glBegin(GL_QUADS); // car_windows
    glColor3ub(70, 80, 84);
    glVertex2f(47.0f, 25.5f);
    glVertex2f(47.0f, 27.5f);
    glVertex2f(48.0f, 28.5f);
    glVertex2f(48.0f, 26.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(47.0f, 25.5f);
    glVertex2f(48.0f, 26.5f);
    glVertex2f(52.0f, 26.5f);
    glVertex2f(53.0f, 25.5f);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70, 80, 84);
    glVertex2f(52.0f, 26.5f);
    glVertex2f(52.0f, 28.5f);
    glVertex2f(53.0f, 27.5f);
    glVertex2f(53.0f, 25.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(115, 202, 102);
    glVertex2f(47.0f, 25.5f);
    glVertex2f(48.0f, 26.5f);
    glEnd();
    glBegin(GL_LINES);
    glColor3ub(115, 202, 102);
    glVertex2f(52.0f, 26.5f);
    glVertex2f(53.0f, 25.5f);
    glEnd();
    // wheel
    drawWheel(48, 24);
    drawWheel(54, 24);

    glPopMatrix();
}

void update(int value)
{
    // cloud 9001 animation
    _cloud9001Move += 0.1f;
    if (_cloud9001Move > 160)
    {
        _cloud9001Move = -30.0f;
    }

    // cloud 9002 animation
    _cloud9002Move += 0.07f;
    if (_cloud9002Move > 160)
    {
        _cloud9002Move = -40.0f;
    }

    if (trafficLight == 2 || trafficLight == 1){
        // car 7001 animation
        _car7001Move += 0.1f *speed;
        if (_car7001Move > 80)
        {
            _car7001Move = -30.0f;
        }

        // car 7002 animation
        _car7002Move += 0.08f *speed;
        if (_car7002Move > 50)
        {
            _car7002Move = -70.0f;
        }

        // car 7003 animation
        _car7003Move -= 0.2f *speed;
        _wheelAngle += 5.0f;

        if (_car7003Move < -30.0f)
        {
            _car7003Move = 160.0f;
        }

        // car 7004 animation
        _car7004Move -= 0.15f *speed;
        _wheelAngle += 5.0f;

        if (_car7004Move < -140.0f)
        {
            _car7004Move = 50.0f;
        }

        // car 7005 animation
        _car7005Move += 0.09f *speed;
        _wheelAngle -= 5.0f;

        if (_car7004Move > 110.0f)
        {
            _car7004Move = -60.0f;
        }

        //portal 0004 animation
        _portalAngle += 2.0f;
        if (_portalAngle > 360)
            _portalAngle -= 360;
            }



    glutPostRedisplay();
    glutTimerFunc(20, update, 0);
}

void display()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Border
    glBegin(GL_LINE_LOOP); // border outline
    glColor3ub(0, 0, 0);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.0f, 80.0f);
    glVertex2f(150.0f, 80.0f);
    glVertex2f(150.0f, 0.0f);
    glEnd();

    // sky
    id0001();

    // sun or moon
    id0002();

    // cloud1 id9001
    glPushMatrix();
    glTranslatef(_cloud9001Move, 0.0f, 0.0f);
    id9001();
    glPopMatrix();

    // cloud2 id9002
    glPushMatrix();
    glTranslatef(_cloud9002Move, 0.0f, 0.0f);
    id9002();
    glPopMatrix();

    // vertical road id8001
    id8001();
    id8003(); // divider
    id8004(); // divider

    // horizontal road id8002
    id8002();
    id8005(); // divider
    id8006(); // divider

    id0003(); // zebra crossing    id 0003

    // car1 id7001
    glPushMatrix();
    glTranslatef(0.0f, _car7001Move, 0.0f);
    id7001();
    glPopMatrix();

    // car2 id7002
    glPushMatrix();
    glTranslatef(0.0f, _car7002Move, 0.0f);
    id7002();
    glPopMatrix();

    // car3 id7003
    glPushMatrix();
    glTranslatef(_car7003Move, 0.0f, 0.0f);
    id7003();
    glPopMatrix();

    //car3 id7004
    glPushMatrix();
    glTranslatef(_car7004Move, 0.0f, 0.0f);
    id7004();
    glPopMatrix();

    //car3 id7005
    glPushMatrix();
    glTranslatef(_car7005Move, 0.0f, 0.0f);
    id7005();
    glPopMatrix();


    // Footpath
    // top left footpath (left) id1001
    id1001();

    // (up) id1002
    id1002();

    // top right footpath (right) id1003
    id1003();

    //(up) id1004
    id1004();

    // bottom right footpath (right) id1005
    id1005();

    //(bottom) id1006
    id1006();

    // bottom left footpath (left) id1007
    id1007();

    //(bottom) id1008
    id1008();

    // traffic light id6001
    id6001();

    // traffic light id6002
    id6002();

    // street lights id4001
    id4001();

    // street lights id4002
    id4002();


    // bottom left area
    // garden / park id0005
    id0005();

    // top right area
    // building1 id2001
    id2001();

    // background soil id0006
    id0006();

    // tree1 id3001
    id3001();

    // tree2 id3002
    id3002();

    // shop id5001
    id5001();

    // top left area
    // building id2002
    id2002();

    // shop id5002
    id5002();

    // shop id5003
    id5003();

    // building id2003
    id2003();

    // bottom right area
    //  bottom right background id0007
    id0007();

    // shop4 id5004
    id5004();

    // shop5 id5005
    id5005();

    // portal id0004
    glPushMatrix();
    glTranslatef(138, 7, 0);
    glRotatef(_portalAngle, 0, 0, 1);
    glTranslatef(-138, -7, 0);
    id0004();
    glPopMatrix();



    glutSwapBuffers();
    glFlush();
}

void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'n': // night
        isNight = true;
        break;

    case 'd': // day
        isNight = false;
        break;

    case 'r': // traffic light red
        trafficLight = 0;
        break;

    case 'y': // traffic light yellow
        trafficLight = 1;
        break;

    case 'g': // traffic light green
        trafficLight = 2;
        break;
    }

    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON)
        {
            speed += 0.5f;
        }
        else if (button == GLUT_RIGHT_BUTTON)
        {
            speed -= 0.5f;
        }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1600, 900);
    glutCreateWindow("Modern City");
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(20, update, 0);
    gluOrtho2D(0, 150, 0, 80);
    glutMainLoop();
    return 0;
}
