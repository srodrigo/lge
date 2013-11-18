/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_GAME_H_
#define _LGE_GAME_H_

#include <string>

#include <SFML/Graphics.hpp>

namespace lge
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

} // namespace

#endif
