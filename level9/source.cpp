class N {
  public:
    N(int param_1) {
        *(N ***)this = &(N::operator+);
        _68 = param_1;
        return;
    }

    int operator+(N *param_1) {
      return *(int *)(param_1->_68) + *(int *)(this._68);
    }

    int operator-(N *param_1) {
      return *(int *)(this._68) - *(int *)(param_1->_68);
    }

    void setAnnotation(char *param_1) {
        size_t __n;
        
        __n = strlen(param_1);
        memcpy(this->str, param_1, __n);
        return;
    }

    N *ptr;
    char *str;
};



void main(int argc, char **argv) {
  N *A;
  N **B;
  
  if (argc < 2) {
    _exit(1);
  }

  A = new N(5);
  B[0] = new N(6);
  A->setAnnotation(argv[1]);
  B[0](A);
  return;
}