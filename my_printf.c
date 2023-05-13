#include "printv.h"

void qztyu(char dxsz){
    write(1, &dxsz, 1);
}

char fgtys(char* iopw){
    pns zinmz;
    zinmz.cn = 0;
    for(zinmz.cn = 0; iopw[zinmz.cn] != 0; zinmz.cn++){
        qztyu(iopw[zinmz.cn]);
    }
    return zinmz.cn;
}


void tnshja(int jtyop[], int qwds)
{
    const char ytrz[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F',};
    if(qwds == 0) {
        qztyu('0');
    }
    for(; qwds > 0; qwds--) {
        qztyu(ytrz[jtyop[qwds - 1]]);
    }
}

int mdftw(unsigned long long wxz, int livazx)
{
    pns jnmv;
    jnmv.cn = 0;
    int *jtyop;
    jtyop = (int *)malloc(sizeof(int) * 128);
    for(; wxz > 0; jnmv.cn++){
        jtyop[jnmv.cn] = (int)(wxz % livazx);
        wxz /= livazx;
    }
    tnshja(jtyop, jnmv.cn);
    free(jtyop);
    return jnmv.cn != 0 ? jnmv.cn : 1;
}

int tyrwl(void* trwq)
{
    const char hex_digitz[] = "0123456789ABCDEF";
    char hex_str[17];
    unsigned long long addr = (unsigned long long)trwq;
    int po;
    write(1, "0x", 2);
    for (po = 15; po >= 0; po--) {
        hex_str[po] = hex_digitz[addr % 0x10];
        addr /= 0x10;
    }
    hex_str[16] = '\0';
    write(1, hex_str, 16);
    return 16;
}

int ptxi(unsigned int nmw)
{
    const char hex_digits[] = "0123456789ABCDEF";
    char hex_strr[9];
    int izx;
    for (izx = 7; izx >= 0; izx--) {
        hex_strr[izx] = hex_digits[nmw % 0x10];
        nmw /= 0x10;
    }
    hex_strr[8] = '\0';
    write(1, hex_strr, 8);
    return 8;
}

char *goctlz(int tkt){
    pns jonmz;
    char octalnum[10000];
    jonmz.cn = 0;
    jonmz.ml = 0;
for (; tkt != 0; tkt /= 8) {
    octalnum[jonmz.cn++] = tkt % 8;
}

    jonmz.nyw = (char*)malloc(sizeof(char*)*jonmz.cn -1);
int ply = jonmz.cn - 1;
while (ply >= 0) {
    jonmz.nyw[jonmz.ml] = octalnum[ply] + '0';
    jonmz.ml++;
    ply--;
}

    return jonmz.nyw;
}

char* nvmlt(int jkwe, char wqt){
    pns viu;
    int gh[10000];
    viu.cn = 0;
    viu.ml = 0;
    if(jkwe == 0){
        return "0";
    }
    int jt = 0;
    if (jkwe < 0){
        jkwe=jkwe*-1;
        if(wqt!='u')
        jt++;
    }
    while(jkwe!=0){
        gh[viu.cn]=jkwe%10;
        jkwe=jkwe/10;
        viu.cn++; 
    }
    viu.nyw =(char*)malloc(viu.cn);
    if(jt == 1){
        viu.nyw[0]='-';
        viu.ml++;
    }
    int xza = viu.cn - 1;
    while(xza >= 0){
        viu.nyw[viu.ml] = gh[xza]+'0';
        viu.ml++;
        xza--;
    }
    return viu.nyw;
}

int my_printf(char* formtxc, ...)
{
    va_list jtywq;
    va_start(jtywq, formtxc);
    pns cnz;
    cnz.ml = 0;
    int hvb = 0;
    while(formtxc[hvb] != 0) {
        if(formtxc[hvb] == '%') {
            hvb++;
            switch(formtxc[hvb]) {
                case 'c':
                    cnz.tr = (char)va_arg(jtywq, int);
                    qztyu(cnz.tr);
                    cnz.ml++;
                    break;
                case 's':
                    cnz.nyw= va_arg(jtywq, char*);
                    if(cnz.nyw == (char*)NULL) {
                        cnz.nyw = (char *)"(null)";
                    }
                    cnz.ml += fgtys(cnz.nyw);
                    break;
                case 'u':
                    cnz.cn = va_arg(jtywq, int);
                    cnz.ml += fgtys(nvmlt(cnz.cn,'u'));
                    break;
                case 'd':
                    cnz.cn = va_arg(jtywq, int);
                   cnz.ml += fgtys(nvmlt(cnz.cn,'d'));
                    break;
                case 'x':
                    cnz.ml += ptxi(va_arg(jtywq, unsigned int));
                    break;
                case 'o':
                    cnz.cn = va_arg(jtywq, int);
                    cnz.ml += fgtys(goctlz(cnz.cn));
                    break;
                case 'p':
                    cnz.ml += tyrwl(va_arg(jtywq, void*));
                    cnz.ml+=2;
                    break;
                default:
                    qztyu('%');
                    qztyu(formtxc[hvb]);
                    cnz.ml+=2;
            }
        }
        else{
            qztyu(formtxc[hvb]);
            cnz.ml++;
        }
        hvb++;
    }
    return cnz.ml;
}
/*
int main(){
    int h = my_printf("%p\n", "1234");
    my_printf("%d",h);
} */