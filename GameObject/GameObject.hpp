#ifndef _GAMEOBJECT_
#define _GAMEOBJECT_

#include <Widget.hpp>

class GameObject;
using GameObjectPtr = std::shared_ptr<GameObject>;


class GameObject{
public:
	GameObject(RendererPtr,SDL_Rect);
	virtual void draw()=0;
	virtual  void event_handle(SDL_Event*)=0;
	inline void hideGO(bool);
	bool isHide();
	unsigned int getUID();
	void setPos_Size(const SDL_Rect&);
	SDL_Rect getPos_Size()const;
private:
	static unsigned int num;
	unsigned int uid;
protected:
	SDL_Rect Pos_Size;
	WidgetPtr wt;
	bool _hide;
};

#endif
