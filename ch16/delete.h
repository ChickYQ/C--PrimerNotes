
namespace del
{
    struct Delete
    {
        template <typename T> auto operator() (T* p) const
        {
            delete p;
        }
    };
    
}