#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include <Widget.hpp>

class GameObject;
using GameObjectPtr = std::shared_ptr<GameObject>;


class GameObject{
public:
	GameObject(RendererPtr,SDL_Rect);
	void draw();
	void event_handle(SDL_Event*);
	inline void hideGO(bool);
	inline bool isHide();
	inline unsigned int getUID()const;
	void setPos_Size(const SDL_Rect&);
	SDL_Rect getPos_Size();
private:
	static unsigned int num;
	WidgetPtr wt;
	SDL_Rect Pos_Size;
	unsigned int uid;
	bool _hide;
};

#endif
