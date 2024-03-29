#include <stdio.h>
#include <stdlib.h>
#include "../Boolean/boolean.h"
#include "tree.h"

/* *** Konstruktor *** */
BinTree Tree(infotree Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (NilRec) jika alokasi gagal */
{
    BinTree P;
    P = AlokNode(Akar);
    if (P != NilRec)
    {
        Akar(P) = Akar;
        Left(P) = L;
        Right(P) = R;
    }
    return P;
}

void MakeTree(infotree Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R
        jika alokasi berhasil. P = NilRec jika alokasi gagal. */
{
    *P = AlokNode(Akar);
    if (*P != NilRec)
    {
        Akar(*P) = Akar;
        Left(*P) = L;
        Right(*P) = R;
    }
}

BinTree BuildBalanceTree(int n)
/* Menghasilkan sebuah balanced tree dengan n node, Nilai setiap node dibaca */
{
    addrNode P;
    BinTree L, R;
    infotree X;
    int nL, nR;

    if (n == 0)
    {
        return NilRec;
    }
    else
    {
        printf("Masukkan akar :");
        scanf("%d", &X);
        P = AlokNode(X);
        if (P != NilRec)
        {
            nL = n / 2;
            nR = n - nL - 1;
            L = BuildBalanceTree(nL);
            R = BuildBalanceTree(nR);
            Left(P) = L;
            Right(P) = R;
        }
        return P;
    }
}

/* Manajemen Memory */
addrNode AlokNode(infotree X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak NilRec, dan misalnya menghasilkan P,
  maka Akar(P) = X, Left(P) = NilRec, Right(P)=NilRec */
/* Jika alokasi gagal, mengirimkan NilRec */
{
    addrNode P;
    P = malloc(sizeof(Node));
    if (P != NilRec)
    {
        Akar(P) = X;
        Left(P) = NilRec;
        Right(P) = NilRec;
    }
    return P;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{
    free(P);
}

/* *** Predikat-Predikat Penting *** */
boolean IsTreeEmpty(BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
    return (P == NilRec);
}

boolean IsTreeOneElmt(BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
{
    if (!IsTreeEmpty(P))
    {
        return (Left(P) == NilRec && Right(P) == NilRec);
    }
    else
    {
        return false;
    }
}

boolean IsUnerLeft(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
{
    return (Left(P) != NilRec && Right(P) == NilRec);
}

boolean IsUnerRight(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
{
    return (Left(P) == NilRec && Right(P) != NilRec);
}

boolean IsBiner(BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
{
    return (Left(P) != NilRec && Right(P) != NilRec);
}

/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        printf("%d", Akar(P));
        PrintPreorder(Left(P));
        PrintPreorder(Right(P));
        printf(")");
    }
}

void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        PrintInorder(Left(P));
        printf("%d", Akar(P));
        PrintInorder(Right(P));
        printf(")");
    }
}
void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar.
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup ().
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh:
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    if (IsTreeEmpty(P))
    {
        printf("()");
    }
    else
    {
        printf("(");
        PrintPostorder(Left(P));
        PrintPostorder(Right(P));
        printf("%d", Akar(P));
        printf(")");
    }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    int i;
    int inith = h;

    if (!IsTreeEmpty(P))
    {
        printf("%d\n", Akar(P));
        if (!IsTreeEmpty(Left(P)))
        {
            for (i = 1; i <= h; i++)
            {
                printf(" ");
            }
            h += h;
            PrintTree(Left(P), h);
        }
        if (!IsTreeEmpty(Right(P)))
        {
            h = inith;
            for (i = 1; i <= h; i++)
            {
                printf(" ");
            }
            h += h;
            PrintTree(Right(P), h);
        }
    }
}

/* *** Searching *** */
boolean SearchTree(BinTree P, infotree X)
/* Mengirimkan true jika ada node dari P yang berNilRecai X */
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if (Akar(P) == X)
        {
            return true;
        }
        else
        {
            return SearchTree(Left(P), X) || SearchTree(Right(P), X);
        }
    }
}

/* *** Fungsi-Fungsi Lain *** */
int CountElmt(BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        return 1 + CountElmt(Left(P)) + CountElmt(Right(P));
    }
}

int NbDaun(BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
/* Prekondisi: P tidak kosong */
{
    if (IsTreeOneElmt(P))
    {
        return 1;
    }
    else
    {
        if (IsUnerLeft(P))
        {
            return NbDaun(Left(P));
        }
        else if (IsUnerRight(P))
        {
            return NbDaun(Right(P));
        }
        else
        {
            return NbDaun(Left(P)) + NbDaun(Right(P));
        }
    }
}

boolean IsSkewLeft(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
/* Pohon kosong adalah pohon condong kiri */
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if (IsTreeOneElmt(P))
        {
            return true;
        }
        else
        {
            if (IsUnerLeft(P))
            {
                return IsSkewLeft(Left(P));
            }
            else
            {
                return false;
            }
        }
    }
}

