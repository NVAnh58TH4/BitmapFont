#include<GL/gl.h>
#include<GL/glut.h>

int index = 0;
int i;
unsigned char mang[1000];
static GLfloat letter_color[3] = {1.0, 1.0, 1.0};
void sub_menu(int);

//---------------------------------------------------------------------------------
GLubyte raster_a[24] = {0x1f, 0x9c, 0x30, 0x72,
						0x60, 0x31, 0xc0, 0x31,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0x60, 0x30,
						0x30, 0x70, 0x1f, 0xb0};

GLubyte raster_b[56] = {0x03, 0xe0, 0x06, 0x18,
						0x0c, 0x04, 0x0c, 0x04,
						0x0c, 0x02, 0x0c, 0x02,
						0x0c, 0x02, 0x0c, 0x02,
						0x8c, 0x02, 0x4c, 0x1c,
						0x2c, 0x17, 0x1c, 0x08,
						0x0e, 0x00, 0x0d, 0x00,
						0x0c, 0x80, 0x0c, 0x40,
						0x0c, 0x40, 0x0c, 0x20,
						0x0c, 0x20, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x20,
						0x06, 0x60, 0x03, 0x80};

GLubyte raster_c[24] = {0x3f, 0x00, 0x60, 0xc0,
						0xc0, 0x20, 0xc0, 0x10,
						0xc0, 0x00, 0xc0, 0x00,
						0xc0, 0x00, 0xc0, 0x00,
						0xc0, 0x00, 0x60, 0x20,
						0x30, 0xc0, 0x0f, 0x00};

GLubyte raster_d[48] = {0x1f, 0x9c, 0x30, 0x72,
						0x60, 0x31, 0xc0, 0x31,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0x60, 0x30,
						0x30, 0x70, 0x1f, 0xb0,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30};

GLubyte raster_e[24] = {0x07, 0xe0, 0x0c, 0x10,
						0xf8, 0x08, 0x1c, 0x04,
						0x1b, 0x00, 0x18, 0xc0,
						0x18, 0x30, 0x18, 0x08,
						0x18, 0x08, 0x0c, 0x08,
						0x06, 0x10, 0x01, 0xe0};

GLubyte raster_f[56] = {0x01, 0xc0, 0x02, 0x60,
						0x04, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x04, 0x30,
						0x02, 0x30, 0x02, 0x30,
						0x01, 0x30, 0x01, 0x30,
						0x00, 0xb0, 0x00, 0xb0,
						0x00, 0x70, 0x00, 0x30,
						0x01, 0x38, 0x00, 0xb4,
						0x00, 0x73, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x38,
						0x00, 0x34, 0x00, 0x32,
						0x00, 0x31, 0x00, 0x31,
						0x00, 0x19, 0x00, 0x0e};

GLubyte raster_g[56] = {0x01, 0xc0, 0x06, 0x60,
						0x04, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x02, 0x30,
						0x02, 0x30, 0x01, 0x30,
						0x00, 0xb0, 0x00, 0x70,
						0x3f, 0xb8, 0x60, 0xf4,
						0xc0, 0x33, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0x60, 0x30,
						0x30, 0x70, 0x0f, 0xb0};

GLubyte raster_h[56] = {0x0c, 0x06, 0x0c, 0x0d,
						0x0c, 0x0d, 0x0c, 0x0c,
						0x0c, 0x0c, 0x0c, 0x0c,
						0x0c, 0x0c, 0x0c, 0x0c,
						0x8c, 0x0c, 0x4e, 0x0c,
						0x2d, 0x18, 0x1c, 0xf0,
						0x0e, 0x00, 0x0d, 0x00,
						0x0c, 0x80, 0x0c, 0x40,
						0x0c, 0x40, 0x0c, 0x20,
						0x0c, 0x20, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x20,
						0x06, 0x60, 0x03, 0x80};
	
GLubyte raster_i[56] = {0x0e, 0x00, 0x19, 0x00,
						0x18, 0x80, 0x18, 0x40,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x98, 0x00,
						0x58, 0x00, 0x38, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x00, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};

GLubyte raster_j[62] = {0x01, 0xc0, 0x02, 0x60,
						0x04, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x04, 0x30,
						0x02, 0x30, 0x02, 0x30,
						0x01, 0x30, 0x01, 0x30,
						0x00, 0xb0, 0x00, 0xb0,
						0x00, 0x70, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x38,
						0x00, 0x34, 0x00, 0x32,
						0x00, 0x31, 0x00, 0x31,
						0x00, 0x30, 0x01, 0x30,
						0x00, 0xb0, 0x00, 0x70,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x00, 0x00, 0x30,
						0x00, 0x30};

