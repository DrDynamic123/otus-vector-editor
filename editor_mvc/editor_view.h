#ifndef EDITOR_VIEW_H
#define EDITOR_VIEW_H

#include <memory>

#include "../editor_buttons.h"
#include "../graphic_primitives.h"

class IEditorModel;
class IEditorController;


class IEditorView
{
public:
    IEditorView() = default;
    virtual ~IEditorView() = default;
    virtual void update(std::shared_ptr<GraphicDocument> document) = 0;
};

class EditorView : public IEditorView, std::enable_shared_from_this<EditorView> 
{
public:
    EditorView(const std::shared_ptr<IEditorModel>& model,
               const std::shared_ptr<IEditorController>& controller);

    virtual void update(std::shared_ptr<GraphicDocument> document) override;
    void mouseClick(int x, int y);

private:
    std::shared_ptr<IEditorModel> m_model;
    std::shared_ptr<IEditorController> m_controller;
    std::shared_ptr<IButton> m_createDocBtn;
    std::shared_ptr<IButton> m_exportDocBtn;
    std::shared_ptr<IButton> m_importDocBtn;

    std::shared_ptr<IButton> m_createCircleBtn;
    std::shared_ptr<IButton> m_deletePrimitiveBtn;
};

#endif // EDITOR_VIEW_H
