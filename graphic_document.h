#ifndef GRAPHIC_DOCUMENT_H
#define GRAPHIC_DOCUMENT_H

#include <vector>
#include <string>

#include "graphic_primitives.h"


class GraphicDocument
{
public:
    GraphicDocument& operator=(const GraphicDocument&) = default;
    GraphicDocument(const GraphicDocument&) = default;
    GraphicDocument() = default;

    GraphicDocument(const std::vector<std::shared_ptr<IGraphicPrimitive>>& primitives) : m_primitives{primitives}
    {}

    void addPrimitive(std::shared_ptr<IGraphicPrimitive> primitive)
    {
        m_primitives.push_back(primitive);
    }
    
    ~GraphicDocument()
    {
        m_primitives.clear();
    }

    void paint()
    {
        for (const auto& p : m_primitives)
        {
            p->paint();
        }
    }

private:
    std::vector<std::shared_ptr<IGraphicPrimitive>> m_primitives; // Документ хранит примитивы
};


#endif // GRAPHIC_DOCUMENT_H
