#ifndef EDITOR_MODEL_H
#define EDITOR_MODEL_H

#include <vector>
#include <memory>

#include "../graphic_document.h"

class IEditorView;

class IEditorModel
{
public:
    IEditorModel() = default;
    virtual ~IEditorModel() = default;
    virtual void addView(std::shared_ptr<IEditorView> view) = 0;

    virtual void changeDocument(std::vector<std::shared_ptr<IGraphicPrimitive>>& primitives) = 0;
    virtual void createDocument() = 0;
    virtual void exportDocument(const std::string& fileName) const = 0;
    virtual void importDocument(const std::string& fileName) = 0;
};

class EditorModel : public IEditorModel
{
public:
    void addView(std::shared_ptr<IEditorView> view) override;
    void notify();

    void changeDocument(std::vector<std::shared_ptr<IGraphicPrimitive>>& primitives) override;
    void createDocument() override;
    void exportDocument(const std::string& fileName) const override;
    void importDocument(const std::string& fileName) override;

private:
    std::shared_ptr<IEditorView> m_view;
    std::shared_ptr<GraphicDocument> m_document;
};

#endif // EDITOR_MODEL_H
