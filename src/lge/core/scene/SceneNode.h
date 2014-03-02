/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_SCENE_NODE_H
#define _LGE_SCENE_NODE_H

#include <vector>

#include <SFML/Graphics.hpp>

namespace lge
{

/**
 * @brief Represents a Scene node
 * 
 * Represents a node in a scene and provides operations to update and draw the node.
 * 
 * Contains children nodes, which allows creating a tree structure (Composite Pattern).
 * 
 * @author Sergio Rodrigo
 */
class SceneNode
{
public:
	SceneNode()
			: posX(0.0f), posY(0.0f) {}
	
	virtual ~SceneNode() {}
	
	/**
	 * @brief Add a child
	 * 
	 * Adds a child to the node.
	 * 
	 * @param child Pointer to the current child
	 */
	void addChild(SceneNode* child);
	
	/**
	 * @brief Remove a child
	 * 
	 * Removes a child from the current node.
	 * 
	 * @param child Pointer to the child
	 * @return true if the child exists; false otherwise
	 */
	bool removeChild(SceneNode* child);
	
	/**
	 * @brief Count children of the node
	 * 
	 * Counts the number of children of the current node.
	 * 
	 * @return Number of children
	 */
	int countChildren() const;
	
	/**
	 * @brief Update the node
	 * 
	 * Updates the current node and its children.
	 * 
	 * @param delta Time elapsed since las update
	 */
	virtual void update(sf::Int32 delta);
	
	/**
	 * @brief Draw the node
	 * 
	 * Draws the current node and its children.
	 * 
	 * @param window Window to draw the node in
	 */
	virtual void draw(sf::RenderWindow* window) const;
	
	void setPosition(float x, float y);
	void setPosition(sf::Vector2f pos);
	void setPosX(float x) { posX = x; }
	void setPosY(float y) { posY = y; }
	
	sf::Vector2f getPosition() { return sf::Vector2f(posX, posY); }
	float getPosX() const { return posX; };
	float getPosY() const { return posY; };

protected:
	std::vector<SceneNode*> getChildren() { return children; }

private:
	std::vector<SceneNode*> children;
	
	float posX, posY;

};

} // namespace

#endif
