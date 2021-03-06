/*!
 * \author David
 * \date 22-May-16.
 */

#ifndef RENDERER_GL_UNIFORM_BUFFER_H
#define RENDERER_GL_UNIFORM_BUFFER_H

#include "../glad/glad.h"

/*!
 * \brief Represents a uniform buffer, which can be used for whatever
 */
class gl_uniform_buffer {
public:
    /*!
     * \brief Initializes this uniform buffer, creating it on the GPU and whatnot
     *
     * \param size The number of bytes to allocate for this buffer
     */
    gl_uniform_buffer(GLuint size);

    /*!
     * \brief Deallocates this uniform buffer
     */
    ~gl_uniform_buffer();

    /*!
     * \brief Binds this uniform buffer so we can to things to it
     *
     * \param bindpoint The buffer thing to bind this buffer to
     */
    void bind();

    /*!
     * \brief Binds this buffer to the given bind point
     *
     * \param bind_point The bind point to bind this buffer to
     */
    void set_bind_point(GLuint bind_point);

private:
    GLuint gl_name;
};


#endif //RENDERER_GL_UNIFORM_BUFFER_H
