#include <iostream>


#include "editor_mvc/editor_model.h"
#include "editor_mvc/editor_view.h"
#include "editor_mvc/editor_controller.h"
#include "editor_buttons.h"

int main()
{
    try
    {
        auto model = std::make_shared<EditorModel>();
        auto controller = std::make_shared<EditorController>(model);
        auto view = std::make_shared<EditorView>(model, controller);
        model->addView(view);
        
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
