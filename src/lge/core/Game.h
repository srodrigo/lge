/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_GAME_H_
#define _LGE_GAME_H_

#include <string>

#include "lge/core/scene/Scene.h"

namespace lge
{

class Game
{
public:
	Game();
	~Game();

	void run();

	void setName(const std::string& name) { this->name = name; }
	const std::string& getName() const { return name; }
	
	void setFPS(unsigned int fps) { this->fps = fps; }
	
	lge::Scene* getScene() const { return scene; }
	
protected:
	/**
	 * @brief Perform actions before running the game
	 * 
	 * Performs the actions required before the game starts running.
	 * 
	 * To be overrided.
	 */
	void setup();
	
	/**
	 * @brief Perform actions after running the game
	 * 
	 * Performs the actions required after the game has finished running.
	 * 
	 * To be overrided.
	 */
	void cleanup();

private:
	static const std::string DEFAULT_NAME;
	static const unsigned int DEFAULT_FPS;
	
	std::string name;
	unsigned int fps;
	
	sf::RenderWindow* window;
	lge::Scene* scene;

};

} // namespace

#endif
