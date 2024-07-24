#ifndef _TEXTURE_
#define _TEXTURE_

#include "Application.hpp"

//针对SDL_Texture封装的智能指针
using TexturePtr = std::shared_ptr<SDL_Texture>;
//针对SDL_Surface封装的智能指针
using SurfacePtr = std::shared_ptr<SDL_Surface>;
//针对TexturePtr的deleter
void TexturePtrDeleter(SDL_Texture*);
//针对SurfacePtr的deleter
void SurfacePtrDeleter(SDL_Surface*);
//根据路径加载图片，返回一个图片纹理
TexturePtr LoadImageTexture(RendererPtr render,std::string path);
//根据文本和字体与颜色创建一个纹理
TexturePtr LoadTextTexture(RendererPtr render,std::string text,FontPtr font,SDL_Color color={0xff,0xff,0xff,0xff});

//根据路径加载图片，返回一个图片表面
SurfacePtr LoadImageSurface(RendererPtr render,std::string path);
//根据文本和字体与颜色创建一个表面
SurfacePtr LoadTextSurface(RendererPtr render,std::string text,FontPtr font,SDL_Color color={0xff,0xff,0xff,0xff});



#endif
