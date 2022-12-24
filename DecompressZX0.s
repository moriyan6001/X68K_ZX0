        .xdef   _ZX0Decompress
        .xref   zx0_decompress

        .offset 8

inParamSrc       ds.l    1
inParamDst       ds.l    1

        .text

_ZX0Decompress:
        link    a6,#0
        movem.l a0-a1,-(sp)

        move.l  inParamSrc(a6),a0
        move.l  inParamDst(a6),a1

        bsr     zx0_decompress

        movem.l (sp)+,a0-a1
        unlk    a6
        rts
