#include "common/runtime.h"

#include "common/drawable.h"
#include "objects/canvas/canvas.h"
#include "modules/window.h"

Canvas::Canvas(int width, int height) : Drawable("Canvas")
{
    this->texture = SDL_CreateTexture(Window::GetRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, width, height);

    this->width = width;
    this->height = height;
    
    this->viewport = {0, 0, this->width, this->height, this->width, this->height};
}

void Canvas::SetAsTarget()
{
    SDL_SetRenderTarget(Window::GetRenderer(), this->texture);
}