GLubyte raster_k[56] = {0x0c, 0x06, 0x0c, 0x0d,
						0x0c, 0x0d, 0x0c, 0x0c,
						0x0c, 0x0c, 0x0c, 0x6c,
						0x0c, 0x50, 0x0c, 0x38,
						0x8c, 0x0c, 0x4e, 0x0c,
						0x2d, 0x18, 0x1c, 0xf0,
						0x0e, 0x00, 0x0d, 0x00,
						0x0c, 0x80, 0x0c, 0x40,
						0x0c, 0x40, 0x0c, 0x20,
						0x0c, 0x20, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x20,
						0x06, 0x60, 0x03, 0x80};

GLubyte raster_l[56] = {0x03, 0xe0, 0x06, 0x18,
						0x0c, 0x04, 0x0c, 0x02,
						0x0c, 0x00, 0x0c, 0x00,
						0x0c, 0x00, 0x0c, 0x00,
						0x8c, 0x00, 0x4c, 0x00,
						0x2c, 0x00, 0x1c, 0x00,
						0x0e, 0x00, 0x0d, 0x00,
						0x0c, 0x80, 0x0c, 0x40,
						0x0c, 0x40, 0x0c, 0x20,
						0x0c, 0x20, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x10,
						0x0c, 0x10, 0x0c, 0x20,
						0x06, 0x60, 0x03, 0x80};
				
