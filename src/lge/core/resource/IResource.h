#ifndef _LGE_IRESOURCE_H_
#define _LGE_IRESOURCE_H_

namespace lge
{

/**
 * @brief Resources Interface
 * 
 * Provides an empty interface for Resource classes, as they must be specialized
 * and it is useful to have a common non-templatizated interface to be able to
 * use polimorfism.
 * 
 * @author Sergio Rodrigo
 */
class IResource
{
public:
	virtual ~IResource() {}

protected:
	IResource() {}
	
};

} // namespace

#endif