boolean IsSkewRight(BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
/* Pohon kosong adalah pohon condong kanan */
{
    if (IsTreeEmpty(P))
    {
        return true;
    }
    else
    {
        if (IsTreeOneElmt(P))
        {
            return true;
        }
        else
        {
            if (IsUnerRight(P))
            {
                return IsSkewRight(Right(P));
            }
            else
            {
                return false;
            }
        }
    }
}

int Level(BinTree P, infotree X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner P.
   Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
    if (Akar(P) == X)
    {
        return 1;
    }
    else
    {
        if (SearchTree(Left(P), X))
        {
            return 1 + Level(Left(P), X);
        }
        else
        {
            return 1 + Level(Right(P), X);
        }
    }
}

int Tinggi(BinTree P)
/* Pohon Biner mungkin kosong. Tinggi pohon kosong = 0.
   Mengirim "height" yaitu tinggi dari pohon */
{
    int a, b;

    if (IsTreeEmpty(P))
    {
        return 0;
    }
    else
    {
        a = Tinggi(Left(P));
        b = Tinggi(Right(P));
        if (a >= b)
        {
            return 1 + a;
        }
        else
        {
            return 1 + b;
        }
    }
}

/* *** Operasi lain *** */
void AddDaunTerkiri(BinTree *P, infotree X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
    if (IsTreeEmpty(*P))
    {
        *P = AlokNode(X);
    }
    else
    {
        AddDaunTerkiri(&Left(*P), X);
    }
}

void AddDaun(BinTree *P, infotree X, infotree Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
        sebagai anak Kanan X (jika Kiri = false) */
/*		Jika ada > 1 daun berNilRecai X, diambil daun yang paling kiri */
{
    if (IsTreeOneElmt(*P) && Akar(*P) == X)
    {
        if (Kiri)
        {
            Left(*P) = Tree(Y, NilRec, NilRec);
        }
        else
        {
            Right(*P) = Tree(Y, NilRec, NilRec);
        }
    }
    else
    {
        if (SearchTree(Left(*P), X))
        {
            AddDaun(&Left(*P), X, Y, Kiri);
        }
        else
        {
            AddDaun(&Right(*P), X, Y, Kiri);
        }
    }
}

void DelDaunTerkiri(BinTree *P, infotree *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
        disimpan pada daun terkiri yang dihapus */
{
    addrNode N;
    if (IsTreeOneElmt(*P))
    {
        *X = Akar(*P);
        N = *P;
        *P = NilRec;
        DealokNode(N);
    }
    else
    {
        if (IsUnerRight(*P))
        {
            DelDaunTerkiri(&Right(*P), X);
        }
        else
        {
            DelDaunTerkiri(&Left(*P), X);
        }
    }
}

void DelDaun(BinTree *P, infotree X)
/* I.S. P tidak kosong, minimum ada 1 daun berNilRecai X. */
/* F.S. Semua daun berNilRecai X dihapus dari P. */
{
    addrNode N;
    if (IsTreeOneElmt(*P) && Akar(*P) == X)
    {
        N = *P;
        *P = NilRec;
        DealokNode(N);
    }
    else
    {
        if (!IsTreeEmpty(*P))
        {
            DelDaun(&Left(*P), X);
            DelDaun(&Right(*P), X);
        }
    }
}

/* *** Binary  Search  Tree  *** */
boolean BSearch(BinTree P, infotree X)
/* Mengirimkan true jika ada node dari P yang berNilRecai X */
{
    if (IsTreeEmpty(P))
    {
        return false;
    }
    else
    {
        if (Akar(P) == X)
        {
            return true;
        }
        else if (X < Akar(P))
        {
            return BSearch(Left(P), X);
        }
        else
        {
            return BSearch(Right(P), X);
        }
    }
}

void InsSearch(BinTree *P, infotree X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum ada simpul P yang berNilRecai X. */
{
    if (IsTreeEmpty(*P))
    {
        MakeTree(X, NilRec, NilRec, P);
    }
    else
    {
        if (X < Akar(*P))
        {
            InsSearch(&Left(*P), X);
        }
        else if (X > Akar(*P))
        {
            InsSearch(&Right(*P), X);
        }
    }
}

void DelBtree(BinTree *P, infotree X)
/* I.S. Pohon P tidak  kosong */
/* F.S. NilRecai X yang dihapus pasti ada */
/* Sebuah node dengan NilRecai X dihapus */
{
    addrNode q;
    if (X < Akar(*P))
    {
        DelBtree(&Left(*P), X);
    }
    else if (X > Akar(*P))
    {
        DelBtree(&Right(*P), X);
    }
    else
    {
        q = Tree(Akar(*P), Left(*P), Right(*P));
        if (IsTreeOneElmt(*P))
        {
            *P = NilRec;
        }
        else if (IsUnerLeft(*P))
        {
            *P = Left(q);
        }
        else if (IsUnerRight(*P))
        {
            *P = Right(q);
        }
        else
        {
            DelNode(&Left(q));
        }
        DealokNode(q);
    }
}

void DelNode(BinTree *P)
{
    if (Right(*P) != NilRec)
    {
        DelNode(&Right(*P));
    }
    else
    {
        *P = Left(*P);
    }
}