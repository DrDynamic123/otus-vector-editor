#include "editor_view.h"

EditorView::EditorView(const std::shared_ptr<IEditorModel>& model,
                       const std::shared_ptr<IEditorController>& controller)
    : m_model{model}, m_controller{controller}
{
    model->addView(shared_from_this());
    m_createDocBtn = std::make_shared<CreateDocBtn>(model);
    m_exportDocBtn = std::make_shared<ExportDocBtn>(model);
    m_importDocBtn = std::make_shared<ImportDocBtn>(model);

    m_createCircleBtn = std::make_shared<CreateCircleBtn>(controller);
    m_deletePrimitiveBtn = std::make_shared<DeletePrimitiveBtn>(controller);
}

void EditorView::update(std::shared_ptr<GraphicDocument> document)
{
    // Выводим документ на экран
    document->paint();
}

void EditorView::mouseClick(int x, int y)
{
    m_controller->setCurrentCoordinate(Point(x, y));
}
