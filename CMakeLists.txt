cmake_minimum_required(VERSION 3.23)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(vector_editor VERSION ${PROJECT_VESRION})

add_executable(vector_editor vector_editor.cpp
editor_mvc/editor_model.cpp
editor_mvc/editor_view.cpp
editor_mvc/editor_controller.cpp)

set_target_properties(vector_editor PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(vector_editor
    PRIVATE "${CMAKE_BINARY_DIR}"
)

include(CTest)

if(BUILD_TESTING)

    include(FetchContent)
    FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/e2239ee6043f73722e7aa812a459f54a28552929.zip
    )
    if (WIN32)
        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    endif (WIN32)

    FetchContent_MakeAvailable(googletest)

    add_executable(test_vector_editor test_vector_editor.cpp)

    set_target_properties(test_vector_editor PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    target_link_libraries(test_vector_editor
        gtest_main
    )
    
    include(GoogleTest)
endif()

if (MSVC)
    target_compile_options(vector_editor PRIVATE
        /W4
    )
    if(BUILD_TESTING)
        target_compile_options(test_vector_editor PRIVATE
            /W4
        )
    endif()
else ()
    target_compile_options(vector_editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    if(BUILD_TESTING)
        target_compile_options(test_vector_editor PRIVATE
            -Wall -Wextra -pedantic -Werror
        )
    endif()
endif()

install(TARGETS vector_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

if(BUILD_TESTING)
    add_test(test_vector_editor test_vector_editor)
endif()
