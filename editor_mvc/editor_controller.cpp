#include "editor_controller.h"

#include "editor_model.h"


EditorController::EditorController(std::shared_ptr<IEditorModel> model)
{
    m_model = model;
}

void EditorController::notify()
{
    m_model->changeDocument(m_primitives);
}

void EditorController::addGraphicPrimitive(std::shared_ptr<IGraphicPrimitive> primitive)
{
    primitive->setPoint(m_coordinate);
    m_primitives.push_back(primitive);
    notify();
}

void EditorController::deleteGraphicPrimitive()
{
    if (m_itCurrentPrimitive != m_primitives.end())
        m_primitives.erase(m_itCurrentPrimitive);
    notify();
}

void EditorController::setCurrentCoordinate(const Point& coordinate)
{
    m_coordinate = coordinate;
    setCurrentPrimitive();
}

void EditorController::setCurrentPrimitive()
{
    m_itCurrentPrimitive = std::find_if(m_primitives.begin(), m_primitives.end(),
        [this](std::shared_ptr<IGraphicPrimitive> primitive)
        {
            return primitive->getPoint() == m_coordinate;
        });
}
