#ifndef _LGE_IMAGE_RESOURCE_H_
#define _LGE_IMAGE_RESOURCE_H_

#include "Resource.h"

#include <SFML/Graphics/Image.hpp>

namespace lge
{

namespace core
{

/**
 * @brief SFML Image resource wrapper
 * 
 * Wraps a SFML Image.
 * 
 * @see Resource
 * 
 * @author Sergio Rodrigo
 */
class ImageResource : public Resource<sf::Image>
{
public:
	explicit ImageResource(const std::string& filename);
	virtual ~ImageResource();
	
	/**
	 * @brief Loads a SFML Image
	 * 
	 * Allocates memory for a new SFML Image and loads the image from disk.
	 * 
	 * @return true if the resource was loaded successfully; false otherwise
	 */
	virtual bool load();
	
	virtual ImageResource* clone() const;
	
protected:
	ImageResource(const std::string& filename, sf::Image* const resource);

};

} // namespace

} // namespace

#endif
