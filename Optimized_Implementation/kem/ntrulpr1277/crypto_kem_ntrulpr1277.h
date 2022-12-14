#ifndef crypto_kem_ntrulpr1277_H
#define crypto_kem_ntrulpr1277_H

#define crypto_kem_ntrulpr1277_ref_SECRETKEYBYTES 2231
#define crypto_kem_ntrulpr1277_ref_PUBLICKEYBYTES 1847
#define crypto_kem_ntrulpr1277_ref_CIPHERTEXTBYTES 1975
#define crypto_kem_ntrulpr1277_ref_BYTES 32
 
#ifdef __cplusplus
extern "C" {
#endif
extern int crypto_kem_ntrulpr1277_ref_keypair(unsigned char *,unsigned char *);
extern int crypto_kem_ntrulpr1277_ref_enc(unsigned char *,unsigned char *,const unsigned char *);
extern int crypto_kem_ntrulpr1277_ref_dec(unsigned char *,const unsigned char *,const unsigned char *);
#ifdef __cplusplus
}
#endif

#define crypto_kem_ntrulpr1277_keypair crypto_kem_ntrulpr1277_ref_keypair
#define crypto_kem_ntrulpr1277_enc crypto_kem_ntrulpr1277_ref_enc
#define crypto_kem_ntrulpr1277_dec crypto_kem_ntrulpr1277_ref_dec
#define crypto_kem_ntrulpr1277_PUBLICKEYBYTES crypto_kem_ntrulpr1277_ref_PUBLICKEYBYTES
#define crypto_kem_ntrulpr1277_SECRETKEYBYTES crypto_kem_ntrulpr1277_ref_SECRETKEYBYTES
#define crypto_kem_ntrulpr1277_BYTES crypto_kem_ntrulpr1277_ref_BYTES
#define crypto_kem_ntrulpr1277_CIPHERTEXTBYTES crypto_kem_ntrulpr1277_ref_CIPHERTEXTBYTES

#endif
