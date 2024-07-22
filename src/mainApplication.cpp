#include <core/core.hpp>
#include "mainApplication.hpp"

constexpr int Delay_Time = 10;

int main(int argc, char *argv[])
{
	std::string name{"Hello Window"};
	SDL_Rect size={200,100,3*640,3*480};
	Application *app=new mainApplication(name,size);
	bool running = true;
	SDL_Event e;
	while (running)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				running = false;
			default:
				continue;
			}
		}
		app->event_handle(&e);
		app->draw();
		app->present();
		SDL_Delay(Delay_Time);
	}
	return 0;
}