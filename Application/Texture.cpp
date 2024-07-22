#include "Texture.hpp"

//针对SurfacePtr的deleter
void SurfacePtrDeleter(SDL_Surface* surface){
    SDL_FreeSurface(surface);
    surface = nullptr;
    return;
}

//针对TexturePtr的deleter
void TexturePtrDeleter(SDL_Texture* texture){
    SDL_DestroyTexture(texture);
    texture=nullptr;
    return;
}

//根据路径加载图片，返回一个图片表面
SurfacePtr LoadImageSurface(RendererPtr render,std::string path){
    SDL_Surface *surface = NULL;
    surface = IMG_Load(path.c_str());
    return SurfacePtr(surface,SurfacePtrDeleter); 

}
//根据文本和字体与颜色创建一个表面
SurfacePtr LoadTextSurface(RendererPtr render,std::string text,TTF_Font*font,SDL_Color color){
    SDL_Surface *surface = NULL; 
    surface = TTF_RenderUTF8_Blended(font,text.c_str(),color);
    return SurfacePtr(surface,SurfacePtrDeleter);
}


//根据路径加载图片，返回一个图片纹理
TexturePtr LoadImageTexture(RendererPtr render,std::string path){
    SDL_Texture *texture = NULL;
    texture = SDL_CreateTextureFromSurface(render.get(),
    LoadImageSurface(render,path).get());
    return TexturePtr(texture,TexturePtrDeleter);
}
//根据文本和字体与颜色创建一个纹理
TexturePtr LoadTextTexture(RendererPtr render,std::string text,TTF_Font*font,SDL_Color color){
    SDL_Texture *texture = NULL;
    texture = SDL_CreateTextureFromSurface(render.get(),LoadTextSurface(render,text,font,color).get());
    return TexturePtr(texture,TexturePtrDeleter);
}