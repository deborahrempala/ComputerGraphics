


#define MYTEXTUREFILE "palmtree.png"


GLuint object;


void GenerateShape()
  {
  object = glGenLists(1);

  glNewList( object, GL_COMPILE );


  /* Assuming you are using QUADS, if not change me */
   glBegin(GL_QUADS);
		/* first side*/
		/* first level*/
   	    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.80f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-1.0f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-1.0f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.80f,0.00f); /* number 4 top right corner */
		/* second level*/
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.60f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.80f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.80f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.60f,0.00f); /* number 4 top right corner */
		/* Third Level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.40f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.60f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.60f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.40f,0.00f); /* number 4 top right corner */
		/* fourth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.20f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.40f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.40f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.20f,0.00f); /* number 4 top right corner */
		/*  fifth level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.0f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.20f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.20f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.0f,0.00f); /* number 4 top right corner */
		/* sixth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.20f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.0f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.0f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.20f,0.00f); /* number 4 top right corner */
		/*  seventh level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.40f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,0.20f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,0.20f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.40f,0.00f); /* number 4 top right corner */
		/* eight level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.60f,0.0f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.40f,0.0f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.40f,0.00f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.60f,0.00f); /* number 4 top right corner */
		
		
		/* back of tree */
			/* first level*/
   	    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.80f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-1.0f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-1.0f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.80f,-0.20f); /* number 4 top right corner */
		/* second level*/
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.80f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.80f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.60f,-0.20f); /* number 4 top right corner */
		/* Third Level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.60f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.60f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.40f,-0.20f); /* number 4 top right corner */
		/* fourth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.40f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.20f,-0.20f); /* number 4 top right corner */
		/*  fifth level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.0f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.20f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.0f,-0.20f); /* number 4 top right corner */
		/* sixth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.0f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.0f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.20f,-0.20f); /* number 4 top right corner */
		/*  seventh level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,0.20f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.40f,-0.20f); /* number 4 top right corner */
		/* eight level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.40f,-0.20f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.60f,-0.20f); /* number 4 top right corner */
		
		/* right side */
		/* 1st level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,-1.0f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.60f,-0.80f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.80f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-1.0f,0.00f); /* number 4 top right corner */
		/* 2nd level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.80f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.80f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.60f,0.0f); /* number 4 top right corner */
		/* 3rd level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,-0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.60f,-0.60f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.60f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.40f,0.00f); /* number 4 top right corner */
		/* 4th level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,-0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,-0.40f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,-0.20f,0.0f); /* number 4 top right corner */
		/* fifth level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,0.0f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.60f,-0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.20f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.0f,0.00f); /* number 4 top right corner */
		/* sixth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,-0.0f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.0f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.20f,0.0f); /* number 4 top right corner */
		/* seventh level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.60f,0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.60f,0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,0.20f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.40f,0.00f); /* number 4 top right corner */
		/* eight level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.60f,0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.60f,0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.40f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.60f,0.0f); /* number 4 top right corner */
		
		
		/*left side */
		/* 1st level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-1.0f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.80f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.80f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-1.0f,0.00f); /* number 4 top right corner */
		/* 2nd level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.80f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.40f,-0.80f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.40f,-0.60f,0.0f); /* number 4 top right corner */
		/* 3rd level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,-0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.60f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.60f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.40f,0.00f); /* number 4 top right corner */
		/* 4th level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,-0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.40f,-0.40f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.40f,-0.20f,0.0f); /* number 4 top right corner */
		/* fifth level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.0f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,-0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.20f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.0f,0.00f); /* number 4 top right corner */
		/* sixth level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.20f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,-0.0f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.40f,0.0f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.40f,0.20f,0.0f); /* number 4 top right corner */
		/* seventh level */
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.40f,0.40f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.40f,0.20f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.20f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.40f,0.00f); /* number 4 top right corner */
		/* eight level */
		glTexCoord2f(0.25f, 1.0f); glVertex3f(0.40f,0.60f,-0.20f); /* number 1 top leftcorner */
		glTexCoord2f(0.25f, 0.0f); glVertex3f(0.40f,0.40f,-0.20f); /* number 2 bottom left corner */
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.40f,0.40f,0.0f); /* number 3 bottm right corner */
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.40f,0.60f,0.0f); /* number 4 top right corner */
		
		/* top of tree */
/*		
		glTexCoord2f(0.25f, 1.0f); glVertex3f(-0.60f,0.80f,0.20f);  number 1 top leftcorner 
		glTexCoord2f(0.25f, 0.0f); glVertex3f(-0.60f,-0.80f,0.0f);  number 2 bottom left corner 
		glTexCoord2f(0.49f, 0.0f); glVertex3f(0.60f,0.80f,0.0f); number 3 bottm right corner 
		glTexCoord2f(0.49f, 1.0f); glVertex3f(0.60f,0.80f,0.20f);  number 4 top right corner */
		
		/* base of leaf 
		glTexCoord2f(0.50f, 1.0f); glVertex3f(0.40f,0.80f,0.0f);  number 1 top leftcorner 
		glTexCoord2f(0.50f, 0.0f); glVertex3f(0.40f,0.60f,0.0f); number 2 bottom left corner 
		glTexCoord2f(0.74f, 0.0f); glVertex3f(0.60f,0.60f,0.00f);number 3 bottm right corner 
		glTexCoord2f(0.74f, 1.0f); glVertex3f(0.60f,0.80f,0.00f);  number 4 top right corner */
		
		
		
		
		
		
		
		
		
		
		
		
		/* base cocunut */
		/*glTexCoord2f(0.75f, 1.0f); glVertex3f(0.60f,0.60f,0.0f);  number 1 top leftcorner 
		glTexCoord2f(0.75f, 0.0f); glVertex3f(0.60f,0.40f,0.0f);  number 2 bottom left corner
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.80f,0.40f,0.00f);  number 3 bottm right corner 
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.80f,0.60f,0.00f);  number 4 top right corner */
	 /* Start your code here! */
	
  glEnd( );
  glEndList( );
  }