GLubyte raster_m1[56] = {0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0e, 0x07, 0x8d, 0x06,
						0x5c, 0x8e, 0x38, 0x7c,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
GLubyte raster_m2[56] = {0x01, 0xc0, 0x03, 0x20,
						0x03, 0x10, 0x03, 0x08,
						0x03, 0x00, 0x03, 0x00,
						0x03, 0x00, 0x03, 0x00,
						0x03, 0x00, 0x83, 0x00,
						0x47, 0x00, 0x3e, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
								
GLubyte raster_n1[56] = {0x0c, 0x03, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0e, 0x06, 0x8d, 0x06,
						0x5c, 0x8e, 0x38, 0x7c,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
GLubyte raster_n2[56] = {0x80, 0x00, 0x40, 0x00,
						0x20, 0x00, 0x10, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};

GLubyte raster_o[24] = {0x1f, 0x80, 0x30, 0x40,
						0x60, 0x20, 0xc0, 0x10,
						0xc0, 0x10, 0xc0, 0x10,
						0xc0, 0x10, 0xc0, 0x10,
						0xc0, 0x10, 0x60, 0x20,
						0x30, 0x40, 0x1f, 0x80};

GLubyte raster_p1[56] = {0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x07, 0x18, 0x0c,
						0x18, 0x0c, 0x18, 0x0c,
						0x18, 0x0c, 0x18, 0x0c,
						0x18, 0x0c, 0x98, 0x0c,
						0x5c, 0x0c, 0x3a, 0x0c,
						0x19, 0x0c, 0x18, 0xf8,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
GLubyte raster_p2[56] = {0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x80, 0x00,
						0x40, 0x00, 0x20, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};						

GLubyte raster_q[48] = {0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x00, 0x30, 0x00, 0x30,
						0x1f, 0xb0, 0x30, 0x70,
						0x60, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0xc0, 0x30,
						0xc0, 0x30, 0x60, 0x30,
						0x30, 0x70, 0x1f, 0xb0};

GLubyte raster_r[32] = {0x80, 0x1c, 0x80, 0x32,
						0x40, 0x31, 0x40, 0x31,
						0x20, 0x30, 0x20, 0x30,
						0x10, 0x30, 0x10, 0x30,
						0x08, 0x30, 0x08, 0x30,
						0x04, 0x70, 0x07, 0xe0,
						0x0e, 0x00, 0x14, 0x00,
						0x14, 0x00, 0x18, 0x00};

GLubyte raster_s[32] = {0x81, 0xf0, 0x82, 0x18,
						0x42, 0x0c, 0x21, 0x06,
						0x21, 0x06, 0x10, 0x06,
						0x08, 0x06, 0x08, 0x0c,
						0x04, 0x18, 0x02, 0x30,
						0x02, 0xe0, 0x01, 0x80,
						0x03, 0x00, 0x05, 0x00,
						0x05, 0x00, 0x06, 0x00};

GLubyte raster_t[56] = {0x0e, 0x00, 0x19, 0x00,
						0x18, 0x80, 0x18, 0x40,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x98, 0x00,
						0x58, 0x00, 0x38, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x7e, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x18, 0x00, 0x18, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};

GLubyte raster_u1[56] = {0x0f, 0x87, 0x1c, 0x4c,
						0x18, 0x2c, 0x18, 0x1c,
						0x18, 0x0c, 0x18, 0x0c,
						0x18, 0x0c, 0x98, 0x0c,
						0x58, 0x0c, 0x38, 0x0c,
						0x18, 0x0c, 0x18, 0x0c,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
GLubyte raster_u2[56] = {0x00, 0x00, 0x80, 0x00,
						0x40, 0x00, 0x20, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
						
GLubyte raster_v[56] = {0x03, 0xe0, 0x04, 0x10,
						0x0c, 0x08, 0x0c, 0x08,
						0x0c, 0x04, 0x0c, 0x04,
						0x0c, 0x04, 0x0c, 0x04,
						0x0c, 0x3c, 0x8c, 0x46,
						0x5c, 0x49, 0x38, 0x30,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};

GLubyte raster_w1[56] = {0x03, 0xe0, 0x04, 0x11,
						0x0c, 0x0a, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x0c, 0x06,
						0x0c, 0x06, 0x8c, 0x06,
						0x5c, 0x00, 0x38, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};
GLubyte raster_w2[56] = {0xf8, 0x00, 0x04, 0x00,
						0x02, 0x00, 0x02, 0x00,
						0x01, 0x00, 0x01, 0x00,
						0x01, 0x00, 0x01, 0x00,
						0x0f, 0x00, 0x11, 0x80,
						0x12, 0x40, 0x0c, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00};

GLubyte raster_x1[24] = {0x1e, 0x0f, 0x23, 0x18,
						0x41, 0xb0, 0x80, 0xe0,
						0x00, 0xe0, 0x00, 0xe0,
						0x00, 0xe0, 0x00, 0xe0,
						0x00, 0xe0, 0x01, 0xb0,
						0x23, 0x18, 0x1e, 0x0f};
GLubyte raster_x2[24] = {0x00, 0x00, 0x80, 0x00,
						0x40, 0x00, 0x20, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x00, 0x00, 0x00, 0x00,
						0x80, 0x00, 0x00, 0x00};

GLubyte raster_y[56] = {0x01, 0xc0, 0x06, 0x60,
						0x04, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x08, 0x30,
						0x08, 0x30, 0x04, 0x30,
						0x04, 0x30, 0x02, 0x30,
						0x02, 0x30, 0x01, 0x30,
						0x00, 0xb0, 0x00, 0x70,
						0x0e, 0x28, 0x18, 0xb4,
						0x30, 0x73, 0x30, 0x30,
						0x30, 0x30, 0x30, 0x30,
						0x30, 0x30, 0xb0, 0x30,
						0x70, 0x30, 0x70, 0x30,
						0x30, 0x30, 0x30, 0x30};

GLubyte raster_z[28] = {0x70, 0x78, 0x98, 0x84,
						0x9f, 0x02, 0x7e, 0x01,
						0x03, 0x00, 0x01, 0x80,
						0x00, 0xc0, 0x00, 0x60,
						0x00, 0x30, 0x60, 0x18,
						0x81, 0xec, 0x83, 0x36,
						0x44, 0x0b, 0x38, 0x07};

GLubyte raster_space[4] = {0x00, 0x00, 0x00, 0x00};

//---------------------------------------------------------------------------------

// The top menu callback function.
void top_menu(int id)
{
   if (id==1) exit(0);
}

// The sub-menu callback function.
void color_menu(int id)
{
	if (id==2) 
	{
		letter_color[0] = 1.0; letter_color[1] = 0.0; letter_color[2] = 0.0; 
    }
    if (id==3) 
    {
		letter_color[0] = 0.0; letter_color[1] = 1.0; letter_color[2] = 0.0; 
    }
	if (id==4) 
    {
		letter_color[0] = 0.0; letter_color[1] = 0.0; letter_color[2] = 1.0; 
    }
	if (id==5) 
    {
		letter_color[0] = 1.0; letter_color[1] = 1.0; letter_color[2] = 1.0; 
    }    
	glutPostRedisplay();
}

//-----------------------------------------------------------------------------------------------			
void drawLetter(unsigned char key)
{
	switch(key)
	{
		case 'a':
			glBitmap (16, 12, 0.0, 0.0, 17.0, 0.0, raster_a);
			break;
		case 'b':
			glBitmap (16, 28, 0.0, 0.0, 19.0, 0.0, raster_b);
			break;
		case 'c':
			glBitmap (16, 12, 0.0, 0.0, 16.0, 0.0, raster_c);
			break;
		case 'd':
			glBitmap (16, 24, 0.0, 0.0, 17.0, 0.0, raster_d);
			break;
		case 'e':
			glBitmap (16, 12, 0.0, 0.0, 16.0, 0.0, raster_e);
			break;
		case 'f':
			glBitmap (16, 28, 6.0, 16.0, 12.0, 0.0, raster_f);
			break;
		case 'g':
			glBitmap (16, 28, 0.0, 16.0, 17.0, 0.0, raster_g);
			break;
		case 'h':
			glBitmap (16, 28, 0.0, 0.0, 19.0, 0.0, raster_h);
			break;
		case 'i':
			glBitmap (16, 28, 0.0, 0.0, 12.0, 0.0, raster_i);
			break;
		case 'j':
			glBitmap (16, 31, 6.0, 16.0, 12.0, 0.0, raster_j);
			break;			
		case 'k':
			glBitmap (16, 28, 0.0, 0.0, 18.0, 0.0, raster_k);
			break;
		case 'l':
			glBitmap (16, 28, 0.0, 0.0, 18.0, 0.0, raster_l);
			break;
		case 'm':
			glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_m1);
		    glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_m2);
			break;
		case 'n':
			glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_n1);
		    glBitmap (16, 28, 0.0, 0.0, 6.0, 0.0, raster_n2);
			break;
		case 'o':
			glBitmap (16, 12, 0.0, 0.0, 16.0, 0.0, raster_o);
			break;
		case 'p':
			glBitmap (16, 28, 0.0, 12.0, 16.0, 0.0, raster_p1);
			glBitmap (16, 28, 0.0, 12.0, 6.0, 0.0, raster_p2);
			break;
		case 'q':
			glBitmap (16, 24, 0.0, 12.0, 16.0, 0.0, raster_q);
			break;
		case 'r':
			glBitmap (16, 16, 0.0, 0.0, 18.0, 0.0, raster_r);
			break;
		case 's':
			glBitmap (16, 16, 0.0, 0.0, 18.0, 0.0, raster_s);
			break;
		case 't':
			glBitmap (16, 28, 0.0, 0.0, 12.0, 0.0, raster_t);
			break;
		case 'u':
			glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_u1);
		    glBitmap (16, 28, 0.0, 0.0, 4.0, 0.0, raster_u2);
			break;
		case 'v':
			glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_v);
			break;
		case 'w':
			glBitmap (16, 28, 0.0, 0.0, 16.0, 0.0, raster_w1);
		    glBitmap (16, 28, 0.0, 0.0, 12.0, 0.0, raster_w2);
			break;
		case 'x':
			glBitmap (16, 12, 0.0, 0.0, 16.0, 0.0, raster_x1);
			glBitmap (16, 12, 0.0, 0.0, 6.0, 0.0, raster_x2);
			break;
		case 'y':
			glBitmap (16, 28, 0.0, 16.0, 16.0, 0.0, raster_y);
			break;
		case 'z':
			glBitmap (16, 14, 0.0, 0.0, 18.0, 0.0, raster_z);
			break;
		case ' ':
			glBitmap (8, 1, 0.0, 0.0, 8.0, 0.0, raster_space);
		default:
			break;
	}	
}

void display(void)
{
	glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv (letter_color);
    glRasterPos2i (60, 100);
    for (i = 0; i < index; i++)
    	drawLetter(mang[i]);
	glutSwapBuffers();
	glFlush ();
}

void keyboard (unsigned char key, int x, int y)
{
	mang[index] = key;
	index++;
	glutPostRedisplay();
}
//---------------------------------------------------------------------------------
void init (void) 
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glClearColor (0.0, 0.0, 0.0, 0.0);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho (0, w, 0, h, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	int sub_menu;
	
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (750, 250); 
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Astralis");
    init();
    glutReshapeFunc(reshape);
    glutDisplayFunc(display); 
    
	sub_menu = glutCreateMenu(color_menu);
	glutAddMenuEntry("Red", 2);
	glutAddMenuEntry("Green", 3);
	glutAddMenuEntry("Blue", 4);
	glutAddMenuEntry("White", 5);
    
	glutCreateMenu(top_menu);
	glutAddMenuEntry("Quit",1);
	glutAddSubMenu("Change Color", sub_menu);
	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
