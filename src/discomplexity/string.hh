#ifndef   __DISCOMPLEXITY__STRING__HH__
#define   __DISCOMPLEXITY__STRING__HH__

#include <discomplexity.hh>

namespace discomplexity
{
	namespace experimental
	{
		class string
		{
		public:		static discomplexity::string from(uint32 v)
					{
						char buffer[4];
						memcpy(buffer, &v, sizeof(uint32));
						return discomplexity::string((char *) buffer, (size_t) 4);
					}
		};
	}
}

#endif // __DISCOMPLEXITY__STRING__HH__

