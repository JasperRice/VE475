#ifndef AES_H
#define AES_H

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class AES {
private:
	unsigned char SBox[256];
	unsigned char InvSBox[256];
	void GenerateSBox();
	void SubBytes(unsigned char state[][4]);
	void InvSubBytes(unsigned char state[][4]);

    void ShiftRows(unsigned char state[][4]);
    void InvShiftRows(unsigned char state[][4]);

    unsigned char Multiplication(unsigned char a, unsigned char b); // !!!!!
    void MixColumns(unsigned char state[][4]);
    void InvMixColumns(unsigned char state[][4]);

    unsigned char rKey[11][4][4];
	void GenerateRoundKey(unsigned char *key, unsigned char rKey[][4][4]); // !!!!!
	void AddRoundKey(unsigned char state[][4], unsigned char k[][4]);
	
public:
	AES(unsigned char *key);
	virtual ~AES();
	unsigned char *Encrypt(unsigned char *input);
	unsigned char *Decrypt(unsigned char *input);
}

#endif
