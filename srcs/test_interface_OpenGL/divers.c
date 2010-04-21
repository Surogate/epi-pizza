void DrawStr(const char *str)
{
	GLint i = 0;
	
	if(!str) return;
        
	while(str[i])
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str[i]);
		i++;
	}
}

void
Atlantis_Init(void)
{
    static float ambient[] = {0.2, 0.2, 0.2, 1.0};
    static float diffuse[] = {1.0, 1.0, 1.0, 1.0};
    static float position[] = {0.0, 1.0, 0.0, 0.0};
    static float mat_shininess[] = {90.0};
    static float mat_specular[] = {0.8, 0.8, 0.8, 1.0};
    static float mat_diffuse[] = {0.46, 0.66, 0.795, 1.0};
    static float mat_ambient[] = {0.3, 0.4, 0.5, 1.0};
    static float lmodel_ambient[] = {0.4, 0.4, 0.4, 1.0};
    static float lmodel_localviewer[] = {0.0};
    //GLfloat map1[4] = {0.0, 0.0, 0.0, 0.0};
    //GLfloat map2[4] = {0.0, 0.0, 0.0, 0.0};
    static float fog_color[] = {0.0, 0.5, 0.9, 1.0};

    glFrontFace(GL_CCW);

    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, lmodel_localviewer);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);

    InitFishs();

    glEnable(GL_FOG);
	glFogi(GL_FOG_MODE, GL_EXP);
	glFogf(GL_FOG_DENSITY, 0.0000025);
	glFogfv(GL_FOG_COLOR, fog_color);

    glClearColor(0.0, 0.5, 0.9, 1.0);
}

sprintf(num_str, "%0.2f Hz, %dx%d, VENDOR: ", filter(t, th), w_win, h_win);
DrawStr(num_str);
DrawStr(glGetString(GL_VENDOR));

static double mtime(void)
{
   struct timeval tk_time;
   struct timezone tz;
   
   gettimeofday(&tk_time, &tz);
   
   return 4294.967296 * tk_time.tv_sec + 0.000001 * tk_time.tv_usec;
}


t2 = mtime();
t = t2 - t1;
if(t > 0.0001) t = 1.0 / t;


static double filter(double in, double *save)
{
	static double k1 = 0.9;
	static double k2 = 0.05;

	save[3] = in;
	save[1] = save[0]*k1 + k2*(save[3] + save[2]);

	save[0]=save[1];
	save[2]=save[3];

	return(save[1]);
}

