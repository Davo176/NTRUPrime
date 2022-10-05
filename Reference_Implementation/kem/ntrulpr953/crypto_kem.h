#ifndef crypto_kem_H
#define crypto_kem_H

#include "crypto_kem_ntrulpr953.h"

#define crypto_kem_keypair crypto_kem_ntrulpr953_keypair
#define crypto_kem_enc crypto_kem_ntrulpr953_enc
#define crypto_kem_dec crypto_kem_ntrulpr953_dec
#define crypto_kem_PUBLICKEYBYTES crypto_kem_ntrulpr953_PUBLICKEYBYTES
#define crypto_kem_SECRETKEYBYTES crypto_kem_ntrulpr953_SECRETKEYBYTES
#define crypto_kem_BYTES crypto_kem_ntrulpr953_BYTES
#define crypto_kem_CIPHERTEXTBYTES crypto_kem_ntrulpr953_CIPHERTEXTBYTES
#define crypto_kem_PRIMITIVE "ntrulpr953"

#endif