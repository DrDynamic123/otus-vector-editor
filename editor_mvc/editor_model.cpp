#include "editor_model.h"

#include "editor_view.h"

void EditorModel::addView(std::shared_ptr<IEditorView> view)
{
    m_view = view;
}

void EditorModel::notify()
{
    m_view->update(m_document);
}

void EditorModel::changeDocument(std::vector<std::shared_ptr<IGraphicPrimitive>>& primitives)
{
    m_document.reset(new GraphicDocument(primitives));
    notify();
}

void EditorModel::createDocument()
{
    m_document.reset(new GraphicDocument());
    notify();
}

void EditorModel::exportDocument(const std::string& fileName) const
{
    // Экспортируем документ из файла
    (void)fileName;
}

void EditorModel::importDocument(const std::string& fileName)
{
    // Импортируем документ в файл
    (void)fileName;
}
