//upcc -trans -T 2 -network smp -pthreads --nolines --opt -Wc,"-DRANGER" -Wu,"-Wb,-do-msg-vect" -Ww,-do-msg-vect -Ww,-do-msg-vect -I../common test.upc
//look for in .i #pragma bupc ivdep_rl


shared [] int *p;


int main() {
int i;
int sum = 0;

#pragma bupc ivdep
for(i = 0; i < 20; i++)
   sum += p[i];

printf("%d\n", sum);
return 0;
}