/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_SCENE_H_
#define _LGE_SCENE_H_

#include "lge/core/scene/SceneNode.h"

#include <SFML/Graphics.hpp>

namespace lge
{

/**
 * @brief Represents a scene
 * 
 * Represents a scene and provides operations to update and draw.
 * 
 * Contains the root node of the scene.
 * 
 * @author Sergio Rodrigo
 */
class Scene
{
public:
	explicit Scene(sf::RenderWindow* window);
	
	virtual ~Scene();
	
	/**
	 * @brief Update the scene
	 * 
	 * Updates the scene updating the root node.
	 */
	void update();
	
	/**
	 * @brief Draw the scene
	 * 
	 * Draws the scene drawing the root node.
	 */
	void draw() const;
	
	/**
	 * @brief Set the root node
	 * 
	 * Sets the root node of the scene.
	 * 
	 * @param rootNode Root node
	 */
	void setRootNode(SceneNode* rootNode) { this->rootNode = rootNode; }
	
	/**
	 * @brief Get the root node
	 * 
	 * Gets the root node of the scene.
	 * 
	 * @return Root node
	 */
	SceneNode* getRootNode() { return rootNode; }
	
	/**
	 * @brief Get the window
	 * 
	 * Gets the window where the scene draws.
	 * 
	 * @return Window
	 */
	sf::RenderWindow* getWindow() { return window; }

private:
	SceneNode* rootNode;
	
	sf::RenderWindow* window;

};

} // namespace

#endif
