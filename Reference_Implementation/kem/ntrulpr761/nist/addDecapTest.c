/*
   PQCgenKAT_kem.c
   Modified from a file created by Bassham, Lawrence E (Fed) on 8/29/17.
   Copyright © 2017 Bassham, Lawrence E (Fed). All rights reserved.
   + mods from djb: see KATNOTES
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rng.h"
#include "crypto_kem.h"

#define KAT_SUCCESS          0
#define KAT_FILE_OPEN_ERROR -1
#define KAT_CRYPTO_FAILURE  -4
#define NUMKATS 10

void	fprintBstr(FILE *fp, char *S, unsigned char *A, unsigned long long L);

unsigned char entropy_input[48];
unsigned char seed[NUMKATS][48];

int
main()
{
    FILE                *fp_req, *fp_rsp;
    int                 ret_val;
    int i;
    unsigned char *ct = 0;
    unsigned char *ss = 0;
    unsigned char *ss1 = 0;
    unsigned char *pk = 0;
    unsigned char *sk = 0;

    for (i=0; i<48; i++)
        entropy_input[i] = i;
    randombytes_init(entropy_input, NULL, 256);

    unsigned char skUnderTest[10][crypto_kem_SECRETKEYBYTES];
    unsigned char ctUnderTest[10][crypto_kem_CIPHERTEXTBYTES];

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[0][i]=0;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[0][i]=0;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[1][i]=0;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[1][i]=255;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[2][i]=255;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[2][i]=0;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[3][i]=255;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[3][i]=255;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[4][i]=0;
        if (i==0){
            ctUnderTest[4][i]=255;
        }
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[4][i]=0;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[5][i]=0;
        if (i==crypto_kem_CIPHERTEXTBYTES-1){
            ctUnderTest[5][i]=255;
        }
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[5][i]=0;
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[6][i]=0;
        if (i==0){
            ctUnderTest[6][i]=255;
        }
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[6][i]=0;
        if (i==0){
            skUnderTest[6][i]=255;
        }
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[7][i]=0;
        if (i==crypto_kem_CIPHERTEXTBYTES-1){
            ctUnderTest[7][i]=255;
        }
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[7][i]=0;
        if (i==crypto_kem_SECRETKEYBYTES-1){
            skUnderTest[7][i]=255;
        }
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[8][i]=0;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[8][i]=0;
        if (i==0){
            skUnderTest[8][i]=255;
        }
    }

    for (int i=0;i<crypto_kem_CIPHERTEXTBYTES;i++){
        ctUnderTest[9][i]=0;
    }
    for (int i=0;i<crypto_kem_SECRETKEYBYTES;i++){
        skUnderTest[9][i]=0;
        if (i==crypto_kem_SECRETKEYBYTES-1){
            skUnderTest[9][i]=255;
        }
    }

    for (i=0; i<NUMKATS; i++)
        randombytes(seed[i], 48);

    fp_req = fdopen(8, "w");
    if (!fp_req)
        return KAT_FILE_OPEN_ERROR;

    for (i=0; i<10; i++) {
        fprintf(fp_req, "count = %d\n", i);
        fprintBstr(fp_req, "seed = ", seed[i], 48);
        fprintf(fp_req, "pk =\n");
        fprintf(fp_req, "sk =\n");
        fprintf(fp_req, "ct =\n");
        fprintf(fp_req, "ss =\n\n");
    }

    fp_rsp = fdopen(9, "w");
    if (!fp_rsp)
        return KAT_FILE_OPEN_ERROR;

    fprintf(fp_rsp, "# kem/%s\n\n", crypto_kem_PRIMITIVE);

    for (i=0; i<NUMKATS; i++) {
        if (!ct) ct = malloc(crypto_kem_CIPHERTEXTBYTES);
        if (!ct) abort();
        if (!ss) ss = malloc(crypto_kem_BYTES);
        if (!ss) abort();
        if (!ss1) ss1 = malloc(crypto_kem_BYTES);
        if (!ss1) abort();
        if (!pk) pk = malloc(crypto_kem_PUBLICKEYBYTES);
        if (!pk) abort();
        if (!sk) sk = malloc(crypto_kem_SECRETKEYBYTES);
        if (!sk) abort();

        randombytes_init(seed[i], NULL, 256);

        fprintf(fp_rsp, "count = %d\n", i);
        fprintBstr(fp_rsp, "seed = ", seed[i], 48);
        
        fprintBstr(fp_rsp, "sk = ", skUnderTest[i], crypto_kem_SECRETKEYBYTES);

        
        if ( (ret_val = crypto_kem_dec(ss, ctUnderTest[i], skUnderTest[i])) != 0) {
            fprintf(stderr, "crypto_kem_dec returned <%d>\n", ret_val);
            return KAT_CRYPTO_FAILURE;
        }

        fprintBstr(fp_rsp, "ct = ", ctUnderTest[i], crypto_kem_CIPHERTEXTBYTES);
        fprintBstr(fp_rsp, "ss = ", ss, crypto_kem_BYTES);
        
        fprintf(fp_rsp, "\n");
    }

    return KAT_SUCCESS;
}

void
fprintBstr(FILE *fp, char *S, unsigned char *A, unsigned long long L)
{
	unsigned long long i;

	fprintf(fp, "%s", S);

	for ( i=0; i<L; i++ )
		fprintf(fp, "%02X", A[i]);

	if ( L == 0 )
		fprintf(fp, "00");

	fprintf(fp, "\n");
}
