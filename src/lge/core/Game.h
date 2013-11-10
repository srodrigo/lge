#ifndef _LGE_GAME_H_
#define _LGE_GAME_H_

#include <string>
#include <SFML/Graphics.hpp>

namespace lge
{

namespace core
{

class Game
{
public:
	Game();
	~Game();

	void run();

	void setName(const std::string& name);
	const std::string& getName() const;

private:
	static const std::string DEFAULT_NAME;
	
	std::string name;	
	sf::RenderWindow window;

};

}

}

#endif // _LGE_GAME_H_
