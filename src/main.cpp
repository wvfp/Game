#include "mainApplication/mainApplication.hpp"
#include <FPSControler.hpp>

constexpr int FPS = 30;


int main(int argc, char *argv[])
{
	std::string name{"Square Adventure"};
	SDL_Rect size={SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1440};
	Application *app=new mainApplication(name,size);

	bool running = true;
	SDL_Event *e = new SDL_Event();	
	FPSControler fps(FPS);
	fps.start();
	while (running)
	{
		while (SDL_PollEvent(e))
		{
			switch (e->type)
			{
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
			app->event_handle(e);
		}
		app->update();
		app->draw();
		fps.tick();
		app->present();
	}
	return 0;
}
