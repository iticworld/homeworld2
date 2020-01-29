#ifndef   __DISCOMPLEXITY__HOMEWORLD2__CHUNK__HH__
#define   __DISCOMPLEXITY__HOMEWORLD2__CHUNK__HH__

#include <discomplexity.hh>
#include <discomplexity/string.hh>
#include <discomplexity/endian.hh>

namespace discomplexity
{
    namespace homeworld2
    {
        class chunk : public array<unsigned char>
        {
        public:     static chunk gen(std::ifstream & ifs);
        public:     enum type
                    {
                        UNKNOWN = 0,
                        NORMAL = 1,
                        FORM = 1297239878u,
                    };
        public:     typedef enum type type;
        private:    uint64 offset_;
        private:    uint32 type_;
        private:    uint32 size_;
        private:    uint32 id_;
        private:    byte * data_;
        public:     uint64 offset() const { return this->offset_; }
        public:     uint32 type() const { return this->type_; }
        public:     uint32 size() const { return this->size_; }
        public:     uint32 id() const { return this->id_; }
        public:     chunk & operator=(const chunk& o);
        public:     chunk & operator=(chunk && o) noexcept = delete;
        public:     chunk();
        public:     chunk(uint64 offset, uint32 type, uint32 size, uint32 id, byte * bytes);
        public:     chunk(const chunk& o);
        public:     chunk(chunk && o) noexcept = delete;
        public:     virtual ~chunk();
        public:     friend std::ostream& operator<<(std::ostream& os, const chunk& o)
                    {
                        if (o.offset_ == -1)
                        {
                            os << "null";
                        }
                        else
                        {
                            os << "{"
                               << "\"offset\": " << o.offset_ << ", "
                               << "\"type\": \"" << experimental::string::from(o.type_) << "\", "
                               << "\"size\": " << o.size_ << ", "
                               << "\"id\": \"" << experimental::string::from(o.id_) << "\""
                               << "}";
                        }
                        return os;
                    }
        };
    }
}

#endif // __DISCOMPLEXITY__HOMEWORLD2__CHUNK__HH__
