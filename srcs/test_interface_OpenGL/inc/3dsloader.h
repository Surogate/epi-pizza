
#define MAX_VERTICES 10000 
#define MAX_POLYGONS 10000 

/* Vertex type */
typedef struct
{
  float		x;
  float		y;
  float		z;
}		vertex_type;

/*The polygon (triangle), 3 numbers that aim 3 vertices*/
typedef struct
{
  int		a;
  int		b;
  int		c;
}		polygon_type;

/* The mapcoord type, 2 texture coordinates for each vertex */
typedef struct
{
  float		u;
  float		v;
}		mapcoord_type;

/* The object type */
typedef struct 
{
  char		name[20];
  int		vertices_qty;
  int		polygons_qty;
  vertex_type	vertex[MAX_VERTICES]; 
  polygon_type	polygon[MAX_POLYGONS];
  mapcoord_type	mapcoord[MAX_VERTICES];
  unsigned int	id_texture;
  float		scale[3];
}		obj_type, *obj_type_ptr;


/*
**  mesh->vertex[ mesh->polygon[index].a ].x,
**  mesh->vertex[ mesh->polygon[index].a ].y,
**  mesh->vertex[ mesh->polygon[index].a ].z); //Vertex definition
*/

extern char Load3DS (obj_type_ptr ogg, const char *filename);

