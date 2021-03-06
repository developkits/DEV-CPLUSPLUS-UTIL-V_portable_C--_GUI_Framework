//=======================================================================
//@V@:Note: This file generated by vgen V1.04 (09:06:20 22 Jun 1998).
//	cubecnv.cpp:	Source for cubeOGLCanvasPane class
//=======================================================================

#include "cubecnv.h"
//
// This program based on cube demo from GLUT distribution:

// Copyright (c) Mark J. Kilgard, 1997.

// This program is freely distributable without licensing fees 
//   and is provided without guarantee or warrantee expressed or 
//   implied. This program is -not- in the public domain.

// This program was requested by Patrick Earl; hopefully someone else
//   will write the equivalent Direct3D immediate mode program.
//###############################################################

// BEW's Note: I've left the code as close to the original as possible,
// including leaving it mostly C-like. This means things aren't
// as hidden as C++ likes. But it was a VERY easy conversion!
//
// This program took about 15 minutes to generate from the original
// demo code - honest! Here's what I did:
// 1) Used VGen to generate a shell V OpenGL app called cube.
// 2) Copied the original GLUT example to this file. Added
//    call to init() in graphicsInit(), and a call to display()
//    in Redraw. Removed glut call from display. Removed excess
//    code from glut cube demo source (main, etc.)
// 3) Changed Test button in cubecmdw.cpp to Exit.
// 4) Changed canvas size to 300 by 300 in cubeapp.cpp.
// THAT'S IT! Ran perfectly first time (well, I actually forgot to
//   change the canvas size until after I ran the program once....)
//
// These lines come from the front of the original cube.c, including
// the global functions drawBox and display....

GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};  /* Infinite light location. */
GLfloat n[6][3] = {  /* Normals for the 6 faces of a cube. */
  {-1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {1.0, 0.0, 0.0},
  {0.0, -1.0, 0.0}, {0.0, 0.0, 1.0}, {0.0, 0.0, -1.0} };
GLint faces[6][4] = {  /* Vertex indices for the 6 faces of a cube. */
  {0, 1, 2, 3}, {3, 2, 6, 7}, {7, 6, 5, 4},
  {4, 5, 1, 0}, {5, 6, 2, 1}, {7, 4, 0, 3} };
GLfloat v[8][3];  /* Will be filled in with X,Y,Z vertexes. */

void
drawBox(void)
{
  int i;

  for (i = 0; i < 6; i++) {
    glBegin(GL_QUADS);
    glNormal3fv(&n[i][0]);
    glVertex3fv(&v[faces[i][0]][0]);
    glVertex3fv(&v[faces[i][1]][0]);
    glVertex3fv(&v[faces[i][2]][0]);
    glVertex3fv(&v[faces[i][3]][0]);
    glEnd();
  }
}

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  drawBox();
//  glutSwapBuffers();
}

void
init(void)
{
  /* Setup cube vertex data. */
  v[0][0] = v[1][0] = v[2][0] = v[3][0] = -1;
  v[4][0] = v[5][0] = v[6][0] = v[7][0] = 1;
  v[0][1] = v[1][1] = v[4][1] = v[5][1] = -1;
  v[2][1] = v[3][1] = v[6][1] = v[7][1] = 1;
  v[0][2] = v[3][2] = v[4][2] = v[7][2] = 1;
  v[1][2] = v[2][2] = v[5][2] = v[6][2] = -1;

  /* Enable a single OpenGL light. */
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);

  /* Use depth buffering for hidden surface elimination. */
  glEnable(GL_DEPTH_TEST);

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  gluPerspective( /* field of view in degree */ 40.0,
    /* aspect ratio */ 1.0,
    /* Z near */ 1.0, /* Z far */ 10.0);
  glMatrixMode(GL_MODELVIEW);
  gluLookAt(0.0, 0.0, 5.0,  /* eye is at (0,0,5) */
    0.0, 0.0, 0.0,      /* center is at (0,0,0) */
    0.0, 1.0, 0.);      /* up is in positive Y direction */

  /* Adjust cube position to be asthetic angle. */
  glTranslatef(0.0, 0.0, -1.0);
  glRotatef(60, 1.0, 0.0, 0.0);
  glRotatef(-20, 0.0, 0.0, 1.0);
}


//===================>>> cubeOGLCanvasPane::cubeOGLCanvasPane <<<====================
  cubeOGLCanvasPane::cubeOGLCanvasPane()
  {
    initDone = 0;
  }

//===================>>> cubeOGLCanvasPane::~cubeOGLCanvasPane <<<====================
  cubeOGLCanvasPane::~cubeOGLCanvasPane()
  {
  }

//======================>>> cubeOGLCanvasPane::graphicsInit <<<========================
  void cubeOGLCanvasPane::graphicsInit(void)
  {
    vBaseGLCanvasPane::graphicsInit();	// Always call the superclass first!

    // **** Your OpenGL initialization code goes here!

    init();		// call original init code...

    initDone = 1;
  }
//======================>>> cubeOGLCanvasPane::HPage <<<========================
  void cubeOGLCanvasPane::HPage(int shown, int top)
  {
    vBaseGLCanvasPane::HPage(shown, top);
  }

//======================>>> cubeOGLCanvasPane::VPage <<<========================
  void cubeOGLCanvasPane::VPage(int shown, int top)
  {
    vBaseGLCanvasPane::VPage(shown, top);
  }

//=======================>>> cubeOGLCanvasPane::HScroll <<<======================
  void cubeOGLCanvasPane::HScroll(int step)
  {
    vBaseGLCanvasPane::HScroll(step);
  }

//======================>>> cubeOGLCanvasPane::VScroll <<<======================
  void cubeOGLCanvasPane::VScroll(int step)
  {
    vBaseGLCanvasPane::VScroll(step);
  }

//======================>>> cubeOGLCanvasPane::MouseDown <<<======================
  void cubeOGLCanvasPane::MouseDown(int X, int Y, int button)
  {
    vBaseGLCanvasPane::MouseDown(X,Y,button);
  }

//========================>>> cubeOGLCanvasPane::MouseUp <<<======================
  void cubeOGLCanvasPane::MouseUp(int X, int Y, int button)
  {
    vBaseGLCanvasPane::MouseUp(X,Y,button);
  }

//======================>>> cubeCanvasPane::MouseMove <<<======================
  void cubeOGLCanvasPane::MouseMove(int x, int y, int button)
  {
    vBaseGLCanvasPane::MouseMove(x,y,button);
  }

//=========================>>> cubeOGLCanvasPane::Redraw <<<======================
  void cubeOGLCanvasPane::Redraw(int x, int y, int w, int h)
  {
    static int inRedraw = 0;

    if (inRedraw || !initDone)  // Don't draw until initialized
        return;

    inRedraw = 1;  // Don't allow recursive redraws.

    vglMakeCurrent();  // Typically done here

    // *** Your drawing code typically goes here. You may
    // insert it here, or just call a drawing routine.

    display();		// the original demo code

    vglFlush();  // After you draw, typically flush

    inRedraw = 0;  // Out of Redraw

  }

//======================>>> cubeOGLCanvasPane::Resize <<<======================
  void cubeOGLCanvasPane::Resize(int w, int h)
  {
    vBaseGLCanvasPane::Resize(w,h);
  }

