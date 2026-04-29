/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 2
 *   Hari dan Tanggal    : Rabu, 29 April 2026
 *   Nama (NIM)          : 13224031
 *   Nama File           : soal1.c
 *   Deskripsi           : Mengerjakan saol 1- Arsip Artefak Terkategori
 * 
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nama[101];
    char kategori [101];
    int tahun;
    int nilai;

} Artefak ;

int UrutArtefak(const void  *a, const void *b){
    Artefak *artA = (Artefak *)a;
    Artefak *artB = (Artefak *)b;

    int hasilkategori = strcmp(artA->kategori, artB->kategori);
    if (hasilkategori !=0){
        return hasilkategori;
    }
    if (artA->tahun != artB->tahun){
        return artA->tahun - artB->tahun;
    }

    if (artA->nilai != artB->nilai){
        return artB->nilai - artA->nilai;
    }
    return strcmp(artA->nama, artB->nama); 
}

int main (){
    int N ;  

    if (scanf("%d", &N) !=1) return 0;

    Artefak *daftarArtefak  = (Artefak *)malloc(N * sizeof(Artefak));

    for (int i = 0; i < N; i++){
        scanf("%s %s %d %d",daftarArtefak[i].nama,daftarArtefak[i].kategori,&daftarArtefak[i].tahun,&daftarArtefak[i].nilai);
    }
    qsort(daftarArtefak, N, sizeof(Artefak), UrutArtefak);

    for (int i = 0; i<N; i++){
        printf("%s %s %d %d\n ",daftarArtefak[i].nama,daftarArtefak[i].kategori,daftarArtefak[i].tahun,daftarArtefak[i].nilai);
    }

    free(daftarArtefak);

    return 0;
} 



