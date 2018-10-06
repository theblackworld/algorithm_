#include"../include/murmurhash.h"
#include"string.h"

uint32_t DecodeFixed32(const char* ptr){
  return ((static_cast<uint32_t>(static_cast<unsigned char>(ptr[0])))
         | (static_cast<uint32_t>(static_cast<unsigned char>(ptr[1])) << 8)
         | (static_cast<uint32_t>(static_cast<unsigned char>(ptr[2])) << 16)
         | (static_cast<uint32_t>(static_cast<unsigned char>(ptr[3])) << 24));

}

uint32_t Hash(const char* data, int size ,int seed){
  const uint32_t r = 24;
  const int m = 0xc6a4a793;
  const char* limit = data + size;

  uint32_t h = seed^(size*m);

  while(data+4<limit){

    uint32_t w = DecodeFixed32(data);
    data = data+4;

    h += w;  //循环操作;
    h *= m;
    h ^= (h >> 16);

  }
  switch (limit - data) {
    case 3:
      h += static_cast<unsigned char>(data[2]) << 16;
      break;
    case 2:
      h += static_cast<unsigned char>(data[1]) << 8;
      break;
    case 1:
      h += static_cast<unsigned char>(data[0]);
      h *= m;
      h ^= (h >> r);  //仅剩余一字节;
      break;
  }
  return h;
}

uint32_t MurmurHashString(const string& key,int seed){
  return Hash(key.data(), key.size(), seed);
}

uint32_t MurmurHashChar(const char* key,int seed){
  return Hash(key, strlen(key), seed);
}


