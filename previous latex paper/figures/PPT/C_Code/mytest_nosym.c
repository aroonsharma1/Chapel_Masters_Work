
unsigned int rewritten_foo(unsigned int llvm_memArgIn1, unsigned int llvm_memArgIn2)
{
  unsigned int llvm_ESP1[10];

  unsigned int llvm_tmp1 = llvm_memArgIn1*llvm_memArgIn2;
  llvm_ESP1[1] = llvm_tmp1;

  unsigned int llvm_tmp2 = llvm_memArgIn1 + llvm_memArgIn2;
  llvm_ESP1[2] = llvm_tmp2;

  unsigned int llvm_tmp3 = llvm_memArgIn1 - llvm_memArgIn2;
  llvm_ESP1[3] = llvm_tmp3;

  if (llvm_memArgIn1 <= 40)
  {
    goto llvm_LL1;
  } else {
    goto llvm_LL2;
  }

llvm_LL1:
  unsigned int llvm_tmp5 = llvm_ESP1[2];
  unsigned int llvm_tmp6 = llvm_ESP1[3];
  unsigned int llvm_ESP1[5] = llvm_tmp5 + llvm_tmp6;
  goto llvm_ret;

llvm_LL2:
  unsigned int llvm_tmp7 = llvm_ESP1[2];
  unsigned int llvm_tmp8 = llvm_ESP1[3];
  llvm_ESP1[5] = llvm_tmp7 - llvm_tmp8;
  goto llvm_ret;

llvm_ret:
  unsigned int llvm_tmp9 = llvm_ESP1[1];
  unsigned int llvm_tmp10 = llvm_EDP[5];
  unsigned int llvm_tmp11 = llvm_tmp9 + llvm_tmp10;
  return llvm_tmp11;
}

unsigned char *main()
{
  unsigned int llvm_ESP1[10];

  llvm_ESP2[1] = 20;
  llvm_ESP2[2] = 10;
  unsigned int llvm_tmp1 = llvm_ESP2[1];
  unsigned int llvm_tmp2 = llvm_ESP2[2];

  unsigned int llvm_tmp_3 = rewritten_foo(llvm_tmp2,llvm_tmp1);
  return llvm_tmp3;
}
