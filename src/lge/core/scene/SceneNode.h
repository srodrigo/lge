/*
 * Copyright (C) 2013 Sergio Rodrigo
 *
 * This software may be modified and distributed under the terms
 * of the MIT license. See the LICENSE file for details.
 */

#ifndef _LGE_SCENENODE_H_
#define _LGE_SCENENODE_H_

#include <vector>

namespace lge
{

/**
 * @brief Represents a node
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
	SceneNode();
	virtual ~SceneNode();
	
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
	 */
	virtual void update();
	
	/**
	 * @brief Draw the node
	 * 
	 * Draws the current node and its children.
	 */
	virtual void draw() const;

private:
	std::vector<SceneNode*> children;

};

} // namespace

#endif
