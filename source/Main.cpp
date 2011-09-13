
#include "core/window.h"
#include "utility/log.h"
#include <assert.h>
#include <iostream>

#include "utility/class_parser.h"

class BasicTest
{
public:
	BasicTest();
	~BasicTest();

	int x;
};

BasicTest::BasicTest()
{
	x = 5;
};

BasicTest::~BasicTest()
{
};

int main()
{
	BasicTest *basic = new BasicTest();
	Utility::ClassParser *class_parser = new Utility::ClassParser();

	std::string test = "test.dat";
	if ( !class_parser->WriteClass<BasicTest>(basic, test) )
	{
		std::cout << "Couldn't write class!" << std::endl;
		return 0;
	}

	BasicTest *basic_2 = new BasicTest();
	basic_2 = class_parser->ReadClass<BasicTest>(test);
	
	assert(basic_2 != NULL && "Basic 2 was null");

	std::cout << "Success! " << basic_2->x << std::endl;

	delete basic;
	delete basic_2;

	// Initialize Game Window
	Core::Window * window;
	window = new (std::nothrow) Core::Window;

	// Assert if initialization succeeded
	assert(window != NULL && "Cannot create window at main()");

	window->Run();

	delete window;

	return 0;
}
