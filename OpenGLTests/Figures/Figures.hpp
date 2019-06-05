#include <iostream>


#define MAX_VERTICES 2000 // Max number of vertices (for each object)
#define MAX_POLYGONS 2000 // Max number of polygons (for each object)

enum class ObjectType
{
    NONE,
    CUBE
};

struct ObjectBase
{
protected:
    virtual ~ObjectBase()
    {
        std::cout << "Graphic object desroyed" << std::endl;
    };

public:
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

class Object : ObjectBase
{
public:
    obj_type GetObject() const
    {
        return m_Object;
    };
    
    ObjectType GetType() const
    {
        return m_Type;
    };
    
protected:
    Object(const ObjectType typeName) : m_Type(typeName) {};
    
protected:
    obj_type m_Object;
    
private:
    ObjectType m_Type = ObjectType::NONE;
};

class Cube final : public Object
{
public:
    Cube(const float sideSize);
    
};
