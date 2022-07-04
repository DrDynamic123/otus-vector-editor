#ifndef EDITOR_BUTTONS_H
#define EDITOR_BUTTONS_H

#include <memory>

#include "editor_mvc/editor_model.h"
#include "editor_mvc/editor_controller.h"
#include "graphic_primitives.h"



class IButton
{
public:
    virtual ~IButton() = default;
    virtual void press() = 0;
};

class DocButton : public IButton
{
public:
    virtual ~DocButton() = default;
protected:
    DocButton(std::shared_ptr<IEditorModel> model) : m_model(model)
    {}

    std::shared_ptr<IEditorModel> m_model;
};

class CreateDocBtn : public DocButton
{
public:
    CreateDocBtn(std::shared_ptr<IEditorModel> model) : DocButton(model)
    {}

    void press() override
    {
        m_model->createDocument();
    }
};

class ExportDocBtn : public DocButton
{
public:
    ExportDocBtn(std::shared_ptr<IEditorModel> model, const std::string& fileName = std::string())
        : DocButton(model), m_fileName(fileName)
    {}

    void press() override
    {
        // Если m_fileName пуст, спросить путь к файлу
        m_model->exportDocument(m_fileName);
    }

private:
    std::string m_fileName;
};

class ImportDocBtn : public DocButton
{
public:
    ImportDocBtn(std::shared_ptr<IEditorModel> model, const std::string& fileName = std::string())
        : DocButton(model), m_fileName(fileName)
    {}

    void press() override
    {
        // Если m_fileName пуст, спросить путь к файлу
        m_model->importDocument(m_fileName);
    }

private:
    std::string m_fileName;
};


class PrimitiveButton : public IButton
{
public:
    virtual ~PrimitiveButton() = default;

protected:
    PrimitiveButton(std::shared_ptr<IEditorController> controller) : m_controller(controller)
    {}

    std::shared_ptr<IEditorController> m_controller;
};

class CreateCircleBtn : public PrimitiveButton
{
public:
    CreateCircleBtn(std::shared_ptr<IEditorController> controller, int radius = 0)
        : PrimitiveButton(controller), m_radius(radius)
    {}

    void press() override
    {
        // Если радиус не задан, спросить радиус
        m_controller->addGraphicPrimitive(std::make_shared<Circle>(m_radius));
    }

private:
    int m_radius;
};

class DeletePrimitiveBtn : public PrimitiveButton
{
public:
    DeletePrimitiveBtn(std::shared_ptr<IEditorController> controller)
        : PrimitiveButton(controller)
    {}

    void press() override
    {
        m_controller->deleteGraphicPrimitive();
    }
};

#endif // EDITOR_BUTTONS_H
