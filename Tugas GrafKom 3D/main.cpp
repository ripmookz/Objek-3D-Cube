#include <stdio.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

// Kelas IF-08
// 10106451 wita mutiara
// 10108381 Anda Alimudin
// 10108386 Eko Gunawan
// 10108390 Ariep Dwi Nugroho
// 10108412 Aswin Nurman Pradana

GLfloat angleKubus = 0.0f;    

void init(void) {
   glShadeModel(GL_SMOOTH);   
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  
   glClearDepth(1.0f);        
   glEnable(GL_DEPTH_TEST);   
}
   

void display(void) {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glLoadIdentity();                
  
   glTranslatef(0.0f, 0.0f, -10.0f);  
   glRotatef(angleKubus, 1.0f, 1.0f, 1.0f);	
   
   glBegin(GL_QUADS);                 
      glColor3f(0.0f, 1.0f, 0.0f);    
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f); 
      glVertex3f(-1.0f, 1.0f,  1.0f); 
      glVertex3f( 1.0f, 1.0f,  1.0f); 
   
      glColor3f(3.0f, 0.5f, 0.0f);     
      glVertex3f( 1.0f, -1.0f,  1.0f); 
      glVertex3f(-1.0f, -1.0f,  1.0f); 
      glVertex3f(-1.0f, -1.0f, -1.0f); 
      glVertex3f( 1.0f, -1.0f, -1.0f); 
   
      glColor3f(1.0f, 0.0f, 0.0f);     
      glVertex3f( 1.0f,  1.0f, 1.0f);  
      glVertex3f(-1.0f,  1.0f, 1.0f);  
      glVertex3f(-1.0f, -1.0f, 1.0f);  
      glVertex3f( 1.0f, -1.0f, 1.0f);  
   
      glColor3f(1.0f, 1.0f, 0.0f);     
      glVertex3f( 1.0f, -1.0f, -1.0f); 
      glVertex3f(-1.0f, -1.0f, -1.0f); 
      glVertex3f(-1.0f,  1.0f, -1.0f); 
      glVertex3f( 1.0f,  1.0f, -1.0f); 
   
      glColor3f(0.0f, 0.0f, 1.0f);     
      glVertex3f(-1.0f,  1.0f,  1.0f); 
      glVertex3f(-1.0f,  1.0f, -1.0f); 
      glVertex3f(-1.0f, -1.0f, -1.0f); 
      glVertex3f(-1.0f, -1.0f,  1.0f); 
   
      glColor3f(1.0f, 0.0f, 1.0f);     
      glVertex3f( 1.0f,  1.0f, -1.0f); 
      glVertex3f( 1.0f,  1.0f,  1.0f);
      glVertex3f( 1.0f, -1.0f,  1.0f); 
      glVertex3f( 1.0f, -1.0f, -1.0f); 
   glEnd();   
   
   glutSwapBuffers(); 
   angleKubus += 0.1f;  
}
   

void reshape(int w, int h){ 
  glViewport(0,0,(GLsizei) w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(25.0,(GLfloat) w/(GLfloat) h, 0.10, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
   
   
int main(int argc, char** argv) {
   glutInit(&argc, argv);      
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); 
   glutInitWindowSize(800, 600);  
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Tugas KomGraf 3D");    
   init();      
   glutDisplayFunc(display);  
   glutReshapeFunc(reshape);    
   glutIdleFunc(display);      
   glutMainLoop();    
   return 0;
}
