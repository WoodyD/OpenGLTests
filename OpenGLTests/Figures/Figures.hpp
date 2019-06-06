#include <iostream>


#define MAX_VERTICES 2000 // Max number of vertices (for each object)
#define MAX_POLYGONS 2000 // Max number of polygons (for each object)

static int s_IDIndex = 0;

enum class ObjectType
{
    NONE,
    CUBE
};

struct GraphicObjectBase
{
protected:
    virtual ~GraphicObjectBase()
    {
        std::cout << "Object base desroyed" << std::endl;
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
    } graphic_object, *obj_type_ptr;
 
};

class GraphicObject : GraphicObjectBase
{
public:
    graphic_object GetObject() const
    {
        return m_Object;
    };
    
    ObjectType GetType() const
    {
        return m_Type;
    };
    
    int GetUniqueID() const
    {
        return m_UniqueID;
    };
    
    virtual ~GraphicObject()
    {
        std::cout << "Object desroyed. ID: " << m_UniqueID << std::endl;
    };
protected:
    GraphicObject(const ObjectType typeName) : m_Type(typeName)
    {
        m_UniqueID = s_IDIndex;
        s_IDIndex++;
    };
    
protected:
    graphic_object m_Object;
    
private:
    ObjectType m_Type = ObjectType::NONE;
    int m_UniqueID = 0;
};

class Cube final : public GraphicObject
{
public:
    Cube(const float sideSize);
};
