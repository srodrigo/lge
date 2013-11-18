/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/Game.h"

namespace lge
{

const std::string Game::DEFAULT_NAME = "Lightweight Game Engine";

Game::Game()
		: name(DEFAULT_NAME), window(sf::VideoMode(800, 600), DEFAULT_NAME)
{
}

Game::~Game()
{
}

void Game::run()
{
	//window.setVisible(true);
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			
			window.clear(sf::Color::Black);
			window.display();
		}
	}
}

void Game::setName(const std::string& name) {
	this->name = name;
}

const std::string& Game::getName() const {
	return name;
}

} // namespace
