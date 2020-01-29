#include "chunk.hh"

namespace discomplexity
{
    namespace homeworld2
    {
        chunk chunk::gen(std::ifstream & ifs)
        {
            uint64 offset = ifs.tellg();
            uint32 type = 0;
            uint32 size = 0;
            uint32 id = 0;
            ifs.read((char*)&type, sizeof(uint32));
            ifs.read((char*)&size, sizeof(uint32));
            ifs.read((char*)&id, sizeof(uint32));
            size = endian::convert(size) - sizeof(id);
            if (type == FORM)
            {
                byte* bytes = nullptr;
                if (size > 0)
                {
                    bytes = new byte[size];
                    ifs.read((char*)bytes, size);
                }
                return chunk(offset, type, size, id, bytes);
            }
            return chunk();
        }

        chunk::chunk() : offset_(-1), type_(UNKNOWN), size_(0), id_(0), data_(nullptr)
        {
        }

        chunk::chunk(const chunk& o) : offset_(o.offset_), type_(o.type_), size_(o.size_), id_(o.id_), data_(nullptr)
        {
            if (this->size_ > 0)
            {
                this->data_ = new byte[this->size_];
                memcpy(this->data_, o.data_, this->size_);
            }
        }

        chunk::chunk(uint64 offset, uint32 type, uint32 size, uint32 id, byte * bytes) : offset_(offset), type_(type), size_(size), id_(id), data_(nullptr)
        {
            if (this->size_ > 0)
            {
                this->data_ = new byte[this->size_];
                memcpy(this->data_, bytes, this->size_);
            }
        }

        chunk::~chunk()
        {
            if (this->data_)
            {
                delete[] this->data_;
                this->data_ = nullptr;
            }
        }

        chunk & chunk::operator=(const chunk& o)
        {
            if (&o != this)
            {
                if (this->data_)
                {
                    delete[] this->data_;
                }
            }
            return *this;
        }
    }
}



using namespace discomplexity::homeworld2;

int main()
{
    std::ifstream ifs("sample.hod");
    while (!ifs.eof())
    {
        chunk p = chunk::gen(ifs);
        std::cout << p << std::endl;
    }
    return 0;
}
