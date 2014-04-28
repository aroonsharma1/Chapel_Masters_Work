
unsigned int rewritten_foo(unsigned int llvm_memArgIn1, unsigned int llvm_memArgIn2)
{
  unsigned int llvm_tmp4;

  unsigned int llvm_tmp1 = llvm_memArgIn1 * llvm_memArgIn2;
  unsigned int llvm_tmp2 = llvm_memArgIn1 + llvm_memArgIn2;
  unsigned int llvm_tmp3 = llvm_memArgIn1 - llvm_memArgIn2;

  if (llvm_memArgIn1 <= 40)
  {
    goto llvm_LL1;
  } else {
    goto llvm_LL2;
  }

llvm_LL1:
  llvm_tmp4 = llvm_tmp2 + llvm_tmp3;
  goto llvm_ret;

llvm_LL2:
  llvm_tmp4 = llvm_tmp2 - llvm_tmp3;
  goto llvm_ret;

llvm_ret:
  llvm_tmp4 = llvm_tmp1 + llvm_tmp4
  return llvm_tmp4;
}

unsigned char *main()
{
  unsigned int llvm_tmp3;
  llvm_tmp_3 = rewritten_foo(10,20);
  return llvm_tmp3;
}
