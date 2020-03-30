#  include <GL/freeglut.h>

using namespace std;

// Routine to draw a bitmap character string.
void writeBitmapString(void *font, char *string)
{  
   char *c;
   for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}
  
// Routine to draw a stroke character string.
void writeStrokeString(void *font, char *string)
{  
   char *c;
   for (c = string; *c != '\0'; c++) glutStrokeCharacter(font, *c);
}

// Drawing routine.
void drawScene(void)
{  
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glColor3f(0.0, 0.0, 0.0);

   glRasterPos3f(-0.4, 0.5, 0.0);
   writeBitmapString(GLUT_BITMAP_8_BY_13, "GLUT_BITMAP_8_BY_13");

   glTranslatef(-0.4, 0.0, 0.0);
   glScalef(0.001, 0.001, 0.001);
   writeStrokeString(GLUT_STROKE_ROMAN, "StrokeText");

   glFlush();
}

// Initialization routine.
void setup(void) 
{
   glClearColor(1.0, 1.0, 1.0, 0.0);  
}

int main(int argc, char **argv) 
{
   glutInit(&argc, argv);
 
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); 
   glutInitWindowSize(400, 400);
   glutInitWindowPosition(300, 300); 
   glutCreateWindow("fonts");
   glutDisplayFunc(drawScene); 

   
   setup(); 

   glutMainLoop(); 
}
