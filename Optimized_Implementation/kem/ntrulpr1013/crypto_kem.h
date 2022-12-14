#ifndef crypto_kem_H
#define crypto_kem_H

#include "crypto_kem_ntrulpr1013.h"

#define crypto_kem_keypair crypto_kem_ntrulpr1013_keypair
#define crypto_kem_enc crypto_kem_ntrulpr1013_enc
#define crypto_kem_dec crypto_kem_ntrulpr1013_dec
#define crypto_kem_PUBLICKEYBYTES crypto_kem_ntrulpr1013_PUBLICKEYBYTES
#define crypto_kem_SECRETKEYBYTES crypto_kem_ntrulpr1013_SECRETKEYBYTES
#define crypto_kem_BYTES crypto_kem_ntrulpr1013_BYTES
#define crypto_kem_CIPHERTEXTBYTES crypto_kem_ntrulpr1013_CIPHERTEXTBYTES
#define crypto_kem_PRIMITIVE "ntrulpr1013"

#endif
