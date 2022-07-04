#ifndef GRAPHIC_PRIMITIVES_H
#define GRAPHIC_PRIMITIVES_H

struct Point
{
    Point() : m_x{0}, m_y{0}
    {}
    Point(int x, int y) : m_x{x}, m_y{y}
    {}

    int m_x;
    int m_y;

    bool operator==(const Point& other)
    {
        return other.m_x == m_x && other.m_y == m_y;
    }
};

class IGraphicPrimitive
{
public:
    IGraphicPrimitive(Point point) : m_point{point}
    {}
    virtual ~IGraphicPrimitive() = default;
    virtual void paint() = 0;

    Point getPoint() const
    {
        return m_point;
    }
    void setPoint(const Point& point)
    {
        m_point = point;
    }

private:
    Point m_point; // Координата привязки примитива
};

class Circle : public IGraphicPrimitive
{
public:
    Circle(int radius, Point center = Point()) : IGraphicPrimitive(center), m_radius{radius}
    {}

    virtual void paint() override
    {}

private:
    int m_radius;
};

#endif // GRAPHIC_PRIMITIVES_H
