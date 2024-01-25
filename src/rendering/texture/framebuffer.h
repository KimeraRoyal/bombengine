//
// Created by s5311430 on 20/10/2023.
//

#pragma once

#include <string>
#include <vector>

#include "graphic.h"
#include "colorbuffer.h"
#include "renderbuffer.h"

namespace bombengine
{
    class FrameBuffer final : public Graphic
    {
    private:
        GLuint m_id;

        std::vector<ColorBuffer> m_colorBuffers;
        RenderBuffer m_renderBuffer;

        std::vector<std::string> m_textureNames;

        glm::ivec2 m_size;

        bool m_dirty;

        void Generate();
        void GenerateColorBuffers();
    public:
        explicit FrameBuffer(const glm::ivec2& _size, const std::vector<std::string>& _textureNames);
        ~FrameBuffer() override;

        void BindFramebuffer();
        void UnbindFramebuffer();

        // TODO: Create base class for this and Texture
        void Bind(GLuint _programId, int _index) override;

        void AddColorBuffer(GLint _internalFormat, GLenum _format, GLenum _type, GLint _filter, GLint _wrap);
        void AddColorBuffers(unsigned int _count, GLint _internalFormat, GLenum _format, GLenum _type, GLint _filter, GLint _wrap);
    };
} // bombengine