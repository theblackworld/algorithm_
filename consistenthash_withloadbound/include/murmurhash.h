#ifndef MURMURHASH_H_INCLUDED
#define MURMURHASH_H_INCLUDED
#include<string>
using std::string;

uint32_t MurmurHashString(const string& key,int seed);
uint32_t MurmurHashChar(const char* key,int seed);

#endif // MURMURHASH_H_INCLUDED
