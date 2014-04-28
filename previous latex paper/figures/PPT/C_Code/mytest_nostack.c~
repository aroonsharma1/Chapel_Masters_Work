//Global Stack Pointer
int* llvm_ESP;

unsigned int rewritten_foo()
{
  int* llvm_EBP = llvm_ESP; //Local Frame Pointer
  llvm_ESP = llvm_ESP+10; //Global Stack Pointer

  unsigned int tmpIn1 = llvm_EBP[0];
  unsigned int tmpIn2; = llvm_EBP[1];

  unsigned int  llvm_tmp1 = tmpIn1*tmpIn2;
  llvm_ESP[1] = llvm_tmp1;

  unsigned int  llvm_tmp2 = tmpIn1+tmpIn2;
  llvm_ESP[2] = llvm_tmp2;

  unsigned int llvm_tmp3 = tmpIn1-tmpIn2;
  llvm_ESP[3] = llvm_tmp3;

  unsigned int llvm_tmpIn3 = llvm_EBP[0];
  if (llvm_tmpIn3 <= 40)
  {
    goto llvm_LL1;
  } else {
    goto llvm_LL2;
  }

llvm_LL1:
  unsigned int llvm_tmp5 = llvm_ESP[2];
  unsigned int llvm_tmp6 = llvm_ESP[3];
  llvm_ESP[5] = llvm_tmp5 + llvm_tmp6;
  goto llvm_ret;

llvm_LL2:
  unsigned int llvm_tmp7 = llvm_ESP[2];
  unsigned int llvm_tmp8 = llvm_ESP[3];
  llvm_ESP[5] = llvm_tmp7 - llvm_tmp8;
  goto llvm_ret;

llvm_ret:
  unsigned int llvm_tmp9 = llvm_ESP[1];
  unsigned int llvm_tmp10 = llvm_ESP[5];
  unsigned int llvm_tmp11 = llvm_tmp9 + llvm_tmp10;
  return llvm_tmp11;
}

unsigned char *main()
{ 
  llvm_ESP = llvm_ESP+2;
  llvm_ESP2[1] = 20;
  llvm_ESP2[0] = 10;
  unsigned int llvm_tmp_3 = rewritten_foo();
  return llvm_tmp3;
}
