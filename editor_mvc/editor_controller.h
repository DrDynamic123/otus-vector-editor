#ifndef EDITOR_CONTROLLER_H
#define EDITOR_CONTROLLER_H

#include <algorithm>
#include <memory>

#include "../graphic_document.h"

class IEditorModel;


class IEditorController
{
public:
    virtual ~IEditorController() = default;

    virtual void addGraphicPrimitive(std::shared_ptr<IGraphicPrimitive> primitive) = 0;
    virtual void deleteGraphicPrimitive() = 0;
    virtual void setCurrentCoordinate(const Point& coordinate) = 0;
};

class EditorController : public IEditorController
{
public:
    EditorController(std::shared_ptr<IEditorModel> model);

    void notify();

    void addGraphicPrimitive(std::shared_ptr<IGraphicPrimitive> primitive) override;
    void deleteGraphicPrimitive() override;
    void setCurrentCoordinate(const Point& coordinate) override;
    void setCurrentPrimitive();

private:
    std::shared_ptr<IEditorModel> m_model;

    Point m_coordinate;
    std::vector<std::shared_ptr<IGraphicPrimitive>> m_primitives;
    std::vector<std::shared_ptr<IGraphicPrimitive>>::iterator m_itCurrentPrimitive;
};

#endif // EDITOR_CONTROLLER_H
