
#define MAX_VERTICES 2000 // Max number of vertices (for each object)
#define MAX_POLYGONS 2000 // Max number of polygons (for each object)

enum class FigureType
{
    CUBE
};

struct FigureBase
{
    // Vertex type
    typedef struct
    {
        float x,y,z;
    } vertex_type;
    
    // Polygon (triangle), 3 numbers that aim 3 vertices
    typedef struct
    {
        int a,b,c;
    } polygon_type;
    
    // Object type
    typedef struct
    {
        vertex_type vertex[MAX_VERTICES];
        polygon_type polygon[MAX_POLYGONS];
    } obj_type, *obj_type_ptr;
    
};

class Cube : FigureBase
{
public:
    Cube(const float sideSize);
    obj_type GetCube() const
    {
        return cube;
    };
    
private:
    obj_type cube;
};
