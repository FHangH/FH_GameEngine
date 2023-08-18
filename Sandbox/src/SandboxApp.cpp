#include <Fangh.h>

class Sandbox : public Fangh::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Fangh::Application* Fangh::CreateApplication()
{
	return new Sandbox();
}