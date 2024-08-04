#include "GameObject.hpp"
#include <algorithm>

unsigned int GameObject::num=0;

GameObject::GameObject(RendererPtr r,SDL_Rect r_t){
	wt = LabelPtr(new Label(r,r_t));
	uid = num;
	num++;
	_hide = false;
	Pos_Size = r_t;
	return;
}	
void GameObject::draw(){
	if(isHide()){
		wt->draw();
	}
}
void GameObject::event_handle(SDL_Event* event){
	
}

void GameObject::hideGO(bool b){
	_hide = b;
}
bool GameObject::isHide(){
	return _hide;
}
unsigned int GameObject::getUID(){
	return uid;	
}
void GameObject::setPos_Size(const SDL_Rect& r){
	Pos_Size = r;
}

SDL_Rect GameObject::getPos_Size()const{
	return Pos_Size;
}	

void GameObject::update(){}