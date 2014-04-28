unsigned int main()
{
  unsigned int llvm_tmp_1;
  llvm_tmp_1 = rewritten_foo(10, 20);
  return llvm_tmp_1;
}

unsigned int rewritten_foo(unsigned int llvm_memArg1, unsigned int llvm_memArg2)
{
  unsigned int llvm_EAX_1;
  unsigned int llvm_EAX_2;;
  unsigned int llvm_stackArg1;

  if (llvm_memArg1 < 41){
    goto llvm_LL1;
  } else {
    goto llvm_LL2;
  }

llvm_LL1:
  llvm_EAX_2 = llvm_memArg2 * 30 + 25;
  llvm_stack1 = llvm_EAX_2;  
  goto llvm_LL3;

llvm_LL2:
  llvm_EAX_1 = llvm__memArg1 * 30 + 5;
  llvm_stack1 = llvm_EAX_1;   
  goto llvm_LL3;

  llvm_LL3:
  return llvm_stack1;
}

