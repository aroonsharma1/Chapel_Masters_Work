
unsigned char *main()
{
  /* Original stack frame of main*/
  int llvm_stackFrame[7];    
  unsigned int *llvm_ptr_1, *llvm_ptr_2;
  unsigned int llvm_tmp_1,llvm_tmp_2,llvm_tmp_3;

  llvm_ptr1 = (&llvm_stackFrame[1]);
  llvm_ptr2 = (&llvm_stackFrame[0]);
  *llvm_ptr1 = 20;
  *llvm_ptr2 = 10;

  llvm_tmp_2 = *llvm_ptr1;
  llvm_tmp_3 = *llvm_ptr2;

  llvm_tmp_1 = rewritten_foo(llvm_tmp_2, llvm_tmp_3);
  return llvm_tmp_1;
}


unsigned int rewritten_foo(unsigned int llvm_memArgIn1, unsigned int llvm_memArgIn2)
{
  /* Original stack frame of foo*/
  unsigned char llvm_stackFrame2[20];
  unsigned int llvm_stack1;
  unsigned int llvm_cbe_PHANTOM64_1_20_65;
  unsigned int llvm_cbe_EAX_20_789;
  unsigned int llvm_cbe_PHANTOM64_1_20_98;
  unsigned int llvm_cbe_EAX_20_1116;
  unsigned int llvm_cbe_storemerge10;

  llvm_ptr3 = &llvm_stackFrame2[8];
  *llvm_ptr3 = 30;

  if (llvm_memArgIn1 < 41)
  {
    goto llvm_cbe_080483dc;
  } else {
    goto llvm_cbe_080483c7;
  }

llvm_cbe_080483dc:
  llvm_tmp2 = llvm_memArgIn2 * 30;
  *(&llvm_stackFrame2[12] = llvm_tmp2;
  llvm_tmp3 = llvm_tmp2 + 25;
  *llvm_ptr3 = llvm_tmp3;   /* for PHI node */

  goto llvm_cbe_080483ef;

llvm_cbe_080483ef:
  *llvm_stack1 = llvm_cbe_storemerge10;

  return llvm_cbe_storemerge10;
llvm_cbe_080483c7:
  llvm_cbe_PHANTOM64_1_20_65 = ((unsigned int )(((unsigned int )llvm_cbe_memArgIn_20_0x00_20_) * ((unsigned int )30u)));
  *(((unsigned int *)((&llvm_cbe_stackFrame2_2e_ptr.array[((signed int )12u)])))) = llvm_cbe_PHANTOM64_1_20_65;
  llvm_cbe_EAX_20_789 = ((unsigned int )(((unsigned int )llvm_cbe_PHANTOM64_1_20_65) + ((unsigned int )5u)));
  *llvm_ptr3 = llvm_cbe_EAX_20_789;   /* for PHI node */
  goto llvm_cbe_080483ef;

}

