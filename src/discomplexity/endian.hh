#ifndef   __DISCOMPLEXITY__ENDIAN__HH__
#define   __DISCOMPLEXITY__ENDIAN__HH__

#include <discomplexity.hh>

namespace discomplexity
{
	class endian
	{
	public:		static uint32 convert(uint32 v)
				{
					return (v & 0xFF000000u) >> 24u |
						   (v & 0x00FF0000u) >>  8u |
						   (v & 0x0000FF00u) <<  8u |
						   (v & 0x000000FFu) << 24u;
				}
	};
}

#endif // __DISCOMPLEXITY__ENDIAN__HH__
