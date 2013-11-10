#include <unittest++/UnitTest++.h>

#include "../test.h"

TEST(TestGame_Run)
{
	lge::core::Game game;
	game.run();
}

int main(int argc, char **argv)
{
	return UnitTest::RunAllTests();
}
