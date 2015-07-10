// Author Kemi Peng
// Unfortunately, it might have run time errors
class Vector4
{
private:
    __m128 m_Vec;
public:
    //functions
}


// to ensure it works when allocate from heap.
class Vector4
{
private:
    __m128 m_Vec;
public:
    //functions

    void* operator new(size_t size)
    {
        void * p = _aligned_malloc( size, 16 );
        if (p == 0)  throw "allocation failure";  //instead of std::bad_alloc
        return p;
    }
 
    void operator delete(void *p)
    {
        Vector4SSE* pc = static_cast<Vector4SSE*>(p);
        _aligned_free( p );
    }
}

// to ensure it works when allocate from stack.
__declspec(align(16)) class Vector4
{
private:
    __m128 m_Vec;
public:
    //functions
    void* operator new(size_t size)
    {
        void * p = _aligned_malloc( size, 16 );
        if (p == 0)  throw "allocation failure";  //instead of std::bad_alloc
        return p;
    }
 
    void operator delete(void *p)
    {
        Vector4SSE* pc = static_cast<Vector4SSE*>(p);
        _aligned_free( p );
    }
}

// it doesn't work for local values
class Camera
{
private:
    Vector4 m_pos;
public:
    Camera()
    {
        m_pos = Vector4();
    }
}

// Now, perfect
class Camera
{
private:
    Vector4* m_pPos;
public:
    Camera()
    {
        m_pPos = new Vector4();
    }
    ~Camera()
    {
       SAFE_DELETE(m_pPos);
    }
}