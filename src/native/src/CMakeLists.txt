cmake_minimum_required(VERSION 3.3)
project(renderer)

find_package(glm REQUIRED)

set(SOURCE_FILES
        gl/glad.c

        core/nova_renderer.cpp core/nova_renderer.h
        core/nova_facade.cpp
        core/texture_manager.cpp core/texture_manager.h
        core/gui/gui_renderer.cpp

        interfaces/iwindow.cpp interfaces/iwindow.h
        interfaces/igraphics_context.cpp interfaces/igraphics_context.h
        interfaces/ivertex_buffer.h
        interfaces/itexture.h

        io/key_forwarder.cpp io/key_forwarder.h

        gl/windowing/glfw_gl_window.cpp gl/windowing/glfw_gl_window.h
        gl/objects/texture2D.cpp gl/objects/texture2D.h
        gl/objects/gl_shader_program.cpp gl/objects/gl_shader_program.h
        gl/objects/gl_uniform_buffer.cpp
        gl/objects/gl_vertex_buffer.cpp

        utils/utils.cpp

        test/main.cpp
        test/sanity.cpp
        test/shader_test.cpp
        test/test_utils.cpp
        )

add_library(nova-renderer SHARED ${SOURCE_FILES})

# configure the project
target_include_directories(nova-renderer SYSTEM PRIVATE)
target_link_libraries(nova-renderer glfw ${GLFW_LIBRARIES})

set_property(TARGET nova-renderer PROPERTY CXX_STANDARD 14)
set_property(TARGET nova-renderer PROPERTY CXX_STANDARD_REQUIRED ON)

set(TEST_SORUCE_FILES
        )

set(ALL_SOURCE_FILES ${SOURCE_FILES} ${TEST_SOURCE_FILES})

add_executable(nova-test ${SOURCE_FILES})
target_include_directories(nova-test SYSTEM PRIVATE)
target_link_libraries(nova-test glfw ${GLFW_LIBRARIES})

set_property(TARGET nova-test PROPERTY CXX_STANDARD 14)
set_property(TARGET nova-test PROPERTY CXX_STANDARD_REQUIRED ON)

set_target_properties(nova-test nova-renderer PROPERTIES LINK_FLAGS -ldl)

set(CMAKE_BUILD_TYPE Debug)
