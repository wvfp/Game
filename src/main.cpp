#include "mainApplication/mainApplication.hpp"

constexpr int Delay_Time = 10;

int main(int argc, char *argv[])
{
	std::string name{"Square Adventure"};
	SDL_Rect size={SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1920,1440};
	Application *app=new mainApplication(name,size);

	bool running = true;
	SDL_Event *e = new SDL_Event();	
	SDL_Event *event = e;
	SDL_Point p;
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
		app->draw();
		app->present();
		//SDL_Delay(Delay_Time);
	}
	return 0;
}
