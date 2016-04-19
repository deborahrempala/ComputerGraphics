


#define MYTEXTUREFILE "test.png"


GLuint object;


void GenerateShape()
  {
  object = glGenLists(1);

  glNewList( object, GL_COMPILE );


  /* Assuming you are using QUADS, if not change me */
   glBegin(GL_QUADS);
   
   
	 /* Start your code here! */
	/* botttom cube */
	/* front face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.80f,-0.90f,0.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.80f,-0.90f,0.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.80f,-0.50f,0.00f); /* number 3 top right corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.80f,-0.50f,0.00f); /* number 4 top left corner */
	/* back face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.80f,-0.90f,-1.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.80f,-0.90f,-1.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.80f,-0.50f,-1.00f); /* number 3 top right corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.80f,-0.50f,-1.00f); /* number 4 top left corner */
 /* left face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.80f,-0.90f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.80f,-0.50f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.80f,-0.50f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.80f,-0.90f,0.0f); /* number 4 bottom left corner */
 /* right face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.80f,-0.90f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.80f,-0.50f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.80f,-0.50f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.80f,-0.90f,0.0f); /* number 4 bottom left corner */
/* top face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.80f,-0.50f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.80f,-0.90f,0.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.80f,-0.90f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.80f,-0.50f,-1.0f); /* number 4 bottom left corner */
/* bottom face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.80f,-0.50f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.80f,-0.90f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.80f,-0.90f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.80f,-0.50f,0.0f); /* number 4 bottom left corner */
	/* second level*/
	/* front face */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.60f,-0.50f,0.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.50f, 0.0f); glVertex3f(0.60f,-0.50f,0.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.50f, 1.0f); glVertex3f(0.60f,0.0f,0.00f); /* number 3 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.60f,0.0f,0.00f); /* number 4 top left corner */
	/* back face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.60f,-0.50f,-1.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.50f,-1.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.0f,-1.00f); /* number 3 top right corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.60f,0.0f,-1.00f); /* number 4 top left corner */
	/* right face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.60f,0.0f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.50f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.50f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,0.00f,0.0f); /* number 4 bottom left corner */
	/* left face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.60f,0.0f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.60f,-0.50f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.60f,-0.50f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.60f,0.00f,0.0f); /* number 4 bottom left corner */
	/* top face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.60f,-0.50f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.60f,-0.00f,0.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.00f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,-0.50f,-1.0f); /* number 4 bottom left corner */
	/* face level*/
	/* front face */
		glTexCoord2f(0.50f, 0.0f); glVertex3f(-0.40f,0.0f,0.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.74f, 0.0f); glVertex3f(0.40f,0.0f,0.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.74f, 1.0f); glVertex3f(0.40f,0.60f,0.00f); /* number 3 top right corner */
		glTexCoord2f(0.50f, 1.0f); glVertex3f(-0.40f,0.60f,0.00f); /* number 4 top left corner */	
		/* back face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.40f,0.0f,-1.0f); /* number 1 bottom lecorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.0f,-1.0f); /* number 2 bottom right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.60f,-1.00f); /* number 3 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.40f,0.60f,-1.00f); /* number 4 top left corner */	
	/* right face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,0.60f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.60f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.60f,0.0f); /* number 4 bottom left corner */
	/* left face */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.40f,0.60f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.40f,-0.60f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.40f,-0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.40f,0.60f,0.0f); /* number 4 bottom left corner */
 /* top face*/
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.40f,-0.0f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.40f,0.60f,0.0f); /* number 2 top right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.00f,-1.0f); /* number 4 bottom left corner */
	/* 1st hat level*/
	/* front face */
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.60f,0.60f,0.0f); /* number 1 bottom lecorner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.60f,0.60f,0.0f); /* number 2 bottom right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.60f,0.80f,0.00f); /* number 3 top right corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.60f,0.80f,0.00f); /* number 4 top left corner */		
	/* back face */
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.60f,0.60f,-1.0f); /* number 1 bottom lecorner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.60f,0.60f,-1.0f); /* number 2 bottom right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.60f,0.80f,-1.00f); /* number 3 top right corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.60f,0.80f,-1.00f); /* number 4 top left corner */	
	/* right face*/
		glTexCoord2f(0.75f, 0.0f); glVertex3f(0.60f,0.80f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.60f,0.60f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.60f,0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(0.60f,0.80f,0.0f); /* number 4 bottom left corner */
	/* left face*/
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.60f,0.80f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.60f,0.60f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.60f,0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.60f,0.80f,0.0f); /* number 4 bottom left corner */
	/* top face*/
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.60f,0.80f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.60f,0.60f,0.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.60f,0.60f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(0.60f,0.80f,-1.0f); /* number 4 bottom left corner */
	/* 2nd hat level*/
	/* front face */
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.40f,0.80f,0.0f); /* number 1 bottom lecorner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.40f,0.80f,0.0f); /* number 2 bottom right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.40f,1.0f,0.00f); /* number 3 top right corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.40f,1.0f,0.00f); /* number 4 top left corner */			
	/* back face */
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.40f,0.80f,-1.0f); /* number 1 bottom lecorner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.40f,0.80f,-1.0f); /* number 2 bottom right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.40f,1.0f,-1.0f); /* number 3 top right corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.40f,1.0f,-1.00f); /* number 4 top left corner */	
	/* right face*/
		glTexCoord2f(0.75f, 0.0f); glVertex3f(0.40f,1.0f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.40f,0.80f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.40f,0.80f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(0.40f,1.0f,0.0f); /* number 4 bottom left corner */	
		/* right face*/
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.40f,1.0f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.40f,0.80f,-1.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.40f,0.80f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(-0.40f,1.0f,0.0f); /* number 4 bottom left corner */
		/* top face */
		glTexCoord2f(0.75f, 0.0f); glVertex3f(-0.40f,0.80f,-1.0f); /* number 1 bottom left corner */
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.40f,1.0f,0.0f); /* number 2 top right corner */
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.40f,0.80f,0.0f); /* number 3 top left corner */
		glTexCoord2f(0.75f, 1.0f); glVertex3f(0.40f,1.0f,-1.0f); /* number 4 bottom left corner */
  /* Leave these here! */
  glEnd( );
  glEndList( );
  }
