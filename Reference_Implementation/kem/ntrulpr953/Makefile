kat_kem.rsp: kat
	./run

kat: Makefile nist/kat_kem.c nist/rng.c nist/rng.h randombytes.h Decode.c Encode.c int32.c kem.c uint32.c     subroutines/crypto_hash_sha512.c subroutines/crypto_sort_uint32.c subroutines/crypto_stream_aes256ctr.c 
	./build

kat_kem_encap.rsp: kat_encap
	./runEncap

kat_encap: Makefile nist/addEncapTest.c nist/rng.c nist/rng.h randombytes.h Decode.c Encode.c int32.c kem.c uint32.c     subroutines/crypto_hash_sha512.c subroutines/crypto_sort_uint32.c subroutines/crypto_stream_aes256ctr.c 
	./buildEncap

kat_kem_decap.rsp: kat_decap
	./runDecap

kat_decap: Makefile nist/addDecapTest.c nist/rng.c nist/rng.h randombytes.h Decode.c Encode.c int32.c kem.c uint32.c     subroutines/crypto_hash_sha512.c subroutines/crypto_sort_uint32.c subroutines/crypto_stream_aes256ctr.c 
	./buildDecap

kat_kem_rand.rsp: kat_rand
	./runRand

kat_rand: Makefile nist/addRandTest.c nist/rng.c nist/rng.h randombytes.h Decode.c Encode.c int32.c kem.c uint32.c     subroutines/crypto_hash_sha512.c subroutines/crypto_sort_uint32.c subroutines/crypto_stream_aes256ctr.c 
	./buildRand