//
// Created by Kimera Royal on 24/01/2024.
//

#pragma once

class RenderSource
{
public:
    virtual ~RenderSource() = default;

    virtual void Render() = 0;
};