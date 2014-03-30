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
const unsigned int Game::DEFAULT_FPS = 30;

Game::Game()
		: name(DEFAULT_NAME), fps(DEFAULT_FPS)
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
	setup();
	mainLoop();
	cleanup();
}

void Game::setup()
{
	window->setVisible(true);
	window->setFramerateLimit(fps);
}

void Game::mainLoop()
{
	while (window->isOpen()) {
		processInput();
		scene->update();
		scene->draw();
	}
}

void Game::processInput()
{
	sf::Event event;
	while (window->pollEvent(event)) {
		lge::log::debug("Game::processInput", "Checking event");
		if (event.type == sf::Event::Closed) {
			window->close();
		}
		// TODO: Read user input
	}
}

void Game::cleanup() {}

} // namespace
