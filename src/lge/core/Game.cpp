/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#include "lge/core/Game.h"

#include "lge/log/logger.h"

namespace lge
{

const std::string Game::DEFAULT_NAME = "Lightweight Game Engine";

Game::Game()
		: name(DEFAULT_NAME)
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), name);
	scene = new lge::Scene(window);
}

Game::~Game()
{
	delete scene;
	delete window;
}

void Game::run()
{
	lge::log::debug("Game::run", "Running game");
	
	sf::RenderWindow* renderWin = scene->getWindow();
	renderWin->setVisible(true);
	while (renderWin->isOpen()) {
		sf::Event event;
		renderWin->pollEvent(event);
		lge::log::debug("Game::run", "Checking event");
		if (event.type == sf::Event::Closed) {
			renderWin->close();
		}
		scene->draw();
		// TODO: delay
	}
}

} // namespace
